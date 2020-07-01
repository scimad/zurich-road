#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

int main(int argc, char** argv){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................." << std::endl;
    std::cout <<"Stitching two images..............." << std::endl;

    if (argc != 3){
        std::cout << "Please enter the path of two images read!" << std::endl;
        return -1;
    }
    try
    {
        cv::Mat base_img, img;
        base_img = cv::imread(argv[1], cv::IMREAD_COLOR);
        img = cv::imread(argv[2], cv::IMREAD_COLOR);
        if (!img.data || !base_img.data)
        {
            std::cout <<"Couldn't open at least one image." <<std::endl;
            return -1;
        }

        cv::imshow("Base Image", base_img);
        cv::waitKey(0);
        cv::destroyAllWindows();

        int minHessian = 100;
        cv::Ptr <cv::xfeatures2d::SIFT> detector = cv::xfeatures2d::SIFT::create(100);
        std::vector <cv::KeyPoint> keypoints_baseimg, keypoints_img;

        cv::Mat desc_baseimg, desc_img;
        // detector->detectAndCompute(base_img, cv::noArray(), keypoints_baseimg, desc_baseimg);
        // detector->detectAndCompute(img, cv::noArray(), keypoints_img, desc_img);

        detector->detect(base_img, keypoints_baseimg);
        detector->detect(img, keypoints_img);

        int n = 100; //no_of_keypoints_selected;
        std::vector<cv::KeyPoint> few_keypoints_baseimg = std::vector<cv::KeyPoint>(keypoints_baseimg.begin(), keypoints_baseimg.begin()+n);
        std::vector<cv::KeyPoint> few_keypoints_img = std::vector<cv::KeyPoint>(keypoints_img.begin(), keypoints_img.begin()+n);

        detector->compute(base_img, few_keypoints_baseimg,desc_baseimg);
        detector->compute(img, few_keypoints_img,desc_img);

        cv::Mat img_matched;

        std::vector <cv::DMatch> matches;
        cv::Ptr <cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE);
        matcher->match(desc_baseimg, desc_img, matches);

        // cv::Mat img_keypoints_baseimg, img_keypoints_img;
        // cv::drawKeypoints(base_img, keypoints_baseimg, img_keypoints_baseimg);
        // cv::drawKeypoints(img, keypoints_img, img_keypoints_img);

        // cv::imshow("Keypoints of base image", img_keypoints_baseimg);
        // cv::waitKey(0);
        // cv::imshow("Keypoints of target image", img_keypoints_img);
        // cv::waitKey(0);
        // cv::destroyAllWindows();

        cv::drawMatches(base_img, few_keypoints_baseimg, img, few_keypoints_img, matches, img_matched);

        cv::imshow ("Matched", img_matched);
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
