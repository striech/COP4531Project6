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

void WriteFile(CharType * data, size_t length, std::string filename);

int main(int argc, char* argv[])
{
  /* Make sure command line arguments are ok. */
  if(argc < 3)
  {
    std::cout << " ** command line arguments:\n"
	      << "     1: input filename (required)\n"
        << "     2: output base filename (required)\n"
	      << " ** try again\n";
    return 0;
  }

  /* Make sure we can open the specified input file of strings to sort. */
  char* infile = argv[1];
  std::ifstream instream(infile);
  if(instream.fail())
  {
    std::cout << " ** cannot open file " << infile << " for read"
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
  std::cout << "LSB sort." << std::endl;
  std::cout << "time (seconds): " << instant.Get_seconds() << std::endl;
  std::cout << "time (useconds): " << instant.Get_useconds() << std::endl;
  std::cout << "comparisons: " << lts.Count() << std::endl;
  std::cout << std::endl;

  /* Write sorted results. */
  WriteFile(data, source_data.Size(), std::string(argv[2]) + std::string(".LSB"));

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
  std::cout << "MSB sort." << std::endl;
  std::cout << "time (seconds): " << instant.Get_seconds() << std::endl;
  std::cout << "time (useconds): " << instant.Get_useconds() << std::endl;
  std::cout << "comparisons: " << lts.Count() << std::endl;
  std::cout << std::endl;

  /* Write sorted results. */
  WriteFile(data, source_data.Size(), std::string(argv[2]) + std::string(".MSB"));

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
  std::cout << "3WQS sort." << std::endl;
  std::cout << "time (seconds): " << instant.Get_seconds() << std::endl;
  std::cout << "time (useconds): " << instant.Get_useconds() << std::endl;
  std::cout << "comparisons: " << lts.Count() << std::endl;
  std::cout << std::endl;

  /* Write sorted results. */
  WriteFile(data, source_data.Size(), std::string(argv[2]) + std::string(".3WQS"));

  return 0;
}

void WriteFile(CharType * data, size_t length, std::string filename)
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