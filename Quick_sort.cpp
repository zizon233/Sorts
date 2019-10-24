#include <vector>
using namespace std;

void Quick_sort(vector<int> &arr, int sidx, int eidx){
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
    Quick_sort(arr, pivot, eidx-1);
    Quick_sort(arr, eidx+1, last);
}