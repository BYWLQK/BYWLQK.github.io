#include<iostream>

using namespace std;

const int N = 100010;

void InsertSort(int arr[], int l, int r){
    if(l >= r) return;

    int i = l + 1;
    while(i <= r){
        int j = i - 1, tmp = arr[i];
        //while(j >= l && arr[i] < arr[j]){
        while(j >= l && arr[i] > arr[j]){
            
            j--;
        }
        
        int k = i;
        while(k > j){
            arr[k] = arr[k - 1];

            k--;
        }

        arr[j + 1] = tmp;

        i++;
    }
}

int main(){
    int a[N],n;

    scanf("%d",&n);

    for(int i =0 ;i<n;i++)
        scanf("%d",&a[i]);

    InsertSort(a,0,n-1);

    for(int i =0 ;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}