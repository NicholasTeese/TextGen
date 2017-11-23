
#include "TakeInput.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

TakeInput::TakeInput()
{
	
}

TakeInput::~TakeInput()
{

}

void TakeInput::Stream(std::string filename)
{
	fs.open(filename, std::ios_base::in);

	if (fs.is_open())
	{
		while (!fs.fail())
		{
			wchar_t temp[80]{ 0 };
			fs.getline(temp, 79);
			// Set getline to be 80 characters long.

			// http://stackoverflow.com/questions/18318980/taking-input-of-a-string-word-by-word
			std::wistringstream iss(temp);

			// While program still taking input
			while (iss >> currentword)
			{
				// make every character lowercase
				transform(currentword.begin(), currentword.end(), currentword.begin(), ::tolower);

				AddToMarkovMap(prevword, currentword);

				prevword = currentword;
			}
		}
		fs.close();
	}
}

void TakeInput::AddToMarkovMap(std::wstring currentWord, std::wstring nextWord)
{
	markovMap[currentWord][nextWord]++;
}