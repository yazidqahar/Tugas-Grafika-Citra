#include "ftraining.h"
#include "ui_ftraining.h"
#include <qfiledialog.h>
#include <QMessageBox>
FTraining::FTraining(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FTraining)
{
    topology.push_back(dimensi * dimensi); //input
    topology.push_back(100); //hidden1
    topology.push_back(output); //output
    myNet.setTopology(topology);
    ui->setupUi(this);
    sourceImg = NULL;
}

FTraining::~FTraining()
{
    delete ui;
}

vector<VPointData> findCharfromImage(IplImage * src){
        vector<VPointData> masterData;
        IplImage * source = cvCloneImage(src);
        BinaryImg imgSrc(source);
        bool masuk = true;
        //find rows;
        Point temp;
        vector<Point> rows;
        bool ketemu;
        temp.awal = -1; temp.akhir = -1;
        int err = 0;
        for(int i = 0; i < source->height; i++){
                ketemu = false;
                for(int j = 0; j < source->width; j++){
                        if(imgSrc[i][j].bin == 255){
                                if(temp.awal == -1)temp.awal = i;
                                ketemu = true; break;
                        }
                }
                if(!ketemu && temp.awal != -1 && (err > 10 || (i+1 >= source->height))){
                        temp.akhir = i-1;
                        rows.push_back(temp);
                        temp.awal = -1; temp.akhir = -1;
                        err = 0;
                }else
                        err++;
        }

        //find char per row
        for(int k = 0; k < rows.size(); k++){
                masterData.push_back(VPointData());
                for(int j = 0; j < source->width; j++){
                        ketemu = false;
                        for(int i = rows[k].awal; i <= rows[k].akhir; i++){
                                if(imgSrc[i][j].bin == 255){
                                        if(temp.awal == -1)temp.awal = j;
                                        ketemu = true; break;
                                }
                        }
                        if(!ketemu && temp.awal != -1){
                                temp.akhir = j-1;
                                masterData.back().push_back(PointData());
                                masterData.back().back().x1 = temp.awal;
                                masterData.back().back().x2 = temp.akhir;
                                masterData.back().back().y1 = rows[k].awal;
                                masterData.back().back().y2 = rows[k].akhir;
                                temp.awal = -1; temp.akhir = -1;
                        }
                }
        }

        //find specific height each char
        temp.awal = -1; temp.akhir = -1;
                for(int k = 0; k < masterData.size(); k++){
                        for(int l = 0; l < masterData[k].size(); l++){
                                temp.awal = -1; temp.akhir = -1;
                                err = 0;
                                for(int i = masterData[k][l].y1; i <= masterData[k][l].y2; i++){
                                        ketemu = false;
                                        for(int j = masterData[k][l].x1; j <= masterData[k][l].x2; j++){
                                                if(imgSrc[i][j].bin == 255){
                                                        if(temp.awal == -1)temp.awal = i;
                                                        ketemu = true; break;
                                                }
                                        }
                                        if(!ketemu && temp.awal != -1)
                                                err++;

                                        if((!ketemu && temp.awal != -1) || (err>10 || i == masterData[k][l].y2)){
                                                temp.akhir = (i == masterData[k][l].y2)?i:(i-1);
                                                masterData[k][l].y1 = temp.awal;
                                                masterData[k][l].y2 = temp.akhir;
                                                temp.akhir = -1;
                                                temp.awal = -1;
                                                err = 0;
                                        }
                                }


                        }
                }
    return masterData;
}

//fungsi untuk melakukan scaling gambar sesuai dimensi yang akan diolah oleh neural
IplImage * getImgCharAndScaling(IplImage * source, PointData point){
        IplImage * result = cvCreateImage(cvSize(dimensi,dimensi),8,1);
        BinaryImg imgSrc(source);
        BinaryImg imgDst(result);

        for(int i = 0; i < dimensi; i++){
                for(int j = 0; j < dimensi; j++){
                        imgDst[i][j].bin = imgSrc[point.y1+(i*(point.y2-point.y1+1)/dimensi)][point.x1+(j*(point.x2-point.x1+1)/dimensi)].bin;
                }
        }
        return result;
}

