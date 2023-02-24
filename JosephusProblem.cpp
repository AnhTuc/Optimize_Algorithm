//Josephus  problem

#include<iostream>
#include<string>
#include<fstream>
struct Node {
	Node* next;
	int value;
};

using namespace std;
int josephus(Node *sword_holder) {
	Node* to_be_killed = sword_holder->next;
	
	if (sword_holder->value == to_be_killed->value)
	{
		cout << endl;
		return sword_holder->value;
	}
	else {
		Node* next = to_be_killed->next;
		sword_holder->next = next;
		sword_holder = next;

		cout << to_be_killed->value << " ";
		delete to_be_killed;

		josephus(sword_holder);
	}

}
int main() {
	string filename = "input_2.txt";
	int n;

	ifstream ifs(filename);
	if (ifs) {
		ifs >> n;
		
		Node* head = new Node();
		head->value = 1;
		Node* sword_holder = head;

		Node* cur = head;
		for (int i = 1; i < n; i++) {
			Node* p = new Node;
			p->value = i + 1;
			cur->next = p;
			cur = p;
		}
		cur->next = head;

		int survivor=josephus(sword_holder);
		cout << survivor << endl;
	}
	else cout << "Error reading file" << endl;

}