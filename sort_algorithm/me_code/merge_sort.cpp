#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int lo, int hi){
	vector<int> tmp;
	int mid = (lo + hi) >> 1;
	int i, j;
	for (i = lo, j = mid+1; i <= mid && j <= hi; ){
		if (v[i] <= v[j]){
			tmp.push_back(v[i++]);
		}
		else{
			tmp.push_back(v[j++]);
		}
	}
	while (i <= mid){
		tmp.push_back(v[i++]);
	}
	while (j <= hi){
		tmp.push_back(v[j++]);
	}
	for (int i = 0; i < hi - lo + 1; i++){
		v[lo + i] = tmp[i];
	}
}
void merge_sort(vector<int>& v, int lo, int hi){
	if (lo >= hi) return;
	int mid = (lo + hi) >> 1;
	merge_sort(v, lo, mid);
	merge_sort(v, mid + 1, hi);
	merge(v, lo, hi);
}
int main(){
	vector<int> v = { 5, 8, 7, 2, 3, 1 };
	int lo = 0, hi = v.size() - 1;
	merge_sort(v, 0, hi);
	for (auto e : v){
		cout << e << " " << endl;
	}
	system("pause");
	return 0;
}
