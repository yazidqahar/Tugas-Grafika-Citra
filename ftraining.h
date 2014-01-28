#ifndef FTRAINING_H
#define FTRAINING_H

#include <QMainWindow>
#include "OpenCV-Header.h"
#include <vector>
#include "net.h"
#define dimensi 8
#define output 26
using namespace std;
vector<VPointData> findCharfromImage(IplImage * src);
IplImage * getImgCharAndScaling(IplImage * source, PointData point);
IplImage * boxing(IplImage * source, vector<VPointData> data);
IplImage * rgbToGray(IplImage * source, int threshold);
QImage IplImage2QImage(const IplImage *iplImage);
vector<double> imageGrayToVector(IplImage * srcImage);

namespace Ui {
    class FTraining;
}

class FTraining : public QMainWindow
{
    Q_OBJECT

public:
    explicit FTraining(QWidget *parent = 0);
    ~FTraining();

private slots:
    void on_actionOpen_triggered();

    void on_thresholdVal_valueChanged(int arg1);

    void on_showThresholdAction_clicked(bool checked);

    void on_ShowBoxAction_clicked(bool checked);

    void on_actionRun_Learning_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_Weight_Neuron_triggered();

private:
    Ui::FTraining *ui;
    IplImage * sourceImg;
    vector<unsigned> topology;
    Net myNet;
};



#endif // FTRAINING_H
