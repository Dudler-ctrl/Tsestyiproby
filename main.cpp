#include <iostream>

using namespace std;

//Technika programowanie - proceduralne ( procedury- podprogramy - funkcje)
//Technika programowania obiektowe ( obiekty )


char tab[3][3];
bool isMoveOK(int x, int y, char sign){
    if (x<0 or x >2 or y < 0 or y >2 ){
        return false;
    }
    if (tab[x][y] != ' '){
        return false;
    }
    return true;
}

void move(int x, int y, char sign){
    tab[x][y] = sign;
}

void print(){
    cout <<" _ _ _" <<endl;
    for(int y=0; y<3; y++){
        for (int x=0; x<3; x++){
            cout << "|";
            if(tab[x][y]==' ' ){
                cout << "_";
            }
            else{
                cout << tab[x][y];
            }
        }
        cout << "|" <<endl;
    }
}

bool isWinInRow(int y, char sign){
    return tab[0][y]==sign and tab[1][y]==sign and tab[2][y]==sign;
}
bool isWinInCol(int x, char sign){
    return tab[x][0]==sign and tab[x][1]==sign and tab[x][2]==sign;
}
bool isWinInDiagonal(char sign){
    return (tab[0][0]==sign and tab[1][1]==sign and tab[2][2]==sign) or
           (tab[2][0]==sign and tab[1][1]==sign and tab[0][2]==sign);
}

bool isArrayFull(){
    for(int y=0; y<3; y++){
        for (int x=0; x<3; x++){
            if (tab[x][y]==' '){
                return false;
            }
            //else...   // !!!!!!!!!!
        }
    }
    return true;
}

bool isEndOfGame(char &whoWon){
    for(int i=0; i<3; i++){
        if( isWinInRow( i,'o') or
            isWinInCol( i,'o')){
            whoWon = 'o';
            return true;
        }
        else if (isWinInCol( i,'x') or
            isWinInRow( i,'x') ){
            whoWon = 'x';
            return true;
        }
    }
    if (isWinInDiagonal('o')){
        whoWon = 'o';
        return true;
    }
    else if(isWinInDiagonal('x')){
        whoWon = 'x';
        return true;
    }
    else if (isArrayFull()){    //remis
        whoWon = 'd';   //DRAW
        return true;
    }
    else{
        return false;
    }
}


void init(){
    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            tab[x][y]= ' ';
        }
    }
}
//
//int funkcja(int a){ //a = 10 PRZEKAZYWANIE PRZEZ WARTOSC (PRZEZ KOPIE)
//    a++;
//    //cout << a <<endl;
//}

void funkcja(int &chudy){ //a = 10, PRZEKAZYWANIE PRZEZ REFERENCJE(CHUDY - INNA NAZWA TEJ SAMEJ ZMIENNEJ (W ORYGINALE JASIU) ( "PRZEZWISKO"/ ALIAS / REFERENCJA - ODNIESIENIE)
    chudy = 100;
    //cout << a <<endl;
}

int fun(){
    return 100;
}





int main()
{
//    int jasiu;
//    funkcja(jasiu);
//    int x = fun();
//    cout << jasiu <<endl;
//    cout << x <<endl;

//
    init();
    int x,y;
    char sign ='x';

    char whoWon;
    while(!isEndOfGame(whoWon)){
        print();
        do{
            cout << "Podaj (x y): " <<endl;
            cin >> x >> y;
        } while(!isMoveOK(x,y,sign));
        move(x,y,sign);
        if(sign == 'x'){
            sign = 'o';
        }
        else{
            sign = 'x';
        }
    }

    //TODO : wyswietl plansze i napisz kto wygral
    print();
    if (whoWon == 'x'){
        cout << "Wygral X" <<endl;
    }
    else if(whoWon == 'o'){
        cout << "Wygralo O" <<endl;
    }
    else{
        cout << "Remis " <<endl;
    }

                 //012
//    string imie = "Ala ma kota";    // imie - obiekt, string - klasa
//    //string imie;    // imie - zmienna, string - typ danych
//
//    cout << imie.length() <<endl;
//    //cout << imie.at(0);
//
//    for (int i=imie.length()-1; i>=0; i--){
//        cout << imie.at(i);
//    }
//    cout << endl;
//    imie = imie + " a";     // + KONKATENACJA ( dodawania napisow, laczenia napisow)
//    cout << imie <<endl;

    return 0;
}
