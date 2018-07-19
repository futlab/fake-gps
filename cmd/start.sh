#!/bin/bash
rosrun mavros mavsys mode -c GUIDED
rosrun mavros mavsafety arm

rosrun mavros mavcmd takeoff 0.1 0 0 0 20

