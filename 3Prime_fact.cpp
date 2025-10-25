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

bool prime(int a){
    if(a==1 || a==0) return false;
    for(int i = 2; i * i <= a; i++){
        if(a%i==0) return false;
    }
    return true;
}

vector<int> prime_factor(int x){
    vector<int> primes;
    vector<int> factors_primes;
    for(int i = 2; i <= x; i++){
        if(prime(i)) primes.push_back(i);
    }
    int i = 0;
    int num = x;
    for(int i = 0; i < primes.size(); i++){
        while (num%primes[i]==0) {
            factors_primes.push_back(primes[i]);
            num/=primes[i];
        }
        if(num==1) break;
    }
    return factors_primes;
}

vector<int> prime_factor_(int x){
    vector<int> factors_primes;
    if (x <= 1) return factors_primes;
    for(int i = 2; i * i<= x; i++){
        while(x%i==0) {
            factors_primes.push_back(i);
            x/=i;
        }
        if(x==1) break;
    }
    if(x > 1) factors_primes.push_back(x);
    
    return factors_primes;
}


int main(){
    vector<int> v= prime_factor_(100);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}