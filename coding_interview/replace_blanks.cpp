#include <iostream>

using namespace std;

/* O(n)
 */

void repalceBlanks(char str[]){
	if (nullptr == str){
		return;
	}
	
	int i = 0, org_len = 0, num_blank = 0;

	while(str[i] != '\0'){

		if (str[i] == ' ')
			num_blank++;

		org_len++;
		i++;
	}

	int new_len = org_len + 2 * num_blank;
	int org_idx = org_len, new_idx = new_len;

	while (new_idx > org_idx){
		if (str[org_idx] == ' '){
			str[new_idx--] = '0';
			str[new_idx--] = '2';
			str[new_idx--] = '%';
		}
		else{
			str[new_idx--] = str[org_idx];
		}
		org_idx--;
	}
}

int main(){
	char str[100] = "we are great programmer\n";
	repalceBlanks(str);
	cout << str;
	system("pause");
    return 0;
}
