#-------------------------------------------------
#
# Project created by QtCreator 2014-01-23T22:42:11
#
#-------------------------------------------------

QT       += core gui

TARGET = OCRNeural
TEMPLATE = app


SOURCES += main.cpp\
        ocrneural.cpp \
    ftraining.cpp \
    OpenCV-Header.cpp \
    neuron.cpp \
    net.cpp

HEADERS  += ocrneural.h \
    ftraining.h \
    OpenCV-Header.h \
    neuron.h \
    net.h

FORMS    += ocrneural.ui \
    ftraining.ui

RESOURCES += \
    MyRes.qrc

INCLUDEPATH += D:\\OpenCV\\OpenCV-2.3.1\\binary\\install\\include
LIBS += -LD:\\OpenCV\\OpenCV-2.3.1\\binary\\install\\lib \
    -lopencv_core231.dll \
    -lopencv_highgui231.dll \
    -lopencv_imgproc231.dll \
    -lopencv_features2d231.dll \
    -lopencv_calib3d231.dll \
    -lopencv_objdetect231.dll






















