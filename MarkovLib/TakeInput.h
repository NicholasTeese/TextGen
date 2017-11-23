#pragma once

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

class TakeInput
{
public:
	TakeInput();
	~TakeInput();

	std::wfstream fs;
	std::wstring currentword;
	std::wstring pairedword;
	std::wstring prevword;
	
	using WordCount = std::map<std::wstring, int>;
	using WordDictionary = std::map<std::wstring, WordCount>;
	
	WordDictionary markovMap;
	
	void Stream(std::string filename);
	void AddToMarkovMap(std::wstring currentWord, std::wstring nextWord);
};

