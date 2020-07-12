#include <iostream>
#include <string>
#include <ostream>

using namespace std;

class Node
{
public:
	string nama_tamu;
	Node* next;
};

Node* first;
Node* last;

void buatKosong(){
	first = NULL;
	last = NULL;
}

bool isKosong(){
	return (first == NULL);
}

int hitungJumlahNode(){
	int jumlah = 0;
	if (isKosong() == false)
	{
		Node* bantu = first;
		while(bantu != NULL){
			jumlah++;

			bantu = bantu->next;
		}
	}

	return jumlah;
}

void cetakIsiQeueu(){
	cout<<"Daftar Antrian ["<<hitungJumlahNode()<<"] = "<<endl;
	if (isKosong() == false)
	{
		Node *bantu = first;
		int i = 1;
		while(bantu != NULL){
			cout<<bantu->nama_tamu<<" | ";

			bantu = bantu->next;
			i++;
		}
		cout<<"\n";
	}else{
		cout<<"Antrian Kosong"<<endl;
	}
}

void tambahNode(string tamu_baru){
	Node* node_baru = new Node();
	node_baru->nama_tamu = tamu_baru;
	node_baru->next = NULL;
	if (isKosong() == true)
	{
		first = last = node_baru;
	}

	last->next = node_baru;
	last = node_baru;
}

void hapusNode(){
	if (isKosong() == true)	cout<<"Antrian Kosong \n";

	Node* node_hapus = first;
	first = node_hapus->next;
	free(node_hapus);
}

int main(){
	first = new Node();
	last = new Node();

	cout<<"Mulai\n";
	buatKosong();
	cetakIsiQeueu();

	cout<<"Masukkan 3 Nama Tamu \n";
	tambahNode("Anggie");
	tambahNode("Astri");
	tambahNode("Rubi");
	cetakIsiQeueu();

	cout<<"Hapus 1 Node paling depan \n";
	hapusNode();
	cetakIsiQeueu();


	return 0;
}