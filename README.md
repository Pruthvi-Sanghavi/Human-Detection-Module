# Human Obstacle Detector Using OpenCV Haar Cascade

[![Build Status](https://travis-ci.com/Pruthvi-Sanghavi/Human-Detection-Module.svg?branch=master)](https://travis-ci.com/Pruthvi-Sanghavi/Human-Detection-Module)[![Coverage Status](https://coveralls.io/repos/github/Pruthvi-Sanghavi/MidTermGroup-14/badge.svg?branch=master)](https://coveralls.io/github/Pruthvi-Sanghavi/MidTermGroup-14?branch=master)
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

## Overview
The development exercise deals with the design and development of a perception module for the new product line of Acme Robotics – warehouse management robots (WMR), for carrying the goods from one place to another in a workspace shared by humans. Hence it is desired that WMRs should not collide with anyone. This problem can be solved by implementing our Human Detector(HD) module. Our HD module works on the principle of supervised learning by utilizing Haar Cascade Classifier for object detection (humans in our case). HD module will use an on-board camera provided in the WMR. It will process the captured images (frame by frame) to detect the presence of any human. The module will return the coordinates of the detected human(s) in the 2D-coordinate frame corresponding to the field of view of the robot. This data will contain bottom left (x,y), bottom right (x,y) and height of the enveloping rectangular box around the detected humans. This data can then be processed by other modules developed by Acme Robotics like-real time path planning, to modify the travel path of the WMR to avoid any possibility of a collision.

<p align="center">
<img src="https://github.com/Pruthvi-Sanghavi/Human-Detection-Module/blob/master/additional_files/demo.gif" height="400px">
</p>

## Agile Iterative Process

[Team Review Notes](https://docs.google.com/document/d/1l4MobMQTboG7WJ2R91XRQfdRSrPovTTvhYkaVo5h1yo/edit?usp=sharing) 

[AIP Spreadsheet](https://drive.google.com/file/d/1GTG-HFxleuQxyrf_1kyI84y_j7N_5Z9h/view?usp=sharing) 


## Approach
The presence of humans in a webcam feed is detected by the use of Haar Cascade Classifier from the OpenCV library, which is covered under the 3-clause BSD License. Cascade functionality can be used to detect objects by importing a trained model XML file. These XML files can be of a pre-trained model or can be generated using command prompt utility of the OpenCV. For this project our team created a new model from scratch. We will thus first higlight the steps to generate a new cascade model.

### First Things First
#### Installing OpenCV and related Dependancies
```
$ sudo apt-get update
 
$ sudo apt-get upgrade

$ sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
 
$ sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
 
$ sudo apt-get install libopencv-dev libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev

$ sudo apt-get install git

$ git clone https://github.com/opencv/opencv.git

$ cd opencv

$ mkdir build

$ cd build

$ cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH= ../ ../opencv_contrib/modules ../

$ make -j4

$ sudo make install

$ sudo ldconfig

$ sudo apt-get install python-opencv
```
Check if everything is done by running below command. A version should be displayed.
```
$ python
>>> import cv2
>>> print(cv2.__version__)
'''after version is printed, exit out of python to commoand line'''
>>> exit()
```

### How to train a cascade model
For any deep learning based training and model generation the most important thing is to have a dataset of POSITIVE and NEGATIVE instances. In this case the postive instances refer to a set of images which contain human object(s) and negative instances refer to a set of images which do not contain humans. Positive dataset is taken from [Horses or Humans](https://www.kaggle.com/sanikamal/horses-or-humans-dataset) and negative dataset is taken from [INRIA Person Dataset](http://pascal.inrialpes.fr/data/human/).

Follow the below steps-
1) Create a directory <_model_> and cd into it.
2) Download the images in two different folders namely, pos and neg.
3) Label the positive images and create a info.lst file in the <pos> directory with entiries for each image to specify the object position: <_filename_> <no_of_instances> <left_top_x_coordinate> <left_top_y_coordinate> <_width_> <_height_>
<p align="center">
<img src="https://github.com/Pruthvi-Sanghavi/MidTermGroup-14/blob/master/additional_files/info_list.png">
</p>

4) In the <_model_> directory create a background text file "bgNeg.txt" with information of path of each negatives instances <filepath_filename>
<p align="center">
<img src="https://github.com/Pruthvi-Sanghavi/MidTermGroup-14/blob/master/additional_files/bgNeg.png">
</p>

5) From the <model> run the below command in terminal to generate a vector file. Lets name that file as "positives.vec". Here -w and -h are the training model parameters (ensure that the object in positive instances have similar width/height ratio for better performance)

```
opencv_createsamples -info pos/info.lst -num 527 -w 36 -h 110 -vec positives.vec
```

6) mkdir data in <_model_>

7) Lastly, tain your Haar Cascade Model from the <_model_> directory.
```
opencv_traincascade -data data -vec positives.vec -bg bgNeg.txt -numPos 500-numNeg 800 -numStages 10 -w 36 -h 110
```

Training is a time demanding and computationally expensive process. Larger the number of instances, traininig stages, -w and -h parametrs, the more time it takes. We used 527 positive instances with w=36 and h=110 over 10 stages, and it took 16hrs (approx.) for one model to train.

# Dependencies 

``` 
Eigen 3.3.7

```
It has been provided in the repository.

# Known issues/bugs

cpplint error in header guards and so was required to added full path as a string for the guard.

# How to build

```
$ cd Human-Detection-Module
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
```
# How to run demo

```
$ cd Human-Detection-Module
$ cd build
$ ./app/humanDetect
```
# How to run tests

```
$ cd Human-Detection-Module
$ cd build
$ ./test/cpp-test
```
# Installing Doxygen and generating doxygen documentation

```
$ git clone https://github.com/doxygen/doxygen.git
$ cd doxygen
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make
$ sudo make install
$ cd
$ doxygen -g dconfig
$ cd MidTermGroup-14
```
The above commands are used to generate doxygen documentation. This file for our project has been provided in the repository as DoxyConfig.

# Function that gives the world coordinates
```
A homogeneous matrix trasformation and lens formula are used to convert from the image cordinate to the world cordinate.
The image origin is at the top left corner with positive x axis pointing towards right, and positive y axis pointing towards bottom.While the world coordinate (view point of robot) is set with origin at the center of view and positive x axis towards right and positive y axis pointing upwards.

This give the roational matrix as
r= [ 1 0 0
     0 -1 0
     0 0 -1]

Translation (from world origin to image origin) = [ -Image width /2
						     Image height /2
							0];

Homogenenous matrix from image to world frame is :

h= [ R T
     0 1};

World Cordinate = H* Image Cordinate;

(with z assumed to be 0) 
```


