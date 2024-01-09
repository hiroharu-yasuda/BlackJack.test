#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
public:
	virtual void playBase(Shoe* shoe);

	Dealer(const char* name);
	Dealer();
	~Dealer();
protected:
	//ゲーム実行
	const char* _name;
};