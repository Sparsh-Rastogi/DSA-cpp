#include <bits/stdc++.h>
using namespace std;
vector<int> prefixSum(vector<int> &v){
    vector<int> prefix;
    for(int i = 0;i<v.size();i++){
        if(i==0){
            prefix.push_back(v[i]);
            continue;
        }
        prefix.push_back(prefix[i-1]+v[i]);
    }
    return prefix;
}
vector<int> differenceArr(vector<int> &v){
    vector<int> diff;
    for(int i = 0;i<v.size();i++){
        if(i==0){
            diff.push_back(v[i]);
            continue;
        }
        diff.push_back(v[i] - v[i-1]);
    }
    return diff;
}
void printv(vector<int> &v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,7,0,0};
    vector<int> output = prefixSum(v);
    printv(output);
    output = differenceArr(output);
    printv(output);
}
