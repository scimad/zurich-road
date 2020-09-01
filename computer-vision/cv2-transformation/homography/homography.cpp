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

        std::vector <cv::Point2f> corners1, corners2;
        bool found1 = cv::findChessboardCorners(img1, cv::Size(9,6), corners1);
        cv::drawChessboardCorners(img1, cv::Size(9,6), cv::Mat(corners1), found1);
        cv::imshow("haha", img1);
        cv::waitKey(0);
        bool found2 = cv::findChessboardCorners(img2, cv::Size(9,6), corners2);
        cv::drawChessboardCorners(img2, cv::Size(9,6), cv::Mat(corners2), found2);
        cv::imshow("ahah", img2);
        cv::waitKey(0);
        
        std::cout << "Corners1: \n" << corners1 << std::endl;
        std::cout << "Corners2: \n" << corners2 << std::endl;


        cv::Mat H = cv::findHomography(corners1, corners2);
        std::cout << "H:\n" << H << std::endl;



        
        



        return 0;

    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }

    return 0;
}
