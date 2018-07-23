#include <iostream>
#include <vector>
using namespace std;

int partion(vector<int>& v, int lo, int hi){
	int key = v[hi];
	int idx = lo;
	for (int i = lo; i < hi; i++){
		if (v[i] < key){
			swap(v[i], v[idx++]);
		}
	}
	swap(v[idx], v[hi]);
	return idx;
}

void quick_sort(vector<int>& v, int lo, int hi){
	if (lo >= hi) return;
	int idx = partion(v, lo, hi);
	quick_sort(v, lo, idx-1);
	quick_sort(v, idx + 1, hi);
}

int main(){
	vector<int> v = { 5, 8, 7, 2, 3, 1 };
	int lo = 0, hi = v.size() - 1;
	quick_sort(v, 0, hi);
	for (auto e : v){
		cout << e << " " << endl;
	}
	system("pause");
	return 0;
}
