#pragma once
<<<<<<< HEAD
=======
#include <string>
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//円周率

<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad

struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	//コンストラクタ
	Voice(const std::string& fileName);
	//デストラクタ
	~Voice();

	//読み込み
	int Load(const std::string& fileName);

	//再生
	void Play(const bool& loop = false);

	//停止
	void Stop(void);

<<<<<<< HEAD

private:
	//ソースボイス作成

	// デストラクタ
	~Voice();

	//音量
	float volume;

=======
	//音量
	float volume;

private:
	//ソースボイス生成
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	void CreateVoice(void);

	//バッファに波形を乗せる
	void Submit(void);

<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	//波形を全部読みこんだか判定
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
};