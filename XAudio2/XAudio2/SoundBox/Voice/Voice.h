#pragma once
#include <string>
<<<<<<< Updated upstream
#include <memory>

#define MPI 3.1415926536
=======
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//円周率

>>>>>>> Stashed changes

struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	//コンストラクタ
	Voice(const std::string& fileName);
<<<<<<< Updated upstream
	//デストラクタ
	~Voice();
=======
>>>>>>> Stashed changes

	//読み込み
	int Load(const std::string& fileName);

	//再生
	void Play(const bool& loop = false);

	//停止
	void Stop(void);

<<<<<<< Updated upstream
private:
	//ソースボイス作成
=======
	// デストラクタ
	~Voice();

	//音量
	float volume;

private:
	//ソースボイス生成
>>>>>>> Stashed changes
	void CreateVoice(void);

	//バッファに波形を乗せる
	void Submit(void);

<<<<<<< Updated upstream
	//波形を全部読み込んだか判定
=======
	//波形を全部読みこんだか判定
>>>>>>> Stashed changes
	void CheckEnd(void);

	//参照ファイル名
	std::string name;

	//読み込み位置
	size_t read;

	//ループフラグ
	bool loop;

	//終了フラグ
	bool end;

	//ソースボイス
	IXAudio2SourceVoice* voice;

	//コールバック
	std::unique_ptr<VoiceCallback>back;
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
};