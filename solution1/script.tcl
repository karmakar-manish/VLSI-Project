############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project vlsiProject
set_top check_best_model
add_files vlsiProject/check_best_model.c
add_files vlsiProject/check_best_model.h
add_files -tb vlsiProject/check_best_model_test_suite.c
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./vlsiProject/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
