#include <iostream>
#include <vector>

/*
 max: O(n^2)
 min: O(n)
 mean: O(n^2)
 stable
*/

using namespace std;

vector<int> shellSort(vector<int>& v, int step){
	int h = 1, n = v.size();

	while (h < n / step){
		h = step * h + 1; //max init step
	}

	while (h >= 1){
		for (int i = h; i < n; i++){
			int j, new_ele = v[i];
			for (j = i - h; j >= 0 && v[j] > new_ele; j -= h){
				v[j + h] = v[j];
			}
			v[j + h] = new_ele;
		}
		h = h / step;
		// cout << " h: " << h << endl;
	}
	return v;
}

int main(){
    vector<int> vec = {6, 4};
    vector<int> res = shellSort(vec, 3);
    for(auto e: res)
        cout << e << " "; 
    system("pause");
    return 0;
}
