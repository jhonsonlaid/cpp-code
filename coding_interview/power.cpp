#include <iostream>

using namespace std;

double power(double base, int exponent){
    if (0 == base)
        return 0.0;

	int res = 1.0;
    for(int i = abs(exponent) ; i > 0; i /= 2){
        if(i & 0x1 == 1) 
			res *= base;
		base *= base;
    }

    return exponent < 0 ? 1. / res : res;
}

double power_forward(double base, int exponent){
	if (exponent == 0)
		return 1;

	int res = power_forward(base, exponent >> 1);
	res *= res;
	if (exponent & 0x1) 
		res *= base;
	return res;
}

double power2(double base, int exponent){
	if (0 == base)
		return 0.0;
	int abs_exp = abs(exponent);
	int res = power_forward(base, abs_exp);
	return exponent < 0 ? 1. / res : res;
}


int main(){
    cout << power(10, 9) << endl;
    system("pause");
    return 0;
}
