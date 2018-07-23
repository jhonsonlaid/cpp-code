#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cows(n, 0);
    int all = 0, mean;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cows[i] = tmp;
        all += tmp;
    }
    mean = all / n;
    if(all % n != 0){
        return -1;
    }
    int less_count, more_count;
    for(int i = 0; i < n; i++){
        int diff = cows[i] - mean;
        if(diff % 2 != 0)
            return -1;
        else{
            if(diff > 0)
                more_count += diff / 2;
            else
                less_count += -(diff / 2);
        }
    }
    return more_count == less_count ? more_count : -1;
}
