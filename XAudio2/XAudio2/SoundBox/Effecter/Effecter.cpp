#include "Effecter.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "../Voice/Voice.h"



Filter::Filter() : threadEnd(false)
{
	if (th.joinable() == false)
	{
		th = std::thread(&Filter::Stream, this);
	}
}
Filter::~Filter()
{
	threadEnd = true;
	if (th.joinable() == true)
	{
		th.join();
	}
}

//�񓯊��p�̊֐�
void Filter::Stream()
{
	while (!threadEnd)
	{
		printf("�t�B���^�[\n");
	}
}


//------------------------
int main()
{
	int num = 10;

	std::thread th;

	if (th.joinable() == false)
	{
		th = std::thread([&](const int& num)->void
		{
			while (true)
			{

			}
		}, std::ref(num));
	}

	if (th.joinable() == true)
	{
		th.join();
	}
}
//------------------------

