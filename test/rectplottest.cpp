/**
 * @file rectplottest.cpp
 * @brief unit testing of RectPlot class
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

#include <gtest/gtest.h>
#include "rectplot.hpp"

TEST(RectPlotTest, testiplot) {
  RectPlot a;
  cv::Mat refImg1, refImg2, refImg3;
  refImg1 = cv::imread("../test/human01-01.png");
  EXPECT_DOUBLE_EQ(1, a.plot(refImg1, 10, 10, 10, 10));
  EXPECT_DOUBLE_EQ(0, a.plot(refImg2, 10, 10, 10, 10));
}

TEST(RectPlotTest, testiworldCord) {
  RectPlot a;
  cv::Mat refImg1, refImg2, refImg3;
  refImg1 = cv::imread("../test/human01-01.png");
  ASSERT_TRUE(a.plot(refImg1, 0, 0, 10, 10));
  EXPECT_DOUBLE_EQ(1, a.worldCord(refImg1));
  EXPECT_DOUBLE_EQ(0, a.worldCord(refImg2));
}
