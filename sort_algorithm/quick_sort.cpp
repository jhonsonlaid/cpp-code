#include <iostream>
#include <vector>

using namesapce std;

void swap(vector<int>& v, int i, int j){
    int tmp = v[i];
    v[i] = tmp;
    v[j] = v[i];
}

int partion(vector<int>& v, int lo, int hi){
    int ele = v[hi];
    int tail = lo;
    for(int i = lo; i < hi-1; i++){
        if(v[i] < ele)
            swap(v, tail++, i);
    }
    swap(v, tail, hi);
    return tail;
}

void quickSort(vector<int>& v, int lo, int hi){
    if(lo >= hi) return;
    int p = partion(v, lo, hi);
    quickSort(v, lo, p-1);
    quickSort(v, p+1, hi);
}

int main(){
    vector<int> v = {5, 2, 9, 4, 7, 6, 1, 3, 8};
    quickSort(v, 0, v.size()-1);
    sytem("pause");
    return 0;
}
