# This is the default target, which will be built when 
# you invoke make
.PHONY: all
all: ycsb_generator

# This rule tells make how to build hello from hello.cpp
ycsb_generator: ycsb_gen.cc
	g++ -o ycsb_gen ycsb_gen.cc
