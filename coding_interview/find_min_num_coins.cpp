#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int find_min_num(vector<int> coins, int value){
	
	if (value <= 0)
		return 0;

	vector<int> ways(value+1, 0);

	for (int i = 0; i <= value; i++){
		int min_way = INT_MAX;
		for (int j = 0; j < coins.size(); j++){
			if (i - coins[j] >= 0 && ways[i-coins[j]] < min_way){
				min_way = ways[i - coins[j]];
			}
		}
		if (min_way != INT_MAX)
			ways[i] = min_way + 1;
	}
	return ways[value];
}

int main(){
	int v[] = { 3, 6, 7 };
	vector<int> coins(v, v + sizeof(v) / sizeof(int));
	cout << find_min_num(coins, 1) << endl;
	system("pause");
	return 0;
}
