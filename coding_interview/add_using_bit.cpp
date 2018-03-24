#include <iostream>

using namespace std;


int add(int a, int b){
	int sum = a ^ b;
	int carry = (a & b) << 1;
	while (carry != 0){
		int old_sum = sum;
		sum = old_sum ^ carry;
		carry = (old_sum & carry) << 1;
	}
	return sum;
}

int main(){
	cout << add(489, 113);
	system("pause");
    return 0;
}
