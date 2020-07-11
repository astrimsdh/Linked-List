#include <iostream>

using namespace std;

class Node{
public:
	string url;
	Node* next;
};

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

int pushNode(string url_new){
	Node *node_new = new Node();
	node_new->url = url_new;

	if (isKosong() == true)
	{
		node_new->next = NULL;
	}else{
		node_new->next = top;
	}

	top = node_new;
	node_new = NULL;

	return 0;
}

int popNode(){
	if (isKosong() == false)
	{
		Node* hapus = top;

		if (hitungNode() == 1)
		{
			top == NULL;
			free(hapus);
		}else{
			top = top->next;
		}

		hapus->next = NULL;
		free(hapus);
	}else{
		cout<<"Stack Kosong"<<endl;
	}

	return 0;
}

int main(){
	top = new Node();

	cout<<"mulai \n";
	buatKosong();
	cetakIsiStack();

	cout<<"Masukkan 3 URL histori browser \n";
	pushNode("http://latihan.nufi3.com");
	pushNode("http://astrimsdh.github.io");
	pushNode("http://www.stmik-tasikmalaya.ac.id");
	cetakIsiStack();

	cout<<"Hapus 1 Node paling atas \n";
	popNode();
	cetakIsiStack();

	return 0;
}