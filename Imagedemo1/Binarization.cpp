#include "Binarization.h"
#include "binarizationwindow1.h"

IplImage* Binarization::SelectTheThreshold(IplImage *img1)    //自定义阈值二值化
{   
	//BinarizationWIndow1 *window =new BinarizationWIndow1;
	//window->getImage(img1);//该类暂时无法使用，等着问人吧！！！
	IplImage *img =cvCreateImage(cvGetSize(img1),img1->depth,img1->nChannels);
	 img=cvCloneImage(img1);
	 for(int i=0;i<img->height;i++)
	 {
		 for(int j=0;j<img->width;j++)
		 {
			if(CV_IMAGE_ELEM(img,uchar,i,j)>120)
				 CV_IMAGE_ELEM(img,uchar,i,j)=255;
			 else
				 CV_IMAGE_ELEM(img,uchar,i,j)=0;
		 }
	 }
    return img;
}
IplImage* Binarization::AdaptiveThreshold(IplImage *img)   //自适应二值化
{
	IplImage * img1 =cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	//局部自适应的图像的变换的方法，，使用的阈值查找的方法主要是利用平均法和高斯加权平均
	//详细的该函数的说明，在博客里有
	cvAdaptiveThreshold(img,img1,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,3,5);

	return img1;
}
IplImage* Binarization::BasedOnGlobalThreshold(IplImage *img)//大律法
{
    int GrayScal=256;
	int width=img->width;
	int height=img->height;
	int pixelCount[256]={0};
	float pixelPro[256]={0};
	int i,j,pixelSum=width*height,threshold=0;
	uchar* data=(uchar*)img->imageData;

	///统计每个灰度级中像素的个数
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{

			pixelCount[(int)data[i*width+j]]++;
		}
   }
	//计算每个灰度级的像素数目占整个图像的比例
	for(i=0;i<GrayScal;i++)
	{
		pixelPro[i]=(float)pixelCount[i]/pixelSum;
	}
	
   //遍历整个灰度级【0,255】 寻找合适的threshold
	float w0,w1,u0tmp,u1tmp,u0,u1,deltaTmp,deltaMax=0;
	for(i=0;i<GrayScal;i++)
	{
		w0=w1=u0tmp=u1tmp=u0=u1=deltaTmp=0;
		for(j=0;j<GrayScal;j++)
		{
			if(j<i)//背景部分
			{
				w0+=pixelPro[j];
				u0tmp+=j*pixelPro[j];
			}
			else  //前景部分
			{
				w1+=pixelPro[j];
				u1tmp+=j*pixelPro[j];

			}

		}
		u0=u0tmp/w0;
		u1=u1tmp/w1;
		deltaTmp=(float)(w1*w0*pow((u0-w1),2));

		if(deltaTmp>deltaMax)
		{
			deltaMax=deltaTmp;
			threshold=i;
		}


	}



	IplImage *img1 =cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	 img1=cvCloneImage(img);
	 for(int i=0;i<img->height;i++)
	 {
		 for(int j=0;j<img->width;j++)
		 {
			if(CV_IMAGE_ELEM(img1,uchar,i,j)>threshold)
				 CV_IMAGE_ELEM(img1,uchar,i,j)=255;
			 else
				 CV_IMAGE_ELEM(img1,uchar,i,j)=0;
		 }
	 }
	return img1;
}