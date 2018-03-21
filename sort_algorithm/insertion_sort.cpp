#include <iostream>
#include <vector>

/*
 max: O(n^2)
 min: O(n)
 mean: O(n^2)
 stable
*/

using namespace std;

vector<int> insertionSort(vector<int>& v){
    for(int i = 0; i < v.size() - 1; i++){
		int j, ele = v[i + 1];
		for (j = i; j >= 0 && ele < v[j]; j--){
			v[j + 1] = v[j];
		}
		v[j + 1] = ele;
	}
    return v;
}

int main(){
    vector<int> vec = {3, 1, 9, 5, 2};
    vector<int> res = insertionSort(vec);
    for(auto e: res)
        cout << e << " "; 
    system("pause");
    return 0;
}
