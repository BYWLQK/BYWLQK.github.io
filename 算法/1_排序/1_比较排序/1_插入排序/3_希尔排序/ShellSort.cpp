#include<iostream>

using namespace std;

const int N = 100010;

void InsertSort(int arr[], int l, int r, int d){
    if(l >= r) return;

    int i = l + d;
    while(i <= r){
        int j = i - d, tmp = arr[i];
        //while(j >= l && arr[i] < arr[j]){
        while(j >= l && arr[i] > arr[j]){
            
            j -= d;
        }
        
        int k = i;
        while(k > j){
            arr[k] = arr[k - d];

            k -= d;
        }

        arr[j + d] = tmp;

        i += d;
    }
}

void ShellSort(int arr[], int l, int r){
    int d = r + l >> 1;
    while(d >= 1){
        int n = (l + r) / d;
        for(int i = 0; i < n; i++){
            InsertSort(arr, l + i, r, d);
        }

        d = d / 2;
    }
}

int main(){
    int a[N],n;

    scanf("%d",&n);

    for(int i =0 ;i<n;i++)
        scanf("%d",&a[i]);

    ShellSort(a ,0 ,n-1);

    for(int i =0 ;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}