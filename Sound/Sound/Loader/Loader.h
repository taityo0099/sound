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

	// �ێ��f�[�^
	struct Sound
	{
		//�T�E���h���
		snd::Info info;
		//�T�E���h�f�[�^
		std::shared_ptr<std::vector<float>>wave;
	};

public:
	// �ǂݍ���
	int Load(const std::string& fileName);

	// �T�E���h���擾
	snd::Info GetInfo(const std::string& fileName);

	// �T�E���h�f�[�^�擾
	std::shared_ptr<std::vector<float>> GetWave(const std::string& fileName);

	// 1��̏����f�[�^�擾
	unsigned int GetFream(const std::string& fileName);

private:
	// �R���X�g���N�^
	Loader();

	// �f�X�g���N�^
	~Loader();


	// �T�E���h
	std::unordered_map<std::string, Sound>sound;
};