#ifndef IMAGEDEMO_H
#define IMAGEDEMO_H

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
#include <windows.h>
#include <QScrollBar>


#include "pointOperation.h"
#include "NeighborhoodProcessing.h"
#include "Binarization.h"
#include "MorphologicalProcessing.h"



using namespace  cv;
using namespace std;

class Imagedemo : public QMainWindow
{
	Q_OBJECT

public:
	Imagedemo(QWidget *parent = 0);
	~Imagedemo();

private:
	Ui::ImagedemoClass ui;
	IplImage*  img;   //记录载入的图像
	IplImage*  img1;   //存储变换后的灰度图像
	IplImage*  img2;    //存储变换后的二值化图像
	QString fileName;//记录载入图像的地址
	pointOperation  demo1;    //点操作的实例
	NeighborhoodProcessing demo2;
	Binarization   demo3;
	MorphologicalProcessing demo4;
private slots:
	 QImage ImageCV2Qimg(IplImage* img);//将opencv的lpllmage与Qt的Qimage进行转换
	 void OpenIamgeClick();           //打开图像
	 void restoreImageClick();        //恢复原图像
	 void exit();                //退出操作

//===============================主窗口对图像点操作的按键响应============================================================
	 void  colorGrayScale();   //图像转灰阶
	 void ImageInversion();   //图像反相
	 void  VerticalMirror();  //垂直镜像
	 void  HorizontalMirror();  //水平镜像
	 void  _180DegreeRotation();  //180度旋转
	 void  _30DegreeRotation();    //30度旋转
	 void  AffineTransformation();  //放射变换
	 void  PerspectiveTransformation();//透视变换
     void  BrightnessTransformation(); //亮度变换
	 void  GrayscaleImageHistogram();//灰阶图像直方图
	 void HistogramEqualization(); //直方图均衡化
//======================================================================================================================

	 
//============================================图像的邻域操作==========================================================
    void NeighborhoodAverage(); //进行图像的邻域平均
    void GaussFilter();//图像的Gauss滤波
	void MedianFilter();//图像的中值滤波
	void SobelBoundaryDetection();//sobel边缘检测
	void LaplaceBoundaryDetection();//laplace边缘检测
//====================================================================================================================


//=========================================图像的二值化的相关的操作==================================================
	void SelectTheThreshold();    //自定义阈值二值化
	void AdaptiveThreshold();   //自适应二值化
	void BasedOnGlobalThreshold();//大律法二值化
//==================================================================================================================





//======================================图像形态学处理的相关的算法======================================


	  void corrosion(); //腐蚀
	  void expand();  //膨胀
	  void OpenOperation();//开运算
	  void ClosedOperation();//闭运算
	  void MorphologicalGradient();//形态学梯度
	  void TopHatTransformation();//顶帽变换
	  void TroughDetection();//波谷检测

//=========================================================================================================
};

#endif // IMAGEDEMO_H
