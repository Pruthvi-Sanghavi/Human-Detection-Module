# Human Obstacle Detector Using OpenCV Haar Cascade

[![Build Status](https://travis-ci.org/Pruthvi-Sanghavi/Mid-Term-group-14.svg?branch=master)](https://travis-ci.org/Pruthvi-Sanghavi/Mid-Term-group-14)
[![Coverage Status](https://coveralls.io/repos/github/Pruthvi-Sanghavi/Mid-Term-group-14/badge.svg?branch=master)](https://coveralls.io/github/Pruthvi-Sanghavi/Mid-Term-group-14?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

---

## Overview
Acme Robotics is developing a new series of robots to add to its portfolio– warehouse management robots (WMR). WMR's main function would be to carry goods from one place to another in a warehouse. One of the issue with such a market is: not all warehouses work on 100% automation, this means that WMRs would often be working in a workspace shared by humans. This raises the issue of safety for the humans working in the warehouse. As a safety counter-measure it is desired that WMRs should not collide with any human.

To achieve the goal of coallision avoidance of WMRs with humans, Acme Robotics reached out to our team to provide a ready to install solution. Our team is developing a Human Detector (HD) module which will identenfy the presence of any human in the vicinity of the robot (in its field of view) and provide the coordinates of the detected human in the robot's coordinate system. These coordinates can then be used by other modules of the WMR developed by Acme Robotics, like-real time path planning module, to modify the travel path of the WMR to avoid any possibility of a collision.

Our HD module works on the principles of supervised learning by utilizing Haar Cascade Classifier for object detection (humans in our case) from the OpenCV library. OpenCV library is covered under the 3-clause BSD License. HD module will use an on-board camera provided in the WMR to capture videos. But for our testing purposes, we will make use of a webcam of a laptop. HD module will process the captured images (frame by frame) to detect the presence of any human, and then return their coordinates in the 2D-coordinate frame corresponding to the field of view of the robot. This data will contain bottom left (x,y),  bottom right (x,y) and height of the enveloping rectangular box around the detected humans.

<p align="center">
<img src="https://github.com/varunasthana92/hello-world/blob/master/additional_files/expected_behaviour.png">
Expected behavior of the HD Module (Images from: Machine Learning by Andrew Ng, Coursera)
</p>

## AIP

[Team Review Notes](https://docs.google.com/document/d/1l4MobMQTboG7WJ2R91XRQfdRSrPovTTvhYkaVo5h1yo/edit?usp=sharing) 

[AIP Spreadsheet](https://drive.google.com/file/d/1GTG-HFxleuQxyrf_1kyI84y_j7N_5Z9h/view?usp=sharing) 

### Team Details
1) Varun Asthana: A graduate student in the University of Maryland pursuing a Master's Degree in Robotics. Completed his Bachelor's degree in Mechanical Engineering in 2014 and has a work experience of 5 years with an automobile manufacturing firm in India.

2) Pruthvikumar Sanghavi: A graduate student in the University of Maryland pursuing a Master's Degree in Robotics


## Approach
The presence of humans in a webcam feed is detected by the use of Haar Cascade Classifier from the OpenCV library. Cascade functionality can be used to detect objects by importing a trained model XML file. These XML files can be of a pre-trained model or can be generated using command prompt utility of the OpenCV. For this project our team created a new model from scratch using pre-acquired training dataset. We will thus first higlight the steps to generate a new cascade model. Before we can proceed with the model generation, we first need to install OpenCV and related dependancies.

#### Installing OpenCV and related dependancies
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

### How to create and train a Haar Cascade model
For any deep learning based training and model generation the most important thing is to have a dataset of POSITIVE and NEGATIVE instances. In this case the postive instances refer to a set of images which contain human object(s) and negative instances refer to a set of images which do not contain humans. Positive dataset is taken from [Horses or Humans](https://www.kaggle.com/sanikamal/horses-or-humans-dataset) and negative dataset is taken from [INRIA Person Dataset](http://pascal.inrialpes.fr/data/human/).

Follow the below steps-
1) Create a directory <_model_> and cd into it.
2) Download the images in two different folders namely, pos and neg.
3) Label the positive images and create a info.lst file in the <pos> directory with entiries for each image to specify the object position: <_filename_> <no_of_instances> <left_top_x_coordinate> <left_top_y_coordinate> <_width_> <_height_>
<p align="center">
<img src="https://github.com/varunasthana92/hello-world/blob/master/additional_files/info_list.png">
</p>

4) In the <_model_> directory create a background text file "bgNeg.txt" with information of path of each negatives instances <filepath_filename>
<p align="center">
<img src="https://github.com/varunasthana92/hello-world/blob/master/additional_files/bgNeg.png">
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
$ cd MidTermGroup_14
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
```
# How to run demo

```
$ cd MidTermGroup-14
$ cd build
$ ./app/humanDetect
```
# How to run tests

```
$ cd MidTermGroup-4
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
As depth is not considered i.e. z=0, it is assumed that the
    object is detected at a distance of 8ft (also 1ft = 304mm)
    From lens formula, magnification can be found as:
    |m| = |f|/(|u|+|f|)
4X4 Homogeneous transformation matrix for world frame of type
    Eigen::matrix (double)
    it is a combination of rotation and translation matrix

