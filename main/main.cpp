#include "TextAndGraph.h"
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	int op;
	Text T;

	string n1 = "top";
	string n2 = "right";
	string n3 = "left";

	while (true) {
		system("cls");
		cout << T;
		cout << "0 .exit\n";
		cout << "1 .right\n";
		cout << "2 .left\n";
		cout << "3 .top\n";
		cout << "4 .addLeft\n";
		cout << "5 .addRight\n";

		cin >> op;
		string tempSt;
		try {
			switch (op) {
			case 0: return 0; break;
			case 1: T.right(); break;
			case 2: T.left(); break;
			case 3: T.top(); break;
			case 4: 
				cin >> tempSt;
				T.addLeft(tempSt); break;
			case 5:

				cin >> tempSt;
				T.addRight(tempSt); break;
			}
		}
		catch (const char *er) {
			cout << er << endl;
			_getch();
		}
	}

	return 0;
}