#include "pointOperation.h"
/*
 完成图像的点操作的具体的算法的实现
*/

IplImage* pointOperation::colorGrayScale(IplImage* img)   //图像转灰阶
{
	/*
	 灰度化方法
       一般有四种方法对彩色图像进行灰度化处理：分量法、最大值法、平均值法、加权平均法。

       图像灰度化处理有以下几种方式：
       1. 分量法
       将彩色图像中的三分量的亮度作为三个灰度图像的灰度值，可根据应用需要选取一种灰度图像。

							f1(i,j)=R(i,j) 
							f2(i,j)=G(i,j) 
							f3(i,j)=B(i,j)
       其中fk(i,j)(k=1,2,3)为转换后的灰度图像在（i,j）处的灰度值。

	   2. 最大值法
	   将彩色图像中的三分量亮度的最大值作为灰度图的灰度值。
       f(i,j)=max(R(i,j),G(i,j),B(i,j))

       3. 平均值法
       将彩色图像中的三分量亮度求平均得到一个灰度值。
       f(i,j)=(R(i,j)+G(i,j)+B(i,j)) /3

       4. 加权平均法
       根据重要性及其它指标，将三个分量以不同的权值进行加权平均。由于人眼对绿色的敏感最高，对蓝色敏感最低，因此，按下式对RGB三分量进行加权平均能得到较合理的灰度图像。
        f(i,j)=0.30R(i,j)+0.59G(i,j)+0.11B(i,j))  心理公式

       5.Opencv中图像灰度化处理
        //彩色图转为灰度图方法调用
         cv::cvtColor(rgbMat, greyMat, CV_BGR2GRAY);
*/
	IplImage *dst_gray = cvCreateImage(cvGetSize(img),img->depth,1);
	int r,g,b;           //利用心理公式
	for(int i=0;i<img->height;i++)
	{
		for(int j=0;j<img->width;j++)
		{
			    r=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+0);  
                g=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+1);  
                b=(int)CV_IMAGE_ELEM(img,uchar,i,j*3+2);  
		CV_IMAGE_ELEM(dst_gray,uchar,i,j)=(int)(r*30 + g*59 + b*11 + 50)/100;
       }

	}
	//cvCvtColor(img,dst_gray,CV_BGR2GRAY);//得到灰度图
	return  dst_gray;
}


