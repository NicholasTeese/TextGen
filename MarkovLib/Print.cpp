#include "Print.h"
#include <iostream>

Print::Print()
{
}

Print::~Print()
{
}

void Print::Run()
{
	std::string Title;
	std::wstring currentWord;
	int TotalWords;// = 100;
	int wordsOutputted = 0;

	std::cout << "Please input the name of the file you wish to read in from." << std::endl;
	std::cout << "File must be a text document, file name cannot include spaces and must be case sensitive." << std::endl;
	//std::cout << "File name cannot include spaces and must be case sensitive" << std::endl;
	std::cin >> Title;
	Title.append(".txt");
	std::cout << "Reading file, please wait." << std::endl;
	TI.Stream(Title);
	std::cout << "Fearile reading completed." << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Input amount of words in desired text. Please use" << std::endl;
	std::cout << "only a whole number as anything else will not work." << std::endl;
	std::cin >> TotalWords;
	std::cout << "" << std::endl;

	
	std::cout << "Input word for sentence to begin from, avoid" << std::endl;
	std::cout << "punctuation and capitalization for best results." << std::endl;
	std::wcin >> currentWord;
	std::cout << "" << std::endl;

	std::wcout << currentWord << " ";

	for (int i = 0; i < TotalWords; ++i)
	{
		// initialise scoring for random
		int fitnessScore = 0;
		auto found = TI.markovMap.find(currentWord);
		WordCount& countList = TI.markovMap[currentWord];
		WordCount::iterator OutcomeList;

		for (OutcomeList = countList.begin(); OutcomeList != countList.end(); ++OutcomeList)
		{
			fitnessScore += OutcomeList->second;
		}
		int fitcheck = RandValue.Seed(fitnessScore);
		for (OutcomeList = countList.begin(); OutcomeList != countList.end(); ++OutcomeList)
		{
			if (fitcheck <= OutcomeList->second)
			{
				if (Check.CheckRecent(OutcomeList->first) && std::next(OutcomeList) != countList.end())
				{

				}
				else
				{
					if (OutcomeList != countList.end())
					{
						//OutcomeList++;
						std::wstring NextWord = Check.Update(OutcomeList->first);
						std::wcout << NextWord << " ";
						wordsOutputted++;
						currentWord = NextWord;
						break;
					}
					else
					{
						std::cout << "" << std::endl;
						std::cout << "Error - End reached/Map no longer traversable.";
					}
				}
			}
			else
			{
				fitcheck = fitcheck - OutcomeList->second;
			}
		}
	}
	if (wordsOutputted < TotalWords)
	{
		std::cout << "" << std::endl;
		std::wcout << "--- Total words not reached, perhaps try a different word." << std::endl;
		
		Run();
	}
}