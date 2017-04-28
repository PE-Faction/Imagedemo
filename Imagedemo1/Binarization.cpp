#include "Binarization.h"
#include "binarizationwindow1.h"

IplImage* Binarization::SelectTheThreshold(IplImage *img1)    //�Զ�����ֵ��ֵ��
{   
	//BinarizationWIndow1 *window =new BinarizationWIndow1;
	//window->getImage(img1);//������ʱ�޷�ʹ�ã��������˰ɣ�����
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
IplImage* Binarization::AdaptiveThreshold(IplImage *img)   //����Ӧ��ֵ��
{
	IplImage * img1 =cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	//�ֲ�����Ӧ��ͼ��ı任�ķ�������ʹ�õ���ֵ���ҵķ�����Ҫ������ƽ�����͸�˹��Ȩƽ��
	//��ϸ�ĸú�����˵�����ڲ�������
	cvAdaptiveThreshold(img,img1,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,3,5);

	return img1;
}
IplImage* Binarization::BasedOnGlobalThreshold(IplImage *img)//���ɷ�
{
    int GrayScal=256;
	int width=img->width;
	int height=img->height;
	int pixelCount[256]={0};
	float pixelPro[256]={0};
	int i,j,pixelSum=width*height,threshold=0;
	uchar* data=(uchar*)img->imageData;

	///ͳ��ÿ���Ҷȼ������صĸ���
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{

			pixelCount[(int)data[i*width+j]]++;
		}
   }
	//����ÿ���Ҷȼ���������Ŀռ����ͼ��ı���
	for(i=0;i<GrayScal;i++)
	{
		pixelPro[i]=(float)pixelCount[i]/pixelSum;
	}
	
   //���������Ҷȼ���0,255�� Ѱ�Һ��ʵ�threshold
	float w0,w1,u0tmp,u1tmp,u0,u1,deltaTmp,deltaMax=0;
	for(i=0;i<GrayScal;i++)
	{
		w0=w1=u0tmp=u1tmp=u0=u1=deltaTmp=0;
		for(j=0;j<GrayScal;j++)
		{
			if(j<i)//��������
			{
				w0+=pixelPro[j];
				u0tmp+=j*pixelPro[j];
			}
			else  //ǰ������
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