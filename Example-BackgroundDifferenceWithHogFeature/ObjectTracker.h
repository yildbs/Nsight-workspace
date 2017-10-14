/*
 * ObjectTracker.h
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

class ObjectTracker {
public:
	ObjectTracker();
	virtual ~ObjectTracker();
};

}
