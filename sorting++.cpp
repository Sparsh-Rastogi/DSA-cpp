#include <bits/stdc++.h>
using namespace std;
void merging(vector<int> &v, int start, int mid, int end){
    vector <int> temp;
    int i = start; int j = mid+1;
    while(i<=mid && j<=end){
        if(v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
            temp.push_back(v[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(v[j]);
        j++;
    }
    for(int i = start;i<=end;i++){
        v[i] = temp[i-start];
    }
    return;
}
//end is last index of the array
void recursive_merge(vector<int> &v, int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;
        recursive_merge(v,start,mid);
        recursive_merge(v,mid+1,end);
        merging(v,start,mid,end);
    }
    return;
}
void iterative_merge(vector<int> &v){
    for(int size = 1;size<=v.size();){
        size*=2;
        for(int i = 0;i<v.size();i+=size){
            merging(v,i,min(i + (size-1)/2,(int)(v.size()-1)),min(i+size-1,(int)(v.size()-1)));
        }
    }
}
int partition(vector<int> &v, int start, int end){
    if(start>=end){return end;}
    int i = -1;
    int pI = end;
    for(int j = 0;j<pI;j++){
        if(v[j]<v[pI]){
            i++;
            swap(v[i],v[j]);
        }
    }
    i++;
    swap(v[i],v[pI]);
    return i;
}
void quick(vector<int> &v,int start, int end){
    if(start<end){
        int pI = partition(v,0,end);
        quick(v,0,pI-1);
        quick(v,pI+1,end);
    }
    return;
}
void printv(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {1,5,2,41,19,13,13,7,3};
    quick(v,0,v.size()-1);
    printv(v);
}