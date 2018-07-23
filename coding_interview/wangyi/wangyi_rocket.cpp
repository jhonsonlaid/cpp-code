#include <iostream>
#include <math.h>
using namespace std;

int judge(long long h, long long x){
    if(x*x + x > h)
        return 1;
    else
        return -1;
};

int main(){
    long long h;
    cin >> h;
    long long lo = 0, hi = sqrt(h), mid, res;
    while(lo <= hi){
        mid = lo +((hi - lo) >> 1);
        if(judge(h, mid) > 0)
            hi = mid - 1;
        else{
            lo = mid + 1;
            res = mid;
        }
    }
    cout << res << endl;
    return 0;
}
