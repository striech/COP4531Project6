#
# makefile for proj6
#

LIB     = /home/courses/cop4531p/fall14
CPP     = $(LIB)/cpp
TCPP    = $(LIB)/tcpp
AREA51  = $(LIB)/area51
PROJ    = .
INCPATH = -I$(PROJ) -I$(TCPP) -I$(CPP)

CC   = g++ -std=c++11 -Wall -Wextra

all: sortspy.x

sortspy.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h
	$(CC) $(INCPATH) $^ -o $@

.PHONY: clean
clean:
	rm -rf *.x *.o