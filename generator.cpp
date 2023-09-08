#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

const int N=1e3;

int main() { 
    srand(time(NULL));  
    ofstream out ("dane.txt");
    int x;
    for (int i=0 ; i<N ; i++ ) {        
        out << (rand() % 1000) << "\n";
    }   
    out.close();
}  