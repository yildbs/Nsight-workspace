/*
 * BackgroundGenerator.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: yildbs
 */

#include "BackgroundGenerator.h"

namespace yot{

BackgroundGenerator::BackgroundGenerator() {
	// TODO Auto-generated constructor stub

	this->params.absorb_ratio = 0.0001;
	this->params.frame_width = 1280;
	this->params.frame_height = 720;

	this->background = cv::Mat(this->params.frame_height, this->params.frame_width, CV_8UC3);
}

BackgroundGenerator::~BackgroundGenerator() {
	// TODO Auto-generated destructor stub
}


BackgroundGenerator& BackgroundGenerator::AbsorbFrame(cv::Mat& frame)
{
	float ratio = this->params.absorb_ratio;
//	this->background = (1.-ratio) * this->background + ratio * frame;

	int width = this->params.frame_width;
	int height = this->params.frame_height;

	for(int y=0;y<height;y++){
		for(int x=0;x<width*3;x++){
			float value = (float)this->background.data[y*width*3+x]*(1.-ratio) + (float)frame.data[y*width*3+x]*ratio;
			if(value >=255.){
				value = 255;
			}
			if(value < 0.){
				value = 0.;
			}
			this->background.data[y*width*3+x] = (unsigned char)value;
		}
	}

	return *this;
}

BackgroundGenerator& BackgroundGenerator::ResetBackground(cv::Mat& frame)
{
	frame.copyTo(this->background);
//	this->background = frame;
	return *this;
}

}