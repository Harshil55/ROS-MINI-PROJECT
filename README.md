

# ROS MINI-PROJECT

How to install the required dependencies :-
    
    Open the terminal and enter the following:
        $ sudo apt install ros-noetic-gazebo-ros-* ros-noetic-lms1xx
        $ cd ~/catkin_ws/src   
        $ git clone https://github.com/husky/husky.git
        $ cd ..
        $ rosdep install --from-path src --ignore-src  
        $ catkin build
        $ source devel/setup.bash

    Start the main launch file for the husky robot using:
        Roslaunch husky_gazebo husky_empty_world.launch

    The estimated location of the robot is provided by the Extended Kalman Filter output: it is published on /odometry/filtered.
        $ rostopic echo /odometry/filtered

=============================================================================================================================================
What your node does :-
    There are two main node play key role to move a husky in virtual environment.
    1. Publisher : my_robot publish the messages to subscriber and set initial position of a husky robot.
                   It is published to /twist_marker_server/cmd_vel.
    2. Subscriber : odom_graph is the subscriber which recieve the message from publisher and move the husky robot to desired position.
                    It is subscribed to /odometry/filtered

==============================================================================================================================================
How to use it :-

    we need to build our workspace using the catkin_make command in the workspace directory
        $ cd ~/ROS_Mini_Project
        $ catkin_make
    Bring up the husky simulation
        $ roslaunch husky_gazebo husky_empty_world.launch
    The final step is to source your setup.bash file in the workspace you have created. This allows ROS to find the packages that are contained in your workspace
        source ~/ros101/devel/setup.bash
    Now Start the node
        $ rosrun random_husky_driver random_driver
    Now we can check that our node publishing data or not 
        $ rostopic echo /twist_marker_server/cmd_vel
    Build the workspace by using the catkin_make function
        $ cd ~/catkin_ws
        $ catkin_make
    Launch the second node
        $ source ~/catkin_ws/devel/setup.bash
        $ roslaunch ROS_Mini_Project odom_graph_test.launch

    
