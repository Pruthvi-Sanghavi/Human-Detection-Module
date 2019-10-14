/**
 * @file cascade.hpp
 * @brief load cascade model and detect object in an image
 * @author Varun Asthana
 * @author Pruthvikumar Sanghavi
 *
 * Copyright [2019] Group14
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INCLUDE_CASCADE_HPP_
#define INCLUDE_CASCADE_HPP_

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

class Cascade : public Cam, public RectPlot {
 private:
  cv::Mat frameImage; /**< variable to hold an image */
  cv::Mat grayImage; /**< variable to hold an image */
  cv::CascadeClassifier humanCascade; /**< variable to load trained cascade model */

 public:
  /**
   * load cascade xml file
   * @param filePath const string&
   * @return loadStatus int
   */
  int loadCascade(const std::string &filePath);

  /**
   * convert RBG image to grayscale
   * @param filePath const string&
   * @return loadStatus int
   */
  cv::Mat color2gray();

  /**
   * detect presence of object in a image
   * @param NULL
   * @return camClose int
   */
  int objectDetect();

};

#endif /* INCLUDE_CASCADE_HPP_ */
