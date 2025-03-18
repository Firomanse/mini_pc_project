#!/usr/bin/bash
rm mini_pc_project
rm -r build/*
cmake -B build
cd build
cmake --build .
mv mini_pc_project ../mini_pc_project
