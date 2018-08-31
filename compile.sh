#!/bin/bash
rm RootLouncher
c++ $(root-config --cflags) $(root-config --glibs) -o RootLouncher RootLouncher.cc
chmod +x RootLouncher
