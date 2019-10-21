/**
 * @file cascade.cpp
 * @brief load cascade model and detect object in an image by class method definition
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

#include "cascade.hpp"

int Cascade::init(cv::Mat &i, cv::Mat &g) {
  frameImage = i;
  grayImage = g;
  if (frameImage.total() == grayImage.total()) {
    return 1;
  }
  return 0;
}

int Cascade::loadCascade(const std::string &filePath) {
  humanCascade.load(filePath);
  if (humanCascade.empty()) {
    std::cout << "Unable to load Cascade XML file" << std::endl;
    return 0;
  }
  return 1;
}

int Cascade::objectDetect(std::vector<cv::Rect> &envlp) {
  cv::Mat imgBlur;
  cv::GaussianBlur(grayImage, imgBlur, cv::Size(5, 5), 1.8);
  humanCascade.detectMultiScale(imgBlur, envlp, 5, 10, 0, cv::Size(75, 30));
  int totalObjects = static_cast<int>(envlp.size());
  return totalObjects;
}
