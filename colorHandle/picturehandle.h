/**
 * @brief
 *  �������ڽ����ɵ������Բʱ���ΪJPG��ʽ�ļ�
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


};

#endif // PICTUREHANDLE_H
