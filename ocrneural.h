#ifndef OCRNEURAL_H
#define OCRNEURAL_H

#include <QMainWindow>
#include "ftraining.h"

namespace Ui {
    class OCRNeural;
}

class OCRNeural : public QMainWindow
{
    Q_OBJECT

public:
    explicit OCRNeural(QWidget *parent = 0);
    ~OCRNeural();

private slots:
    void on_action_Training_triggered();

    void on_actionLoad_Image_triggered();

    void on_actionLoad_Neural_triggered();

    void on_actionRun_OCR_triggered();

    void on_showThresholdAction_clicked(bool checked);

    void on_ShowBoxAction_clicked(bool checked);

    void on_thresholdVal_valueChanged(int arg1);

private:
    Ui::OCRNeural *ui;
    FTraining ftraining;
    IplImage * sourceImg;
    vector<double> resultVals;
    vector<unsigned> topology;
    Net myNet;
};

#endif // OCRNEURAL_H
