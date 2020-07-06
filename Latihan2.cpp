#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	
};

void tampilkanData(Node* n){
	while(n != NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
	cout<<"\n\n";
}

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	tampilkanData(head);
	return 0;
}
