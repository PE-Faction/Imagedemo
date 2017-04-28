#include "pointOperation.h"
/*
 ���ͼ��ĵ�����ľ�����㷨��ʵ��
*/

IplImage* pointOperation::colorGrayScale(IplImage* img)   //ͼ��ת�ҽ�
{
	/*
	 �ҶȻ�����
       һ�������ַ����Բ�ɫͼ����лҶȻ����������������ֵ����ƽ��ֵ������Ȩƽ������

       ͼ��ҶȻ����������¼��ַ�ʽ��
       1. ������
       ����ɫͼ���е���������������Ϊ�����Ҷ�ͼ��ĻҶ�ֵ���ɸ���Ӧ����Ҫѡȡһ�ֻҶ�ͼ��

							f1(i,j)=R(i,j) 
							f2(i,j)=G(i,j) 
							f3(i,j)=B(i,j)
       ����fk(i,j)(k=1,2,3)Ϊת����ĻҶ�ͼ���ڣ�i,j�����ĻҶ�ֵ��

	   2. ���ֵ��
	   ����ɫͼ���е����������ȵ����ֵ��Ϊ�Ҷ�ͼ�ĻҶ�ֵ��
       f(i,j)=max(R(i,j),G(i,j),B(i,j))

       3. ƽ��ֵ��
       ����ɫͼ���е�������������ƽ���õ�һ���Ҷ�ֵ��
       f(i,j)=(R(i,j)+G(i,j)+B(i,j)) /3

       4. ��Ȩƽ����
       ������Ҫ�Լ�����ָ�꣬�����������Բ�ͬ��Ȩֵ���м�Ȩƽ�����������۶���ɫ��������ߣ�����ɫ������ͣ���ˣ�����ʽ��RGB���������м�Ȩƽ���ܵõ��Ϻ���ĻҶ�ͼ��
        f(i,j)=0.30R(i,j)+0.59G(i,j)+0.11B(i,j))  ����ʽ

       5.Opencv��ͼ��ҶȻ�����
        //��ɫͼתΪ�Ҷ�ͼ��������
         cv::cvtColor(rgbMat, greyMat, CV_BGR2GRAY);
*/
	IplImage *dst_gray = cvCreateImage(cvGetSize(img),img->depth,1);
	int r,g,b;           //��������ʽ
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
	//cvCvtColor(img,dst_gray,CV_BGR2GRAY);//�õ��Ҷ�ͼ
	return  dst_gray;
}


