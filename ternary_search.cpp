#include <bits/stdc++.h>
using namespace std;
int TSnormal(vector<int> &v, int target){
    int l=0;
    int r=v.size();
    int m1,m2;
    int ans = -1;
    while(l<r){
        m1 = l +(r-l)/3 ;
        m2 = l + (2*(r-l))/3 ;
        if(v[m1]==target || v[m2]==target){
            ans = v[m1]==target?m1:m2;
            break;
        }
        else if(target<v[m1]){
            r=m1-1;
        }
        else if(target>v[m2]){
            l = m2+1;
        }
        else{
            r = m2-1;
            l = m1+1;
        }
        //cout << l << " " << r << endl;
    }
    return ans;
}
int main(){
    vector<int> v = {1,2,3,4,7,8,9};
    int n;
    cin >> n;
    cout << TSnormal(v,n);

}