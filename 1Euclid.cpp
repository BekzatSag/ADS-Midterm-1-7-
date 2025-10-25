#include<iostream>
using namespace std;

int Euclid(int a, int b){
    if(b==0) return a;
    return Euclid(b, a%b);
}

int main(){
    cout << Euclid(10, 5) << endl;
}