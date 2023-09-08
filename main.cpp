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

void isEven(int T[]){
    int Even = 0;
    int notEven = 0;
    pair<int, int> pair1;
    for (int i=0 ; i<N ; i++ ){
        if((T[i]%2) == 0) Even++;
        else notEven++;
    }
    cout << "Parzyste: " << Even << "\nNieparzyste: " << notEven;
}