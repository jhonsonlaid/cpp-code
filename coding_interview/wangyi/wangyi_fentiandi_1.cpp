//Time Limit Exceed
#include <iostream>
#include<vector>
using namespace std;

int get_area(vector<vector<int>>&sum, int r1, int c1, int r2, int c2){
    return sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
}
int judge(vector<vector<int>>& sum, int val){
    int n = sum.size()-1, m = sum[0].size() - 1;
    for(int r1 = 1; r1 <= n-3; r1++){
        for(int r2 = r1 + 1; r2 <= n-2; r2++){
            for(int r3 = r2 + 1; r3 <= n-1; r3++){
                int c1 = 0, count = 0;
                for(int c2 = 1; c2 <= m; c2++){
                    if(get_area(sum, 0, c1, r1, c2) >= val &&
                       get_area(sum, r1, c1, r2, c2) >= val &&
                       get_area(sum, r2, c1, r3, c2) >= val &&
                       get_area(sum, r3, c1, n, c2) >= val){
                        count++;
                        c1 = c2;
                    }
                }
                if(count >= 4)
                   return true;
            }
        }
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> farm(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++){
            farm[i][j] = tmp[j] - '0';
        }
    }

    vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
    // the sum of [0, 0] to [i, j]
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + farm[i-1][j-1];
        }
    }
    
    int lo = 0, hi = sum[n][m], res, mid;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(judge(sum, mid)){
            lo = mid + 1;
            res = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    
    cout << res << endl;
    return 0;
}
