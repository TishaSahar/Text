#include "TextAndGraph.h"

void PrintTRL(ostream &o, Node *root, Node *curr, int level) {
	if (root == NULL) return;
	if (root == curr) o << "*";
	else o << "|";
	for (int i = 0; i < level; i++) {
		o << "      ";
	}
	o << root->val << endl;
	PrintTRL(o, root->right, curr, level + 2);
	PrintTRL(o, root->left, curr, level-1);
	system("pause");
}

ostream &operator<<(ostream &o, const Text &T){
	PrintTRL(o, T.root, T.curr, 0);
	return o;
}

void Text::right() {
	if (curr == NULL) throw "current is NULL";
	if (curr->right == NULL) throw "right is empty";
	st.push(curr);
	curr = curr->right;
}

void Text::left() {
	if (curr == NULL) throw "current is NULL";
	if (curr->left == NULL) throw "left is empty";
	st.push(curr);
	curr = curr->left;
}

void Text::top() {
	if (curr == NULL) throw "current is NULL";
	if (st.empty()) throw "current is top";
	curr = st.top();
	st.pop();
}

void Text::addCurr(string &st) {
	if (curr == root) { 
		root = new Node(st);
		curr = root;
	}
	else {
		curr = new Node(st);
	}
}

void Text::addRight(string &st) {
	if (curr == root) {
		root->right = new Node(st);
		curr = root->right;
	}
	else {
		if (curr->right == NULL) {
			curr->right = new Node(st);
			curr = curr->right;
		}
		else
			throw logic_error("right isn't empty / can't add");
	}
}

void Text::addLeft(string &st) {
	if (curr == root) {
		root->left = new Node(st);
		curr = root->left;
	}
	else {
		if (curr->left == NULL) {
			curr->left = new Node(st);
			curr = curr->left;
		}
		else
			throw logic_error("left isn't empty / can't add");
	}
}

