#include "binarizationwindow1.h"
/*
�ú�����ҪΪ�����Զ����ֵ���Ĵ��ڣ�����spinbox�ı任����ʱ����ʾͼƬ�Ķ�ֵ���仯��
���ǲۺ���onSpinValueChange()һֱ�����޷�ִ�У����Խ�����������temp ��ֵ����ȥ
*/
BinarizationWIndow1::BinarizationWIndow1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle("my first window");
	QSpinBox *spinBox=new QSpinBox;
	QSlider *slider=new QSlider(Qt::Horizontal);
	slider->setRange(0,255);
	spinBox->setRange(0,255);
	QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
	QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
	QObject::connect(spinBox, SIGNAL(valueChanged),this, SLOT(onSpinValueChanged(int)));
	QObject::connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(onSpinValueChanged(int)));
	spinBox->setValue(120);
	QHBoxLayout *layout =new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	this->setLayout(layout);
	this->show();

}

BinarizationWIndow1::~BinarizationWIndow1()
{

}
void BinarizationWIndow1::getImage(IplImage *img1)
{
     img =cvCreateImage(cvGetSize(img1),img1->depth,img1->nChannels);
     img=cvCloneImage(img1);
	
    //cvWaitKey(0);//�ȴ����� 
}
IplImage* BinarizationWIndow1::sendImage(IplImage *img)
{

	return img;
}
void BinarizationWIndow1::onSpinValueChanged(int a)
{
	/* IplImage *img1 =cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	 img1=cvCloneImage(img);
	 for(int i=0;i<img->height;i++)
	 {
		 for(int j=0;j<img->width;j++)
		 {
			if(CV_IMAGE_ELEM(img,uchar,i,j)>a)
				 CV_IMAGE_ELEM(img,uchar,i,j)=255;
			 else
				 CV_IMAGE_ELEM(img,uchar,i,j)=0;
		}
	
	 }*/
	/* cvNamedWindow("Test",CV_WINDOW_AUTOSIZE);//�������ڣ��ڶ�������CV_WINDOW_AUTOSIZE������ͼ��ԭ����С  
      cvShowImage("Test",img);//��ʾͼƬ    
      cvWaitKey(10);*/
	 temp=a;
	QString s = QString::number(a, 10); 
	 QMessageBox::about(NULL, "About", s);
	 
	
}