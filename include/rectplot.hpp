/**
 * @file rectplot.hpp
 * @brief plot a rectangular envelop over a detected object
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

#ifndef INCLUDE_RECTPLOT_HPP_
#define INCLUDE_RECTPLOT_HPP_

#include <Eigen/Dense>
#include <iomanip>
#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cascade.hpp>

class RectPlot : public Cascade{
 private:
  int px;  ///< top left pixel x-coordinate of bounding rectangle
  int py;  ///< top left pixel y-coordinate of bounding rectangle
  int pw;  ///< pixel width of bounding rectangle
  int ph;  ///< pixel height of bounding rectangle

 public:
  int loadCascade(const std::string &filePath);
  /**
   * plot a rectangular envelop over a detected object
   * @param cv::Mat&
   * @param x int
   * @param y int
   * @param w int
   * @param h int
   * @return int
   */
  int plot(cv::Mat&, int x, int y, int w, int h);

  /**
   * convert image coordinates to world coordinate system
   * @param cv::Mat&
   * @return int
   */
  int worldCord(cv::Mat&);
};
#endif  // INCLUDE_RECTPLOT_HPP_
