#include "TextAndGraph.h"
using namespace std;

int main() {
	Text T;

	string n1 = "top";
	string n2 = "right";
	string n3 = "left";

	T.addCurr(n1); T.addRight(n2); T.addLeft(n3); T.addLeft(n3); T.addRight(n2); T.addRight(n2);
	cout << T;

	return 0;
}