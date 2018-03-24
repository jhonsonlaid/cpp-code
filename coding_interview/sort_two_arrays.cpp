#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortTwoArray(vector<int>& a1, vector<int>& a2){
	int size1 = 0, size2 = a2.size();
	for (int i = 0; i < a1.size() && a1[i] != -1; i++){
		size1++;
	}

	int idx1 = size1 - 1;
	int idx2 = size2 - 1;
	int new_idx = size1 + size2 - 1;

	while (idx1 >= 0 && idx2 >= 0){
		if (a2[idx2] > a1[idx1]){
			a1[new_idx--] = a2[idx2--];
		}
		else{
			a1[new_idx--] = a1[idx1--];
		}
	}
}

int main(){
	vector<int> a1 = { 1, 3, 5, 7, 9 };
	a1.resize(50, -1);
	vector<int> a2 = { 2, 4, 5, 8, 10 };
	sortTwoArray(a1, a2);
	for (int i = 0; i < a1.size() && a1[i] != -1; i++){
		cout << a1[i] << " ";
	}
	system("pause");
    return 0;
}
