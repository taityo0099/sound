#pragma once
#include <string>
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//�~����


struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	// �R���X�g���N�^
	Voice(const std::string& fileName);

	// �ǂݍ���
	int Load(const std::string& fileName);


	// �Đ�
	void Play(const bool& loop = false);

	// ��~
	void Stop(void);

	// ���[�p�X�ݒ�
	void LowPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));

	// �n�C�p�X�ݒ�
	void HighPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));

	// �t�B���^���s
	std::vector<float> Filter(const std::vector<float>& data);

	// �f�X�g���N�^
	~Voice();


	//����
	float volume;

private:
	// �\�[�X�{�C�X����
	void CreateVoice(void);

	// �o�b�t�@�ɔg�`���悹��
	void Submit(void);

	// �g�`��S���ǂ݂��񂾂�����
	void CheckEnd(void);


	// �Q�ƃt�@�C����
	std::string name;

	// �ǂݍ��݈ʒu
	size_t read;

	// ���[�v�t���O
	bool loop;

	// �I���t���O
	bool end;

	// �\�[�X�{�C�X
	IXAudio2SourceVoice* voice;

	// �R�[���o�b�N
	std::unique_ptr<VoiceCallback>back;

	// �t�B���^�W��
	std::array<float, 3>a;
	// �t�B���^�W��
	std::array<float, 3>b;
	//�ߋ����̓f�[�^
	std::array<float, 2>input;
	//�ߋ��o�̓f�[�^
	std::array<float, 2>output;
};
