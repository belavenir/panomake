

# opencv
FIND_PACKAGE (OpenCV REQUIRED)


ADD_EXECUTABLE (depthverify depthverify.cpp)
TARGET_LINK_LIBRARIES (depthverify ${OpenCV_LIBS})

