#include "Loader.h"
#include "../WavFmt.h"


//�R���X�g���N�^
Loader::Loader()
{
}

//�f�X�g���N�^
Loader::~Loader()
{
}
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes

//�ǂݍ���
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

//�T�E���h���擾
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

//�T�E���h�f�[�^�擾
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

//1��̏����f�[�^�擾
unsigned int Loader::GetFrame(const std::string & fileName)
{
<<<<<<< Updated upstream
	if (sound.find(fileName) != sound.end())
	{
		//�؂�ǂ�0.01�b
=======
	if(sound.find(fileName) != sound.end())
	{ 
>>>>>>> Stashed changes
		return (sound[fileName].info.sample * sound[fileName].info.channel) / 100;
	}
	return 0;
}


