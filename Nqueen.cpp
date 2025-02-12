#include <bits/stdc++.h>
using namespace std;

int IsSafe(int** arr, int x, int y, int n){
    for(int j = 0;j<x;j++){
        if(arr[j][y]==1){
            return 0;
        }
    }
    int i = x-1; int j = y-1;
    while(i>=0 && j>=0){
        if(arr[i][j]==1){
            return 0;
        }
        i--;j--;
    }
    i = x-1;j = y+1;
    while(i>=0 && j<n){
        if(arr[i][j]==1){
            return 0;
        }
        i--;j++;
    }
    //cout << x << " " << y << " is safe" << endl;
    return 1;
}

int NQueen(int** arr,int n, int x){
    if(x>=n){
        return 1;
    }
    for(int i = 0;i<n;i++){
        if(IsSafe(arr,x,i, n)){
            arr[x][i] = 1;
            if(NQueen(arr,n,x+1)){
                return 1;
            }
            else{
                arr[x][i] = 0;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter the number of Queens: " << endl;
    cin >> n;
    int** arr = new int*[n];
    for(int i = 0;i<n;i++){
        arr[i] = new int[n];
        for(int j = 0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    if(NQueen(arr,n,0)){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }


}