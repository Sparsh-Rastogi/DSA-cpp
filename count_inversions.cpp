#include <bits/stdc++.h>
using namespace std;

long long merging(vector<int> &v, int start, int mid, int end){
    vector <int> temp;
    int i = start; int j = mid+1;
    long long count_inv = 0;
    while(i<=mid && j<=end){
        if(v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            count_inv += mid-i+1;
            // cout << i << " " << j << " " << count_inv << endl;
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
    return count_inv;
}
//end is the last index of the array
long long recursive_merge(vector<int> &v, int start, int end){
    long long count_inv = 0;
    if(start<end){
        int mid = start + (end-start)/2;
        count_inv += recursive_merge(v,start,mid);
        count_inv+= recursive_merge(v,mid+1,end);

        count_inv += merging(v,start,mid,end);
    }
    return count_inv;
}

int main(){
    vector<int> v = {2,3,5,10,2,6,8,9,1};
    cout << recursive_merge(v,0,8);
}