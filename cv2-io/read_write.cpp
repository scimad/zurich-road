#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
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
        
        cv::Mat img_gray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
        cv::imshow("Grayscale", img_gray);        
        
        cv::waitKey(0);
        std::cout << "Now writing data to new_file.jpg" << std::endl;
        cv::imwrite("./new_file.jpg", img);

        return 0;

    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }

    return 0;
}
