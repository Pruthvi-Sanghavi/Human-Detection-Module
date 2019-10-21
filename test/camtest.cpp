/**
 * @file camTest.cpp
 * @brief unit testing of Cam class
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
#include "cam.hpp"

TEST(CamTest, testreadVideo) {
  Cam a;
  cv::Mat refImg;
  std::string demo = "../test/test1.mp4";
  EXPECT_DOUBLE_EQ(2, a.readVideo(demo));
}

TEST(CamTest, testreadVideo1) {
  Cam a;
  cv::Mat refImg;
  EXPECT_DOUBLE_EQ(0, a.readVideo("../xyz/est1.mp4"));
  EXPECT_DOUBLE_EQ(3, a.readFrameImage(refImg));
}

TEST(CamTest, testreadFrameImage) {
  Cam a;
  std::string d = "../test/test1.mp4";
  cv::Mat refImg1, refImg2;
  EXPECT_DOUBLE_EQ(2, a.readVideo(d));
  EXPECT_DOUBLE_EQ(4, a.readFrameImage(refImg1));
  EXPECT_DOUBLE_EQ(static_cast<int>(refImg1.total()),
                   a.color2gray(refImg1, refImg2));
}

TEST(CamTest, testcolor2gray) {
  Cam a;
  std::string d = "../test/test1.mp4";
  cv::Mat refImg;
  ASSERT_TRUE(a.readVideo(d));
  EXPECT_DOUBLE_EQ(4, a.readFrameImage(refImg));
}
