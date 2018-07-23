#include <iostream>
#include <string>

using namespace std;

bool is_digit(char a){
	return a <= '9' && a >= '0';
}

bool scan_unsigned_integer(string& str){
	int i = 0;
	while(i < str.size() && is_digit(str[i]))
		i++;
	str = str.substr(i);
	return i > 0;
}

bool scan_integer(string& str){
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	str = str.substr(i);
	return scan_unsigned_integer(str);
}


bool is_numeric(string str){
	if (str.empty()) return false;

	bool res = scan_integer(str);
	if (str[0] == '.'){
		str = str.substr(1);
		res = scan_unsigned_integer(str) || res; 
	}
	if (str[0] == 'e' || str[0] == 'E'){
		str = str.substr(1);
		res = res && scan_integer(str);
	}
	return res && str.empty();
}


int main(){
	cout << is_numeric("+") << endl;
	cout << is_numeric("+12.e-13") << endl;
	cout << is_numeric("+12.e-1.3") << endl;
	cout << is_numeric("+12.+1e-13") << endl;
	cout << is_numeric("+12.1e-13") << endl;
	cout << is_numeric("+-5") << endl;
	system("pause");
	return 0;
}
