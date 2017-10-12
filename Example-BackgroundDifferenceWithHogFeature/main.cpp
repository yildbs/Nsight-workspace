#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <ycv/core/core.hpp>
#include <ycv/imgproc/hog/hog.h>

int main()
{
	int image_width = 1280;
	int image_height = 720;

	cv::Mat image = cv::imread("/home/yildbs/Data/sample.ppm");
	cv::resize(image, image, cv::Size(image_width, image_height));
	cv::imshow("image", image);
	cv::waitKey(0);

//	cv::HOGDescriptor hog(
//			cv::Size(image_width, image_height),
//			cv::Size(16, 16),
//			cv::Size(8, 8),
//			8,
//			9
//	);

	ycv::hog::HOGDescriptorSingle hog_descriptor;

	int cell_size = 8;
	hog_descriptor.Initialize(
		image_width,
		image_height,
		3,
		1.0,
		true,
		false,
		9,
		cell_size,
		2,
		static_cast<int>(image_width/cell_size),
		static_cast<int>(image_height/cell_size)
	);

	ycv::YMat<unsigned char> yimage(image_width, image_height, 3, image.data);

	hog_descriptor.SetImage(yimage);
	hog_descriptor.MakeHistogram();
	hog_descriptor.MakeNormalizedBlocks();
	hog_descriptor.MakeDescriptor(0, 0);
	auto descriptor_size = hog_descriptor.GetDescriptorLength();
	auto descriptor = hog_descriptor.GetDescriptor();


}
