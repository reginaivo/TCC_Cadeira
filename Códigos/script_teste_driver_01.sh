#!/bin/bash
echo 0 > /sys/class/gpio/gpio26/value
cd /sys/devices/ocp.3/pwm_test_P8_13.13
echo 10000000 > duty
sleep 2
echo 9000000 > duty
sleep 2
echo 8000000 > duty
sleep 2
echo 7000000 > duty
sleep 2
echo 6000000 > duty
sleep 2
echo 5000000 > duty
sleep 2
echo 4000000 > duty
sleep 2
echo 3000000 > duty
sleep 2
echo 2000000 > duty
sleep 2
echo 1000000 > duty
sleep 2
echo 0000000 > duty
sleep 6
echo 1 > /sys/class/gpio/gpio48/value
echo 1000000 > duty 
sleep 2
echo 2000000 > duty
sleep 2
echo 3000000 > duty
sleep 2
echo 4000000 > duty
sleep 2
echo 5000000 > duty
sleep 2
echo 6000000 > duty
sleep 2
echo 7000000 > duty
sleep 2
echo 8000000 > duty
sleep 2
echo 9000000 > duty
sleep 2
echo 10000000 > duty
sleep 2
echo 0000000 > duty
exit 0
