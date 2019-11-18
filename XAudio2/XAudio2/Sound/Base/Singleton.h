#pragma once

template <typename T>
class Singleton
{
public:
	// �C���X�^���X�ϐ��̎擾
	static T& Get(void)
	{
		T instance;
		return instance;
	}

private:
	// �R�s�[�R���X�g���N�^
	Singleton(const Singleton& obj) = delete;
	//������Z�q�I�[�o�[���[�h
	void operator=(const Singleton& obj) = delete;

protected:
	// �R���X�g���N�^
	Singleton() {}
	// �f�X�g���N�^
	virtual ~Singleton() {}
};