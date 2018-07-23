#include <iostream>
#include <string>

using namespace std;

void permutation(string str, string res, int num){
	if (res.size() == num && !res.empty()){
		cout << res << " ";
		return;
	}
	if (str.empty())
		return;

	string res1 = res;
	res1.push_back(str[0]);
	string str1 = str.substr(1);
	
	permutation(str1, res1, num);
	permutation(str1, res, num);
}

void permutation_main(string str){
	string res;
	for (int i = 1; i <= str.size(); i++){
		permutation(str, res, i);
		cout << endl;
	}
		
}

int main(){
	string str = "123456";
	permutation_main(str);
	system("pause");
	return 0;
}
