#include <iostream>
#include <vector>

/*
 max: O(n^2)
 min: O(n)
 mean: O(n^2)
 stable
*/
using namespace std;

vector<int> bubbleSort(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
		int cmp_flag = 0;
        for(int j = 0; j < v.size() - 1 - i; j++){
            if(v[j] > v[j+1]){
				cmp_flag = 1;
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
		if (cmp_flag == 0) return v;
    }
    return v;
}

int main(){
    vector<int> vec = {3, 2, 9, 7, 1};
    vector<int> res = bubbleSort(vec);
    for(auto e: res)
        cout << e << " "; 
    system("pause");
    return 0;
}
