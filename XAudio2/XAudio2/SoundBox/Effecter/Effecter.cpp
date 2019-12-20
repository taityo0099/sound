#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Effecter.h"
#include "../Effect/Effect.h"
#include "../Voice/Voice.h"





Effecter::Effecter() : threadEnd(false)
{
	if (th.joinable() == false)
	{
		std::lock_guard<std::mutex>lock(mtx);
		th = std::thread(&Effecter::Stream, this);

	}
}

Effecter::~Effecter()
{
	threadEnd = true;
	if (th.joinable() == true)
	{
		th.join();
	}
}

//�񓯊��p�̊֐�
void Effecter::Stream()
{
	while (!threadEnd)
	{
		printf("�t�B���^�[\n");
	}
}


//------------------------
//int main()
//{
//	int num = 10;
//
//	std::thread th;
//
//	if (th.joinable() == false)
//	{
//		th = std::thread([&](const int& num)->void
//		{
//			while (true)
//			{
//
//			}
//		}, std::ref(num));
//	}
//
//	if (th.joinable() == true)
//	{
//		th.join();
//	}
//}
//------------------------

