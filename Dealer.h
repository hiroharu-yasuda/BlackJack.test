#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
public:
	virtual void playBase(Shoe* shoe);

	Dealer(const char* name);
	Dealer();
	~Dealer();
protected:
	//�Q�[�����s
	const char* _name;
};