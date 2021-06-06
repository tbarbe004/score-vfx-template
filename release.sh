#!/bin/bash
rm -rf release
mkdir -p release

cp -rf MyVfx *.{hpp,cpp,txt,json} LICENSE release/

mv release score-addon-my-vfx
7z a score-addon-my-vfx.zip score-addon-my-vfx
