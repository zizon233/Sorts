#include <iostream>
using namespace std;

void quick_sort(int arr[], int sidx, int eidx){
    if(sidx>=eidx) {
        return;
    }
    int pivot = sidx, last = eidx;
    while(1){
        while (arr[sidx]<=arr[pivot] && sidx <= last) sidx++;
        while (arr[eidx]>=arr[pivot] && eidx > pivot) eidx--;
        if(sidx>eidx) break;
        if(arr[sidx]>arr[eidx]) {
            int temp = arr[sidx];
            arr[sidx] = arr[eidx];
            arr[eidx] = temp;
        }
    }
    int temp = arr[eidx];
    arr[eidx] = arr[pivot];
    arr[pivot] = temp;
    quick_sort(arr, pivot, eidx-1);
    quick_sort(arr, eidx+1, last);
}

int main(){
    int n, * arr;
    arr = new int[10000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}