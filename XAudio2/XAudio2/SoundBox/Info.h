#pragma once

namespace snd
{
	struct  Info
	{
		//�T���v�����O���g��
		unsigned int sample;
		//�ʎq���r�b�g��
		unsigned char bit;
		//�`�����l����
		unsigned char channel;

		//�S������
		Info()
		{
			sample = bit = channel = 0;
		}

		Info(const unsigned int& s, const unsigned char& b, const unsigned char& c)
		{
			sample = s;
			bit = b;
			channel = c;
		}

		Info(const Info& info)
		{
			(*this) = info;
		}
		void operator= (const Info& info)
		{
			sample	= info.sample;
			bit		= info.bit;
			channel = info.channel;
		}
	};
}