#pragma once

namespace sound
{
	struct  Info
	{
		//�T���v�����O���g��
		unsigned int sample;	//�K�i44.1kHz

		//�ʎq���r�b�g��
		unsigned char bit;		//32bit �\��

		//�`�����l����
		unsigned char channel;	//2ch	�\��

		Info()
		{
			sample = bit = channel = 0;
		}

		Info(const unsigned int s, const unsigned int& b, const unsigned char& c)
		{
			sample = s;
			bit = b;
			channel = c;
		}

	};
}