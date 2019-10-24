#pragma once

template <typename T>
class Singleton
{
public:
	// �C���X�^���X�ϐ��擾
	static T& Get(void)
	{
		static T instance;
		return instance;
	}

protected:
	// �R���X�g���N�^
	Singleton() {}
	// �f�X�g���N�^
	virtual ~Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
};
