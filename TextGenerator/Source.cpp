#pragma once
#include "Print.h"

/// these includes are used for navigational/Debug purposes and should not be executed.
//#include "Frankenstein.txt"
//#include "Dracula.txt"

/// All text documents used in this program during production were obtained 
/// Through use of the Gutenberg Project, which can be found here
// http://www.gutenberg.org

Print Output;

void main()
{
	Output.Run();

	std::cout << "" << std::endl;
	system("pause");
}