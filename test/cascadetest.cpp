/**
 * @file cascadetest.cpp
 * @brief unit testing of Cascade class
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
#include <gmock/gmock.h>
#include "cam.hpp"
#include "cascade.hpp"


TEST(CascadeTest, testinit) {
  Cascade a;
  cv::Mat refImg1, refImg2, refImg3;
  refImg1 = cv::imread("../test/human01-01.png");
  refImg2 = cv::imread("../test/human01-01g.png");
  EXPECT_DOUBLE_EQ(1, a.init(refImg1, refImg2));
  refImg3 = cv::imread("../test/dog_1g.png");
  ASSERT_FALSE(a.init(refImg1, refImg3));
}

TEST(CascadeTest, testloadCascade) {
  Cascade a;
  std::string path1 = "../test/humanDetectCascade.xml";
  EXPECT_DOUBLE_EQ(1, a.loadCascade(path1));
  path1 = "../xyz/a.xml";
  ASSERT_FALSE(a.loadCascade(path1));
}

TEST(CascadeTest, testobjectDetect) {
  Cascade a;
  cv::Mat img1, img2;
  std::vector<cv::Rect> border;
  img1 = cv::imread("../test/objdet1.JPG");
  img2 = cv::imread("../test/objdet1g.JPG");
  std::string path1 = "../test/humanDetectCascade.xml";
  ASSERT_TRUE(a.loadCascade(path1));
  ASSERT_TRUE(a.init(img1, img2));
  EXPECT_LE(2, a.objectDetect(border));
}
