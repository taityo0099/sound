#pragma once
#include "Info.h"
#include <string>
#include <vector>
#include <memory>

namespace wav
{
	int Load(const std::string& fileName,
		std::shared_ptr<std::vector<float>>& wave, sound::Info& info)
	{
		FILE* fp = nullptr;
		if (fopen_s(&fp, fileName.c_str(), "rb")!= 0)
		{
			return -1;
		}

		//riffチャンク
		char chunckID[4];
		fread(&chunckID[0], sizeof(chunckID), 1, fp);

		unsigned long chunckSize = 0;
		fread(&chunckSize, sizeof(chunckSize), 1, fp);

		char formType[4];
		fread(&formType[0], sizeof(formType), 1, fp);


		//fmtチャンク
		fread(&chunckID[0], sizeof(chunckID), 1, fp);

		fread(&chunckSize, sizeof(chunckSize), 1, fp);

		short waveFormatType = 0;
		fread(&waveFormatType, sizeof(waveFormatType), 1, fp);

		short channel = 0;
		fread(&channel, sizeof(channel), 1, fp);

		unsigned long sampePerSec = 0;
		fread(&sampePerSec, sizeof(sampePerSec), 1, fp);

		unsigned long bytesPerSec = 0;
		fread(&bytesPerSec, sizeof(bytesPerSec), 1, fp);

		short blockSize = 0;
		fread(&blockSize, sizeof(blockSize), 1, fp);

		short bitesPerSample = 0;
		fread(&bitesPerSample, sizeof(bitesPerSample), 1, fp);

		std::string id;
		unsigned long size = 0;
		do
		{
			fseek(fp, size, SEEK_CUR);
			fread(&chunckID[0], sizeof(chunckID), 1, fp);
			id.assign(&chunckID[0], sizeof(chunckID));
			fread(&size, sizeof(size), 1, fp);
		} while (id != "data");
		
		info.sample = sampePerSec;
		info.bit = bitesPerSample;
		info.channel = channel;
		wave = std::make_shared<std::vector<float>>(size / (info.bit / 8));
		
		for (float& i : *wave)
		{
			short tmp = 0;
			fread(&tmp, sizeof(tmp), 1, fp);
			i = float(tmp) / float(0xffff / 2);
		}

		fclose(fp);
		return 0;
	}
}