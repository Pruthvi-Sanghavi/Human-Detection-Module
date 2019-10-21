/**
 * @file main.cpp
 * @brief program to detect human
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

#include <unistd.h>
#include <iostream>
#include <string>
#include "cam.hpp"
#include "rectplot.hpp"
#include "cascade.hpp"

int main() {
  Cascade obj;
  Cam web;
  RectPlot fig;
  std::string cascadePath = "../app/humanDetectCascade.xml";
  std::string demo = "../app/demo/video2.mp4";
  cv::Mat readFrame;
  cv::Mat grayFrame;
  /**
   * Check if cascade called successfully
   */
  if (!obj.loadCascade(cascadePath)) {
    return 0;
  }
  /**
   * Check if video has been initialized successfully
   */
  if (!web.readVideo(demo)) {
    return 0;
  }
  /**
   * ESC key to exit the program at any time
   */
  std::cout << "\n How to interact with this program:\n";
  std::cout
      << "\n Once you enter a character, a demo video will be initialized";
  std::cout
      << "\n\n To terminate the program press ECS key (after video starts)";
  std::cout << "\n\n Detected Human will be shown in a "
            "rectangular box with world coordinates";
  std::cout << "\n\n These coordinates will also be printed on the console.";
  std::cout << "\n\n Lets get Started.....Input a character and press Enter: ";
  char a;
  std::cin >> a;
  while (cv::waitKey(1) != 27) {
    if (!web.readFrameImage(readFrame)) {
      return 0;
    }
    try {
      web.color2gray(readFrame, grayFrame);
      obj.init(readFrame, grayFrame);
      std::vector<cv::Rect> border;
      obj.objectDetect(border);
      std::vector<cv::Rect>::iterator it;  /// iterator used in for loop
      it = std::begin(border);
      for (; it != border.end(); ++it) {
        fig.plot(readFrame, (*it).x, (*it).y, (*it).width, (*it).height);
        fig.worldCord(readFrame);
      }
      cv::imshow("Detected Human", readFrame);
      usleep(15000);
    } catch (cv::Exception&) {
      std::cout << "\n\n\nDemo Video Ended!!!!\n";
      return 0;
    }
  }
  return 1;
}

