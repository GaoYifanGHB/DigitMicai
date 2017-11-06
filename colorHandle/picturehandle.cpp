#include "picturehandle.h"

PictureHandle::PictureHandle()
{
}

void PictureHandle::setSize(int l, int w, int h)
{
    this->l=l;
    this->w=w;
    this->h=h;
}

void PictureHandle::setBgColor(QColor bgcolor)
{
    this->bgcolor=bgcolor;
}

void PictureHandle::drawOneGrid(int x, int y, QColor color, Mat &mat)
{
    int r,b,g;
    color.getRgb(r,g,b);
    x*=10;y*=10;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            Vec3b&rgb=mat.at<Vec3b>(i,j);
            rgb[2]=r;rgb[1]=g;rgb[0]=b;
        }
    }
}

void PictureHandle::drawBgColor(Mat &mat)
{
    int r,b,g;
    bgcolor.getRgb(r,g,b);
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            Vec3b&rgb=mat.at<Vec3b>(i,j);
            rgb[2]=r;rgb[1]=g;rgb[0]=b;
        }
    }
}

void PictureHandle::drawOneDigit(Digit d, int dx, int dy, Mat &mat)
{
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                drawOneGrid(d.getLocationX()+dx+j,d.getLocationY()+dy+i,d.getColor(),mat);
            }
        }
    }
}
