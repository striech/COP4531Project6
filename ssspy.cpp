#include <iostream>
#include <fstream>
#include <compare_spy.h>
#include <compare.h>
#include "lsd.h"
#include "msd.h"
#include "qs3w.h"
#include "genalg.h"
#include "vector.h"
#include <timer.h>
#include <string>
#include <sstream>
#include <iterator>
#include <assert.h>
#include "stringsort_type.h"

/* UNICODE16
typedef uint16_t CharType;
const size_t logR = 16;
const size_t R = 65536;
*/

/* EXTENDED ASCII
typedef uint8_t CharType;
const size_t logR = 8;
const size_t R = 256;
*/

/* UPPERCASE
typedef uint8_t CharType;
const size_t logR = 5;
const size_t R = 26;
*/

/* DECIMAL
typedef uint8_t CharType;
const size_t logR = 4;
const size_t R = 10;
*/

/* DNA
typedef uint8_t CharType;
const size_t logR = 2;
const size_t R = 4;
*/

/* BINARY
typedef uint8_t CharType;
const size_t logR = 1;
const size_t R = 2;
*/

void WriteSortedResultsFile(fsu::Vector< fsu::Vector<CharType> > & data, std::string filename);

int main(int argc, char* argv[])
{
  /* Make sure command line arguments are ok. */
  if(argc < 3)
  {
    std::cout << " ** command line arguments:" << std::endl
	      << "     1: input filename (required)" << std::endl
        << "     2: output filename (required) [This will output a file with the timing results," << std::endl
        << "                                    and also files with the sorted results, with extensions" << std::endl
        << "                                    .LSD, .MSD, and .3WQS." << std::endl
	      << " ** try again" << std::endl;
    return 0;
  }

  /* Make sure we can open the specified input file of strings to sort. */
  std::string infile = argv[1];
  std::ifstream instream(infile);
  if(instream.fail())
  {
    std::cout << " ** cannot open file " << infile << " for read"
         << std::endl << " ** try again" << std::endl;
    return 0;
  }

  /* Make sure we can open the specified output file. */
  std::string outfile = argv[2];
  std::ofstream outstream(outfile);
  if(outstream.fail())
  {
    std::cout << " ** cannot open file " << outstream << " for write"
         << std::endl << " ** try again" << std::endl;
    return 0;
  }

  /* The less than spy used to determine how many comparisons were done as part
     of the sort. */
  fsu::LessThanSpy<CharType> lts;

  /* The timer information. */
  fsu::Instant instant;
  fsu::Timer timer;

  /* Get the source data strings from the input file. */
  fsu::Vector< fsu::Vector<CharType> > source_strings;
  std::string line;
  while(getline(instream, line))
  {
    size_t item;
    fsu::Vector<CharType> characters;

    std::istringstream is(line);
    while(is >> item)
    {
      /* Make sure inputs look valid. */
      assert(item < R);

      characters.PushBack(item);
    }

    source_strings.PushBack(characters);
  }

  /* Close instream. */
  instream.close();

  /******************** LSD Sort ********************/

  /* Create the LSD class with the specified alphabet. */
  LSD<CharType> lsd(logR, R);

  /* Populate the data array to be sorted. */
  fsu::Vector< fsu::Vector<CharType> > lsd_data = source_strings;

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the LSD sort. */
  timer.SplitReset();
  lsd.Sort(lsd_data, lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "LSD sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(lsd_data, outfile + std::string(".LSD"));

  /******************** MSD Sort ********************/

  /* Create the MSD class with the specified alphabet. */
  MSD<CharType> msd(logR, R);

  /* Populate the data array to be sorted. */
  fsu::Vector< fsu::Vector<CharType> > msd_data = source_strings;

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the MSD sort. */
  timer.SplitReset();
  msd.Sort(msd_data, lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "MSD sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(msd_data, outfile + std::string(".MSD"));

  /******************** 3WQS Sort ********************/

  /* Create the MSD class with the specified alphabet. */
  QS3W<CharType> qs3w(logR, R);

  /* Populate the data array to be sorted. */
  fsu::Vector< fsu::Vector<CharType> > qs3w_data = source_strings;

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the 3WQS sort. */
  timer.SplitReset();
  qs3w.Sort(qs3w_data, lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "3WQS sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(qs3w_data, outfile + std::string(".3WQS"));

  /* Close file. */
  outstream.close();

  return 0;
}

void WriteSortedResultsFile(fsu::Vector< fsu::Vector<CharType> > & data, std::string filename)
{
  std::ofstream outstream(filename);

  if (outstream.fail())
  {
    std::cout << " ** cannot open file " << filename << " for write\n"
        << " ** try again\n";
    return;
  }

  for(size_t i = 0; i < data.Size(); i++)
  {
    outstream << (size_t)data[i][0];

    for(size_t j = 1; j < data[i].Size(); j++)
    {
      outstream << ' ';
      outstream << (size_t)data[i][j];
    }

    outstream << std::endl;
  }

  outstream.close();
}