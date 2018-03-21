#include <iostream>
#include <vector>

/*
 max: O(nlogn)
 min: O(nlogn)
 mean: O(nlogn)
 stable
*/

using namespace std;

void merge(vector<int>& v, int lo , int mid,  int hi){
    int i = lo, j = mid + 1;
    vector<int> tmp(hi - lo + 1, -1);
    int k = 0;
	// v to tmp
    while(i <= mid && j <= hi){
        if(v[i] <= v[j])
            tmp[k++] = v[i++];
        else
            tmp[k++] = v[j++];
    }
    while(i <= mid){
        tmp[k++] = v[i++];
    }
    while(j <= hi){
        tmp[k++] = v[j++];
    }
	// tmp to v
    for(int m = 0, s = lo; m <= hi - lo; m++){
        v[s++] = tmp[m];
    }
}

void mergeSortRecursion(vector<int>& v, int lo, int hi){
    if(lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSortRecursion(v, lo, mid);
    mergeSortRecursion(v, mid+1, hi);
    merge(v, lo, mid, hi);
}

int main(){
    vector<int> v = {3, 1, 5, 2, 9, 7, 2, 3};
	mergeSortRecursion(v, 0, v.size() - 1);
	for (auto e : v){
		cout << e << " ";
	}
    system("pause");
    return 0;
}
