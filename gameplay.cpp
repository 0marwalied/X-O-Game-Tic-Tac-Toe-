#include "bits/stdc++.h"

using namespace std;

char matrix[3][3], cur_player;
vector<int>numpers;

char valied() {
	for (int i = 0; i < 3; i++) {
		if (matrix[i][1] == matrix[i][0] && matrix[i][1] == matrix[i][2])
			return matrix[i][1];
	}
	for (int i = 0; i < 3; i++) {
		if (matrix[1][i] == matrix[0][i] && matrix[1][i] == matrix[2][i])
			return matrix[1][i];
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] == 'X' || matrix[i][j] == 'O')
				cnt++;
	if (cnt == 9)
		return 'D';
	return 'E';
}

void init() {
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cnt++;
			matrix[i][j] = char(cnt + '0');
		}
}

void start_game() {
	cout << "Press 1 to play with X" << endl;
	cout << "press 2 to play with O" << endl;
	cout << "Input 1 or 2 : ";
	char x; cin >> x;
	while (x != '1' && x != '2') {
		system("cls");
		cout << "Press 1 to play with X" << endl;
		cout << "press 2 to play with O" << endl;
		cout << "Incorrect data please enter 1 or 2 to start the game" << endl;
		cout << "Input 1 or 2 : "; cin >> x;
	}
	if (x == '1')cur_player = 'X';
	else cur_player = 'O';
}

void view() {
	for (int i = 0; i <= 12; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "| " << matrix[i][j] << " ";
			if (j == 2)
				cout << "|";
		}
		cout << endl;
		for (int j = 0; j <= 12; j++)
			cout << "-";
		cout << endl;
	}
}

void play() {
	int cnt = 0, numper = 0;
	cout << endl;
	numpers.clear();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cnt++;
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9') {
				numper++;
				numpers.push_back(cnt);
			}
		}
	for (int i = 0; i < 32; i++)
		cout << "-";
	for (int i = 0; i < numper * 2; i++)
		cout << "-";
	cout << endl;
	cnt = 0;
	cout << "| Press any key of this keys : ";
	for (auto &it : numpers)
		cout << it << " ";
	cout << "|";
	cout << endl;
	for (int i = 0; i < 32; i++)
		cout << "-";
	for (int i = 0; i < numper * 2; i++)
		cout << "-";
	cout << endl;
}

bool isNumper(string &s) {
	for (auto &it : s) {
		if ('0' <= it && it <= '9')continue;
		return 0;
	}
	return 1;
}

void update(int player_num) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cnt++;
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9') {
				if (cnt == player_num) {
					matrix[i][j] = cur_player;
					return;
				}
			}
		}
	}
}

bool playAgain() {
	string choice;
	cout << "To play again press 1\n";
	cout << "To exit press 2\n";
	cout << "Input 1 or 2 : ";
	cin >> choice;
	while (choice != "1" && choice != "2") {
		cout << "Incorrect data" << endl;
		cout << "press any key to play your turn" << endl;
		system("pause");
		system("cls");
		cout << "Play again press 1\n";
		cout << "To exit press 2\n";
		cout << "Input 1 or 2 : ";
		cin >> choice;
	}
	system("cls");
	if (choice == "1")
		return 1;
	return 0;
}

int main() {
start:

	cout << "X,O game" << endl << endl;
	init();
	// cout << "to start press any key" << endl << endl;
	system("pause");
	system("cls");
	start_game();
	system("cls");
	while (1) {
		if (valied() == 'X') {
			cout << "The Player X is the winner" << endl;
			if (!playAgain()){cout<<"Nice to meet you <3";break;}
			else goto start;
		} else if (valied() == 'O') {
			cout << "The Player O is the winner" << endl;
			if (!playAgain()){cout<<"Nice to meet you <3";break;}
			else goto start;
		} else if (valied() == 'D') {
			cout << "The game is draw " << endl;
			if (!playAgain()){cout<<"Nice to meet you <3";break;}
			else goto start;
		}
		view();
		cout << endl << "The " << cur_player << " Player is playing now " << endl;
		play();
		string player_num;
		cout << "Input : ";
		cin >> player_num;
		if (!isNumper(player_num))
			player_num = "-1";
		bool found = 0;

		for (auto &it : numpers)
			if (it == stoi(player_num))
				found = 1;

		if (found) {
			if (cur_player == 'X') {
				update(stoi(player_num));
				cur_player = 'O';
				system("cls");
			} else {
				update(stoi(player_num));
				cur_player = 'X';
				system("cls");
			}
		} else {
			cout << "Incorrect data" << endl;
			cout << "Press any key to play your turn" << endl;
			system("pause");
			system("cls");
		}
	}
}
