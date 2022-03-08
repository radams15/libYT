#!/bin/sh

java -XshowSettings:properties -version 2>&1 > /dev/null | grep 'java.home' 
echo $(dirname $(readlink $(which javac)))/java_home
