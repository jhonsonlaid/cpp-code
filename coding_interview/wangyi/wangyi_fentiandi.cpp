#include <iostream>
#include<vector>
using namespace std;
 
int get_area(vector<vector<int>>& farm, int r1, int r2, int c1, int c2){
    int area = 0;
    for(int i = r1; i < r2; i++){
        for(int j = c1; j < c2; j++){
            area += farm[i][j];
        }
    }
    return area;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> farm(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            farm[i][j] = tmp;
    }
 
    int max_area = 0;
    for(int r1 = 1; r1 <= n-3; r1++){
        for(int r2 = r1 + 1; r2 <= n-2; r2++){
            for(int r3 = r2 + 1; r3 <= n-1; r3++){
                for(int c1 = 1; c1 <= m-3; c1++){
                    for(int c2 = c1 + 1; c1 <= m-2; c2++){
                        for(int c3 = c2 + 1; c3 <= m-1; c3++){
                            vector<int> areas;
                            int rows[5] = {0, r1, r2, r3, n};
                            int cols[5] = {0, c1, c2, c3, m};
                            int min_area = 1e4;
                            for(int i = 0; i < 4; i++){
                                for(int j = 0; j < 4; j++){
                                    min_area = min(min_area, get_area(farm, rows[i], rows[i+1], cols[j], cols[j+1]));
                                }
                            }
                            max_area = max(max_area, min_area);
                        }
                    }
                }
            }
        }
    }
    cout << max_area << endl;
    return 0;
}
