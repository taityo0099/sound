#include "Loader.h"
#include "../WavFmt.h"


//�R���X�g���N�^
Loader::Loader()
{
}

// �f�X�g���N�^
Loader::~Loader()
{
}

<<<<<<< HEAD
// �ǂݍ���
int Loader::Load(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return 0;
	}

=======
//�ǂݍ���
int Loader::Load(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end());
	{
		return 0;
	}
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	return wav::Load(fileName, sound[fileName].wave, sound[fileName].info);
}

// �T�E���h���擾
snd::Info Loader::GetInfo(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].info;
	}
<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	return snd::Info();
}

// �T�E���h�f�[�^�擾
std::shared_ptr<std::vector<float>> Loader::GetWave(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
		return sound[fileName].wave;
	}
<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	return nullptr;
}

// 1��̏����f�[�^�擾
unsigned int Loader::GetFrame(const std::string & fileName)
{
	if (sound.find(fileName) != sound.end())
	{
<<<<<<< HEAD
=======
		//�؂�ǂ�0.01�b
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}

	return 0;
}

