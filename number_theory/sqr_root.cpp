#include <bits/stdc++.h>
using namespace std;

long long sqrRoot(long long a, int isFloor=1){
    int l = 1;
    int h = a;
    int mid;
    int ctr=0;
    while(l<=h){
        ctr++;
        mid = l + ((h-l)/2);
        //cout << l << endl;
        if(mid*mid==a){
            return mid;
        }
        else{
            if(mid*mid>a){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    return h+(isFloor&&(h*h!=a)?0:1);
}

int main(){
    cout << sqrRoot(255);
}