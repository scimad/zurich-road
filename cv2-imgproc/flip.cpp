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
        

        //TODO: Fill up the above matrix now


        std::cout << flipped_hor << std::endl;
        std::cout << "succedded creating flipped_hor" << std::endl;

        return 0;



    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }

    return 0;
}
