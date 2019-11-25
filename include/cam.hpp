/**
 * @file cam.hpp
 * @brief initializing video input with a recorded clip
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

#ifndef INCLUDE_CAM_HPP_
#define INCLUDE_CAM_HPP_

#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Cam {
 private:
  cv::VideoCapture feed;  ///< variable to hold video input

 public:
  /**
   * overloaded function to read video from a video file into feed
   * @param demoPath std::string
   * @return int
   */
  int readVideo(std::string demoPath);

  /**
   * read each frame of the video feed
   * @param cv::MAT&
   * @return int
   */
  int readFrameImage(cv::Mat&);

  /**
   * convert RBG image to grayscale
   * @param frameImage cv::Mat%
   * @param grayImage cv::Mat%
   * @return grayImgSize int
   */
  int color2gray(cv::Mat&, cv::Mat&);
};
#endif  // INCLUDE_CAM_HPP_
