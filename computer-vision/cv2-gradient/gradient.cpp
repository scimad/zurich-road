#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
    std::cout <<"Applying gradient.................." << std::endl;

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

        int scale = 1;
        int delta = 0;
        int ddepth = CV_16S;

        cv::Mat src, src_gray;
        src = cv::imread(argv[1]);
        cv::GaussianBlur( src, src, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );
        cv::cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );
        // cv::namedWindow("Hello", cv::WINDOW_AUTOSIZE );

        cv::Mat grad_x, grad_y, abs_grad_x, abs_grad_y, grad;

        /// Gradient X
        //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
        Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
        convertScaleAbs( grad_x, abs_grad_x );

        /// Gradient Y
        //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
        Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
        convertScaleAbs( grad_y, abs_grad_y );

        /// Total Gradient (approximate)
        addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

        cv::imshow( "Total approx gradient", grad);
        

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
