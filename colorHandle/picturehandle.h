/**
 * @brief
 *  �������ڽ����ɵ������Բʱ���ΪPNG��ʽ�ļ�
 * @author GaoYifan
 */
#ifndef PICTUREHANDLE_H
#define PICTUREHANDLE_H
#include"digitmananger.h"
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class PictureHandle
{
public:
    PictureHandle();
    void setSize(int l,int w,int h);
    void setBgColor(QColor bgcolor);
    void setDigitManager(DigitManager dm);

private:
    int l,w,h;
    DigitMananger dm;
    QColor bgcolor;
    void drawOneGrid(int x,int y,QColor color,Mat &mat);
    void drawBgColor(Mat &mat);
    void drawOneDigit(Digit d,int dx,int dy,Mat &mat);




};

#endif // PICTUREHANDLE_H