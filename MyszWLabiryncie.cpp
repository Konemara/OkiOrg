#include <iostream>
#include <string>
char tab[1002][1002];
void Ruch(int x, int y){
    tab[x][y] = 'x';
    if(tab[x + 1][y] != 'x')
        Ruch(x + 1, y);
    if(tab[x - 1][y] != 'x')
        Ruch(x - 1, y);
    if(tab[x][y + 1] != 'x')
        Ruch(x, y + 1);
    if(tab[x][y - 1] != 'x')
        Ruch(x, y - 1);
    }
    
int main(){
    using namespace std;
    
    int MAXX, MAXY;
    cin >> MAXX >> MAXY;
    
    int Ex, Ey;
    int Sx, Sy;
    
    for(int i = 0; i < MAXX + 2; ++i){
        tab[i][MAXY + 2] = 'x';
        tab[i][0] = 'x';
    }
    
    for(int i = 0; i < MAXY + 2; ++i){
        tab[MAXX + 2][i] = 'x';
        tab[0][i] = 'x';
    }
    
    for(int y = 0; y < MAXX; ++y){
        string Line;
        cin >> Line;
        for(int x = 0; x < MAXX; ++x){
            tab[x+1][y+1] = Line[x];
            if(Line[x] == 'w')
                Ex = x, Ey = y;
            else if(Line[x] == 'o')
                Sx = x, Sy = y;
        }
    }
    
    Ruch(Sx+1, Sy+1);
    
    if(tab[Ex+1][Ey+1] == 'x')
        cout << "TAK";
    else
        cout << "NIE";
        
    return 0;
}
