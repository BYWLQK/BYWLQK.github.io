#include<iostream>

using namespace std;

double n;

bool check(double x){
    return (x * x) > n ? 1 : 0; 
}

double bsearch_float(double l, double r){
    const double eps = 1e-8;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }
        else    
            l = mid;
    }
    return l;
}

int main(){

    scanf("%lf",&n);

    double res = 0;
    if(n >= 1)
        res = bsearch_float(1,n);
    else
        res = bsearch_float(0,1);

    printf("%lf",res);

    return 0;
}