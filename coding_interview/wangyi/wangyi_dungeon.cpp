#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Point{
	int x;
	int y;
	Point(int a, int b) : x(a), y(b){}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> dungeon(n, vector<char>(m, ' '));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char ch; cin >> ch;
			dungeon[i][j] = ch;
		}
	}

	int x0, y0;
	cin >> x0 >> y0;
	int k;
	cin >> k;
	vector<vector<int>> steps(k, vector<int>(2, 0));
	for (int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		steps[i][0] = r;
		steps[i][1] = c;
	}

	vector<vector<int>> count(n, vector<int>(m, -1));
	queue<Point> q1;
	Point start(x0, y0);
	q1.push(start);
	count[x0][y0] = 0;

	while (!q1.empty()){
		Point pt = q1.front();
		q1.pop();
		for (int i = 0; i < k; i++){
			Point next(0, 0);
			next.x = pt.x + steps[i][0];
			next.y = pt.y + steps[i][1];
			if (next.x >= 0 && next.x < n &&
				next.y >= 0 && next.y < m &&
				dungeon[next.x][next.y] == '.' &&
				count[next.x][next.y] < 0){
				q1.push(next);
				count[next.x][next.y] = count[pt.x][pt.y] + 1;
			}
		}
	}

	int max_step = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (dungeon[i][j] == '.' && count[i][j] < 0){
				cout << -1 << endl;
				return 0;
			}
				max_step = max(max_step, count[i][j]);
		}
	}
	max_step = max_step > 0 ? max_step : -1;
	cout << max_step << endl;
	return 0;
}
