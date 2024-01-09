#pragma once

#include "Person.h"

//プレイヤークラス
class Player : public Person
{public:
	Player();
	 Player(const char* name) ;
	~Player();
	virtual void playBase(Shoe* shoe);
protected:
	//ゲーム実行
	
	const char* _name;
};
