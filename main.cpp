#include<iostream>
#include<fstream>
#include<time.h>
#include <utility>
#include <vector>
using namespace std;

const int N=1e3;
int T[N];

float favg();
void minmax(int &minv, int &maxv);
void isEven(int T[]);
void incrs(int T[]);
void decrs(int T[]);
void itsOverTwelveHundred(int T[]);

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
    cout << "\n";
    decrs(T);
    cout << "\n";
    itsOverTwelveHundred(T);
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


//Zadanie domowe 2
 void incrs(int T[]){

    int max_lenght = 1;
    int start;
    int lenght = 1;
    int p = 0;
    vector<int> longest_temp;
    vector<int> longest;

    start = p;
    for (int i=1;i<N;i++){
        if(T[i]>T[i-1]){
            ++lenght;
            longest_temp.push_back(T[i]);
            if(lenght>max_lenght){
                max_lenght = lenght;
                start = p;
                longest = longest_temp;
            }
        }
        else{
            p = i;
            lenght = 1;
            longest_temp.clear();
        }
    }
    //Do poprawy
    cout << "Długosc najdluzszego ciagu rosnacego to: " << max_lenght << ", zaczyna sie w linii " << start+1; 
    cout << "\tJest to ciag: ";
    //Wypisuje pierwszy element ciągu
    cout << T[start] << " ";
    //Reszta ciągu
    for(int i=0;i<longest.size();i++){
        cout << longest.at(i) << " ";
    }
}

void itsOverTwelveHundred(int T[]){
    int bigger= 0;
    for (int i=0;i<N;i++){
        if(T[i]>200) bigger++;
    }
    cout << "Ilosc wiekszych od 200: " << bigger;
}

//Do zaktualizowania 
void decrs(int T[]){
    int max_lenght = 1;
    int start;
    int lenght = 1;
    int p = 0;

    start = p;
    for (int i=1;i<N;i++){
        if(T[i]<T[i-1]){
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
    cout << "Długosc najdluzszego ciagu malejacego to: " << max_lenght << ", zaczyna sie w linii " << start+1;
}