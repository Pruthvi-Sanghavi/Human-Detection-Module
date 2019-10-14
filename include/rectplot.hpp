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

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class RectPlot {
 private:
  int grpLoc;/**< variable to hold an x,y,w,h parameters of detected object as a number xywh */

 public:
  /**
   * plot a rectangular envelop over a detected object
   * @param img cv::Mat&
   * @param x int
   * @param y int
   * @param w int
   * @param h int
   * @return grpLoc int
   */
  int plot(cv::Mat &img, int x, int y, int w, int h);
};

#endif /* INCLUDE_RECTPLOT_HPP_ */
