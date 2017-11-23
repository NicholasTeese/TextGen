#include "Checker.h"
#include <fstream>
#include <sstream>

Checker::Checker()
{

}

bool Checker::CheckRecent(std::wstring currentword)
{
	bool RecentlyUsed;
	if (currentword != firstLastwordUsed
		&& currentword != secondLastwordUsed
		&& currentword != thirdLastwordUsed
		&& currentword != fourthLastwordUsed)
	{
		RecentlyUsed = false;
	}
	else
	{
		RecentlyUsed = true;
	}
	return RecentlyUsed;	
}

std::wstring Checker::Update(std::wstring Outcome)
{
	std::wstring NextWord = Outcome;
	fourthLastwordUsed = thirdLastwordUsed;
	thirdLastwordUsed = secondLastwordUsed;
	secondLastwordUsed = firstLastwordUsed;
	firstLastwordUsed = NextWord;
	return NextWord;	
}
