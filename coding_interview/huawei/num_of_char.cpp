#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	char ch;
	getline(cin, str);
	cin >> ch;
	if (ch >= 'A' && ch <= 'Z')
		ch = ch - 'A' + 'a';
	for (int i = 0; i < str.size(); i++){
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	cout << count(str.begin(), str.end(), ch) << endl;
	return 0;
}
