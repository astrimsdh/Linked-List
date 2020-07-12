#include <iostream>
#include <string>

using namespace std;

class Cucian{
public:
	string nama;
	int berat;
	int harga;
	string alamat;
	string status;
	Cucian* next;
};

Cucian* firstCucian;
Cucian* lastCucian;

void buatKosong(){
	firstCucian = NULL;
	lastCucian = NULL;
}

bool isCucianKosong(){
	return (firstCucian == NULL);
}

int hitungJumlahCucian(){
	int jumlah = 0;
	if (isCucianKosong() == false)
	{
		Cucian* bantu = firstCucian;
		while(bantu != NULL){
			jumlah++;

			bantu = bantu->next;
		}
	}

	return jumlah;
}

void cetakIsiCucian(){
	cout<<"Jumlah Cucian : "<<hitungJumlahCucian()<<endl;
	cout<<"======================================"<<endl;
	if (isCucianKosong() == false)
	{
		Cucian *bantu = firstCucian;
		int i = 1;
		while(bantu != NULL){
			cout<<"Nama     : "<<bantu->nama<<endl;
			cout<<"Berat    : "<<bantu->berat<<" kg"<<endl;
			cout<<"Harga    : Rp. "<<bantu->harga<<" ,-"<<endl;
			cout<<"Alamat   : "<<bantu->alamat<<endl;
			cout<<"Status   : "<<bantu->status<<endl;
			bantu = bantu->next;
			i++;
			cout<<"-----------------------------------\n\n";
		}
		cout<<"\n";
	}else{
		cout<<" ANTRIAN KOSONG"<<endl;
	}
	cout<<"====================================="<<endl;
}

void tambahCucian(string nama_baru, int berat_baru, int harga_baru, string alamat_baru){
	Cucian* cucian_baru = new Cucian();
	cucian_baru->nama = nama_baru;
	cucian_baru->berat = berat_baru;
	cucian_baru->harga = harga_baru;
	cucian_baru->alamat = alamat_baru;
	cucian_baru->status = "Belum di Cuci";
	cucian_baru->next = NULL;
	if (isCucianKosong() == true)
	{
		firstCucian = lastCucian = cucian_baru;
	}
	lastCucian->next = cucian_baru;
	lastCucian = cucian_baru;
}

int main(){
	firstCucian = new Cucian();
	lastCucian = new Cucian();

	buatKosong();
	tambahCucian("Astri Musidah", 1, 40000, "Cibona");
	tambahCucian("Anggie Anggara", 1, 60000, "Panyingkiran");
	cetakIsiCucian();

	return 0;
}