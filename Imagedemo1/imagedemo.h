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
	IplImage*  img;   //��¼�����ͼ��
	IplImage*  img1;   //�洢�任��ĻҶ�ͼ��
	IplImage*  img2;    //�洢�任��Ķ�ֵ��ͼ��
	QString fileName;//��¼����ͼ��ĵ�ַ
	pointOperation  demo1;    //�������ʵ��
	NeighborhoodProcessing demo2;
	Binarization   demo3;
	MorphologicalProcessing demo4;
private slots:
	 QImage ImageCV2Qimg(IplImage* img);//��opencv��lpllmage��Qt��Qimage����ת��
	 void OpenIamgeClick();           //��ͼ��
	 void restoreImageClick();        //�ָ�ԭͼ��
	 void exit();                //�˳�����

//===============================�����ڶ�ͼ�������İ�����Ӧ============================================================
	 void  colorGrayScale();   //ͼ��ת�ҽ�
	 void ImageInversion();   //ͼ����
	 void  VerticalMirror();  //��ֱ����
	 void  HorizontalMirror();  //ˮƽ����
	 void  _180DegreeRotation();  //180����ת
	 void  _30DegreeRotation();    //30����ת
	 void  AffineTransformation();  //����任
	 void  PerspectiveTransformation();//͸�ӱ任
     void  BrightnessTransformation(); //���ȱ任
	 void  GrayscaleImageHistogram();//�ҽ�ͼ��ֱ��ͼ
	 void HistogramEqualization(); //ֱ��ͼ���⻯
//======================================================================================================================

	 
//============================================ͼ����������==========================================================
    void NeighborhoodAverage(); //����ͼ�������ƽ��
    void GaussFilter();//ͼ���Gauss�˲�
	void MedianFilter();//ͼ�����ֵ�˲�
	void SobelBoundaryDetection();//sobel��Ե���
	void LaplaceBoundaryDetection();//laplace��Ե���
//====================================================================================================================


//=========================================ͼ��Ķ�ֵ������صĲ���==================================================
	void SelectTheThreshold();    //�Զ�����ֵ��ֵ��
	void AdaptiveThreshold();   //����Ӧ��ֵ��
	void BasedOnGlobalThreshold();//���ɷ���ֵ��
//==================================================================================================================





//======================================ͼ����̬ѧ�������ص��㷨======================================


	  void corrosion(); //��ʴ
	  void expand();  //����
	  void OpenOperation();//������
	  void ClosedOperation();//������
	  void MorphologicalGradient();//��̬ѧ�ݶ�
	  void TopHatTransformation();//��ñ�任
	  void TroughDetection();//���ȼ��

//=========================================================================================================
};

#endif // IMAGEDEMO_H
