## In file pano_series

1 use testarea topology lat/lon to get a rawpano positon and yaw, all raw data in raw
2 use unique to get a unique line from rawpano.csv as pano_pose.csv (since there are some repetitive pano)
3 use pano_pose as a reference in the google map
4. delete avenue with vegetation
5. Final panopose as posepano.csv 
6. use the python script streetview_gt.py to download all panorama and depth in the test area
7. notice our special way to register depth map

## pcl_visualizer

Illustrate 3D point of an example of street view panorama

## visualize_misaligne

The coarse matching bewteen google street view and its depth map

## rectiliner
To rectilinear the panorama in a proper way

## verify_depth
verify the depth registering way is corecct

