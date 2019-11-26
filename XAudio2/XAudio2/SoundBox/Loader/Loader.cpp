#include "Loader.h"
#include "../WavFmt.h"


//コンストラクタ
Loader::Loader()
{
}

//デストラクタ
Loader::~Loader()
{
}
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes

//読み込み
int Loader::Load(const std::string & fileName)
{
<<<<<<< Updated upstream
	if (sound.find(fileName) != sound.end());
	{
		return 0;
	}

=======
	if (sound.find(fileName) != sound.end())
	{
		return 0;
	}
>>>>>>> Stashed changes
	return wav::Load(fileName, sound[fileName].wave, sound[fileName].info);
}

//サウンド情報取得
snd::Info Loader::GetInfo(const std::string & fileName)
{
<<<<<<< Updated upstream
	if (sound.find(fileName) != sound.end());
	{
		return snd::Info();
	}

=======
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].info;
	}
>>>>>>> Stashed changes
	return snd::Info();
}

//サウンドデータ取得
std::shared_ptr<Vfloat> Loader::GetWave(const std::string & fileName)
{
<<<<<<< Updated upstream
	if (sound.find(fileName) != sound.end());
	{
		return sound[fileName].wave;
	}

=======
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].wave;
	}
>>>>>>> Stashed changes
	return nullptr;
}

//1回の処理データ取得
unsigned int Loader::GetFrame(const std::string & fileName)
{
<<<<<<< Updated upstream
	if (sound.find(fileName) != sound.end())
	{
		//切り良く0.01秒
=======
	if(sound.find(fileName) != sound.end())
	{ 
>>>>>>> Stashed changes
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}
	return 0;
}


