#include <iostream>
#include <vector>
#include <list>

using namespace std;

// LSD 从低位开始排序, Least sgnificant digital

int getMaxDigit(vector<int>& v){
	int max = -1;
	for (auto e : v){
		max = e > max ? e : max;
	}
	int digit = 1;
	while ((max /= 10) > 0){
		digit *= 10;
	}

	return digit;
}

void radixSort(vector<int>& v){
	vector<list<int>> bucket(10);
	int md = getMaxDigit(v);
	for (int i = 1; i <= md; i *= 10){
		for (int j = 0; j < v.size(); j++){
			int idx = (v[j] / i) % 10;
			bucket[idx].push_back(v[j]);
		}
		
		// v.erase(v.begin(), v.end());
		int pos = 0;
		for (int k = 0; k < 9; k++){
			for (auto e : bucket[k]){
				v[pos++] = e; // replace original value
			}
			bucket[k].erase(bucket[k].begin(), bucket[k].end());
		}
	}
}

int main(){
    vector<int> v = {2314, 5428, 373, 2222, 17};
    radixSort(v);
	for (auto e : v){
		cout << e << " ";
	}

	cout << endl; 
    system("pause");
    return 0;
}
