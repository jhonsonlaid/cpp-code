#include <iostream>
#include <string>

using namespace std;

bool reg_match(string a, string b){
	if (a.size() == 0)
		return b.size() == 0;
	if (b.size() == 0)
		return a.size() == 0;

	cout << a << " " << b << endl;
	if (b[1] != '*'){
		if (a[0] == b[0] || b[0] == '.'){
			return reg_match(a.substr(1), b.substr(1));
		}
		else
			return false;
	}
	else 
		return reg_match(a, b.substr(2)) ||
		(a[0] == b[0] || b[0] == '.') && reg_match(a.substr(1), b);
}

int main(){
	string a = "aaca";
	string b = "ab*a*cc*b";
	cout << reg_match(a, b) << endl;
	system("pause");
	return 0;
}
