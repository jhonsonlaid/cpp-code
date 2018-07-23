#include <iostream>
#include <algorithm>

using namespace std;

void countCoins(vector<int> v, int n, int sum, int &nw){
    if(sum >= n || v.size() < 0){
        if(sum == n) nw++;
        return;
    }
    for(int i = 0; i < v.size(); i++){
        vector<int> tmp_v = v;
        tmp_v.erase(tmp_v.begin(), tmp_v.begin()+i);
        countCoins(tmp_v, n, sum+v[i], nw);
    }
}

int main(){
    int k = 10;
    vector<int> v;
    for(int i = 0; i < 2 * k; i++){
        v.push_back(pow(2, i/k));
    }
    int num_ways = 0;
    countCoins(v, 10, 0, num_ways);
    system("pause");
    return 0;
}
