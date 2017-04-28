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
  实现图像的邻域变换的相关的操作
*/
class NeighborhoodProcessing
{
public:
	IplImage *NeighborhoodAverage(IplImage* img); //进行图像的邻域平均
	IplImage *GaussFilter(IplImage* img);//图像的Gauss滤波
	IplImage *MedianFilter(IplImage* img);//图像的中值滤波
	IplImage *SobelBoundaryDetection(IplImage *img);//sobel边缘检测
	IplImage *LaplaceBoundaryDetection(IplImage *img);//laplace边缘检测
};
#endif //NEIGHBORHOODPROCESSING_H