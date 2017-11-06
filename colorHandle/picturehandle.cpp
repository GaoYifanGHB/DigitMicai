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

void PictureHandle::setDigitManager(DigitMananger dm)
{
    this->dm=dm;
}

void PictureHandle::drawToPicture()
{
    //    -(w/2),-l/2,(w/2)-1,l/2-1
    Mat center(l*10,w*10,CV_8UC4);
    Mat up(h*10,w*10,CV_8UC4);
    drawBgColor(center);
    drawBgColor(up);
    for(int i=0;i<dm.digitList.size();i++){
        Digit d=dm.digitList[i];
        if(d.getLocationX()>=-(w/2)&&d.getLocationX()<=(w/2)-1&&d.getLocationY()>=-l/2&&d.getLocationY()<=l/2-1){
            drawOneDigit(d,-(w/2),-(l/2),center);
        }else if(d.getLocationX()>=-(w/2)&&d.getLocationX()<=(w/2)-1&&d.getLocationY()>=-l/2-h&&d.getLocationY()<=-l/2-1){
            drawOneDigit(d,-(w/2),-(l/2)-h,up);
        }
    }
    writeToFile(center,"center");
    writeToFile(up,"up");
}

void PictureHandle::drawOneGrid(int x, int y, QColor color, Mat &mat)
{
    int r,b,g;
    color.getRgb(&r,&g,&b);
    x*=10;y*=10;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            Vec4b&rgb=mat.at<Vec4b>(i+y,j+x);
            rgb[2]=r;
            rgb[1]=g;
            rgb[0]=b;
            rgb[3]=255;
        }
    }
}

void PictureHandle::drawBgColor(Mat &mat)
{
    int r,b,g;
    bgcolor.getRgb(&r,&g,&b);
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            Vec4b&rgb=mat.at<Vec4b>(i,j);
            rgb[2]=r;
            rgb[1]=g;
            rgb[0]=b;
            rgb[3]=255;
        }
    }
}

void PictureHandle::drawOneDigit(Digit d, int dx, int dy, Mat &mat)
{
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                drawOneGrid(d.getLocationX()-dx+j,d.getLocationY()-dy+i,d.getColor(),mat);
            }
        }
    }
}
void PictureHandle::writeToFile(Mat mat, string filename)
{
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
//    string file=".//side//"+filename+".png";
    string file=filename+".png";
    imwrite(file,mat,compression_params);
}
