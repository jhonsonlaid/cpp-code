#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool inc(string& num){
	int carry = 0;
	for (int i = num.size() - 1; i >= 0; i--){
		int sum = num[i] - '0' + carry;

		if (i == num.size() - 1)
			sum++;

		if (sum >= 10){
			if (i == 0)
				return true;
			else{
				sum -= 10;
				num[i] = sum + '0';
				carry = 1;
			}
		}
		else{
			num[i] = sum + '0';
			carry = 0;
			break;
		}
	}

	return false;
}

void print_num(const string num){
	int i = 0;
	while (num[i] == '0')
		i++;
	while (i < num.size())
		cout << num[i++];
	cout << endl;
}

void print_one_to_max_digits(int n){
	if (n <= 0)
		return;
	string num(n, '0');
	while (!inc(num)){
		print_num(num);
	}
}

void print_recursively(string &num, int idx){
	if (idx >= num.size()){
		print_num(num);
		return;
	}
	for (int i = 0; i < 10; i++){
		num[idx] = i + '0';
		print_recursively(num, idx + 1);
	}
}

void print_one_to_max_digits2(int n){
	if (n <= 0)
		return;
	string num(n, '0');
	print_recursively(num, 0);
}

int main(){
	print_one_to_max_digits2(3);
    system("pause");
    return 0;
}
