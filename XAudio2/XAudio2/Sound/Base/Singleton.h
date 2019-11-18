#pragma once

template <typename T>
class Singleton
{
public:
	// インスタンス変数の取得
	static T& Get(void)
	{
		T instance;
		return instance;
	}

private:
	// コピーコンストラクタ
	Singleton(const Singleton& obj) = delete;
	//代入演算子オーバーロード
	void operator=(const Singleton& obj) = delete;

protected:
	// コンストラクタ
	Singleton() {}
	// デストラクタ
	virtual ~Singleton() {}
};