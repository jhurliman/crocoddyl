# Visualizing Humanoid Walking

## Introduction

This document provides detailed instructions on how to visualize a humanoid walking using the provided examples in the repository. The examples use different display methods such as `GepettoDisplay`, `MeshcatDisplay`, and `RvizDisplay`.

## Setting Up the Environment

To visualize the humanoid walking, you need to set up the environment by installing the necessary dependencies. Follow the steps below to set up the environment:

1. Install the required dependencies using `conda`:
   ```bash
   conda install -c conda-forge crocoddyl example-robot-data gepetto-viewer-corba meshcat-python
   ```

2. If you are using macOS M1, you can run the examples in a Docker container. First, install Docker from [Docker's official website](https://www.docker.com/products/docker-desktop). Then, follow the instructions below to set up the Docker container:
   ```bash
   docker pull robotpkg/robotpkg:latest
   docker run -it --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix robotpkg/robotpkg:latest
   ```

3. Clone the repository and navigate to the `examples` directory:
   ```bash
   git clone https://github.com/jhurliman/crocoddyl.git
   cd crocoddyl/examples
   ```

## Running the Examples

The repository contains several examples of visualizing humanoid walking using different display methods. The examples are implemented in Python scripts located in the `examples` directory. Follow the steps below to run the provided examples:

1. Running the `bipedal_walk_fwddyn.py` example:
   ```bash
   python bipedal_walk_fwddyn.py display plot
   ```

2. Running the `bipedal_walk_invdyn.py` example:
   ```bash
   python bipedal_walk_invdyn.py display plot
   ```

## Visualizing the Results

The examples use different display methods to visualize the results. Follow the instructions below to visualize the results using the provided display methods:

1. Gepetto Viewer:
   - The `GepettoDisplay` class is used to visualize the results in the Gepetto Viewer. Make sure you have the `gepetto-viewer-corba` package installed.
   - The Gepetto Viewer will automatically open and display the humanoid walking motion.

2. Meshcat:
   - The `MeshcatDisplay` class is used to visualize the results in Meshcat. Make sure you have the `meshcat-python` package installed.
   - The Meshcat Viewer will automatically open in your default web browser and display the humanoid walking motion.

3. Rviz:
   - The `RvizDisplay` class is used to visualize the results in Rviz. Make sure you have the `whole_body_state_rviz_plugin`, `crocoddyl_msgs`, and `urdf_parser_py` packages installed.
   - Launch Rviz and load the provided configuration file to visualize the humanoid walking motion.
