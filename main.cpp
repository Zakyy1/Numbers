#include<iostream>
#include<fstream>
#include<time.h>
#include <utility>
using namespace std;

const int N=1e3;
int T[N];

float favg();
void minmax(int &minv, int &maxv);
void isEven(int T[]);
void incrs(int T[]);

int main() {    
    ifstream in ("dane.txt");
    int x;
    for (int i=0 ; i<N ; i++ ) {        
         in >> T[i];
    }   
    in.close();
    /* srednia */
    float avg = favg();
    cout << "\nSrednia: " << avg;
    /* min max */
    int maxw,minw;
    minmax(minw,maxw);
    cout << "\nMin:" << minw;
    cout << "\nMax:" << maxw;
    cout << "\n";
    isEven(T);
    cout << "\n";
    incrs(T);
}
float favg() {
    float sum = 0;
    for (auto el:T)
        sum += el;
    return sum/N;       
}
void minmax(int &minv, int &maxv) {
    minv=1000;
    maxv=-1000;
    for (auto el:T){
        if (el<minv)
            minv = el;
        maxv = max(maxv,el);    
    }   
}

//Zadanie domowe
void isEven(int T[]){
    int Even = 0;
    int notEven = 0;
    for (int i=0 ; i<N ; i++ ){
        if((T[i]%2) == 0) Even++;
        else notEven++;
    }
    cout << "Parzyste: " << Even << "\nNieparzyste: " << notEven;
}


//Zadanie z kolejnej lekcji
void incrs(int T[]){
    int max_lenght = 1;
    int start;
    int lenght = 1;
    int p = 0;

    start = p;
    for (int i=1;i<N;i++){
        if(T[i]>T[i-1]){
            ++lenght;
            if(lenght>max_lenght){
                max_lenght = lenght;
                start = p;
            }
        }
        else{
            p = i;
            lenght = 1;
        }
    }
    cout << "Długosc najdluzszego ciagu rosnacego to: " << max_lenght << ", zaczyna sie w linii " << start+1;
}