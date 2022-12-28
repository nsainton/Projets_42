#!/bin/bash
#This script intends to compile the libft in the dir passed as an argument
#It then moved the archive file in the current directory
#use as follows : /path_to_script /path_to_archive archive_name
make -C $1 && mv $1/$2 . && make clean -C $1
