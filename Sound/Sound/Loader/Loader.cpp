#include "Loader.h"
#include "../WavFmt.h"

// �R���X�g���N�^
Loader::Loader()
{
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
