#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int binarySearch(vector<int>& v, int value)
{
	int lo = 0, hi = v.size() - 1;
	while (lo <= hi){
		int mid = lo + ((hi - lo) >> 1);
		if (v[mid] > value)
			hi = mid - 1;
		else if (v[mid] < value)
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}


int main(){
	vector<int> v = {0};
	int idx = binarySearch(v, 0);
	cout << idx << endl;
	system("pause");
	return 0;
}
