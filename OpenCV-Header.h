#ifndef OpenCV_h
#define OpenCV_h

#endif // OPENCVHEADER_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QtCore>
using namespace std;

template <class T> class Image
{
        private:
                IplImage *imgp;
        public:
                Image(IplImage *img = 0) {imgp = img;}
                ~Image() {imgp = 0;}
                void operator = (IplImage *img){imgp = img;}
                inline T* operator[](const int rowIndx){
                        return ((T*)(imgp->imageData + rowIndx *imgp ->widthStep));
                }
};
typedef struct{
        unsigned char b, g, r;
}
RgbPixel;
typedef struct{
        unsigned char bin;
}
BinaryPixel;
typedef Image<RgbPixel> RgbImage;
typedef Image<BinaryPixel> BinaryImg;

typedef struct{
        int x1, x2, y1, y2;
} PointData;

typedef vector<PointData> VPointData;
typedef struct {int awal, akhir;} Point;
typedef vector<double> VVDouble;


