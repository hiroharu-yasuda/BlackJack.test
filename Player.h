#pragma once

#include "Person.h"

//�v���C���[�N���X
class Player : public Person
{public:
	Player();
	 Player(const char* name) ;
	~Player();
	virtual void playBase(Shoe* shoe);
protected:
	//�Q�[�����s
	
	const char* _name;
};
