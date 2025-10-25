#include<iostream>
#include<vector>
using namespace std;

void Erast(int a){
    vector<bool> primes (a+1, true);
    primes[0] = 0;
    primes[1] = 0;
    for(int i = 2; i < a+1; i++){
        if(primes[i]){
            for(int j = i*i; j < a+1; j+=i){
                primes[j] = 0;
            }
        }
    }
    for(int i = 0; i < a+1; i++){
        if(primes[i]) cout << i << endl;
    }
}

int main(){
    Erast(100);
}