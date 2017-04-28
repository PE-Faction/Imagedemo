#ifndef NEIGHBORHOODPROCESSING_H
#define NEIGHBORHOODPROCESSING_H

#include <QtWidgets/QMainWindow>
#include "ui_imagedemo.h"
#include <QMessageBox>
#include<cv.h>
#include<highgui.h>
#include<opencv2\core\core.hpp>
#include <Qsize>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cmath>
/*
  ʵ��ͼ�������任����صĲ���
*/
class NeighborhoodProcessing
{
public:
	IplImage *NeighborhoodAverage(IplImage* img); //����ͼ�������ƽ��
	IplImage *GaussFilter(IplImage* img);//ͼ���Gauss�˲�
	IplImage *MedianFilter(IplImage* img);//ͼ�����ֵ�˲�
	IplImage *SobelBoundaryDetection(IplImage *img);//sobel��Ե���
	IplImage *LaplaceBoundaryDetection(IplImage *img);//laplace��Ե���
};
#endif //NEIGHBORHOODPROCESSING_H