IplImage* pointOperation::ImageInversion(IplImage* img)   //ͼ����
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
IplImage* pointOperation::VerticalMirror(IplImage* img)  //��ֱ����
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
IplImage*  pointOperation::HorizontalMirror(IplImage* img)  //ˮƽ����
{

	/* CvScalar color=cvGet2D(img, i, j);  
			 cvSet2D(img2, i, img->width-j-1, color);//ע������  */
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
IplImage*  pointOperation::_180DegreeRotation(IplImage* src)  //180����ת
{
	/*   ���÷���任����ͼ�����ת����ʹ��2*3�ķ�������Ȱ�srcͼ������ݸ��Ƶ�temp�ϣ�Ȼ�������÷���������ͼ�����ת
	     ������ͼ��
	*/
   bool clockwise=true;//���Կ���ͼ����˳ʱ����ת������ʱ����ת
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
  // ����ת��������ͼ���м� 
  m[2] = w * 0.5f; 
  m[5] = h * 0.5f; 
 
 CvMat M = cvMat(2, 3, CV_32F, m); 
 cvGetQuadrangleSubPix(temp, dst, &M); //����ͼ�����ת�ȽϺ��ʣ�������ԱȽ�С
 cvReleaseImage(&temp); 
 return dst; 
}
IplImage*  pointOperation::_30DegreeRotation(IplImage* src)    //30����ת
{
	/*   ���÷���任����ͼ�����ת����ʹ��2*3�ķ�������Ȱ�srcͼ������ݸ��Ƶ�temp�ϣ�Ȼ�������÷���������ͼ�����ת
	     ������ͼ��
	*/
   bool clockwise=true;//���Կ���ͼ����˳ʱ����ת������ʱ����ת
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
  // ����ת��������ͼ���м� 
  m[2] = w * 0.5f; 
  m[5] = h * 0.5f; 
 
 CvMat M = cvMat(2, 3, CV_32F, m); 
 cvGetQuadrangleSubPix(temp, dst, &M);
 cvReleaseImage(&temp); 
 return dst; 
}
IplImage*  pointOperation::AffineTransformation(IplImage* src)  //����任
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
    cvGetAffineTransform( srcTri, dstTri,warp_mat );  //���ݸ������������㣬�Ƴ�����ͼ��֮���ӳ�����warp_mat
    cvWarpAffine( src,dst,warp_mat);           //���������ӳ����󣬽��з���任  �ú�����һЩ��ֵ���㣬����Ť����ͼ��任�ȽϺ��ʣ��������ϴ�
	return  dst;
}
IplImage*  pointOperation::PerspectiveTransformation(IplImage* src)//͸�ӱ任
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
	cvGetPerspectiveTransform(srcQuad,dstQuad,warp_matrix);//����8�����㣬�������ͼ���ӳ�����warp_matrix
	cvWarpPerspective(src,dst,warp_matrix);//����ӳ����󣬽���ͼ��ı任  ---�����任������
    return  dst;
}
IplImage*  pointOperation::BrightnessTransformation(IplImage* img) //���ȱ任  ���ǻ����ĵ�������ӶԱȶȺ�����
{
	IplImage *img2 = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    double alpha=2.2; /**< ���ƶԱȶ� */
    int beta=50;  /**< �������� */
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
IplImage*  pointOperation::GrayscaleImageHistogram(IplImage* img)//�ҽ�ͼ��ֱ��ͼ
{
	 int hist_size = 256;    //ֱ��ͼ�ߴ�  
    int hist_height = 256;  
    float range[] = {0,255};  //�Ҷȼ��ķ�Χ  
    float* ranges[]={range};  
    //����һάֱ��ͼ��ͳ��ͼ����[0 255]���صľ��ȷֲ�  
	/*
	   OpenCV����cvCreateHist()����һ��ֱ��ͼ��

 CvHistogram* cvCreateHist(   
                           int dims, //ֱ��ͼά��   
                           int* sizes,//ֱ��ͼά���ߴ�  
                           int type, //ֱ��ͼ�ı�ʾ��ʽ  
                           float** ranges=NULL, //ͼ�з��鷶Χ������  
                           int uniform=1 //��һ����ʶ  
                          );  

      size����ĳ���Ϊdims��ÿ������ʾ�������Ӧά����bin�ĸ�������dims=3����size����[s1,s2,s3]�ֱ�ָ��ÿάbin�ĸ�����
       type�����֣�CV_HIST_ARRAY ��ζ��ֱ��ͼ���ݱ�ʾΪ��ά�ܼ����� CvMatND; CV_HIST_TREE ��ζ��ֱ��ͼ���ݱ�ʾΪ��άϡ������ CvSparseMat��
       ranges�����Ǹ����ӵĲ�������thresh�ķ�Χ����������ȡ����uniform��ֵ��uniformΪ0�Ǿ��ȵģ���0ʱ�����ȡ�
	*/
    CvHistogram* gray_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);  
    //����Ҷ�ͼ���һάֱ��ͼ  
	cvCalcHist(&img,gray_hist,0,0);  
    //��һ��ֱ��ͼ  
    cvNormalizeHist(gray_hist,1.0);  
  
    int scale = 2;  
    //����һ��һάֱ��ͼ�ġ�ͼ����������Ϊ�Ҷȼ���������Ϊ����   
    IplImage* hist_image = cvCreateImage(cvSize(hist_size*scale,hist_height),8,3);  
    cvZero(hist_image);  
    //ͳ��ֱ��ͼ�е����ֱ����  
    float max_value = 0;  
    cvGetMinMaxHistValue(gray_hist, 0,&max_value,0,0);  
      
    //�ֱ�ÿ��ֱ�����ֵ���Ƶ�ͼ��  
    for(int i=0;i<hist_size;i++)  
    {  
        float bin_val = cvQueryHistValue_1D(gray_hist,i); //����i�ĸ���  
        int intensity = cvRound(bin_val*hist_height/max_value);  //Ҫ���Ƶĸ߶�  
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
    float fRange[] = {0, 255};  //�Ҷȼ��ķ�Χ    
    float *pfRanges[] = {fRange};    
    CvHistogram *pcvHistogram = cvCreateHist(1, &nHistSize, CV_HIST_ARRAY, pfRanges);  
    cvCalcHist(ppImage, pcvHistogram);  
    return pcvHistogram;  
}  
// ����ֱ��ͼ����ֱ��ͼͼ��  
IplImage* CreateHisogramImage(int nImageWidth, int nScale, int nImageHeight, CvHistogram *pcvHistogram)  
{  
    IplImage *pHistImage = cvCreateImage(cvSize(nImageWidth * nScale, nImageHeight), IPL_DEPTH_8U, 1);  
    FillWhite(pHistImage);  
  
    //ͳ��ֱ��ͼ�е����ֱ����  
    float fMaxHistValue = 0;  
    cvGetMinMaxHistValue(pcvHistogram, NULL, &fMaxHistValue, NULL, NULL);  
  
    //�ֱ�ÿ��ֱ�����ֵ���Ƶ�ͼ��  
    int i;  
    for(i = 0; i < nImageWidth; i++)  
    {  
        float fHistValue = cvQueryHistValue_1D(pcvHistogram, i); //����Ϊi��ֱ�����С  
        int nRealHeight = cvRound((fHistValue / fMaxHistValue) * nImageHeight);  //Ҫ���Ƶĸ߶�  
        cvRectangle(pHistImage,  
            cvPoint(i * nScale, nImageHeight - 1),  
            cvPoint((i + 1) * nScale - 1, nImageHeight - nRealHeight),  
            cvScalar(i, 0, 0, 0),   
            CV_FILLED  
            );   
    }  
    return pHistImage;  
} 
IplImage* pointOperation::HistogramEqualization(IplImage* pSrcImage) //ֱ��ͼ���⻯
{
	IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);  
    IplImage *pGrayEqualizeImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);  
     
    // �Ҷ�ͼ  
     cvCopy(pSrcImage,pGrayImage);
    // ֱ��ͼͼ������  
    int nHistImageWidth = 255;  
    int nHistImageHeight = 150;   
    int nScale = 2;    
  
    // �Ҷ�ֱ��ͼ��ֱ��ͼͼ��  
    CvHistogram *pcvHistogram = CreateGrayImageHist(&pGrayImage);  
    IplImage *pHistImage = CreateHisogramImage(nHistImageWidth, nScale, nHistImageHeight, pcvHistogram);  
  
    // ���⻯ 
    //�������ܣ�ֱ��ͼ���⻯���ú����ܹ�һ��ͼ�����Ⱥ���ǿ�Աȶ�
    //��һ��������ʾ����ͼ�񣬱���Ϊ�Ҷ�ͼ��8λ����ͨ��ͼ��
    //�ڶ���������ʾ���ͼ��
    //�ú����������·��������ͼ�����ֱ��ͼ���⻯��
        //1����������ͼ���ֱ��ͼH��
        //2��ֱ��ͼ��һ�������ֱ�����Ϊ255��
        //3������ֱ��ͼ���֣�H'(i) = Sum(H(j)) (0<=j<=i)��
        //4������H'��Ϊ��ѯ��dst(x, y) = H'(src(x, y))����ͼ��任��
    cvEqualizeHist(pGrayImage, pGrayEqualizeImage);  
    // ���⻯��ĻҶ�ֱ��ͼ��ֱ��ͼͼ��  
    const char *pstrWindowsHistTitle = "ֱ��ͼ";   
    const char *pstrWindowsHistEqualizeTitle = "ֱ��ͼ-���⻯��"; 
    CvHistogram *pcvHistogramEqualize = CreateGrayImageHist(&pGrayEqualizeImage);         
    IplImage *pHistEqualizeImage = CreateHisogramImage(nHistImageWidth, nScale, nHistImageHeight, pcvHistogramEqualize);
	cvShowImage(pstrWindowsHistTitle,pHistImage);
    cvShowImage(pstrWindowsHistEqualizeTitle,pHistEqualizeImage);
	return  pSrcImage;
}

