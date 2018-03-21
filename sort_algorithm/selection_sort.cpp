#include <iostream>
#include <vector>

/*
 max: O(n^2)
 min: O(n^2)
 mean: O(n^2)
 Unstable
*/

using namespace std;

vector<int> selectionSort(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
		int min = i;
        for(int j = i + 1; j < v.size(); j++){
			if (v[j] < v[min])
				min = j;
        }
		if(v[min] != v[i]){
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
    return v;
}

int main(){
    vector<int> vec = {3, 2, 9, 7, 1};
    vector<int> res = selectionSort(vec);
    for(auto e: res)
        cout << e << " "; 
    system("pause");
    return 0;
}
