# Google Mock :: Extra Credit Assignment

[![Build Status](https://travis-ci.org/Pruthvi-Sanghavi/MidTermGroup-14.svg?branch=GMock_Extra_Credit)](https://travis-ci.org/Pruthvi-Sanghavi/MidTermGroup-14)
[![Coverage Status](https://coveralls.io/repos/github/Pruthvi-Sanghavi/MidTermGroup-14/badge.svg?branch=GMock_Extra_Credit)](https://coveralls.io/github/Pruthvi-Sanghavi/MidTermGroup-14?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## License Disclaimer
```
MIT License

Copyright (c) 2019 Pruthvikumar Sanghavi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
---

#### Installing OpenCV and related Dependancies
```
sudo apt-get update
 
sudo apt-get upgrade

sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
 
sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
 
sudo apt-get install libopencv-dev libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev

sudo apt-get install git

git clone https://github.com/opencv/opencv.git

cd opencv

mkdir build

cd build

cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH= ../ ../opencv_contrib/modules ../

make -j4

sudo make install

sudo ldconfig

sudo apt-get install python-opencv
```

Check if everything is done by running below command. A version should be displayed.
```
$ python
>>> import cv2
>>> print(cv2.__version__)
'''after version is printed, exit out of python to commoand line'''
>>> exit()
```

# Build

```
$ git clone -b GMock_Extra_Credit https://github.com/Pruthvi-Sanghavi/Human-Detection-Module.git
cd Human-Detection-Module
mkdir build
cd build
cmake ..
make

```
# Run Tests

```
cd Human-Detection-Module
cd build
./test/cpp-test

```

Cascade and Rectplot classes have been used for the Google Mock testing.


