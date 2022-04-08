#include<iostream>
#include <string>
#include <fstream>


using namespace std;

char gameboard[8][8]
void initialize_gameboard(char gameboard[8][8]); // Function declaration
void print_gameboard(char gameboard[8][8]);
int prompt_user();
int num;
void askForBattleShip(char gameboard[8][8]);
void askForAllBattleShips(char gameboard[8][8]);
void startShooting(char gameboard[8][8]);
void takeshot(char gameboard[8][8]);
void checkifallarehit(char gameboard[8][8]);


const char noship = '0'; //point without ship
const char ship = '1'; //point with a ship
const char hit = 'h'; //tried and hit ship
const char miss = 'f'; //tried and missed ship
const char nearmiss = 'n'; //you were close to ship


int main() {
	cout << "Battleship" << endl;
	initialize_gameboard(gameboard);
	while (true) {

		cout << "Enter 1 to position the battleships.\n";
		cout << "Enter 2 to start playing.\n";
		cout << "Enter 3 to quit.\n";
		cin >> num;

		if (num == 1) {
			askForAllBattleShips(gameboard);
		}
		else if (num == 2) {
			startShooting(gameboard);
		}
		else if (num == ) {
			cout << "bye!bye!\n";
			return 0;
			break;
		}
		else {

		}
	}
}
void askForBattleShip(char gameboard[8][8])
{
	int x, y, ok = 0;

	do
	{
		cout << "Please enter a battle ship" << endl;
		cout << "please enter x coordinate.\n";
		cin >> x;
		cout << "please enter y coordinate.\n";
		cin >> y;

		if (gameboard[x][y] == noship)
		{
			gameboard[x][y] = ship;
			ok = 1;
		}
		else if (gameboard[x][y] == nearmiss)
		{
			gameboard[x][y] = near;
			cout << "It was close!\n"
		}
		else if (gameboard[x][y] == ship)
	{
		gameboard[x][y] = hit;
		cout << "hit.\n";

	}
		else
			cout << "That coordinate was already taken!!\n";

	} while (ok == 0);

	ok = 0;

	do
	{
		cout << "please enter 2nd x coordinate.\n";
		cin >> x;
		cout << "please enter 2nd y coordinate.\n";
		cin >> y;

		if (gameboard[x][y] == noship)
		{
			gameboard[x][y] = ship;
			ok = 1;
		}
		else if (gameboard[x][y] == nearmiss)
		{
			gameboard[x][y] = near;
			cout << "It was close!\n"
		}
		else if (gameboard[x][y] == ship)
	{
		gameboard[x][y] = hit;
		cout << "hit.\n";

	}
		else
			cout << "That coordinate was already taken!!\n";

	} while (ok == 0);

}

void askForAllBattleShips(char gameboard[8][8]) {
	for (int i = 0; i < 7; i++) {
		askForBattleShip(gameboard);
	}
	print_gameboard(gameboard);
}

void initialize_gameboard(char gameboard[8][8]) { // Function Definition
	for (int i = 0; i < 8; i++) { //row
		for (int j = 0; j < 8; j++) { // column
			gameboard[i][j] = noship;
		}
	}
}

void print_gameboard(char gameboard[8][8]) {
	for (int i = 0; i < 8; i++) { //row
		for (int j = 0; j < 8; j++) { // column
			cout << gameboard[i][j];
		}
		cout << endl;
	}
}

void startShooting(char gameboard[8][8])
{
	for (int i = 0; i < 12; i++)
		takeshot(gameboard);

	for (int i = 0; i < 8; i++)
	{  //row
		for (int j = 0; j < 8; j++)
			cout << gameboard[i][j];
		cout << endl;
	}

}
void takeshot(char gameboard[8][8]) {
	int x, y;
	cout << "Please enter shot x value" << endl;
	cin >> x;
	cout << "Please enter shot y value" << endl;
	cin >> y;

	if (gameboard[x][y] == ship)
	{
		gameboard[x][y] = hit;
		cout << "hit.\n";

	}
	else if (gameboard[x][y] == noship)

	{
		gameboard[x][y] = miss;
		cout << "miss.\n";
	}
	else (gameboard[x][y] == nearmiss)
	{
		gameboard[x][y] = nearmiss;
		cout << "nearmiss.\n"
	}


	cout << endl;
}

//code tweaked and pulled from cplusplus.com
//changed some things to fit the idea of how I wanted battle ship to be