#include <stdio.h>
int normal(int a, int b){
    int min = a>b?b:a;
    for(int i=2;i<=min;i++){
        if(a%i == 0 and b%i == 0){
            return i*normal(a/i, b/i);
        }
    }
    return 1;
}
int euclidean_diff(int a, int b){
    if(b==0){ return a;}
    else if(a==0){ return b;}
    int min = a>b?b:a;
    return euclidean_diff(a+b - 2*min,min);
    
}
int euclidean_modulo(int a, int b){
    if(b==0){return a;}
    if(a>=b){return euclidean_modulo(b,a%b);}
    else{ return euclidean_modulo(b,a);}
}
int main(){
    printf("%d", euclidean_modulo(1,19));
}