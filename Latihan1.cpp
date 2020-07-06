#include <iostream>
using namespace std;

int main(){
	int var = 50;
	int angka = 1;
	int *ptr = &var;

	cout<<&var<<" memiliki nilai "<<var<<endl;
	cout<<"ptr = "<<ptr<<endl;

	ptr = &angka;
	cout<<"ptr = "<<ptr<<endl;
	cout<<&angka<<" memiliki nilai "<<angka<<endl;
	return 0;
}
