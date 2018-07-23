#include <iostream>
#include <queue>
#include <vector>
#include <functional> // greater/less
#include <algorithm>

using namespace std;

int main(){
	int myints[] = { 5, 2, 3, 7, 6};
	priority_queue<int, vector<int>, greater<int>> min_pq(myints, myints+5); // min_heap
	while (!min_pq.empty()){
		cout << min_pq.top() << " ";
		min_pq.pop();
	}
	cout << endl;

	priority_queue<int, vector<int>, less<int>> max_pq(myints, myints+5); // max_heap
	while (!max_pq.empty()){
		cout << max_pq.top() << " ";
		max_pq.pop();
	}
	cout << endl;

	vector<int> vec{myints, myints + 5};
	make_heap(vec.begin(), vec.end(), greater<int>()); //min_heap, make heap's structure, not the least to greatest 
	for (auto e : vec){
		cout << e << " ";
	}
	cout << endl;

	pop_heap(vec.begin(), vec.end(), greater<int>()); // put top of heap to vector's tail
	vec.pop_back();
	for (auto e : vec){
		cout << e << " ";
	}
	cout << endl;
	
	vec.push_back(6);
	push_heap(vec.begin(), vec.end(), greater<int>()); // add new element to vecotr's tail then adjust heap
	for (auto e : vec){
		cout << e << " ";
	}


	system("pause");
	return 0;
}
