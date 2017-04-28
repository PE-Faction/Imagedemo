#include "NeighborhoodProcessing.h"
/**  
           图像与算子计算的一般的C++实现
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

IplImage* NeighborhoodProcessing::NeighborhoodAverage(IplImage* in) //进行图像的邻域平均
{

	IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels);   
	cvSmooth(in,out,CV_BLUR,3,in->nChannels);  //  简单平均   
  
	return out;
}


IplImage* NeighborhoodProcessing::GaussFilter(IplImage* in)//图像的Gauss滤波
{
    IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels); // 建立辅助位图
	cvSmooth(in,out,CV_GAUSSIAN,3,in->nChannels); // Gauss 平滑
	return out;//对于高斯函数的计算，还存在比较大的疑问
}


IplImage* NeighborhoodProcessing::MedianFilter(IplImage* in)//图像的中值滤波
{
	 IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,in->nChannels);   
	 cvSmooth(in,out,CV_MEDIAN,3,in->nChannels);  //  中值滤波  
	return out;
}


IplImage* NeighborhoodProcessing::SobelBoundaryDetection(IplImage *img)//sobel边缘检测
{
	IplImage* H = cvCreateImage(cvGetSize(img), img->depth,1);
	IplImage* V = cvCreateImage(cvGetSize(img),img->depth,1);
	IplImage* HV = cvCreateImage(cvGetSize(img),img->depth,1);
	IplImage* HV1 = cvCreateImage(cvGetSize(img),img->depth,1);
 
         cvSobel(img,H,0,1,3); 
         cvSobel(img,V,1,0,3);
/*
  void cvLaplaceconst（ CvArr* src,CvArr* dst,int xorder,int yorder,int aperture_size = 3);src 输入图像.dst 输出图像.xorder和yorder是求导的阶数，aperture_size 核大小.函数。
Sobel导数有一个很好的性质，可以定义任意大小的核，并且这些核可以用快速且迭代的方式构造。大核对导数有更好的逼近，小核对噪声更敏感。
             src 输入图像.
             dst 输出图像.
             xorder x 方向上的差分阶数
             yorder y 方向上的差分阶数
             aperture_size  扩展 Sobel 核的大小，必须是 1, 3, 5 或 7。 除了尺寸为 1， 其它情况下， aperture_size ×aperture_size 可分离内核将用来计算差分。对 aperture_size=1的情况， 使用 3x1 或 1x3 内核 （不进行高斯平滑操作）。这里有一个特殊变量 CV_SCHARR (=-1)，对应 3x3 Scharr 滤波器，可以给出比 3x3 Sobel 滤波更精确的结果。Scharr 滤波器系数是：
                            对 x-方向 以及转置矩阵对 y-方向。
函数 cvSobel 通过对图像用相应的内核进行卷积操作来计算图像差分：
  由于Sobel 算子结合了 Gaussian 平滑和微分，所以，其结果或多或少对噪声有一定的鲁棒性。通常情况，函数调用采用如下参数 (xorder=1, yorder=0, aperture_size=3) 或 (xorder=0, yorder=1, aperture_size=3) 来计算一阶 x- 或 y- 方向的图像差分。第一种情况对应：
核。
第二种对应：
或者
核的选则依赖于图像原点的定义 (origin 来自 IplImage 结构的定义)。由于该函数不进行图像尺度变换，所以和输入图像(数组)相比，输出图像(数组)的元素通常具有更大的绝对数值（译者注：即象素的深度）。为防止溢出，当输入图像是 8 位的，要求输出图像是 16 位的。当然可以用函数 cvConvertScale 或 cvConvertScaleAbs 转换为 8 位的。除了 8-比特 图像，函数也接受 32-位 浮点数图像。所有输入和输出图像都必须是单通道的，并且具有相同的图像尺寸或者ROI尺寸。
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


IplImage* NeighborhoodProcessing::LaplaceBoundaryDetection(IplImage *img)//laplace边缘检测
{
	IplImage* HV1 = cvCreateImage(cvGetSize(img), img->depth,1);
	cvLaplace(img,HV1,3);
		 return HV1;
}