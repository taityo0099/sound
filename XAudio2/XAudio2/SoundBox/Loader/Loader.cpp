#include "Loader.h"







//�ǂݍ���
int Loader::Load(const std::string & fileName)
{
	return 0;
}

//�T�E���h���擾
sound::Info Loader::GetInfo(const std::string & fileName)
{
	return sound::Info();
}

//�T�E���h�f�[�^�擾
std::shared_ptr<Vfloat> Loader::GetWave(const std::string & fileName)
{
	return std::shared_ptr<Vfloat>();
}

//1��̏����f�[�^�擾
unsigned int Loader::GetFrame(const std::string & fileName)
{
	return 0;
}

//�R���X�g���N�^
Loader::Loader()
{
}

//�f�X�g���N�^
Loader::~Loader()
{
}
