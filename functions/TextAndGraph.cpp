#include "TextAndGraph.h"

void PrintTRL(ostream &o, Node *root, Node *curr, int level) {
	if (root == NULL) return;
	if (root == curr) o << "*";
	else o << "|";
	for (int i = 0; i < level; i++) {
		o << "    ";
	}
	o << root->val << endl;
	PrintTRL(o, root->right, curr, level + 2);
	PrintTRL(o, root->left, curr, level-1);
	//system("pause");
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


void Text::addRight(string &st) {
	if (root == NULL) {
		root = curr = new Node(st);
		return;
	}
	Node *p = new Node(st, curr->right);
	curr->right = p;
}

void Text::addLeft(string &st) {
	if (root == NULL) {
		root = curr = new Node(st);
		return;
	}
	Node *p = new Node(st, curr->left);
	curr->left = p;
}

void Text::remoteBranch(Node *n) {
	if (n == NULL) return;
	remoteBranch(n->left);
	remoteBranch(n->right);
	delete n;
}
void Text::remote() {
	if (curr == NULL) return;
	remoteBranch(curr->right);
	Node *temp = curr;
	if (!st.empty()) {
		top();
		if (curr->left == temp)
			curr->left = temp->left;
		if (curr->right == temp) {
			curr->right = temp->right;
		}
	}
	else {
		root = temp->left;
		curr = root;
		delete temp;
	}
}

void Text::readFile(ifstream &in) {
	if (!in.is_open()) throw logic_error("file isn't open");
	string line = "";
	while (getline(in, line)) {
		int i = 0;
		int level = 0;
		string tmp = "";
		while ((line[i] != '{') && (line[i] != '}') && (line[i] != '\n')) {
			if(line[i] != ' ')
				tmp += line[i];
			i++;
		}
		addLeft(tmp);
		left();
		if (line[i] == '{') {
			tmp = "{";
			addRight(tmp);
			right();
		}
		if (line[i] == '}') {
			tmp = "}";
			top();
			addLeft(tmp);
		}
	}
	in.close();
}