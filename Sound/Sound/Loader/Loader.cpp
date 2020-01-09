#include "Loader.h"
#include "../WavFmt.h"

// コンストラクタ
Loader::Loader()
{
	
}

// デストラクタ
Loader::~Loader()
{
}

// 読み込み
int Loader::Load(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return 0;
	}

	return wav::Load(fileName, sound[fileName].wave, sound[fileName].info);
}

// サウンド情報取得
snd::Info Loader::GetInfo(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].info;
	}

	return snd::Info();
}

// サウンドデータ取得
std::shared_ptr<std::vector<float>> Loader::GetWave(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].wave;
	}

	return nullptr;
}

// 1回の処理データ取得
unsigned int Loader::GetFrame(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}

	return 0;
}