IplImage * boxing(IplImage * source, vector<VPointData> data)
{
    IplImage * temp = cvCloneImage(source);
        RgbImage imgSrc(temp);

        for(int s = 0; s < data.size(); s++){
                for(int k = 0; k < data[s].size(); k++)
                {
                        for(int i = data[s][k].y1; i <= data[s][k].y2; i++)
                        {
                                for(int j = data[s][k].x1; j <= data[s][k].x2;j++)
                                {
                                        if(i > (data[s][k].y1) && i < (data[s][k].y2) && j > (data[s][k].x1) && j < data[s][k].x2)
                                                continue;

                                        imgSrc[i][j].r = 255;imgSrc[i][j].g = 0; imgSrc[i][j].b = 0;
                                }
                        }

                }
        }
        int min = 0; int max = 0;
        for(int s = 0; s < data.size(); s++){
                for(int i = 0; i < data[s].size(); i++){
                        if(data[s][i].y1 < data[s][min].y1)
                                min = i;
                        if(data[s][i].y2 < data[s][max].y1)
                                max = i;
                }

                for(int i = data[s][min].y1; i <= data[s][max].y2; i++){
                        for(int j = data[s][0].x1; j <= data[s][data[s].size()-1].x2; j++)
                        {
                                if(i > (data[s][min].y1) && i < (data[s][max].y2) && j > (data[s][0].x1) && j < data[s][data[s].size()-1].x2)
                                        continue;
                                imgSrc[i][j].r = 0;imgSrc[i][j].g = 255;imgSrc[i][j].b = 0;
                        }
                }

        }

    return temp;
}

IplImage * rgbToGray(IplImage * source, int threshold)
{
    IplImage * binary = cvCreateImage(cvSize(source->width, source->height),8,1);
    RgbImage imgSrc(source);
    BinaryImg imgDst(binary);

    for(int i = 0; i < binary->height; i++)
        for(int j = 0; j < binary->width; j++)
            if(imgSrc[i][j].r < threshold && imgSrc[i][j].g < threshold && imgSrc[i][j].b < threshold)
                imgDst[i][j].bin = 255;
            else
                imgDst[i][j].bin = 0;
    return binary;
}

QImage IplImage2QImage(const IplImage *iplImage){
    int height = iplImage->height;
    int width = iplImage->width;

    if  (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3)
    {
      const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
      QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
      return img.rgbSwapped();
    }
    else if  (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 1)
    {
        const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
        QImage img(qImageBuffer, width, height, QImage::Format_Indexed8);

        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++)
        {
            colorTable.push_back(qRgb(i, i, i));
        }
        img.setColorTable(colorTable);
        return img;
    }
    else
    {
      std::cout << "Image cannot be converted.";
      return QImage();
    }
}

vector<double> imageGrayToVector(IplImage * srcImage)
{
        BinaryImg imgSrc(srcImage);
        vector<double> result;
        for(int i = 0; i < srcImage->height; i++)
                for(int j = 0; j < srcImage->width; j++){
                        if(imgSrc[i][j].bin < 190){
                                result.push_back(0.0);
                        }else{
                                result.push_back(1.0);
                        }
                }
        return result;
}

void FTraining::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open File Gambar","","File Gambar (*.jpg)");
    if(filename != ""){
        sourceImg = cvLoadImage(filename.toStdString().c_str(), 1);
        if (sourceImg)
        {
            QImage qt_img = IplImage2QImage(sourceImg);
            ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
            ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
            ui->scrollArea->setWidget(ui->gambarshow);


        }else
            QMessageBox::information(this,"Error Open File","File Image Cannot to Open");
    }
}

