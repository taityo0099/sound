#pragma once
<<<<<<< HEAD
=======
#include <string>
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//�~����

<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad

struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	//�R���X�g���N�^
	Voice(const std::string& fileName);
	//�f�X�g���N�^
	~Voice();

	//�ǂݍ���
	int Load(const std::string& fileName);

	//�Đ�
	void Play(const bool& loop = false);

	//��~
	void Stop(void);

<<<<<<< HEAD

private:
	//�\�[�X�{�C�X�쐬

	// �f�X�g���N�^
	~Voice();

	//����
	float volume;

=======
	//����
	float volume;

private:
	//�\�[�X�{�C�X����
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	void CreateVoice(void);

	//�o�b�t�@�ɔg�`���悹��
	void Submit(void);

<<<<<<< HEAD

=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	//�g�`��S���ǂ݂��񂾂�����
	void CheckEnd(void);

	//�Q�ƃt�@�C����
	std::string name;

	//�ǂݍ��݈ʒu
	size_t read;

	//���[�v�t���O
	bool loop;

	//�I���t���O
	bool end;

	//�\�[�X�{�C�X
	IXAudio2SourceVoice* voice;

	//�R�[���o�b�N
	std::unique_ptr<VoiceCallback>back;
};