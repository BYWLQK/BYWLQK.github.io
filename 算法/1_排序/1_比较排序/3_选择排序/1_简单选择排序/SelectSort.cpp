#include<iostream>

using namespace std;

const int N = 100010;

void SelectSort(int arr[], int l, int r){
    if(l>=r) return;

    for(int i = l; i < r; i ++){
        int k = i;
        for(int j = i; j <= r; j ++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        if(k > i)
            swap(arr[k], arr[i]);
    }
}

int main(){
    int arr[N],n=0;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    SelectSort(arr, 0 , n-1);

    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);

    return 0;
}