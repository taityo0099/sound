#pragma once
#include "../Base/Singleton.h"

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio2 :
	public Singleton<XAudio2>
{
	friend Singleton<XAudio2>;
public:
	// �G���W���J�n
	void EngineStart(void);

	// �G���W����~
	void EngineStop(void);

	// �I�[�f�B�I�擾
	IXAudio2* GetAudio(void) const;

	// �}�X�^�����O�擾
	IXAudio2MasteringVoice* GetMastering(void) const;

private:
	// �R���X�g���N�^
	XAudio2();
	// �f�X�g���N�^
	~XAudio2();

	// �I�[�f�B�I����
	void CreateAudio(void);

	// �}�X�^�����O����
	void CreateMastring(void);


	// �I�[�f�B�I
	IXAudio2* audio;

	// �}�X�^�����O
	IXAudio2MasteringVoice* mastering;
};
