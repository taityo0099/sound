#pragma once
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>

#define MPI 3.1415926536			//�~����



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

	//����
	float volume;
private:
	// �X���b�h
	std::thread th;

	//�~���[�e�b�N�X
	std::mutex mtx;

	//�\�[�X�{�C�X����
	void CreateVoice(void);

	//�o�b�t�@�ɔg�`���悹��
	void Submit(void);


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

//class Volume
//{
//public:
//	Volume();
//	~Volume();
//
//private:
//	//����
//	float volume;
//};
