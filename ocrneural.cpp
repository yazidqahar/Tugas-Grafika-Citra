#include "ocrneural.h"
#include "ui_ocrneural.h"
#include <qfiledialog.h>
#include <QMessageBox>

OCRNeural::OCRNeural(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OCRNeural)
{
    topology.push_back(dimensi * dimensi); //input
    topology.push_back(100); //hidden1
    topology.push_back(output); //output
    myNet.setTopology(topology);
    sourceImg = NULL;
    ui->setupUi(this);
}

OCRNeural::~OCRNeural()
{
    delete ui;
}

//fungsi untuk melakukan scaling gambar sesuai dimensi yang akan diolah oleh neural


char outputChar(vector<double> data){
        int max = 0;
        char result = ' ';
        for(int i = 0; i < data.size(); i++)
            if(data[max] < data[i])
                max = i;

        if(max < 26)
            result = (char)(max+65);
        else if(max < 52)
            result = (char)(max+71);
        else
            result = (char)(max-4);

        return result;
}

void OCRNeural::on_action_Training_triggered(){
    ftraining.raise();
    ftraining.activateWindow();
    ftraining.showNormal();
}

void OCRNeural::on_actionLoad_Image_triggered(){
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

void OCRNeural::on_actionLoad_Neural_triggered(){
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

void OCRNeural::on_actionRun_OCR_triggered(){
    if(sourceImg != NULL){
        vector<double> resultVals;
        vector<VPointData> masterData;
        IplImage * gray = rgbToGray(sourceImg,ui->thresholdVal->value());
        masterData = findCharfromImage(gray);
        boxing(sourceImg,masterData);
        stringstream ss;
        for(int l = 0; l < masterData.size(); l++){
            for(int k = 0; k < masterData[l].size(); k++){
                myNet.feedForward(imageGrayToVector(getImgCharAndScaling(gray,masterData[l][k])));
                myNet.getResults(resultVals);
                ss << outputChar(resultVals);
                if((masterData[l][((k+1) < masterData[l].size())?(k+1):k].x1 - masterData[l][k].x2) > 5)
                    ss << " ";
            }
                ss << endl;
        }
        ui->resultOCR->setText(ss.str().c_str());
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}

void OCRNeural::on_showThresholdAction_clicked(bool checked){
    if(sourceImg != NULL){
        QImage qt_img = IplImage2QImage(rgbToGray(sourceImg,ui->thresholdVal->value()));
        ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
        ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
        ui->scrollArea->setWidget(ui->gambarshow);
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}

void OCRNeural::on_ShowBoxAction_clicked(bool checked){
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

void OCRNeural::on_thresholdVal_valueChanged(int arg1){
    if(sourceImg != NULL){
        QImage qt_img = IplImage2QImage(rgbToGray(sourceImg,arg1));
        ui->gambarshow->setGeometry(QRect(0,0,sourceImg->width,sourceImg->height));
        ui->gambarshow->setPixmap(QPixmap::fromImage(qt_img));
        ui->scrollArea->setWidget(ui->gambarshow);
    }else
        QMessageBox::information(this,"Information","Please Select Image File first");
}
