#pragma once
#include "../Base/Singleton.h"

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio2 : public Singleton<XAudio2>
{
	//�V���O���g���ŕK�{
	friend Singleton<XAudio2>;

public:

	//�G���W���J�n
	void EngineStart(void);
	//�G���W����~
	void EngineStop(void);

	//�I�[�f�B�I�擾
	IXAudio2* GetAudio(void);

	//�}�X�^�����O�擾
	IXAudio2MasteringVoice* GetMastering(void) const;


private:

	//�R���X�g���N�^
	XAudio2();
	//�f�X�g���N�^
	~XAudio2();

	//�I�[�f�B�I����
	void CreateAudio(void);

	//�}�X�^�����O����
	void CreateMastering(void);

	//�I�[�f�B�I
	IXAudio2* audio;

	//�}�X�^�����O
	IXAudio2MasteringVoice* mastering;

};