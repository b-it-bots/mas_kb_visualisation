# rviz_3d_object_visualizer

A package containing functionalities for for visualizing 3D object models on RViz. 

It consists of i) an RViz panel plugin that loads 3D object meshes and lists them on the panel, and ii) a node that handles reading a MongoDB database to obtain and update the necessary object information. The panel enables selectively visualizing individual objects (e.g. bottle_1, person_2, etc.) or groups of objects (for e.g. bottles, chairs, etc.).

The `rviz_3d_object_visualizer` has been tested on ROS Kinetic and Ubuntu 16.04.


<!-- TODO: add demo video -->


## Installation

The package can be installed by cloning this repository and building:
```
git clone https://github.com/AhmedFaisal95/rviz_3d_object_visualizer.git
```
```
catkin build rviz_3d_object_visualizer
```


## Usage

The `rviz_3d_object_visualizer` can be started ny running the launch file:
```
roslaunch rviz_3d_object_visualizer rviz_3d_object_visualizer.launch
```

On RViz, the panel can be added from the "Panels" tab: ```Panels -> Add New Panel -> ObjectVisualizationManager```.


### Adding New 3D Models
<!-- TODO: describe instructions for adding object models -->


## Documentation

### Architecture

<!-- TODO: UML diagram -->



### RViz Mesh Scene Graph

![scene](docs/images/SceneGraph.svg)


## Maintainers

`rviz_3d_object_visualizer` is developed and maintained by [Ahmed Faisal Abdelrahman](https://github.com/AhmedFaisal95) and [Sushant Vijay Chavan](https://github.com/Sushant-Chavan).
