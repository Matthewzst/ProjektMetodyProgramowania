#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <list>

using namespace std;

class DrawCube
{
public:
	void randNumberdraw() {
		int cykl{ 1 };
		do {			
			drawRandomCube();
			cykl++;
		} while (cykl != 6);
	}
	void drawRandomCube() {

		int cubeSide = rand() % 6 + 1;

		switch (cubeSide) {
		case 1:
			drawCubeNumberOne();
			break;
		case 2:
			drawCubeNumberTwo();
			break;
		case 3:
			drawCubeNumberThree();
			break;
		case 4:
			drawCubeNumberFour();
			break;
		case 5:
			drawCubeNumberFive();
			break;
		case 6:
			drawCubeNumberSix();
			break;
		}
		Sleep(500);
		system("cls");
	}
	void drawCubeNumberOne() {
		for (int i = 1; i <= 13; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|           |\n";
		cout << "\t|           |\n";
		cout << "\t|     *     |\n";
		cout << "\t|           |\n";
		cout << "\t|           |\n";
		for (int j = 1; j <= 13; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
	void drawCubeNumberTwo() {
		for (int i = 1; i <= 12; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|          |\n";
		cout << "\t|   *      |\n";
		cout << "\t|          |\n";
		cout << "\t|      *   |\n";
		cout << "\t|          |\n";
		for (int j = 1; j <= 12; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
	void drawCubeNumberThree() {
		for (int i = 1; i <= 13; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|           |\n";
		cout << "\t|   *       |\n";
		cout << "\t|     *     |\n";
		cout << "\t|       *   |\n";
		cout << "\t|           |\n";
		for (int j = 1; j <= 13; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
	void drawCubeNumberFour() {
		for (int i = 1; i <= 13; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|           |\n";
		cout << "\t|   *   *   |\n";
		cout << "\t|           |\n";
		cout << "\t|   *   *   |\n";
		cout << "\t|           |\n";
		for (int j = 1; j <= 13; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
	void drawCubeNumberFive() {
		for (int i = 1; i <= 13; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|           |\n";
		cout << "\t|   *   *   |\n";
		cout << "\t|     *     |\n";
		cout << "\t|   *   *   |\n";
		cout << "\t|           |\n";
		for (int j = 1; j <= 13; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
	void drawCubeNumberSix() {
		for (int i = 1; i <= 12; i++) {
			if (i == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
		cout << "\t|          |\n";
		cout << "\t|   *  *   |\n";
		cout << "\t|   *  *   |\n";
		cout << "\t|   *  *   |\n";
		cout << "\t|          |\n";
		for (int j = 1; j <= 12; j++) {
			if (j == 1)
				cout << "\t-";
			else
				cout << "-";
		}
		cout << endl;
	}
};

class Game{
public:
	
	struct Player
	{
		string nickname{};
		int points{};
	};
	
	list<Player> players;
	

	int GameOption() {
		int gameChoice{0}, goBack{0};
		do {
			cout << "___________________________________\n";
			cout << "| --- Choice your game option --- |\n";
			cout << "| - 1: Two Players Game         - |\n";
			cout << "| - 2: Four Players Game        - |\n";
			cout << "| - 3: Six Players Game         - |\n";
			cout << "| - 0: Go Back                  - |\n";
			cout << "| - Type your choice: ";
			cin >> gameChoice;
			cin.ignore(2000, '\n');

			switch (gameChoice) {
			case 0:
				system("cls");
				goBack = 1;
				break;
			case 1:
			case 2:
			case 3:
				system("cls");
				setPlayerNickname(gameChoice*2);
				Sleep(80);
				system("cls");
				PlayersGame(gameChoice*2);
				break;
			default:
				break;

			}
		} while (goBack != 1);
		return 0;
	}

	bool checkIfNickNameIsUnique(string newPlayerNickName) {
		for (Player player : players) {
			if (player.nickname == newPlayerNickName) {
				return false;
			}
		}
		return true;
	}
	
	

	void setPlayerNickname(int playersNumber){
		cout << "_________________________________\n";
		cout << "| - Creating Players Nickname - |\n";
		int playersValue{1};
		for (int i = 0; i <= playersNumber; i++) {
			cout << "| -        Player nr. " << playersValue << "       - |\n" << "| Type your nickname: ";
			string newPlayerNickName;
			getline(cin, newPlayerNickName);
			i++;

			bool isNickNameUnique = false;

			while (!isNickNameUnique) {
			
				isNickNameUnique = checkIfNickNameIsUnique(newPlayerNickName);
				if (!isNickNameUnique) {
					cout << "Ten Nickname jest juz zajety!\n";
					cout << "Podaj Ponownie Nickname: ";
					getline(cin, newPlayerNickName);
					cout << "\n";
				}
			}		

			Player newPlayer = Player();
			newPlayer.nickname = newPlayerNickName;
			newPlayer.points = 0;
			
			players.push_front(newPlayer);
			playersValue++;
		}
					
	}

	bool checkIfPlayerPointsIsUnique(Player currentPlayer) {
		for (Player player : players) {
			if (player.nickname != currentPlayer.nickname && player.points == currentPlayer.points) {
				return false;
			}
		}
		return true;
	}

	int checkWitchPlayerHaveHeigstNumber(Player currentPlayer) {
		for (Player player : players) {
			if (player.nickname != currentPlayer.nickname && player.points < currentPlayer.points) {
				cout << "| - Was won by " << player.nickname << "\n";
			}
		}
		return 0;
	}

	void PlayersGame(int playersNumber){
		int time{ 0 }, round{ 1 }, currentPoint{0};
		string znak{ "" };
		DrawCube draw;
				do{
					for (Player player : players) {
						cout << "_________________________________\n";
						cout << "| ---      Round nr. " << round << "      --- |\n";
						cout << "| - " << player.nickname << " turn \n";
						cout << "| - To roll a dice type (l): ";
						cin >> znak;
						cin.ignore(2000, '\n');
						cout << "\n";

						again: if (znak == "l")
								currentPoint = rand() % 6 + 1;
								system("cls");
								draw.randNumberdraw();

								switch (currentPoint) {
								case 1:
									draw.drawCubeNumberOne();
									break;
								case 2:
									draw.drawCubeNumberTwo();
									break;
								case 3:
									draw.drawCubeNumberThree();
									break;
								case 4:
									draw.drawCubeNumberFour();
									break;
								case 5:
									draw.drawCubeNumberFive();
									break;
								case 6:
									draw.drawCubeNumberSix();
									break;
								default:
									throw new exception("imposible cube side found");
								}

								cout << "__________________________________\n";
								cout << "| - Your number is: " << currentPoint;
								cout << "\n";
								Sleep(1200);

								player.points = currentPoint;

						if (checkIfPlayerPointsIsUnique(player) == false) {
							cout << "| - Your number is the same. We will roll dice again!\n";
							goto again;
						}		

						time++;
						if (time == 2) {
							system("cls");
							cout << "__________________________________\n";
							cout << "| ---      The "<< round << ". Round      --- |\n";
							checkWitchPlayerHaveHeigstNumber(player);
							Sleep(2500);
						}


						if (time % 2 == 0)
							round++;

						system("cls");
					}
				} while (round != 5);
	
	}
	
};


int main()
{ 
	setlocale(LC_ALL, "Polish");
	int choice{ 0 }, exit{ 0 }, time{ 0 };
	do {
		if (time > 1) {
			system("cls");
		}
		else {
			time++;
		}
		cout << "__________________________________\n";
		cout << "| --- Welcome to Roll a Dice --- |\n";
		cout << "| - 1: Game mode               - |\n";
		cout << "| - 0: Exit                    - |\n";
		cout << "| ------------------------------ |\n";
		cout << "| Wprowadz numer: ";
		cin >> choice;
		cin.ignore(2000, '\n');
		Game show;

		switch (choice)
		{
		case 0:
			exit = 1;
			break;
		case 1:
			system("cls");
			show.GameOption();
			break;
		default:
			break;
		}
	} while (exit != 1);

	return 0;
}