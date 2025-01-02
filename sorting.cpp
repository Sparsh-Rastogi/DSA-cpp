#include <bits/stdc++.h>
using namespace std;
void bubble(vector<int> &v){
    for(int i = 0;i<v.size()-1;i++){
        for(int j = 0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
void selection(vector<int> &v){
    for(int i = 0;i<v.size()-1;i++){
        int m = i;
        for(int j = i;j<v.size();j++){
            if(v[j]<v[m]){
                m=j;
            }
        }
        swap(v[m],v[i]);
    }
}
void insertion(vector<int> &v){
    if(v.size()<=1){ return;}
    for(int i =1;i<v.size();i++){
        for(int j = 0;j<i;j++){
            if(v[i]<v[j]){
                swap(v[i],v[j]);
            }
        }
    }
}
void printv(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v = {3,6,3,8,2,4,0,9,7};
    insertion(v);
    printv(v);
    return 0;
}