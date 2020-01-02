#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    cout <<"... and miles to go before I sleep." << endl;
    cout <<"..................................." << endl;
    try
    {
        cv::Mat barca_img;
        std::string filename("../sample-data/barca.jpg");
        barca_img = cv::imread(filename);
        if (!barca_img.data)
        {
            cout <<"Couldn't open the image" <<endl;
            return -1;
        }
        cv::imshow("barca", barca_img);
        cv::waitKey(0);

        cv::Mat inv_img(cv::Size(barca_img.size()), CV_8UC1);
        inv_img = cv::Mat(cv::Size(barca_img.size()), CV_8UC3,cv::Scalar(255,255,255)) - barca_img;

        cv::imshow("inv-barca", inv_img);
        cv::waitKey(0);

        return 0;

    }
    catch( cv::Exception& e )
    {
        const char* err_msg = e.what();
        cout << "exception caught: " << err_msg << endl;
    }

    return 0;
}
