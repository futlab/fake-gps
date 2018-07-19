#!/bin/bash
rostopic pub /mavros/hil/gps mavros_msgs/HilGPS '{fix_type: 3, geo: {latitude: 60, longitude: 60, altitude: 2} }'

