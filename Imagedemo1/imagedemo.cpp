#include "imagedemo.h"
/*  ������������ڵ���ز���      
*/


Imagedemo::Imagedemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*int width = this->geometry().width();
    int height = this->geometry().height();
    this->setFixedSize(width,height); //���ô���̶���С*/
	this->showMaximized();  //�������

	//=========================�ź���۵���Ӧ==================================================
    QObject::connect(ui.actionOpen_Image, SIGNAL(triggered()),this, SLOT(OpenIamgeClick()));
	QObject::connect(ui.actionRestore_Image, SIGNAL(triggered()),this, SLOT(restoreImageClick()));
	QObject::connect(ui.action_Exit, SIGNAL(triggered()),this, SLOT(exit()));
	QObject::connect(ui.actionColor_gray_scale, SIGNAL(triggered()),this, SLOT(colorGrayScale()));
	QObject::connect(ui.actionImage_inversion, SIGNAL(triggered()),this, SLOT(ImageInversion()));
	QObject::connect(ui.actionVertical_mirror, SIGNAL(triggered()),this, SLOT(VerticalMirror()));
	QObject::connect(ui.actionHorizontal_mirror, SIGNAL(triggered()),this, SLOT(HorizontalMirror()));
	QObject::connect(ui.action_180_degree_rotation, SIGNAL(triggered()),this, SLOT(_180DegreeRotation()));
	QObject::connect(ui.action30_degree_rotation, SIGNAL(triggered()),this, SLOT(_30DegreeRotation()));
	QObject::connect(ui.actionAffine_transformation, SIGNAL(triggered()),this, SLOT(AffineTransformation()));
	QObject::connect(ui.actionPerspective_transformation, SIGNAL(triggered()),this, SLOT(PerspectiveTransformation()));
	QObject::connect(ui.actionBrightness_transformation, SIGNAL(triggered()),this, SLOT(BrightnessTransformation()));
	QObject::connect(ui.actionGrayscale_image_histogram, SIGNAL(triggered()),this, SLOT(GrayscaleImageHistogram()));
	QObject::connect(ui.actionHistogram_equalization, SIGNAL(triggered()),this, SLOT(HistogramEqualization()));
	QObject::connect(ui.actionNeighborhood_average, SIGNAL(triggered()),this, SLOT(NeighborhoodAverage()));
	QObject::connect(ui.actionGauss_Filter, SIGNAL(triggered()),this, SLOT(GaussFilter()));
	QObject::connect(ui.actionMedian_filter, SIGNAL(triggered()),this, SLOT(MedianFilter()));
	QObject::connect(ui.actionSobel_Boundary_detection, SIGNAL(triggered()),this, SLOT(SobelBoundaryDetection()));
	QObject::connect(ui.actionLaplace_Boundary_detection, SIGNAL(triggered()),this, SLOT(LaplaceBoundaryDetection()));
	QObject::connect(ui.actionSelect_the_threshold, SIGNAL(triggered()),this, SLOT(SelectTheThreshold()));
	QObject::connect(ui.actionAdaptive_threshold, SIGNAL(triggered()),this, SLOT(AdaptiveThreshold()));
	QObject::connect(ui.actionCorrosion, SIGNAL(triggered()),this, SLOT(corrosion()));
	QObject::connect(ui.actionExpand, SIGNAL(triggered()),this, SLOT(expand()));
	QObject::connect(ui.actionBased_on_global_threshold, SIGNAL(triggered()),this, SLOT(BasedOnGlobalThreshold()));
	QObject::connect(ui.actionOpen_operation, SIGNAL(triggered()),this, SLOT(OpenOperation()));
	QObject::connect(ui.actionClosed_operation, SIGNAL(triggered()),this, SLOT(ClosedOperation()));
	QObject::connect(ui.actionMorphological_gradient, SIGNAL(triggered()),this, SLOT(MorphologicalGradient()));




}

