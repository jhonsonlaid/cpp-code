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
void arange(vector<int>& nums, vector<int>& unks, vector<int>& new_vec, int& count, const int k){
    if(unks.size() == 0){
        int j = 0;
        vector<int> tmp(nums);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                tmp[i] = new_vec[j++];
            }
            else{
                tmp[i] = nums[i];
            }
        }
        if(count_nums(tmp) == k)
            count += 1;
    }
    for(int i = 0; i < unks.size(); i++){
        vector<int> tmp(unks), new_tmp(new_vec);
        tmp.erase(tmp.begin() + i);
        new_tmp.push_back(unks[i]);
        arange(nums, tmp, new_tmp, count, k);
    }
}
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }
    vector<int> kns, unks;
    for(int i = 1; i <= n; i++){
        bool found = false;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == i){
                found = true;
                break;
            }
        }
        if(!found){
            unks.push_back(i);
        }
        else{
            kns.push_back(i);
        }
    }
    int count = 0;
    vector<int> new_vec;
    arange(nums, unks, new_vec, count, k);
    cout << count << endl;
    return 0;
}
