#include <iostream>
#include <fstream>
#include <stdlib.h> //srand()和rand()函数
#include <time.h> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>

using namespace std;
using namespace cv;

int CropImageCount = 0; //裁剪出来的负样本图片个数

int main()
{
    Mat src;
    string ImgName;
    char saveName[256];//裁剪出来的负样本图片文件名
    //打开原始负样本图片文件列表


    ifstream fin("E:\\INRIAPerson\\INRIAPerson\\train_64x128_H96\\neg.lst");

    ofstream fout("E:\\INRIAPerson\\INRIAPerson\\train_64x128_H96\\neg_64x128.lst");

    //ifstream fin_pos("E:/INRIAPerson/INRIAPerson/train_64x128_H96//pos.lst");

   // ofstream fout_pos("E:/INRIAPerson/INRIAPerson/train_64x128_H96//pos_path.lst")

    cout<<"**************************************"<<endl;
    //一行一行读取文件列表
    while(getline(fin,ImgName))
    {

        cout<<"Processing "<<ImgName<<endl;
        //get the path of the img
        ImgName = "E:/INRIAPerson/INRIAPerson/" + ImgName;

        src = imread(ImgName);//读取图片

        //图片大小应该能能至少包含一个64*128的窗口
        if(src.cols >= 64 && src.rows >= 128)
        {
            srand(time(NULL));//设置随机数种子

            //从每张图片中随机裁剪10个64*128大小的不包含人的负样本
            for(int i=0; i<10; i++)
            {
                int x = ( rand() % (src.cols-64) ); //左上角x坐标
                int y = ( rand() % (src.rows-128) ); //左上角y坐标
                //cout<<x<<","<<y<<endl;
                Mat imgROI = src(Rect(x,y,64,128));
                sprintf(saveName,"noperson%06d.jpg",++CropImageCount);//生成裁剪出的负样本图片的文件名
                string img_path="E:/INRIAPerson/INRIAPerson/train_64x128_H96/neg_64x128/"+string(saveName);
                imwrite(img_path, imgROI);//保存文件
                fout<<img_path<<endl;
            }
        }

    }

    fout.close();
    fin.close();
    cout<<"****************************"<<endl;
    cout<<"Done!"<<endl;
    cout<<CropImageCount<<endl;

    waitKey();
}
