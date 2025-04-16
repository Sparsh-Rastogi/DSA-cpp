#include <bits/stdc++.h>
using namespace std;

//Assuming every character to be distinct

void permutations(string s,int* arr, int n , int ctr){
    if(ctr==n){
        for(int i = 0;i<n;i++){
            cout<<s[arr[i]];
        }
        cout << endl;
        return;
    }
    for(int i = 0;i<n;i++){
        if(arr[i]==-1){
            arr[i] = ctr;
            permutations(s,arr,n,ctr+1);
            arr[i] = -1;
        }
    }
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = -1;
    }
    permutations(s,arr,n,0);

}