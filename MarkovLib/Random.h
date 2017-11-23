#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <random>

class Random
{
public:

	Random()
	{

	}

	int Seed(int maxvalue)
	{
		static std::random_device rd;
		static std::default_random_engine engine(rd());
		if (maxvalue == 0)
		{
			return 0;
		}
		else
		{
			std::uniform_int_distribution<int> dist(0, maxvalue - 1);


			return dist(engine);
		}
	}
};