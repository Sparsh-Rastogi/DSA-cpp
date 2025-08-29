#include <bits/stdc++.h>
using namespace std;

vector<long long> factt;
void nthLexoORder(vector<int>& v, int n){
    //Assuming v[0] is irrelevant 
    //The vector size is v.size()-1
    int last = v.size()-1;
    int start = max(1,last-15);
    n--;
    while(n>0){
        if(factt[last-start]>n){
            start++;
            continue;
        }
        int q = n/factt[last-start];
        swap(v[start],v[start+q]);
        sort(v.begin()+start+1,v.end());
        n -= factt[last-start]*q;
        start++;
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
    int n = 15;
    factt.push_back(1);
    for(int i= 1;i<=n;i++){
        factt.push_back(factt[i-1]*i);
    }
    vector<int> v = {INT_MIN,1,2,3,4,5,6,7,8,9,10,11,12,13};
    for(int i = 1;i<16;i++){
        nthLexoORder(v,i);
        printv(v);
        sort(v.begin(),v.end());
    }
    cout << "hello" << endl;
    return 0;
}