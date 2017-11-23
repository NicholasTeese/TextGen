#pragma once
#include <fstream>
#include <sstream>

class Checker
{
public:

	std::wstring firstLastwordUsed = L"****";
	std::wstring secondLastwordUsed = L"***";
	std::wstring thirdLastwordUsed = L"**";
	std::wstring fourthLastwordUsed = L"*";

	Checker();
	bool CheckRecent(std::wstring currentword);
	std::wstring Update(std::wstring Outcome);
};