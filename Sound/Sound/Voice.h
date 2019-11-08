#pragma once
#include <string>

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

	// �f�X�g���N�^
	~Voice();

	float volume;		//

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

	//�t�B���^�[�W��
	float a0, a1, a2, b0, b1, b2;

	//�o�b�t�@�W��
	float out1, out2;
	float in1, in2;
	

	// ���[�v�t���O
	bool loop;

	// �I���t���O
	bool end;

	// �\�[�X�{�C�X
	IXAudio2SourceVoice* voice;

	// �R�[���o�b�N
	std::unique_ptr<VoiceCallback>back;
};
