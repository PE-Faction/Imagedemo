#include "imagedemo.h"
/*  用于完成主窗口的相关操作      
*/


Imagedemo::Imagedemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*int width = this->geometry().width();
    int height = this->geometry().height();
    this->setFixedSize(width,height); //设置窗体固定大小*/
	this->showMaximized();  //窗口最大化

	//=========================信号与槽的响应==================================================
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
//===================================主窗口的基本窗口操作============================================================
QImage Imagedemo::ImageCV2Qimg(IplImage* img)//将opencv的lpllmage与Qt的Qimage进行转换
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
     fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), //获取文件名
                                ".",tr("Image Files (*.png *.jpg *.bmp)"));

	char * cstr;                    //Qstring转char*
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


 //================================图像的点操作的按键响应==============================================================
 	 void  Imagedemo::colorGrayScale()   //图像转灰阶
	 {
		 img1=cvCreateImage(cvSize(demo1.colorGrayScale(img)->width,demo1.colorGrayScale(img)->height),demo1.colorGrayScale(img)->depth,demo1.colorGrayScale(img)->nChannels);
		 cvCopy(demo1.colorGrayScale(img),img1);
		 QImage qimg = ImageCV2Qimg(img1);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	 }
	 void Imagedemo::ImageInversion()   //图像反相
	 {
		 QImage qimg = ImageCV2Qimg(demo1.ImageInversion(img));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	 }
	 void  Imagedemo::VerticalMirror()  //垂直镜像
	 {
		 QImage qimg = ImageCV2Qimg(demo1.VerticalMirror(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::HorizontalMirror()  //水平镜像
	 {
		 QImage qimg = ImageCV2Qimg(demo1.HorizontalMirror(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::_180DegreeRotation()  //180度旋转
	 {

		 QImage qimg = ImageCV2Qimg(demo1._180DegreeRotation(demo1._180DegreeRotation(img1)));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void Imagedemo:: _30DegreeRotation()    //30度旋转
	 {
		 QImage qimg = ImageCV2Qimg(demo1._30DegreeRotation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::AffineTransformation()  //放射变换
	 {
		 QImage qimg = ImageCV2Qimg(demo1.AffineTransformation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::PerspectiveTransformation()//透视变换
	 {
		  QImage qimg = ImageCV2Qimg(demo1.PerspectiveTransformation(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	 }
     void  Imagedemo::BrightnessTransformation() //亮度变换
	 {
		  QImage qimg = ImageCV2Qimg(demo1.BrightnessTransformation(img));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void  Imagedemo::GrayscaleImageHistogram()//灰阶图像直方图
	 {
		  QImage qimg = ImageCV2Qimg(demo1.GrayscaleImageHistogram(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	 }
	 void Imagedemo::HistogramEqualization() //直方图均衡化
	 {
		  QImage qimg = ImageCV2Qimg(demo1.HistogramEqualization(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	 }

//=====================================================================================================================

//==========================图像的邻域操作============================================================================

    void Imagedemo::NeighborhoodAverage() //进行图像的邻域平均
	{
		QImage qimg = ImageCV2Qimg(demo2.NeighborhoodAverage(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}
    void Imagedemo::GaussFilter()//图像的Gauss滤波
	{
		QImage qimg = ImageCV2Qimg(demo2.GaussFilter(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();



	}
	void Imagedemo::MedianFilter()//图像的中值滤波
	{
		QImage qimg = ImageCV2Qimg(demo2.MedianFilter(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}
	void Imagedemo::SobelBoundaryDetection()//sobel边缘检测
	{
		QImage qimg = ImageCV2Qimg(demo2.SobelBoundaryDetection(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	}
	void Imagedemo::LaplaceBoundaryDetection()//laplace边缘检测
	{
		QImage qimg = ImageCV2Qimg(demo2.LaplaceBoundaryDetection(img1));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();


	}

//===================================================================================================================



//=================================图像二值化的相关的操作============================================================


	void Imagedemo::SelectTheThreshold()    //自定义阈值二值化
	{
		 img2=cvCreateImage(cvSize(demo3.SelectTheThreshold(img1)->width,demo3.SelectTheThreshold(img1)->height),demo3.SelectTheThreshold(img1)->depth,demo3.SelectTheThreshold(img1)->nChannels);
		 cvCopy(demo3.SelectTheThreshold(img1),img2);
		 QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
		

	}
	void Imagedemo::AdaptiveThreshold()  //自适应二值化
	{
		img2=cvCreateImage(cvSize(demo3.AdaptiveThreshold(img1)->width,demo3.AdaptiveThreshold(img1)->height),demo3.AdaptiveThreshold(img1)->depth,demo3.AdaptiveThreshold(img1)->nChannels);
		cvCopy(demo3.AdaptiveThreshold(img1),img2);
		QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	
	}
	void Imagedemo::BasedOnGlobalThreshold()//大律法二值化
	{
		img2=cvCreateImage(cvSize(demo3.BasedOnGlobalThreshold(img1)->width,demo3.BasedOnGlobalThreshold(img1)->height),demo3.BasedOnGlobalThreshold(img1)->depth,demo3.BasedOnGlobalThreshold(img1)->nChannels);
		cvCopy(demo3.BasedOnGlobalThreshold(img1),img2);
		QImage qimg = ImageCV2Qimg(img2);
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
		
	}



//================================================================================================================


//=================================图像形态学的相关的算法===============================================
	  void Imagedemo::corrosion() //腐蚀
	  {
		  QImage qimg = ImageCV2Qimg(demo4.corrosion(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::expand()  //膨胀
	  {
		  QImage qimg = ImageCV2Qimg(demo4.expand(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::OpenOperation()//开运算
	  {
		  QImage qimg = ImageCV2Qimg(demo4.OpenOperation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::ClosedOperation()//闭运算
	  {
		  QImage qimg = ImageCV2Qimg(demo4.ClosedOperation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::MorphologicalGradient()//形态学梯度
	  {
		  QImage qimg = ImageCV2Qimg(demo4.MorphologicalGradient(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();
	  }
	  void Imagedemo::TopHatTransformation()//顶帽变换
	  {
		  QImage qimg = ImageCV2Qimg(demo4.TopHatTransformation(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }
	  void Imagedemo::TroughDetection()//波谷检测
	  {
		  QImage qimg = ImageCV2Qimg(demo4.TroughDetection(img2));
         ui.label->setPixmap(QPixmap::fromImage(qimg));    
         ui.label->resize(ui.label->pixmap()->size());  
         ui.label->show();

	  }

//====================================================================================================