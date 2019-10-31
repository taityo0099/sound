#pragma once
#include "../Base/Singleton.h"
#include "../Info.h"
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Loader : 
	public Singleton<Loader>
{
	friend Singleton<Loader>;

	// 保持データ
	struct Sound
	{
		//サウンド情報
		snd::Info info;
		//サウンドデータ
		std::shared_ptr<std::vector<float>>wave;
	};

public:
	// 読み込み
	int Load(const std::string& fileName);

	// サウンド情報取得
	snd::Info GetInfo(const std::string& fileName);

	// サウンドデータ取得
	std::shared_ptr<std::vector<float>> GetWave(const std::string& fileName);

	// 1回の処理データ取得
	unsigned int GetFrame(const std::string& fileName);

private:
	// コンストラクタ
	Loader();

	// デストラクタ
	~Loader();


	// サウンド
	std::unordered_map<std::string, Sound>sound;
};