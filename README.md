A minimal opencv+cuda test

`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
`./test_cv_cuda`  

If everything goes OK, you'll see some CUDA info, plus get the file _out.png_ in the build directory,
which looks just like _out\_reference.png_.

Needs NVidia Drivers + CUDA + OpenCV built with CUDA, if OpenCV is in a custom location, configure with:

`cmake -DOpen_CV_DIR=<dir> ..`  

where `<dir>` is the full path to the OpenCV directory (subdirectory with *.cmake files)
