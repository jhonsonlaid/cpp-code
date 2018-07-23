#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>&v, int i, int j){
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void printHeap(vector<int>& v){
	for (auto e : v){
		cout << e << " ";
	}
	cout << endl;
}

void topDown(vector<int>& v, int start, int end){
	for (int j = start; 2 * j + 1 < end; ){
		int left = 2 * j + 1;
		int right = 2 * j + 2;
		int max = j;
		if (left < end && v[left] > v[max])
			max = left;
		if (right < end && v[right] > v[max])
			max = right;
		
		if (j == max){
			break;
		}
		else{
			swap(v, j, max);
			j = max;
		}

	}
}

void buildHeap(vector<int>& v){
	int p = v.size() / 2 - 1;
	for (int i = p; i >= 0; i--){ // O(n)
		topDown(v, i, v.size());
	}
}

void heapSort(vector<int>& v){
	buildHeap(v);
	int size = v.size();
	// printHeap(v);
	for (int j = v.size()-1; j > 0; j--){
		swap(v, 0, j);
		// printHeap(v);
		topDown(v, 0, j);
		// printHeap(v);
	}
}

int main(){
    vector<int> v = {16,7,3,20,17,8};
    heapSort(v);
	printHeap(v);
	cout << endl; 
    system("pause");
    return 0;
}
