#pragma once

namespace sound
{
	struct  Info
	{
		//サンプリング周波数
		unsigned int sample;	//規格44.1kHz

		//量子化ビット数
		unsigned char bit;		//32bit 予定

		//チャンネル数
		unsigned char channel;	//2ch	予定

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