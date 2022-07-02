#include<iostream>

using namespace std;

const int N = 100010;

void InsertSort(int arr[], int l, int r){
    if(l >= r) return;

    int i = l + 1;
    while(i <= r){
        int m = l, n = i - 1, tmp = arr[i];
        //if(arr[i] < arr[i-1]){
        if(arr[i] > arr[i-1]){
            while(m < n){
                int mid = l + n >> 1;

                //if(arr[mid] >= arr[i]){
                if(arr[mid] <= arr[i]){
                    n = mid;
                }
                else{
                    m = mid + 1;
                }
            }
        }
        else{
            m = i;
        }

        int k = i;
        while(k > m - 1){
            arr[k] = arr[k - 1];

            k--;
        }

        arr[m] = tmp;

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