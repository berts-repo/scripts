// fileOutputEx.cpp
// by Bin "Crystal" Peng. CS225
//
// demonstrate file output: output data to a file.
// - if the file already exists, will erase its old content
// - if the file doesn't already exist, will create a file with that name

#include <iostream> // std::cerr
                    // standard output stream for error, http://www.cplusplus.com/reference/iostream/cerr/
#include <fstream>  // std::ofstream
                    // 1. include <fstream>

int main()
{
  std::ofstream outFile;  // 2. declare ofstream var

  outFile.open("result.txt"); // 3. open file
  if (outFile.fail())         // !!! 3.5 check if successful
  {
    std::cerr << "can't create output file. Abort. \n"; // report to cerr
    return 1;                                           // and terminate now
  }

  for (int i = 0; i < 10; i++)  // 4. output operations
    outFile << i << std::endl;

  outFile.close();              // 5. close file

  return 0;
} // end main