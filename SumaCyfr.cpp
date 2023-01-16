#include <iostream>
using namespace std;

int Sumacyfr (long long liczba){
	int suma_cyfr;
    suma_cyfr = 0;
	while(liczba > 0){
        suma_cyfr +=(liczba % 10);
        liczba = liczba / 10;
    }
    return suma_cyfr;
}

int main() {
	long long cena = 153;
	cout << SumaCyfr(cena) << endl;
	long long cena = 2137;
	cout << SumaCyfr(cena) << endl;
	return 0;
}
