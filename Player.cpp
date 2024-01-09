#include <iostream>
#include "Player.h"
#include "Shoe.h"

using namespace std;
Player::Player() {
	_name = 0;
}
Player::Player(const char* name) {
	_name = name;

}
Player::~Player() {

}
//�Q�[�����s
void Player::playBase(Shoe* shoe) {
	//�o�[�X�g����܂Ń��[�v����
	while (getScore()) {
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(*shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << _name << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�I������
			break;
		}
	}
}
