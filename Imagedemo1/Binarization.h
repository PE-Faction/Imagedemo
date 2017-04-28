#ifndef BINARIZATION_H
#define BINARIZATION_H

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include<cv.h>
#include<highgui.h>
#include<opencv2\core\core.hpp>
#include <Qsize>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cmath>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


/*
  实现二值化的相关的操作
*/
class Binarization
{
public:
	IplImage *SelectTheThreshold(IplImage *img);    //自定义阈值二值化
	IplImage *AdaptiveThreshold(IplImage *img);   //自适应二值化
	IplImage *BasedOnGlobalThreshold(IplImage *img);//大律法二值化
   
};
#endif // BINARIZATION_H