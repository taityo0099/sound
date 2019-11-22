#include "Loader.h"







//読み込み
int Loader::Load(const std::string & fileName)
{
	return 0;
}

//サウンド情報取得
sound::Info Loader::GetInfo(const std::string & fileName)
{
	return sound::Info();
}

//サウンドデータ取得
std::shared_ptr<Vfloat> Loader::GetWave(const std::string & fileName)
{
	return std::shared_ptr<Vfloat>();
}

//1回の処理データ取得
unsigned int Loader::GetFrame(const std::string & fileName)
{
	return 0;
}

//コンストラクタ
Loader::Loader()
{
}

//デストラクタ
Loader::~Loader()
{
}
