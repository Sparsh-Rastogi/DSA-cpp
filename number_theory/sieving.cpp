#include <bits/stdc++.h>
using namespace std;
int primes[100001];
void PRIME_sieve(){
    for(int i = 0;i<100001;i++){primes[i]=-1;}
    for(int i = 2;i*i < 100001;i++){
        if(primes[i]==-1){
            primes[i]=i;
            for(int j = i*i;j<100001;j+=i){
                primes[j]=i;
            }
        }
    }
}
int main(){
    int ctr = 0;
    PRIME_sieve();
    //printing the first 100 primes
    /*
    for(int i =2;ctr<100;i++){
        if(primes[i]==-1){
            cout << i << " ";
            ctr++;
        }
    }
    */
    int n = 62595;
    while(primes[n]!=n){
        cout << primes[n] << " ";
        n/=primes[n];
    }
    cout << primes[n] << endl;
}