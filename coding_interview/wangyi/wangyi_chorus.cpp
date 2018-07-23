#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> val;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		val.push_back(tmp);
	}
	int k, d;
	cin >> k >> d;
	vector<vector<long long>> dp_max(n, vector<long long>(k, -100));
	vector<vector<long long>> dp_min(n, vector<long long>(k, -100));

	for (int i = 0; i < n; i++){
		dp_max[i][0] = val[i];
		dp_min[i][0] = val[i];
	}

	for (int i = 1; i < n; i++){
		for (int j = 1; j < k; j++){
			for (int h = max(0, i - d); h <= i - 1; h++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[h][j - 1] * val[i], dp_min[h][j-1] * val[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_max[h][j - 1] * val[i], dp_min[h][j-1] * val[i]));
			}
		}
	}

	long long max_val = 0;
	for (int i = k - 1; i < n; i++){
		max_val = max(max_val, dp_max[i][k - 1]);
	}
    cout << max_val << endl;
}
