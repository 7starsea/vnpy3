#!/bin/bash

cmake_make(){
        cmake_source_dir=$1
        cmake_release_flag=$2
        cmake_debug_flag=$3

        cmake=`which cmake`
		if [ -z $cmake ]
		then 
			echo "cmake does not exist!"
			exit -1
		fi 
        if [ $cmake_release_flag == 1 ]
        then
                [ -d release ] || mkdir release
                cd release
                $cmake -DCMAKE_BUILD_TYPE=Release $cmake_source_dir
                make
                cd ..
        fi

        if [ $cmake_debug_flag == 2 ]
        then
                [ -d debug ] || mkdir debug
                cd debug
                $cmake -DCMAKE_BUILD_TYPE=Debug $cmake_source_dir
                make
                cd ..
        fi
}

debug_flag=0
release_flag=1
vnpy_api_xtp_dir=`pwd`
[ -d build ] || mkdir build
cd build
        cmake_make $vnpy_api_xtp_dir $release_flag $debug_flag
cd ..



