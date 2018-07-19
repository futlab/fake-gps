#!/bin/bash
rostopic pub -r 10 /mavros/setpoint_velocity/cmd_vel_unstamped geometry_msgs/Twist  '{linear:  {x: -0.5, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.0}}'

