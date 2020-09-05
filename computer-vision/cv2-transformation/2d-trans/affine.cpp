#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>

#include <iostream>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
    std::cout <<"Homography.........................\n\n" << std::endl;

    if (argc != 3){
        std::cout << "Please enter the path of two images to read!" << std::endl;
        return -1;
    }
    try
    {
        cv::Mat img1, img2;
        img1 = cv::imread(argv[1], cv::IMREAD_COLOR);
        if (!img1.data)
        {
            std::cout <<"Couldn't open image1" <<std::endl;
            return -1;
        }
        img2 = cv::imread(argv[2], cv::IMREAD_COLOR);
        if (!img2.data)
        {
            std::cout <<"Couldn't open image" <<std::endl;
            return -1;
        }
        float data[6] = { 1, -0.4, 0.36, 0.27, 0.24, 0.1 };

        cv::Mat H(2, 3, CV_32F, data);
        cv::Mat img1_warp;
        cv::warpAffine(img1, img1_warp, H, img1.size());
        
        cv::imshow("warped", img1_warp);
        cv::waitKey(0);
        
        return 0;

    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }

    return 0;
}
