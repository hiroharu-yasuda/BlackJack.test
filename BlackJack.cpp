#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << "player" << endl;
	p[0]->showHand();
	cout << "============================" << endl;
	cout << "dealer" << endl;
	p[1]->showHand();
	cout << "============================" << endl;

	if (p[0]->getScore() > p[1]->getScore()) {
		cout << "Player Win!" << endl;
	}
	else if (p[0]->getScore() < p[1]->getScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

static void showHand(Person* p, const char* name = "player")
{
	//手札の表示
	cout << "====================" << endl;
	cout << name << endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		PLAYER, DEALER
	};

	//各オブジェクトの生成
	Shoe shoe;
	Player p1("Player1");
	Player p2("Player2");
	Player p3("Player3");
	Dealer D("Dealer");
    Player	players[3] = { p1,p2,p3 };

	const int num = 3;

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		players[i].hit(shoe);
		players[i].hit(shoe);
		players[i].showHand();
	}
	D.hit(shoe);
	
	for (int i = 0; i < num; i++) {
		players[i].playBase(&shoe);
	}
	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	if (players[PLAYER].play(&shoe)) {
		//バーストせずstandした

		//ディーラーの手札を表示
		D.showHand();
		//ディーラーの自動実行
		D.play(&shoe);
		//結果の表示
	}
	else {
		cout << "Burst Player Lose" << endl;
	}
	cout << "====================" << endl;
	return 0;
}