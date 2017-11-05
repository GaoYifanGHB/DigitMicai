/**
 * @brief
 *  �������ڽ����ɵ������Բʱ���ΪPNG��ʽ�ļ�
 * @author GaoYifan
 */
#ifndef PICTUREHANDLE_H
#define PICTUREHANDLE_H
#include"digitmananger.h"
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class PictureHandle
{
public:
    PictureHandle();
private:
    int l,w,h;
    DigitMananger dm;
    Mat up;
    Mat down;
    Mat center;
    Mat left;
    Mat right;


};

#endif // PICTUREHANDLE_H
