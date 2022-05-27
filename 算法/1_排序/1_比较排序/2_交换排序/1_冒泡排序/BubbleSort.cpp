#include<iostream>

using namespace std;

const int N = 100010;

void BubbleSort(int arr[], int l, int r){
    if(l>=r) return;

    for(int i = r; i > l; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[N],n=0;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    BubbleSort(arr, 0 , n-1);

    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);

    return 0;
}