#include <bits/stdc++.h>
using namespace std;
int BSnormal(vector<int> &v,int target){
    int l = 0;
    int r = v.size();
    while(l!=r){
        if(v[(l+r)/2] == target){
            l = (l+r)/2;
            break;
        }
        if(v[(l+r)/2] > target){
            r = (l+r)/2;
        }
        else{
            if(l== (l+r)/2){
                l++;
                break;
            }
            else{
                l = (l+r)/2 ;
            }
        }
    }
    return l;

}
int BSlowest(vector<int> &v,int target){
    int l = 0;
    int r = v.size();
    while(l!=r){
        if(v[(l+r)/2] == target){
            r = (l+r)/2;
        }
        else if(v[(l+r)/2] > target){
            r = (l+r)/2;
        }
        else{
            if(l== (l+r)/2){
                if(v[l]!=target){l++;}
                break;
            }
            else{
                l = (l+r)/2 ;
            }
        }
        //cout << l << " " << r << endl;
    }
    return l;
}
int BShighest(vector<int> &v,int target){
    int l = 0;
    int r = v.size();
    while(l!=r){
        if(v[(l+r)/2] > target){
            r = (l+r)/2;
        }
        else{
            if(l== (l+r)/2){
                if(v[l]!=target){l++;}
                break;
            }
            else{
                l = (l+r)/2 ;
            }
        }
        cout << l << " " << r << endl;
    }
    return l;
}
int main(){
    vector<int> v = {1,2,5,6,6,6,7,7,9,10};
    cout << BShighest(v,8) << endl;
}