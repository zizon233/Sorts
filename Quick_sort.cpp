#include <vector>
using namespace std;

void Quick_sort(vector<int> &arr, int sidx, int eidx){
    if(eidx-sidx<2) {
        return;
    }
    int pivot = sidx++, last = eidx--;
    while(1){
        while (sidx < last && arr[sidx]<=arr[pivot]) sidx++;
        while (eidx > pivot && arr[eidx]>=arr[pivot]) eidx--;
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
    Quick_sort(arr, pivot, eidx);
    Quick_sort(arr, eidx+1, last);
}