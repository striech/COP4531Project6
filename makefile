#
# makefile for proj6
#

LIB     = /home/courses/cop4531p/fall14
CPP     = $(LIB)/cpp
TCPP    = $(LIB)/tcpp
AREA51  = $(LIB)/area51
PROJ    = .
INCPATH = -I$(PROJ) -I$(TCPP) -I$(CPP)

CC   = g++47 -std=c++11 -Wall -Wextra

all: sortspy_unicode16.x sortspy_extendedascii.x sortspy_uppercase.x sortspy_decimal.x sortspy_dna.x sortspy_binary.x

sortspy_unicode16.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/unicode16/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/unicode16 $^ -o $@

sortspy_extended_ascii.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/extended_ascii/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/extended_ascii $^ -o $@

sortspy_uppercase.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/uppercase/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/uppercase $^ -o $@

sortspy_decimal.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/decimal/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/decimal $^ -o $@

sortspy_dna.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/dna/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/dna $^ -o $@

sortspy_binary.x: $(PROJ)/sortspy.cpp $(TCPP)/timer.cpp $(PROJ)/stringsort.h $(PROJ)/sortspy_types/binary/stringsort_type.h
	$(CC) $(INCPATH) -I$(PROJ)/sortspy_types/binary $^ -o $@

.PHONY: clean
clean:
	rm -rf *.x *.o testing/results