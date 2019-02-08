# OpenCV-4-Setup-On-Ubuntu-18.04-LTS-With-Python-C++
OpenCV 4 Alpha setup commands on Ubuntu 18.04 LTS for Python and C++.

Note: The rows starting with the '#' character is the comment line that gives you information. Other rows is command and you should write them on your computer.

### Update & Upgrade
```
sudo apt-get update
sudo apt-get upgrade
```

### Install Compiler
```
sudo apt-get install build-essential
```

### Required Dependency
```
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

### Optional Packages
```
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```

### Clone git repository
```
cd ~
mkdir OpenCV
cd OpenCV
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

### Python Setup
```
wget https://bootstrap.pypa.io/get-pip.py
sudo python3 get-pip.py
sudo pip install virtualenv virtualenvwrapper
sudo rm -rf ~/get-pip.py ~/.cache/pip
echo -e "\n# virtualenv and virtualenvwrapper" >> ~/.bashrc
echo "export WORKON_HOME=$HOME/.virtualenvs" >> ~/.bashrc
echo "export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3" >> ~/.bashrc
echo "source /usr/local/bin/virtualenvwrapper.sh" >> ~/.bashrc
source ~/.bashrc
mkvirtualenv cv -p python3
workon cv
pip install numpy
```
*Press Ctrl+D to exit from workon cv*


### Create build folder
```
workon cv
cd opencv
mkdir build
cd build
```

### Configure CMake
```
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D INSTALL_PYTHON_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D OPENCV_PYTHON3_INSTALL_PATH = <path to python in your computer> #If you do not know, you can delete this line.
        -D WITH_QT=ON \
        -D WITH_OPENGL=ON \
        -D OPENCV_EXTRA_MODULES_PATH=~/OpenCV/opencv_contrib/modules \
        -D BUILD_EXAMPLES=ON ..
``` 
 
### Build & Install
```
make -j8 # runs 8 jobs in parallel(8 Threads), Do "-j4" if your computer has 2 cores 4 threads.
sudo make install
```

### Python & OpenCV Configure
```
cd /usr/local/lib/python3.6/site-packages/cv2/python-3.6/cv2.so
mv /usr/local/lib/python3.6/site-packages/cv2/python-3.6/cv2.so cv2.so
cd ~/.virtualenvs/cv/lib/python3.6/site-packages/
ln -s /usr/local/lib/python3.6/site-packages/cv2/python-3.6/cv2.so cv2.so
```
**My screenshoot**

![bashrc](https://user-images.githubusercontent.com/27829773/52468975-4d668380-2b9b-11e9-818e-e71af1d5b49f.png)

### Test1 (Optional) For Python Development
```
cd ~
workon cv
python

# Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
# [GCC 8.2.0] on linux
# Type "help", "copyright", "credits" or "license" for more information.
# >>> 
import cv2
cv2.__version__
# '4.0.1-dev'
```
*It is OK. Press Ctrl+D to exit python.*

**My screenshoot**

![pythonsurum](https://user-images.githubusercontent.com/27829773/52469122-a209fe80-2b9b-11e9-9e7e-9760e40bd40b.png)


### Test2 (Optional) For C++ Development
*First download Source.cpp and lena.png from here, then create a project folder like FirstProject.*
```
mkdir FirstProject
cd FirstProject
```
*Move Source.cpp and lena.jpg to FirstProject folder, then create CMakeList.txt and write them to it:*
```
cmake_minimum_required(VERSION 3.1)
project( FirstProject )
find_package( OpenCV REQUIRED )
add_executable( FirstProject Source.cpp )
target_link_libraries( FirstProject ${OpenCV_LIBS} )
```

*Then;*
```
mkdir build && cd build
cmake ..
make
./FirstProject
```

*You should see lena.png if all of them is OK.
It is OK.*

**My screenshoot**

![cppexample](https://user-images.githubusercontent.com/27829773/52469121-a1716800-2b9b-11e9-8ee9-30b2116990ec.png)


### Test3 (Optional)
```
cd ~/OpenCV/opencv/build/bin
./opencv_test_core
```
*Running test, it may take long time, if you want to cancel, Press Ctrl+C.
Result would be like below. It is OK.*
```
#[----------] Global test environment tear-down
#[==========] 10799 tests from 228 test cases ran. (304554 ms total)
#[  PASSED  ] 10798 tests.
#[  FAILED  ] 1 test, listed below:
#[  FAILED  ] Core_globbing.accuracy
#
# 1 FAILED TEST
#  YOU HAVE 10 DISABLED TESTS
```

## Finish
**You can start coding C++ or Python**
