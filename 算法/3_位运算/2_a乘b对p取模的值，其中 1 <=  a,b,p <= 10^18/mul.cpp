#include<iostream>

using namespace std;

long long mul_1(long long a, long long b, long long p){
    long long res = 0;
    for(;b;b >>= 1){
        if(b & 1) res = (res + a) % p;
        a = a * 2 % p;
    }

    return res;
}

long long mul_2(long long a, long long b, long long p){
    a %= p, b %= p;
    long long c = (long double)a * b / p;
    long long res = a * b - c * p;
    if(res < 0) 
        res += p;
    else if(res >= p) res -= p;

    return res;
}

int main(){

    cout << mul_1(22221,11111,2) << " " << mul_2(22221,11111,2) << endl;

    return 0;
}