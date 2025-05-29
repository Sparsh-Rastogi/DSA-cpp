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
void DNFsort(vector<int> &v){
    int ptr1=0;
    int ptr2=0;
    int ptr3 = v.size()-1;
    while(ptr3>ptr2){
        if(v[ptr2]==0){
            swap(v[ptr1],v[ptr2]);
            ptr2++;
            ptr1++;
        }
        else if(v[ptr2]==1){
            ptr2++;
        }
        else{
            swap(v[ptr2],v[ptr3]);
            ptr3--;
        }
    }
    return;
}
int main(){
    vector<int> v = {1,5,5,4,3,4,5,2,1};
    countSort(5,v);
    printv(v);
    vector<int> v2 = {1,2,0,0,2,1,0,1,2};
    DNFsort(v2);
    printv(v2);
}