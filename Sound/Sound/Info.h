#pragma once

namespace snd
{
	struct Info
	{
		//サンプリング周波数
		unsigned int sample;
		//量子化ビット数
		unsigned char bit;
		//チャンネル数
		unsigned char channel;
	};
}
