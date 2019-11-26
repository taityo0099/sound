#pragma once
#include <string>
<<<<<<< Updated upstream
#include <memory>

#define MPI 3.1415926536
=======
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//�~����

>>>>>>> Stashed changes

struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	//�R���X�g���N�^
	Voice(const std::string& fileName);
<<<<<<< Updated upstream
	//�f�X�g���N�^
	~Voice();
=======
>>>>>>> Stashed changes

	//�ǂݍ���
	int Load(const std::string& fileName);

	//�Đ�
	void Play(const bool& loop = false);

	//��~
	void Stop(void);

<<<<<<< Updated upstream
private:
	//�\�[�X�{�C�X�쐬
=======
	// �f�X�g���N�^
	~Voice();

	//����
	float volume;

private:
	//�\�[�X�{�C�X����
>>>>>>> Stashed changes
	void CreateVoice(void);

	//�o�b�t�@�ɔg�`���悹��
	void Submit(void);

<<<<<<< Updated upstream
	//�g�`��S���ǂݍ��񂾂�����
=======
	//�g�`��S���ǂ݂��񂾂�����
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
};