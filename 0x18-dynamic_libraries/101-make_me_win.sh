#!/bin/bash
wget -P /tmp https://github.com/ShahdAmmar/alx-low_level_programming/blob/d037137143233695f63155e1ceb120a59ef74df8/0x18-dynamic_libraries/libgiga.so
export LD_RELOAD=/tmp/libgiga.so
