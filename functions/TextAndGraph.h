#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node {
	string val;

	Node *left;
	Node *right;

	Node(string _val, Node *_l = NULL, Node *_r = NULL) :val(_val), left(_l), right(_r) {}

};

class Text {
	Node *root;
	Node *curr;
	stack<Node*> st;
public:
	Text() { root = curr = NULL; }

	void right();
	void left();
	void top();

	void addCurr(string &st);
	void addRight(string &st);
	void addLeft(string &st);

	friend ostream &operator<<(ostream &o, const Text &T);
};