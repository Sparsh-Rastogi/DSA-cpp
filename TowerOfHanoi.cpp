#include <bits/stdc++.h>
using namespace std;

void TowerHanoi(int n, char from, char to, char other){
    if(n==0){ return; }
    TowerHanoi(n-1,from,other,to);
    cout << "Move disk " << n << " from tower " << from << " to tower " << to << endl;
    TowerHanoi(n-1,other,to,from);
    return;
}
int main(){
    int n;
    cout << "Enter number of disks to be transferred from TowerA to TowerC: " << endl;
    cin >> n;
    TowerHanoi(n,'A','C','B');

}