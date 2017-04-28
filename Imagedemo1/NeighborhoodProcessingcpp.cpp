#include "NeighborhoodProcessing.h"
/**  
           ͼ�������Ӽ����һ���C++ʵ��
void gaussianFilter2 (unsigned char* corrupted, unsigned char* smooth, int width, int height)  
{  
    int templates[25] = { 1, 4, 7, 4, 1,   
                          4, 16, 26, 16, 4,   
                          7, 26, 41, 26, 7,  
                          4, 16, 26, 16, 4,   
                          1, 4, 7, 4, 1 };        
      
    memcpy ( smooth, corrupted, width*height*sizeof(unsigned char) );  
    for (int j=2;j<height-2;j++)  
    {  
        for (int i=2;i<width-2;i++)  
        {  
            int sum = 0;  
            int index = 0;  
            for ( int m=j-2; m<j+3; m++)  
            {  
                for (int n=i-2; n<i+3; n++)  
                {  
                    sum += corrupted [ m*width + n] * templates[index++] ;  
                }  
            }  
            sum /= 273;  
            if (sum > 255)  
                sum = 255;  
            smooth [ j*width+i ] = sum;  
        }  
    }  
}  
*/

IplImage* NeighborhoodProcessing::NeighborhoodAverage(IplImage* in) //����ͼ�������ƽ��
{

	IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels);   
	cvSmooth(in,out,CV_BLUR,3,in->nChannels);  //  ��ƽ��   
  
	return out;
}


IplImage* NeighborhoodProcessing::GaussFilter(IplImage* in)//ͼ���Gauss�˲�
{
    IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels); // ��������λͼ
	cvSmooth(in,out,CV_GAUSSIAN,3,in->nChannels); // Gauss ƽ��
	return out;//���ڸ�˹�����ļ��㣬�����ڱȽϴ������
}


IplImage* NeighborhoodProcessing::MedianFilter(IplImage* in)//ͼ�����ֵ�˲�
{
	 IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels);   
	 cvSmooth(in,out,CV_MEDIAN,3,in->nChannels);  //  ��ֵ�˲�  
	return out;
}


IplImage* NeighborhoodProcessing::SobelBoundaryDetection(IplImage *img)//sobel��Ե���
{
	IplImage* H = cvCreateImage(cvGetSize(img), img->depth,1);
	IplImage* V = cvCreateImage(cvGetSize(img),img->depth,1);
	IplImage* HV = cvCreateImage(cvGetSize(img),img->depth,1);
	IplImage* HV1 = cvCreateImage(cvGetSize(img),img->depth,1);
 
         cvSobel(img,H,0,1,3); 
         cvSobel(img,V,1,0,3);
/*
  void cvLaplaceconst�� CvArr* src,CvArr* dst,int xorder,int yorder,int aperture_size = 3);src ����ͼ��.dst ���ͼ��.xorder��yorder���󵼵Ľ�����aperture_size �˴�С.������
Sobel������һ���ܺõ����ʣ����Զ��������С�ĺˣ�������Щ�˿����ÿ����ҵ����ķ�ʽ���졣��˶Ե����и��õıƽ���С�˶����������С�
             src ����ͼ��.
             dst ���ͼ��.
             xorder x �����ϵĲ�ֽ���
             yorder y �����ϵĲ�ֽ���
             aperture_size  ��չ Sobel �˵Ĵ�С�������� 1, 3, 5 �� 7�� ���˳ߴ�Ϊ 1�� ��������£� aperture_size ��aperture_size �ɷ����ں˽����������֡��� aperture_size=1������� ʹ�� 3x1 �� 1x3 �ں� �������и�˹ƽ����������������һ��������� CV_SCHARR (=-1)����Ӧ 3x3 Scharr �˲��������Ը����� 3x3 Sobel �˲�����ȷ�Ľ����Scharr �˲���ϵ���ǣ�
                            �� x-���� �Լ�ת�þ���� y-����
���� cvSobel ͨ����ͼ������Ӧ���ں˽��о������������ͼ���֣�
  ����Sobel ���ӽ���� Gaussian ƽ����΢�֣����ԣ����������ٶ�������һ����³���ԡ�ͨ��������������ò������²��� (xorder=1, yorder=0, aperture_size=3) �� (xorder=0, yorder=1, aperture_size=3) ������һ�� x- �� y- �����ͼ���֡���һ�������Ӧ��
�ˡ�
�ڶ��ֶ�Ӧ��
����
�˵�ѡ��������ͼ��ԭ��Ķ��� (origin ���� IplImage �ṹ�Ķ���)�����ڸú���������ͼ��߶ȱ任�����Ժ�����ͼ��(����)��ȣ����ͼ��(����)��Ԫ��ͨ�����и���ľ�����ֵ������ע�������ص���ȣ���Ϊ��ֹ�����������ͼ���� 8 λ�ģ�Ҫ�����ͼ���� 16 λ�ġ���Ȼ�����ú��� cvConvertScale �� cvConvertScaleAbs ת��Ϊ 8 λ�ġ����� 8-���� ͼ�񣬺���Ҳ���� 32-λ ������ͼ��������������ͼ�񶼱����ǵ�ͨ���ģ����Ҿ�����ͬ��ͼ��ߴ����ROI�ߴ硣
*/
 
         
         int i,j;
         double v1,v2,v;
         for (i=0;i<img->height;i++)
         {
                  for (j=0;j<img->width;j++)
                   {
                            v1 = cvGetReal2D(H,i,j);
                            v2 = cvGetReal2D(V,i,j);
                            v = sqrt(v1*v1+v2*v2);
 
                            cvSetReal2D(HV,i,j,v);
                   }
         }
         cvNormalize(HV,HV1,0,255,CV_MINMAX,0);
 
         cvReleaseImage(&H);
         cvReleaseImage(&V);
         cvReleaseImage(&HV);

		 return HV1;
}


IplImage* NeighborhoodProcessing::LaplaceBoundaryDetection(IplImage *img)//laplace��Ե���
{
	IplImage* HV1 = cvCreateImage(cvGetSize(img), img->depth,1);
	cvLaplace(img,HV1,3);
		 return HV1;
}