void FTraining::on_thresholdVal_valueChanged(int arg1)
{
    if(sourceImg != NULL){
        QImage qt_img = IplImage2QImage(rgbToGray(sourceImg,arg1));
        ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
        ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
        ui->scrollArea->setWidget(ui->gambarshow);
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}

void FTraining::on_showThresholdAction_clicked(bool checked)
{
    if(sourceImg != NULL){
        QImage qt_img = IplImage2QImage(rgbToGray(sourceImg,ui->thresholdVal->value()));
        ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
        ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
        ui->scrollArea->setWidget(ui->gambarshow);
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}

void FTraining::on_ShowBoxAction_clicked(bool checked)
{
    if(sourceImg != NULL){
        vector<VPointData> masterData;
        masterData = findCharfromImage(rgbToGray(sourceImg,ui->thresholdVal->value()));
        QImage qt_img = IplImage2QImage(boxing(sourceImg,masterData));
        ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
        ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
        ui->scrollArea->setWidget(ui->gambarshow);
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}



void FTraining::on_actionRun_Learning_triggered()
{
    if(sourceImg != NULL){
        vector<VVDouble> inputVals;
        vector<double> targetVal;
        vector<VVDouble> targetVals;
        vector<VPointData> masterData;
        IplImage * imgGray = rgbToGray(sourceImg,ui->thresholdVal->value());
        masterData = findCharfromImage(imgGray);
        for(int l = 0; l < masterData.size(); l++){
            for(int i = 0; i < output; i++) targetVal.push_back(0.0);
            targetVal[l] = 1.0;

            targetVals.push_back(targetVal);
            targetVal.clear();

            for(int k = 0; k < masterData[l].size(); k++){
                inputVals.push_back(imageGrayToVector(getImgCharAndScaling(imgGray,masterData[l][k])));
            }
        }

        stringstream ss;
        ss << "You Will Learn with " << masterData.size() << " pattern ?";
        if(QMessageBox::question(this, "Confirmation Learning", ss.str().c_str(),QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes){
            long i = 0;
            double error = 0.0;
            int idxData;
            bool berhasil = true;
            do{
                error = 0.00001;
                idxData = 0;
                berhasil = true;
                for(int l = 0; l < masterData.size(); l++){
                    for(int k = 0; k < masterData[l].size(); k++){
                        myNet.feedForward(inputVals[idxData++]);
                        myNet.backProp(targetVals[l]);
                    }
                    i++;
                    if(error < myNet.getError())
                        error = myNet.getError();
                    if(i % 100 == 0){

                        QCoreApplication::processEvents();
                        ss.clear();
                        ss.str("");
                        ss << i;
                        ui->iterationVal->setText(ss.str().c_str());
                        ss.str("");
                        ss << error;
                        ui->CurrErrorVal->setText(ss.str().c_str());
                        ss.str("");
                        ss << (ui->targetErrorVal->value()/error*100) << " %";
                        ui->CompleteVal->setText(ss.str().c_str());
                    }
                    //ss.str("");
                    //ss << ui->targetErrorVal->value();
                    //QMessageBox::information(this,"judu",ss.str().c_str());

                    if(myNet.getError() > ui->targetErrorVal->value())
                        berhasil =false;
                }

            }while (!berhasil);

        }
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}


void FTraining::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save Weight Learned","","File Neural (*.neu)");
    if(filename != ""){
        FILE * file;
        file = fopen(filename.toStdString().c_str(),"wb");
        for(int i = 0; i< myNet.m_layers.size(); i++) {
            for(int j = 0; j < myNet.m_layers[i].size(); j++){
                for(int k = 0; k < myNet.m_layers[i][j].m_outputWeights.size(); k++){
                    fwrite(&myNet.m_layers[i][j].m_outputWeights[k],sizeof(myNet.m_layers[i][j].m_outputWeights[k]),1, file);
                }
                fwrite(&myNet.m_layers[i][j].m_outputVal,sizeof(double),1, file);
            }
        }
        fclose(file);
    }
}

void FTraining::on_actionLoad_Weight_Neuron_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Save Weight Learned","","File Neural (*.neu)");
    if(filename != ""){
        FILE * file;
        file = fopen(filename.toStdString().c_str(),"rb");
        for(int i = 0; i< myNet.m_layers.size(); i++) {
            for(int j = 0; j < myNet.m_layers[i].size(); j++){
                for(int k = 0; k < myNet.m_layers[i][j].m_outputWeights.size(); k++){
                    fread(&myNet.m_layers[i][j].m_outputWeights[k],sizeof(myNet.m_layers[i][j].m_outputWeights[k]),1, file);
                }
                fread(&myNet.m_layers[i][j].m_outputVal,sizeof(double),1, file);
            }
        }
        fclose(file);
    }
}
