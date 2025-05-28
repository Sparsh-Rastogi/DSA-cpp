#include <bits/stdc++.h>
using namespace std;
void printv(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void countSort(int limit, vector<int> &v){
    vector<int> hash(limit+1,0);
    for(auto &u: v){
        hash[u]++;
    }
    int ptr=0;
    for(auto &u: v){
        // cout << hash[ptr] << endl;
        while(hash[ptr]<=0){
            ptr++;
        }
        u = ptr;
        hash[ptr]--;
    }
    return;
}
int main(){
    vector<int> v = {1,5,5,4,3,4,5,2,1};
    countSort(5,v);
    printv(v);
}