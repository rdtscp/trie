#!/bin/bash

cd build
xargs rm < install_manifest.txt
cd ..
rm -rf ./build/