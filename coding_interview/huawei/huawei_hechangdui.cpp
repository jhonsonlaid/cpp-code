#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int k;
	while (cin >> k){
		vector<int> t(k);
		for (int i = 0; i < k; i++){
			int tmp;
			cin >> t[i];
		}
		vector<int> dp1(k, 1);
		vector<int> dp2(k, 1);
		for (int i = 1; i < k; i++){
			for (int j = 0; j < i; j++){
				if (t[j] < t[i])
					dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
		for (int i = k - 2; i >= 0; i--){
			for (int j = k - 1; j > i; j--){
				if (t[j] < t[i])
					dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
		int max_num = 0;
		for (int i = 0; i < k; i++){
			max_num = max(dp1[i] + dp2[i], max_num);
		}
		cout << k - max_num + 1 << endl;
	}
	return 0;
}
