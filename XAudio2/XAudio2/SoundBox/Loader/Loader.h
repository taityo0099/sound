#pragma once
#include "../Base/Singleton.h"
#include "../Info.h"
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>


using Vfloat = std::vector<float>;

class Loader : public Singleton<Loader>
{
	friend Singleton<Loader>;

	struct  Sound
	{
		//�T�E���h���
		sound::Info info;

		//�T�E���h�f�[�^
		std::shared_ptr<Vfloat>wave;
	};

public:
	//�ǂݍ���
	int Load(const std::string& fileName);
	
	//�T�E���h���擾
	sound::Info GetInfo(const std::string& fileName);

	//�T�E���h�f�[�^�擾
	std::shared_ptr<Vfloat> GetWave(const std::string& fileName);

	//1��̏����f�[�^�擾
	unsigned int GetFrame(const std::string& fileName);

private:
	//�R���X�g���N�^
	Loader();
	//�f�X�g���N�^
	~Loader();

	std::unordered_map<std::string, Sound>sound;
};