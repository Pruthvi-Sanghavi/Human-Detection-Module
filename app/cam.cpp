/**
 * @file cam.cpp
 * @brief initializing video input with recorded video by class method definition
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

#include "cam.hpp"

int Cam::readVideo(std::string demoPath) {
  feed.open(demoPath);
  if (!feed.isOpened()) {
    std::cout << "\nerror: Demo Video not initialized successfully\n\n";
    return 0;
  }
  return 2;
}

int Cam::readFrameImage(cv::Mat &img) {
  if (!feed.isOpened()) {
    std::cout << "error: Feed not initialized \n\n";
    return 3;
  }
  feed.read(img);
  return 4;
}

int Cam::color2gray(cv::Mat &frameImage, cv::Mat &grayImage) {
  cv::cvtColor(frameImage, grayImage, cv::COLOR_BGR2GRAY);
  int grayImgSize = static_cast<int>(grayImage.total() * grayImage.channels());
  return grayImgSize;
}
