#pragma once
#include <iostream>
#include <fstream>
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

	void remoteBranch(Node *n);
public:
	Text() { root = curr = NULL; }
	Node *getRoot() { return root; }

	void right();
	void left();
	void top();

	void addRight(string &st);
	void addLeft(string &st);

	void remote();

	friend fstream& operator >> (fstream &f, const Text &T);
	friend ostream &operator<<(ostream &o, const Text &T);
};