#!/bin/bash 

find . -type f -name "*.tmp" -mtime -3 -ok rm {} \;
