/* Autogenerated with kurento-module-creator */

#include "OpencvPluginSampleOpenCVImpl.hpp"
#include <KurentoException.hpp>

using namespace cv;

namespace kurento
{
namespace module
{
namespace opencvpluginsample
{

OpencvPluginSampleOpenCVImpl::OpencvPluginSampleOpenCVImpl ()
{
  this->filterType = 0;
  this->edgeValue = 125;
}

/*
 * This function will be called with each new frame. mat variable
 * contains the current frame. You should insert your image processing code
 * here. Any changes in mat, will be sent through the Media Pipeline.
 */
void OpencvPluginSampleOpenCVImpl::process (cv::Mat &mat)
{
  cv::Mat matBN (mat.rows, mat.cols, CV_8UC1);
  cv::cvtColor(mat, matBN, COLOR_BGRA2GRAY);

  if (filterType == 0) {
    Canny (matBN, matBN, edgeValue, 125);
  }
  cvtColor (matBN, mat, COLOR_GRAY2BGRA);
}

void OpencvPluginSampleOpenCVImpl::setFilterType (int filterType)
{
  this->filterType = filterType;
}

void OpencvPluginSampleOpenCVImpl::setEdgeThreshold (int edgeValue)
{
  this->edgeValue = edgeValue;
}

} /* opencvpluginsample */
} /* module */
} /* kurento */