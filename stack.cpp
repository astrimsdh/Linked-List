#include <iostream>

using namespace std;

class Node(){
public:
	string url;
	Node* next;
}

Node* top;

void buatKosong(){
	top = NULL;
}

bool isKosong(){
	return (top == NULL);
}

int hitungNode(){
	int hasil = 0;
	if (isKosong() == false){
		Node *bantu = new Node();
		bantu = top;

		while(bantu != NULL){
			hasil += 1;
			bantu = bantu->next;
		}
	}

	return hasil;
}

void cetakIsiStack(){
	if (isKosong() == false)
	{
		cout<<"Isi Stack ["<<hitungNode()<<"] : "<<endl;

		Node *bantu = top;
		int i = 1;
		while(bantu != NULL){
			cout<<bantu->url<<" | ";
			bantu = bantu->next;
			i++;
		}

		cout<<"\n";
	}else{
		cout<<"Stack Kosong"<<endl;
	}
}




int main(){
	
}