/*
 * FrameSubstractor.h
 *
 *  Created on: Oct 14, 2017
 *      Author: yildbs
 */

#pragma once

#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <ycv/core/core.hpp>
#include <ycv/imgproc/hog/hog.h>


namespace yot{

class FrameSubstractor {
public:
	FrameSubstractor();
	virtual ~FrameSubstractor();

public:
	struct{
		int frame_width;
		int frame_height;
		int cell_size ;
		int nbins;
	}params;
	cv::Mat difference;
	ycv::hog::HOGDescriptorSingle hog_descriptor;

	FrameSubstractor& Substract(cv::Mat background,cv::Mat frame);

};



}