Imagedemo::~Imagedemo()
{

}
//===================================�����ڵĻ������ڲ���============================================================
QImage Imagedemo::ImageCV2Qimg(IplImage* img)//��opencv��lpllmage��Qt��Qimage����ת��
{
 assert(img!=NULL);
 int h = img->height;
 int w = img->width;
 int channel = img->nChannels;
 QImage qimg = QImage(w, h, QImage::Format_RGB32);
 for(int i=0;i<h;i++)  
    {  
        for(int j=0;j<w;j++)  
        {  
            int r,g,b;  
            if(channel == 3)  
            {  
                b=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+0);  
                g=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+1);  
                r=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+2);  
            }  
            else if(channel == 1)  
            {  
                b=(int)CV_IMAGE_ELEM(img,uchar,i,j);  
                g=b;  
                r=b;  
            }  
            qimg.setPixel(j,i,qRgb(r,g,b));  
        }  
    }  
 return qimg;
}
void Imagedemo::OpenIamgeClick()
{
     fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), //��ȡ�ļ���
                                ".",tr("Image Files (*.png *.jpg *.bmp)"));

	char * cstr;                    //Qstringתchar*
   // qDebug()<<"filenames:"<<fileName;  
	QByteArray ba = fileName.toLatin1();    
    cstr=ba.data();
    //QMessageBox ::information(NULL, NULL, cstr);  

	img = cvLoadImage(cstr);
    QImage qimg = ImageCV2Qimg(img);
    ui.label->setPixmap(QPixmap::fromImage(qimg));    
    ui.label->resize(ui.label->pixmap()->size());  
    ui.label->show();
	
}

 void Imagedemo::restoreImageClick()
 {
 
	char * cstr;                    
	QByteArray ba = fileName.toLatin1();    
    cstr=ba.data();
	img = cvLoadImage(cstr);
    QImage qimg = ImageCV2Qimg(img);
    ui.label->setPixmap(QPixmap::fromImage(qimg));    
    ui.label->resize(ui.label->pixmap()->size());  
    ui.label->show();

}
 

 void Imagedemo::exit()
 {
	  QApplication* app;
      app->quit();

 }
 //===================================================================================================================


 //================================ͼ��ĵ�����İ�����Ӧ==============================================================
 	 void  Imagedemo::colorGrayScale()   //ͼ��ת�ҽ�
	 {
		 img1=cvCreateImage(cvSize(demo1.colorGrayScale(img)->width,demo1.colorGrayScale(img)->height),demo1.colorGrayScale(img)->depth,demo1.colorGrayScale(img)->nChannels);
		 cvCopy(demo1.colorGrayScale(img),img1);
		 QImage qimg = ImageCV2Qimg(img1);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	 }
	 void Imagedemo::ImageInversion()   //ͼ����
	 {
		 QImage qimg = ImageCV2Qimg(demo1.ImageInversion(img));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	 }
	 void  Imagedemo::VerticalMirror()  //��ֱ����
	 {
		 QImage qimg = ImageCV2Qimg(demo1.VerticalMirror(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::HorizontalMirror()  //ˮƽ����
	 {
		 QImage qimg = ImageCV2Qimg(demo1.HorizontalMirror(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::_180DegreeRotation()  //180����ת
	 {

		 QImage qimg = ImageCV2Qimg(demo1._180DegreeRotation(demo1._180DegreeRotation(img1)));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void Imagedemo:: _30DegreeRotation()    //30����ת
	 {
		 QImage qimg = ImageCV2Qimg(demo1._30DegreeRotation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::AffineTransformation()  //����任
	 {
		 QImage qimg = ImageCV2Qimg(demo1.AffineTransformation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::PerspectiveTransformation()//͸�ӱ任
	 {
		  QImage qimg = ImageCV2Qimg(demo1.PerspectiveTransformation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	 }
     void  Imagedemo::BrightnessTransformation() //���ȱ任
	 {
		  QImage qimg = ImageCV2Qimg(demo1.BrightnessTransformation(img));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::GrayscaleImageHistogram()//�ҽ�ͼ��ֱ��ͼ
	 {
		  QImage qimg = ImageCV2Qimg(demo1.GrayscaleImageHistogram(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void Imagedemo::HistogramEqualization() //ֱ��ͼ���⻯
	 {
		  QImage qimg = ImageCV2Qimg(demo1.HistogramEqualization(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	 }

//=====================================================================================================================

//==========================ͼ����������============================================================================

    void Imagedemo::NeighborhoodAverage() //����ͼ�������ƽ��
	{
		QImage qimg = ImageCV2Qimg(demo2.NeighborhoodAverage(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}
    void Imagedemo::GaussFilter()//ͼ���Gauss�˲�
	{
		QImage qimg = ImageCV2Qimg(demo2.GaussFilter(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();



	}
	void Imagedemo::MedianFilter()//ͼ�����ֵ�˲�
	{
		QImage qimg = ImageCV2Qimg(demo2.MedianFilter(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}
	void Imagedemo::SobelBoundaryDetection()//sobel��Ե���
	{
		QImage qimg = ImageCV2Qimg(demo2.SobelBoundaryDetection(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	}
	void Imagedemo::LaplaceBoundaryDetection()//laplace��Ե���
	{
		QImage qimg = ImageCV2Qimg(demo2.LaplaceBoundaryDetection(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}

//===================================================================================================================



//=================================ͼ���ֵ������صĲ���============================================================


	void Imagedemo::SelectTheThreshold()    //�Զ�����ֵ��ֵ��
	{
		 img2=cvCreateImage(cvSize(demo3.SelectTheThreshold(img1)->width,demo3.SelectTheThreshold(img1)->height),demo3.SelectTheThreshold(img1)->depth,demo3.SelectTheThreshold(img1)->nChannels);
		 cvCopy(demo3.SelectTheThreshold(img1),img2);
		 QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
		

	}
	void Imagedemo::AdaptiveThreshold()  //����Ӧ��ֵ��
	{
		img2=cvCreateImage(cvSize(demo3.AdaptiveThreshold(img1)->width,demo3.AdaptiveThreshold(img1)->height),demo3.AdaptiveThreshold(img1)->depth,demo3.AdaptiveThreshold(img1)->nChannels);
		cvCopy(demo3.AdaptiveThreshold(img1),img2);
		QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	
	}
	void Imagedemo::BasedOnGlobalThreshold()//���ɷ���ֵ��
	{
		img2=cvCreateImage(cvSize(demo3.BasedOnGlobalThreshold(img1)->width,demo3.BasedOnGlobalThreshold(img1)->height),demo3.BasedOnGlobalThreshold(img1)->depth,demo3.BasedOnGlobalThreshold(img1)->nChannels);
		cvCopy(demo3.BasedOnGlobalThreshold(img1),img2);
		QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
		
	}



//================================================================================================================


//=================================ͼ����̬ѧ����ص��㷨===============================================
	  void Imagedemo::corrosion() //��ʴ
	  {
		  QImage qimg = ImageCV2Qimg(demo4.corrosion(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::expand()  //����
	  {
		  QImage qimg = ImageCV2Qimg(demo4.expand(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::OpenOperation()//������
	  {
		  QImage qimg = ImageCV2Qimg(demo4.OpenOperation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::ClosedOperation()//������
	  {
		  QImage qimg = ImageCV2Qimg(demo4.ClosedOperation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::MorphologicalGradient()//��̬ѧ�ݶ�
	  {
		  QImage qimg = ImageCV2Qimg(demo4.MorphologicalGradient(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::TopHatTransformation()//��ñ�任
	  {
		  QImage qimg = ImageCV2Qimg(demo4.TopHatTransformation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::TroughDetection()//���ȼ��
	  {
		  QImage qimg = ImageCV2Qimg(demo4.TroughDetection(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }

//====================================================================================================