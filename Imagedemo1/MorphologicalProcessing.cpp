#include "MorphologicalProcessing.h"
/*形态学基本的操作:腐蚀，膨胀，开运算，闭运算，形态学梯度，顶帽变换，黑帽变换等*/


	IplImage* MorphologicalProcessing::corrosion(IplImage *img)//腐蚀
	{
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvErode(img,img1,0,1);//腐蚀
		/*
		  CVAPI(void)  cvErode( const CvArr* src, CvArr* dst,
                      IplConvKernel* element CV_DEFAULT(NULL),
                      int iterations CV_DEFAULT(1) );
　　       前两个参数比较熟悉，第三个参数是用于传递模板的信息，默认是（NULL），即为3*3的模板，第四个参数是迭代的次数（即该腐蚀操作做几次）
		*/
		return img1;
	}


	IplImage* MorphologicalProcessing::expand(IplImage *img)  //膨胀
	{
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvDilate(img,img1,0,1);//膨胀 腐蚀的反操作
		return img1;

	}



	IplImage* MorphologicalProcessing::OpenOperation(IplImage *img)//开运算
	{
		/*开运算： 
        先腐蚀后膨胀的过程开运算。用来消除小物体、在纤细点处分离物体、平滑较大物
       体的边界的同时并不明显改变其面积。
        开运算通常是在需要去除小颗粒噪声，以及断开目标物之间粘连时使用。
        其主要作用与腐蚀相似，与腐蚀操作相比，具有可以基本保持目标原有大小不变的优点*/
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		IplImage *img2=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvErode(img,img1,0,1);//腐蚀
		cvDilate(img1,img2,0,1);//膨胀 腐蚀的反操作
		return img2;

	}




	IplImage* MorphologicalProcessing::ClosedOperation(IplImage *img)//闭运算
	{
		/*闭运算： 
               先膨胀后腐蚀的过程称为闭运算。用来填充物体内细小空洞、连接邻近物体、平滑
               其边界的同时并不明显改变其面积*/
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		IplImage *img2=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvDilate(img,img1,0,1);//膨胀 腐蚀的反操作
		cvErode(img1,img2,0,1);//腐蚀
		return img2;
	}



	IplImage* MorphologicalProcessing::MorphologicalGradient(IplImage *img)//形态学梯度
	{
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		IplImage *img2=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvMorphologyEx(img,img1,img2,0,CV_MOP_GRADIENT,1);
		return img1;
	}



	IplImage* MorphologicalProcessing::TopHatTransformation(IplImage *img)//顶帽变换
	{
		/*  顶帽运算（Top Hat）又常常被译为”礼帽“运算。为原图像与“开运算“的结果图之差，
            因为开运算带来的结果是放大了裂缝或者局部低亮度的区域，因此，从原图中减去开运算后的图，
	        得到的效果图突出了比原图轮廓周围的区域更明亮的区域，且这一操作和选择的核的大小相关。
           顶帽运算往往用来分离比邻近点亮一些的斑块。
	       当一幅图像具有大幅的背景的时候，而微小物品比较有规律的情况下，可以使用顶帽运算进行背景提取。*/
		IplImage *img1=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		IplImage *img2=cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
		cvMorphologyEx(img,img1,img2,0,CV_MOP_TOPHAT,1);
		return img1;

	}

	IplImage* MorphologicalProcessing::TroughDetection(IplImage *img)//波谷检测
	{
				return img;

	}