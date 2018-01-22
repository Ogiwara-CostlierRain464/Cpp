#include "Block.h"
#include "Drawer.h"
#include <stdlib.h>

vector<Block> stopingblockstuck;

vector<Block> movingblockstuck;

int getfirstx() {
	return (WIDTH / 2);
}

int getfirsty() {
	//return (HEIGHT / 2);
	return 2;
}

void createrandomblock() {
	Color c;
	Block s;
	Block k;
	int num = rand() % 10;
	switch (num) {
	case 1:
		c.R = 0; c.G = 0; c.B = 255;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx() + 1;
		k.Y = getfirsty();
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	case 2:
		c.R = 0; c.G = 0; c.B = 0;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx() - 1;
		k.Y = getfirsty();
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	case 3:
		c.R = 0; c.G = 255; c.B = 153;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx();
		k.Y = getfirsty() + 1;
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	case 4:
		c.R = 204; c.G = 0; c.B = 0;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx();
		k.Y = getfirsty() - 1;
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	case 5:
		c.R = 255; c.G = 255; c.B = 0;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx() + 1;
		k.Y = getfirsty() + 1;
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	default:
		c.R = 255; c.G = 102; c.B = 153;
		s.X = getfirstx();
		s.Y = getfirsty();
		s.c = c;
		movingblockstuck.push_back(s);
		k.X = getfirstx() - 1;
		k.Y = getfirsty() - 1;
		k.c = c;
		movingblockstuck.push_back(k);
		break;
	}
}

bool isfilled(int x, int y) {
	if (x <= 0 || x >= WIDTH) return true;
	if (y <= 0 || y >= HEIGHT) return true;

	for (Block b : stopingblockstuck) {
		if (b.X == x && b.Y == y) {
			return true;
		}
	}

	return false;
}

void spawn() {
	if (isfilled(getfirstx(),getfirsty())) {
		MessageBox(window, TEXT("ゲームオーバー"), TEXT("Gameover"), MB_ICONERROR);
		PostQuitMessage(0);
		return;
	}

	createrandomblock();
	CallWMPAINT();
}

void unactivemovingblock() {
	for (Block b : movingblockstuck) {
		stopingblockstuck.push_back(b);
	}
	movingblockstuck.clear();
}

void goDown() {
	bool result = true;//いけるならtrue

	for (Block b : movingblockstuck) {
		if (isfilled(b.X,b.Y + 1)) {
			result = false;
		}
	}//こういう値を変更しないやつはこれでいい!

	if (result) {

		for (int i = 0; i <= movingblockstuck.size() - 1; i++) {
			movingblockstuck[i].Y += 1;
		}
		CallWMPAINT();
	}
	else {
		unactivemovingblock();
		spawn();
	}
}

void goLeft() {
	bool result = true;

	for (Block b : movingblockstuck) {
		if (isfilled(b.X - 1, b.Y)) {
			result = false;
		}
	}

	if (result) {
		for (int i = 0; i <= movingblockstuck.size() - 1; i++) {
			movingblockstuck[i].X -= 1;
		}
		CallWMPAINT();
	}
}

void goRight() {
	bool result = true;

	for (Block b : movingblockstuck) {
		if (isfilled(b.X + 1, b.Y)) {
			result = false;
		}
	}

	if (result) {
		for (int i = 0; i <= movingblockstuck.size() - 1; i++) {
			movingblockstuck[i].X += 1;
		}
		CallWMPAINT();
	}
}

void CheckDelete() {
	for (int i = 0; i <= HEIGHT; i++) {
		for (Block b : stopingblockstuck) {//movingstuckがunactiveされた後に呼び出すのが適切

		}
	}
}