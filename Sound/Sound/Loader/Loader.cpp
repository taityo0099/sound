#include "Loader.h"
#include "../WavFmt.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
Loader::~Loader()
{
}

// �ǂݍ���
int Loader::Load(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return 0;
	}

	return wav::Load(fileName, sound[fileName].wave, sound[fileName].info);
}

// �T�E���h���擾
snd::Info Loader::GetInfo(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].info;
	}

	return snd::Info();
}

// �T�E���h�f�[�^�擾
std::shared_ptr<std::vector<float>> Loader::GetWave(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].wave;
	}

	return nullptr;
}

// 1��̏����f�[�^�擾
unsigned int Loader::GetFream(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}

	return 0;
}
