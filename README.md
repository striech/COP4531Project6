# COP4531Project6

## Overview

This is the FSU COP4531 Project 6 code repository.

### Folders

#### Top Level

At the top level are the files that are required to be submitted. This includes the ssspy.cpp file, as well as the lsb.h, msb.h, and qs3w.h files. ssspy.cpp implements the testing and timing of the various sort algorithms, lsb.h is the class implementation of the LSB sort, msb.h is the class implementation of the MSB sort, and qs3w.h is the class implementation of the QS3W sort.

#### sortspy_types

These are header files for the different alphabets of the ssspy.x program.

#### testing

The testing folder contains files that ssspy.x uses to test the performance of the different sorting algorithm, and also tests the correctness of the sorting algorithms.

## Building

The program should build with 'make'. This produces the following version of the ssspy.x executables:
  * unicode16 - 65536 characters
  * extended_ascii - 256 characters
  * uppercase - 26 characters
  * decimal - 10 characters
  * dna - 4 characters
  * binary - 2 characters

## Testing

In the testing folder, there is a run.sh shell script. This shell script runs the testing to generate timing information and ensure that the sorts are implemented correctly. It requires the executables to built.

The shell script uses data in the testing/data/ folder as inputs to the ssspy.x program. For each of the versions of the ssspy.x program that is created (unicode16, extended_ascii, etc.), the following input files are run through the ssspy.x program. The results, including the timing information, and the sorted results produced from the different sorting algorithms, are written to files. The timing information needs to be analyzed manually, but the run.sh shell script does a diff of the sorted results versus the expected results, and the user will receive a notification if there are any sorted results that are not correct. These results are placed into the testing/results folder.
  * random_10000 - A file with 10000 random strings of the given type (unicode16, extended_ascii, etc.)
  * sorted_10000 - A file with 10000 strings, sorted, of the given type (unicode16, extended_ascii, etc.)
  * reversed_10000 - A file with 10000 strings, reversed, of the given type (unicode16, extended_ascii, etc.)
  * duplicate_10000 - A file with 10000 strings, all duplicates, of the given type (unicode16, extended_ascii, etc.)