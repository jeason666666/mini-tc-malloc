
INC_PATH := ./include
SRC_PATH := ./src
UTIL_PATH := ./utils

SRCS := $(wildcard $(SRC_PATH)/*.cc)
INCS := $(wildcard $(INC_PATH)/*.h)

CFLAGS := -std=c++17

test:test_bench.cc $(SRCS) $(UTILS)
	g++ $^ $(CFLAGS) -I$(INC_PATH) $(UTIL_PATH) -o $@ 

main:main.cc $(SRCS) $(UTILS)
	g++ $^ $(CFLAGS) -I$(INC_PATH) $(UTIL_PATH) -o $@

# get the row count
count: 
	wc $(INCS) $(SRCS) $(UTILS) -l

clean:
	rm -rf test
