#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>
#include <math.h>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
    std::cout <<"Rotating image....................." << std::endl;

    int theta;
    std::cout << "Enter clockwise rotation angle: ";
    std::cin >> theta;

    if (argc != 2){
        std::cout << "Please enter the path of the image to read!" << std::endl;
        return -1;
    }
    try
    {
        cv::Mat img;
        img = cv::imread(argv[1], cv::IMREAD_COLOR);
        if (!img.data)
        {
            std::cout <<"Couldn't open the image" <<std::endl;
            return -1;
        }

        cv::imshow("Original Image", img);
        cv::waitKey(0);

        int l = sqrt(img.rows*img.rows + img.cols*img.cols);

        cv::Mat img_rotated(l, l, CV_8UC3);
        int i, j, newi, newj;

        for (i=0; i<img.rows; i++){
            for (j=0; j<img.cols; j++){
                newi = (-i+img.rows/2) * cos(theta*3.1415/180) - (-j+img.cols/2)* sin(theta*3.1415/180);
                newj = (-i+img.rows/2) * sin(theta*3.1415/180) + (-j+img.cols/2)* cos(theta*3.1415/180);
                img_rotated.at<cv::Vec3b>(l/2 - newi, l/2 - newj) = img.at<cv::Vec3b>(i, j);
            }
        }

        cv::imshow("Rotated", img_rotated);
        cv::waitKey(0);
        cv::destroyAllWindows();

        return 0;
    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }

    return 0;
}
