#include <iostream>
#include <vector>
using namespace std;
 
int count_nums(vector<int>& nums){
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[j] > nums[i])
                count++;
        }
    }
    return count;
}
 
int get_count(vector<int> nums, vector<int>& unks){
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0)
            nums[i] = unks[j++];
    }
    return count_nums(nums);
 
}
 
void arange(vector<int>&nums, vector<int>& unks, int idx, int& count, const int k){
    if(idx == unks.size()){
		if (get_count(nums, unks) == k)
			count++;
    }
    for(int i = idx; i < unks.size(); i++){
        swap(unks[i], unks[idx]);
        arange(nums, unks, idx+1, count, k);
        swap(unks[i], unks[idx]);
    }
}
 
int main(){
    int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		nums[i] = tmp;
	}
	vector<int> kns, unks;
	for (int i = 1; i <= n; i++){
		bool found = false;
		for (int j = 0; j < nums.size(); j++){
			if (nums[j] == i){
				found = true;
				break;
			}
		}
		if (!found){
			unks.push_back(i);
		}
		else{
			kns.push_back(i);
		}
	}
	int count = 0;
	arange(nums, unks, 0, count, k);
	cout << count << endl;
    return 0;
}
