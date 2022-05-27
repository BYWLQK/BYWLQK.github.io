#include<iostream>

using namespace std;

const int N = 100010;

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int i = l - 1,j = r + 1, n = i+j >>1;
    while(i<j){
        while(q[++i]<q[n]);
        while(q[--j]>q[n]);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,i),quick_sort(q,i+1,r);
}

int main(){
    int q[N],n=0;
    scanf("%d",&n);

    for(int i = 0; i<n;i++)
        scanf("%d",&q[i]);
    
    quick_sort(q,0,n-1);

    for(int i = 0;i <n ;i++)
        printf("%d ",q[i]);


    return 0;
}