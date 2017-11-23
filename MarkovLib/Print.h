#pragma once

#include "TakeInput.h"
#include "Random.h"
#include "Checker.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

class TakeInput;
class Random;
class Checker;

class Print
{
public:
	Print();
	~Print();

	TakeInput TI;
	Random RandValue;
	Checker Check;

	using WordCount = std::map<std::wstring, int>;
	using WordDictionary = std::map<std::wstring, WordCount>;

	WordDictionary markovMap;

	void Run();
};