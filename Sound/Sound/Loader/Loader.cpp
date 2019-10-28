#include "Loader.h"
#include "../WavFmt.h"

// コンストラクタ
Loader::Loader()
{
	/*sound["A.wav"].info = snd::Info(44100, 16, 2);
	sound["A.wav"].wave = std::make_shared<std::vector<float>>((sound["A.wav"].info.sample * sound["A.wav"].info.channel));
	for (size_t i = 0; i < sound["A.wav"].wave->size(); i += sound["A.wav"].info.channel)
	{
		sound["A.wav"].wave->at(i) = std::sin(2.0f * std::acos(-1.0f) * 220.0f * i / sound["A.wav"].info.sample);
		sound["A.wav"].wave->at(i + 1) = sound["A.wav"].wave->at(i);
	}*/
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
unsigned int Loader::GetFream(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}

	return 0;
}
