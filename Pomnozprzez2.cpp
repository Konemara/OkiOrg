#include <iostream>
using namespace std;

void PomnozPrzez2 (int liczba) {
    liczba *= 2;
    cout << liczba << endl;
}
int main(){
    int cena = 7;
    PomnozPrzez2(cena);
    return 0;
}