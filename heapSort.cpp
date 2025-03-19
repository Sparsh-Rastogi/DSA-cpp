#include <bits/stdc++.h>
using namespace std;
int parent(int i){return (i-1)/2;}
int left(int i){return 2*i +1;}
int right(int i){return 2*i +2;}
void heapifyUp(vector<int> &v, int i){
    if(i==0){return;}
    if(v[i]<v[parent(i)]){
        swap(v[i],v[parent(i)]);
    }
    heapifyUp(v,parent(i));
    return;
}
void heapifyDown(vector<int> &v, int i,int size){
    // cout << "size: " << size << endl;
    if(left(i)>=size && right(i)>=size){
        return;
    }
    else if(left(i)>=size){
        if(v[i]>v[right(i)]){
            swap(v[i],v[right(i)]);
            heapifyDown(v,right(i),size);
        }
        return;
    }
    else if(right(i)>=size){
        if(v[i]>v[left(i)]){
            swap(v[i],v[left(i)]);
            heapifyDown(v,left(i),size);
        }
        return;
    }
    else{
        if(v[right(i)]<v[left(i)]){
            if(v[i]>v[right(i)]){
                swap(v[i],v[right(i)]);
                heapifyDown(v,right(i),size);
            }
            return;
        }
        else{
            if(v[i]>v[left(i)]){
                swap(v[i],v[left(i)]);
                heapifyDown(v,left(i),size);
            }
            return;
        }
    }
}
void buildHeap(vector<int> &v){
    for(int i =0;i<v.size();i++){
        heapifyUp(v,i);
    }
    return;
}
void printv(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void heapSort(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        swap(v[v.size()-i-1],v[0]);
        heapifyDown(v,0,v.size()-i-1);
        // printv(v);
    }
}


int main(){
    vector<int> v = {1,11,9,5,13,3,23};
    buildHeap(v);
    printv(v);
    heapSort(v);
    printv(v);
}