#include <bits/stdc++.h>
using namespace std;

//returns the bit at a position
int getBit(int n, int pos){
    return (n & (1<<pos))!=0;
}

//sets the bit at position to 1
int setBit(int n, int pos){
    return n | (1<<pos);
}

//sets the bit at position to 0
int clearBit(int n, int pos){
    return n & (~ ( 1<<pos));
}

//returns 1 if number is power of 2
int isPowerOf2(int n){
    if(n==0){
        return 0;
    }
    return !(n&(n-1));
}

//counts number of set Bits
int numberOf1s(int n){
    int count = 0;
    while(n){
        n= n&(n-1);
        count++;
    }
    return count;
}
int main(){
    cout << getBit(21,3) << endl;
    cout << getBit(21,4) << endl;
    cout << setBit(21,3) << endl;
    cout << clearBit(21,4) << endl;
    cout << isPowerOf2(64) << endl;
    cout << isPowerOf2(39) << endl;
    cout << numberOf1s(21) << endl;
    cout << numberOf1s(64) << endl;
}