IplImage* pointOperation::ImageInversion(IplImage* img)   //图像反相
{
	IplImage *img2= cvCreateImage(cvGetSize(img),img->depth,3);
	for(int i=0;i<img->height;i++)
	{
		for(int j=0;j<img->width;j++)
		{
			CV_IMAGE_ELEM(img2,uchar,i,j*3+0)=256-1-(int)CV_IMAGE_ELEM(img,uchar,i,j*3+0);
			CV_IMAGE_ELEM(img2,uchar,i,j*3+1)=256-1-(int)CV_IMAGE_ELEM(img,uchar,i,j*3+1);
			CV_IMAGE_ELEM(img2,uchar,i,j*3+2)=256-1-(int)CV_IMAGE_ELEM(img,uchar,i,j*3+2);

		}

	}

	return  img2;
}
IplImage* pointOperation::VerticalMirror(IplImage* img)  //垂直镜像
{
	IplImage *img2= cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	for(int i=0;i<img->height;i++)
	{
		for(int j=0;j<img->width;j++)
		{
			CV_IMAGE_ELEM(img2,uchar,((img->height)-1-i),j)=(int)CV_IMAGE_ELEM(img,uchar,i,j);
			
		}
	}

	return  img2;
}
IplImage*  pointOperation::HorizontalMirror(IplImage* img)  //水平镜像
{

	/* CvScalar color=cvGet2D(img, i, j);  
			 cvSet2D(img2, i, img->width-j-1, color);//注意这里  */
	IplImage *img2= cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	for(int i=0;i<img->height;i++)
	{
		for(int j=0;j<img->width;j++)
		{
			CV_IMAGE_ELEM(img2,uchar,i,img->width-1-j)=(int)CV_IMAGE_ELEM(img,uchar,i,j);
			
		}
	}
	return  img2;
}
IplImage*  pointOperation::_180DegreeRotation(IplImage* src)  //180度旋转
{
	/*   利用仿射变换进行图像的旋转，及使用2*3的仿射矩阵，先把src图像的数据复制到temp上，然后再利用仿射矩阵进行图像的旋转
	     最后输出图像
	*/
   bool clockwise=true;//可以控制图像是顺时针旋转还是逆时针旋转
   int angle = abs(90)% 180; 
   if (angle > 90) 
  { 
    angle = 90 - (angle % 90); 
  } 
   IplImage* dst = NULL; 
   int width = 
       (double)(src->height * sin(angle * CV_PI / 180.0)) + 
       (double)(src->width * cos(angle * CV_PI / 180.0 )) + 1; 
   int height = 
   (double)(src->height * cos(angle * CV_PI / 180.0)) + 
   (double)(src->width * sin(angle * CV_PI / 180.0 )) + 1; 
   int tempLength = sqrt((double)src->width * src->width + src->height * src->height) + 10; 

   int tempX = (tempLength + 1) / 2 - src->width / 2; 
   int tempY = (tempLength + 1) / 2 - src->height / 2; 
   int flag = -1; 

   dst = cvCreateImage(cvSize(width, height), src->depth, src->nChannels); 
   cvZero(dst); 
   IplImage* temp = cvCreateImage(cvSize(tempLength, tempLength), src->depth, src->nChannels); 
   cvZero(temp); 

   cvSetImageROI(temp, cvRect(tempX, tempY, src->width, src->height)); 
   cvCopy(src, temp, NULL); 
   cvResetImageROI(temp); 

  if (clockwise) 
  flag = 1; 

  float m[6]; 
  int w = temp->width; 
  int h = temp->height; 
  m[0] = (float) cos(flag * angle * CV_PI / 180.); 
  m[1] = (float) sin(flag * angle * CV_PI / 180.); 
  m[3] = -m[1]; 
  m[4] = m[0]; 
  // 将旋转中心移至图像中间 
  m[2] = w * 0.5f; 
  m[5] = h * 0.5f; 
 
 CvMat M = cvMat(2, 3, CV_32F, m); 
 cvGetQuadrangleSubPix(temp, dst, &M); //用于图像的旋转比较合适，开销相对比较小
 cvReleaseImage(&temp); 
 return dst; 
}
IplImage*  pointOperation::_30DegreeRotation(IplImage* src)    //30度旋转
{
	/*   利用仿射变换进行图像的旋转，及使用2*3的仿射矩阵，先把src图像的数据复制到temp上，然后再利用仿射矩阵进行图像的旋转
	     最后输出图像
	*/
   bool clockwise=true;//可以控制图像是顺时针旋转还是逆时针旋转
   int angle = abs(30)% 180; 
   if (angle > 90) 
  { 
    angle = 90 - (angle % 90); 
  } 
   IplImage* dst = NULL; 
   int width = 
       (double)(src->height * sin(angle * CV_PI / 180.0)) + 
       (double)(src->width * cos(angle * CV_PI / 180.0 )) + 1; 
   int height = 
   (double)(src->height * cos(angle * CV_PI / 180.0)) + 
   (double)(src->width * sin(angle * CV_PI / 180.0 )) + 1; 
   int tempLength = sqrt((double)src->width * src->width + src->height * src->height) + 10; 

   int tempX = (tempLength + 1) / 2 - src->width / 2; 
   int tempY = (tempLength + 1) / 2 - src->height / 2; 
   int flag = -1; 

   dst = cvCreateImage(cvSize(width, height), src->depth, src->nChannels); 
   cvZero(dst); 
   IplImage* temp = cvCreateImage(cvSize(tempLength, tempLength), src->depth, src->nChannels); 
   cvZero(temp); 

   cvSetImageROI(temp, cvRect(tempX, tempY, src->width, src->height)); 
   cvCopy(src, temp, NULL); 
   cvResetImageROI(temp); 

  if (clockwise) 
  flag = 1; 

  float m[6]; 
  int w = temp->width; 
  int h = temp->height; 
  m[0] = (float) cos(flag * angle * CV_PI / 180.); 
  m[1] = (float) sin(flag * angle * CV_PI / 180.); 
  m[3] = -m[1]; 
  m[4] = m[0]; 
  // 将旋转中心移至图像中间 
  m[2] = w * 0.5f; 
  m[5] = h * 0.5f; 
 
 CvMat M = cvMat(2, 3, CV_32F, m); 
 cvGetQuadrangleSubPix(temp, dst, &M);
 cvReleaseImage(&temp); 
 return dst; 
}
IplImage*  pointOperation::AffineTransformation(IplImage* src)  //仿射变换
{
	CvPoint2D32f srcTri[3];
	CvPoint2D32f dstTri[3];
	CvMat*  rot_mat=cvCreateMat(2,3,CV_32FC1);
	CvMat*  warp_mat=cvCreateMat(2,3,CV_32FC1);
	IplImage *dst;
	
	dst =cvCloneImage(src);
	dst->origin=src->origin;
	cvZero(dst);
	srcTri[0] = Point2f( 0,0 );  
	srcTri[1] = Point2f( src->width - 1, 0 );  
	srcTri[2] = Point2f( 0, src->height - 1 );  
	dstTri[0] = Point2f( src->width*0.0, src->height*0.33 );  
    dstTri[1] = Point2f( src->width*0.85, src->height*0.25 );  
    dstTri[2] = Point2f( src->width*0.15, src->height*0.7 );  
    cvGetAffineTransform( srcTri, dstTri,warp_mat );  //根据给出的六个顶点，推出两个图像之间的映射矩阵warp_mat
    cvWarpAffine( src,dst,warp_mat);           //根据求出的映射矩阵，进行仿射变换  该函数有一些插值运算，对于扭曲的图像变换比较合适，但开销较大
	return  dst;
}
IplImage*  pointOperation::PerspectiveTransformation(IplImage* src)//透视变换
{
	CvPoint2D32f srcQuad[4],dstQuad[4];
	CvMat* warp_matrix =cvCreateMat(3,3,CV_32FC1);
	IplImage* dst;

	dst = cvCloneImage(src);
	dst->origin=src->origin;
	cvZero(dst);

	srcQuad[0] = Point2f(0,0);
	srcQuad[1] = Point2f(src->width,0);
	srcQuad[2] = Point2f(0,src->height);
	srcQuad[3] = Point2f(src->width,src->height);

	dstQuad[0] = Point2f(src->width*0.05,src->height*0.33);
	dstQuad[1] = Point2f(src->width*0.9,src->height*0.25);
	dstQuad[2] = Point2f(src->width*0.2,src->height*0.7);
	dstQuad[3] = Point2f(src->width*0.8,src->height*0.9);
	cvGetPerspectiveTransform(srcQuad,dstQuad,warp_matrix);//根据8个顶点，求出两个图像的映射矩阵，warp_matrix
	cvWarpPerspective(src,dst,warp_matrix);//根据映射矩阵，进行图像的变换  ---与仿射变换相类似
    return  dst;
}
IplImage*  pointOperation::BrightnessTransformation(IplImage* img) //亮度变换  就是基本的点操作增加对比度和亮度
{
	IplImage *img2 = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    double alpha=2.2; /**< 控制对比度 */
    int beta=50;  /**< 控制亮度 */
    /*Mat image(img);
    Mat new_image = Mat::zeros( image.size(), image.type());*/
	for( int i = 0; i < img2->height; i++ )
    {
		for( int j = 0; j < img2->width; j++ )
        {
            for( int c = 0; c < 3; c++ )
            {
				CV_IMAGE_ELEM(img2,uchar,i,j*3+c)=saturate_cast<uchar>(alpha*( CV_IMAGE_ELEM(img,uchar,i,j*3+c) ) + beta );
                //new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }
	
	return  img2;
}
IplImage*  pointOperation::GrayscaleImageHistogram(IplImage* img)//灰阶图像直方图
{
	 int hist_size = 256;    //直方图尺寸  
    int hist_height = 256;  
    float range[] = {0,255};  //灰度级的范围  
    float* ranges[]={range};  
    //创建一维直方图，统计图像在[0 255]像素的均匀分布  
	/*
	   OpenCV中用cvCreateHist()创建一个直方图：

 CvHistogram* cvCreateHist(   
                           int dims, //直方图维数   
                           int* sizes,//直翻图维数尺寸  
                           int type, //直方图的表示格式  
                           float** ranges=NULL, //图中方块范围的数组  
                           int uniform=1 //归一化标识  
                          );  

      size数组的长度为dims，每个数表示分配给对应维数的bin的个数。如dims=3，则size中用[s1,s2,s3]分别指定每维bin的个数。
       type有两种：CV_HIST_ARRAY 意味着直方图数据表示为多维密集数组 CvMatND; CV_HIST_TREE 意味着直方图数据表示为多维稀疏数组 CvSparseMat。
       ranges就是那个复杂的不好理解的thresh的范围，他的内容取决于uniform的值。uniform为0是均匀的，非0时不均匀。
	*/
    CvHistogram* gray_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);  
    //计算灰度图像的一维直方图  
	cvCalcHist(&img,gray_hist,0,0);  
    //归一化直方图  
    cvNormalizeHist(gray_hist,1.0);  
  
    int scale = 2;  
    //创建一张一维直方图的“图”，横坐标为灰度级，纵坐标为像素   
    IplImage* hist_image = cvCreateImage(cvSize(hist_size*scale,hist_height),8,3);  
    cvZero(hist_image);  
    //统计直方图中的最大直方块  
    float max_value = 0;  
    cvGetMinMaxHistValue(gray_hist, 0,&max_value,0,0);  
      
    //分别将每个直方块的值绘制到图中  
    for(int i=0;i<hist_size;i++)  
    {  
        float bin_val = cvQueryHistValue_1D(gray_hist,i); //像素i的概率  
        int intensity = cvRound(bin_val*hist_height/max_value);  //要绘制的高度  
        cvRectangle(hist_image,  
            cvPoint(i*scale,hist_height-1),
            cvPoint((i+1)*scale - 1, hist_height - intensity),  
            CV_RGB(255,255,255));    
    }   
    cvNamedWindow( "H-S Histogram", 1 );  
    cvShowImage( "H-S Histogram", hist_image );  
  
    cvWaitKey(0);  
	return  img;
}



void FillWhite(IplImage *pImage)  
{  
    cvRectangle(pImage, cvPoint(0, 0), cvPoint(pImage->width, pImage->height), CV_RGB(255, 255, 255), CV_FILLED);  
}  
CvHistogram* CreateGrayImageHist(IplImage **ppImage)  
{  
    int nHistSize = 256;  
    float fRange[] = {0, 255};  //灰度级的范围    
    float *pfRanges[] = {fRange};    
    CvHistogram *pcvHistogram = cvCreateHist(1, &nHistSize, CV_HIST_ARRAY, pfRanges);  
    cvCalcHist(ppImage, pcvHistogram);  
    return pcvHistogram;  
}  
// 根据直方图创建直方图图像  
IplImage* CreateHisogramImage(int nImageWidth, int nScale, int nImageHeight, CvHistogram *pcvHistogram)  
{  
    IplImage *pHistImage = cvCreateImage(cvSize(nImageWidth * nScale, nImageHeight), IPL_DEPTH_8U, 1);  
    FillWhite(pHistImage);  
  
    //统计直方图中的最大直方块  
    float fMaxHistValue = 0;  
    cvGetMinMaxHistValue(pcvHistogram, NULL, &fMaxHistValue, NULL, NULL);  
  
    //分别将每个直方块的值绘制到图中  
    int i;  
    for(i = 0; i < nImageWidth; i++)  
    {  
        float fHistValue = cvQueryHistValue_1D(pcvHistogram, i); //像素为i的直方块大小  
        int nRealHeight = cvRound((fHistValue / fMaxHistValue) * nImageHeight);  //要绘制的高度  
        cvRectangle(pHistImage,  
            cvPoint(i * nScale, nImageHeight - 1),  
            cvPoint((i + 1) * nScale - 1, nImageHeight - nRealHeight),  
            cvScalar(i, 0, 0, 0),   
            CV_FILLED  
            );   
    }  
    return pHistImage;  
} 
IplImage* pointOperation::HistogramEqualization(IplImage* pSrcImage) //直方图均衡化
{
	IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);  
    IplImage *pGrayEqualizeImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);  
     
    // 灰度图  
     cvCopy(pSrcImage,pGrayImage);
    // 直方图图像数据  
    int nHistImageWidth = 255;  
    int nHistImageHeight = 150;   
    int nScale = 2;    
  
    // 灰度直方图及直方图图像  
    CvHistogram *pcvHistogram = CreateGrayImageHist(&pGrayImage);  
    IplImage *pHistImage = CreateHisogramImage(nHistImageWidth, nScale, nHistImageHeight, pcvHistogram);  
  
    // 均衡化 
    //函数功能：直方图均衡化，该函数能归一化图像亮度和增强对比度
    //第一个参数表示输入图像，必须为灰度图（8位，单通道图）
    //第二个参数表示输出图像
    //该函数采用如下法则对输入图像进行直方图均衡化：
        //1：计算输入图像的直方图H。
        //2：直方图归一化，因此直方块和为255。
        //3：计算直方图积分，H'(i) = Sum(H(j)) (0<=j<=i)。
        //4：采用H'作为查询表：dst(x, y) = H'(src(x, y))进行图像变换。
    cvEqualizeHist(pGrayImage, pGrayEqualizeImage);  
    // 均衡化后的灰度直方图及直方图图像  
    const char *pstrWindowsHistTitle = "直方图";   
    const char *pstrWindowsHistEqualizeTitle = "直方图-均衡化后"; 
    CvHistogram *pcvHistogramEqualize = CreateGrayImageHist(&pGrayEqualizeImage);         
    IplImage *pHistEqualizeImage = CreateHisogramImage(nHistImageWidth, nScale, nHistImageHeight, pcvHistogramEqualize);
	cvShowImage(pstrWindowsHistTitle,pHistImage);
    cvShowImage(pstrWindowsHistEqualizeTitle,pHistEqualizeImage);
	return  pSrcImage;
}

