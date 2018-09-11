#include <iostream>

#include <opencv2/opencv.hpp>

#include <opencv2/core/cuda.hpp>

using namespace std;
using namespace cv;

int main() {
    {
        cout << "OpenCV version = " << CV_VERSION << endl;
        int count = cuda::getCudaEnabledDeviceCount();
        cout << "CUDA count = " << count << endl;
        for (int i = 0; i < count; ++i) {
            cuda::printCudaDeviceInfo(i);
        }
    }

    Mat cpuIn = imread("lena512.png");
    if (cpuIn.empty())
        throw runtime_error("lena512.png not found !");


    cuda::GpuMat g1, g2;
    g1.upload(cpuIn);

    cuda::cvtColor(g1, g1, cv::COLOR_BGR2HSV);
    g2 = g1(Rect(100, 100, 350, 350)).clone();
    cuda::resize(g2, g2, Size(700, 400));

    Mat cpuOut;
    g2.download(cpuOut);
    imwrite("out.png", cpuOut);

    return 0;
}
