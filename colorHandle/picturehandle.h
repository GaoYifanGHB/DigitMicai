/**
 * @brief
 *  该类用于将生成的数码迷彩保存为PNG格式文件
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
