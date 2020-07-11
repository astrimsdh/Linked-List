#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	
};

int tambahDepan(Node** head_ref, int data_baru){
	// a. Siapkan Node Baru
	Node* Node_baru = new Node();

	// b. Masukkan data baru pada Node_baru
	Node_baru->data = data_baru;

	// c. Buat Node baru menjadi head
	Node_baru->next = (*head_ref);

	// d. rubah head agar mengarah ke Node baru
	(*head_ref) = Node_baru;

	return 0;
}

int sisipkanSetelah(Node* node_terpilih, int data_baru){
	// a. Cek apakah node terpilih adalah null
	if (node_terpilih == NULL)		
	{
		cout<<"Node yang dipilih kosong. Penambahan Batal \n";
		return 0;
	}

	// b. Menyiapkan Node Baru
	Node* node_baru = new Node();

	// c. Masukkan data Baru pada node baru
	node_baru->data = data_baru;

	// d. Buat node baru mengarah pada node yang sama dengan node terpilih
	node_baru->next = node_terpilih->next;

	// e. Ubah node terpilih mengarah ke node_baru
	node_terpilih->next = node_baru;

	return 0;
}

// Menambahkan pada bagian akhir
int tambahAkhir(Node** head_ref, int data_baru){
	// a. Siapkan node baru
	Node* node_baru = new Node();
	Node* last = *head_ref;

	// b. Masukkan data baru pada node baru
	node_baru->data = data_baru;

	// c. Menjadikan node baru sebagai last node
	node_baru->next = NULL;

	// d. Mengecek apakah list kosong?
	if (*head_ref == NULL)
	{
		*head_ref = node_baru;
	}

	// e. Jika tidak kosong jelajahi list sampai last
	while(last->next != NULL){
		last = last->next;
	}

	// f. rubah last node mengarah ke node baru
	last->next = node_baru;

	return 0;
}

// Menghapus Node berdasarkan key
int hapusNodeKey(Node **head_ref, int key){
	// simpan reference head node & node sebelumnya
	Node* temp = *head_ref;
	Node *node_sebelum;
	// jika key berada di head node
	// maka headnya dihapus
	if (temp != NULL && temp->data ==key)
	{
		*head_ref = temp->next;
		free(temp);

		return 0;
	}

	// mencari key node yang akan dihapus 
	// terus mendeteksi node sebelumnya
	while(temp != NULL && temp->data != key){
		node_sebelum = temp;
		temp = temp->next;
	}

	// jika key tidak ditemukan pada linked list 
	// proses berhenti
	if (temp == NULL) return 0;	

	// melepaskan node key dari linked list
	node_sebelum->next = temp->next;

	// free memori
	free(temp);
	return 0;
}

// Menghapus node posisi
int hapusNodePosisi(Node **head_ref, int posisi){
	// jika list kosong
	if (*head_ref == NULL) return 0;

	// simpan node head
	Node* temp = *head_ref;

	// jika posisi adalah head
	if(posisi == 0){
		*head_ref = temp->next;
		free(temp);

		return 0;
	}

	// Mencari node sebelum node yang akan di hapus
	for (int i = 0; temp != NULL && i < posisi - 1; ++i)
	{
		temp = temp->next;
	}

	// jika posisi lebih dari jumlah node, selesai
	Node *node_selanjutnya = temp->next->next;

	// Lepaskan node dari list;
	free(temp->next);
	temp->next = node_selanjutnya;

	return 0;
}

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

	tambahDepan(&head, 30);
	cout<<"Setelah penambahan data didepan \n";
	tampilkanData(head);

	sisipkanSetelah(head->next, 70);
	cout<<"Setelah Penambahan data penambahan First\n";
	tampilkanData(head);

	tambahAkhir(&second, 100);
	cout<<"Setelah penambahan data dibelakang! \n";
	tampilkanData(head);

	int key = 30;
	hapusNodeKey(&head, key);
	cout<<"Setelah "<<key<<" dihapus \n";
	tampilkanData(head);

	int posisi = 2;
	hapusNodePosisi(&head, posisi);
	cout<<"Setelah Node posisi ke-"<<posisi<<" dihapus! \n";
	tampilkanData(head);

	return 0;
}
