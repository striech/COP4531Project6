#include <iostream>
#include <fstream>
#include <compare_spy.h>
#include <compare.h>
#include "stringsort.h"
#include "genalg.h"
#include "vector.h"
#include <timer.h>
#include <string>

/* EXTENDED ASCII */
typedef uint8_t CharType;
const size_t logR = 8;
const size_t R = 256;

/* DECIMAL
typedef enum {0,1,2,3,4,5,6,7,8,9} CharType;
const size_t logR = 4;
const size_t R = 10;
*/

void WriteSortedResultsFile(CharType * data, size_t length, std::string filename);

int main(int argc, char* argv[])
{
  /* Make sure command line arguments are ok. */
  if(argc < 3)
  {
    std::cout << " ** command line arguments:" << std::endl
	      << "     1: input filename (required)" << std::endl
        << "     2: output filename (required) [This will output a file with the timing results," << std::endl
        << "                                    and also files with the sorted results, with extensions" << std::endl
        << "                                    .LSB, .MSB, and .3WQS." << std::endl
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

  /* Create the StringSort class with the specified alphabet. */
  StringSorts<CharType> string_sorts(R, logR);

  /* The less than spy used to determine how many comparisons were done as part
     of the sort. */
  fsu::LessThanSpy<CharType> lts;

  /* The timer information. */
  fsu::Instant instant;
  fsu::Timer timer;

  /* Get the source data strings from the input file. */
  fsu::Vector<CharType> source_data;
  uint32_t item;
  while(instream >> item)
  {
    source_data.PushBack(item);
  }
  CharType * data = new CharType[source_data.Size()];

  /* Close instream. */
  instream.close();

  /******************** LSB Sort ********************/

  /* Populate the data array to be sorted. */
  fsu::g_copy(source_data.Begin(), source_data.End(), data);

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the LSB sort. */
  timer.SplitReset();
  string_sorts.Sort_LSB(data, source_data.Size(), lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "LSB sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(data, source_data.Size(), outfile + std::string(".LSB"));

  /******************** MSB Sort ********************/

  /* Populate the data array to be sorted. */
  fsu::g_copy(source_data.Begin(), source_data.End(), data);

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the MSB sort. */
  timer.SplitReset();
  string_sorts.Sort_MSB(data, source_data.Size(), lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "MSB sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(data, source_data.Size(), outfile + std::string(".MSB"));

  /******************** 3WQS Sort ********************/

  /* Populate the data array to be sorted. */
  fsu::g_copy(source_data.Begin(), source_data.End(), data);

  /* Reset comparison count. */
  lts.Reset();
  
  /* Perform and time the 3WQS sort. */
  timer.SplitReset();
  string_sorts.Sort_3WQS(data, source_data.Size(), lts);
  instant = timer.SplitTime();

  /* Output pertinent data. */
  outstream << "3WQS sort." << std::endl;
  outstream << "time (seconds): " << instant.Get_seconds() << std::endl;
  outstream << "time (useconds): " << instant.Get_useconds() << std::endl;
  outstream << "comparisons: " << lts.Count() << std::endl;
  outstream << std::endl;

  /* Write sorted results. */
  WriteSortedResultsFile(data, source_data.Size(), outfile + std::string(".3WQS"));

  /* Close file. */
  outstream.close();

  return 0;
}

void WriteSortedResultsFile(CharType * data, size_t length, std::string filename)
{
  std::ofstream outstream(filename);

  if (outstream.fail())
  {
    std::cout << " ** cannot open file " << filename << " for write\n"
        << " ** try again\n";
    return;
  }

  for(size_t i = 0; i < length; i++)
  {
    outstream << data[i] << std::endl;
  }

  outstream.close();
}