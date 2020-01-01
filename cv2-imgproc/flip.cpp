#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
    std::cout <<"Flipping image....................." << std::endl;

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
        
        // cv::namedWindow("named-window", cv::WINDOW_FULLSCREEN);
        cv::imshow("Original Image", img);
        cv::waitKey(0);
        cv::Mat img_gray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
        cv::imshow("Grayscale", img_gray);        
        cv::waitKey(0);
        
        cv::Mat flipped_hor(img_gray.rows , img_gray.cols, CV_8UC1, cv::Scalar(0));
        cv::Mat flipped_ver(img_gray.rows , img_gray.cols, CV_8UC1, cv::Scalar(0));

        std::cout << "succedded creating flipped_hor" << std::endl;

        int i, j;
        for (i=0; i<flipped_hor.rows; i++){
            for (j=0; j<flipped_hor.cols; j++){
                flipped_hor.at<uchar>(i,j) = img_gray.at<uchar>(i, img_gray.cols-j);
                flipped_ver.at<uchar>(i,j) = img_gray.at<uchar>(img_gray.rows-i, j);
            }
        }
        cv::imshow("Transformed", flipped_hor);
        cv::waitKey(0);

        cv::imshow("Transformed", flipped_ver);
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
