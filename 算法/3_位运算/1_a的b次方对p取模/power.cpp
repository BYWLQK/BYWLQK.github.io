#include<iostream>

using namespace std;

int power(int a, int b, int p){//caaculate (a^b) mod p
    int res = 1 % p;
    for(;b; b >>= 1){
        if(b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
    }
    return res;
}

int main(){

    cout << power(1111,4444,2);

    return 0;
}