/**
 * @file rectplot.cpp
 * @brief plot a rectangular envelop over a detected object by class method definition
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

#include "rectplot.hpp"

int RectPlot::plot(cv::Mat &img, int x, int y, int w, int h) {
  px = x;
  py = y;
  pw = w;
  ph = h;
  if (img.total()) {
    cv::rectangle(img, cv::Size(px, py), cv::Size(px + pw, py + ph),
                  cv::Scalar(255, 0, 255), 4, 8, 0);
    return 1;
  }
  return 0;
}

int RectPlot::worldCord(cv::Mat &img) {
  double f = 28.0;  ///< effective focal length of robot's vision system
  /**
   * As depth is not considered i.e. z=0, it is assumed that the
   * object is detected at a distance of 8ft (also 1ft = 304mm)
   * From lens formula, magnification can be found as:
   * |m| = |f|/(|u|+|f|)
   */
  double mag;
  mag = f / ((304 * 8) + f);
  if (img.total()) {
    /**
     * 4X4 Homogeneous transformation matrix for world frame of type
     * Eigen::matrix (double)
     * it is a combination of rotation and translation matrix
     */
    Eigen::MatrixXd homog(4, 4);
    homog(0, 0) = 1;
    homog(0, 1) = 0;
    homog(0, 2) = 0;
    homog(0, 3) = -(img.cols) / 2;
    homog(1, 0) = 0;
    homog(1, 1) = -1;
    homog(1, 2) = 0;
    homog(1, 3) = (img.rows) / 2;
    homog(2, 0) = 0;
    homog(2, 1) = 0;
    homog(2, 2) = -1;
    homog(2, 3) = 0;
    homog(3, 0) = 0;
    homog(3, 1) = 0;
    homog(3, 2) = 0;
    homog(3, 3) = 1;
    /**
     * Bottom Left and Top right coordinates in homogeneous form
     * of bounding rectangle with z=0, as column vectors of a
     * Eigen::matrix (double) of size 4X2
     */
    Eigen::MatrixXd imgPt(4, 2);
    imgPt(0, 0) = px;
    imgPt(1, 0) = py + ph;
    imgPt(2, 0) = 0;
    imgPt(3, 0) = 1;
    imgPt(0, 1) = px + pw;
    imgPt(1, 1) = py;
    imgPt(2, 1) = 0;
    imgPt(3, 1) = 1;
    /**
     * Calculating Bottom Left and Top right coordinates of bounding
     * rectangle in world frame
     */
    Eigen::MatrixXd objPt(4, 2);
    objPt = homog * imgPt;
    objPt *= mag;
    double btx = objPt(0, 0);
    double bty = objPt(1, 0);
    double tpx = objPt(0, 1);
    double tpy = objPt(1, 1);
    /**
     * Printing world frame coordinates on the image
     */
    std::string btcord;  /// bottom left coordinates as type  string
    std::string tpcord;  /// top right coordinates as type  string
    btcord = "(" + (std::to_string(btx)) + "' " + (std::to_string(bty)) + ")";
    tpcord = "(" + (std::to_string(tpx)) + ", " + (std::to_string(tpy)) + ")";
    cv::putText(img, btcord, cv::Point(px, py + ph), cv::FONT_HERSHEY_DUPLEX, 1,
                1);
    cv::putText(img, tpcord, cv::Point(px + pw, py), cv::FONT_HERSHEY_DUPLEX, 1,
                1);
    /**
     * Printing world frame coordinates on the output window
     */
    std::cout << std::setprecision(3);
    std::cout << "\nBottom Left\t\t\tTop Right\nx= " << objPt(0, 0);
    std::cout << "   y= " << objPt(0, 1) << "\t\tx= " << objPt(1, 0);
    std::cout << "   y= " << objPt(1, 1) << "\n";
    return 1;
  }
  return 0;
}
