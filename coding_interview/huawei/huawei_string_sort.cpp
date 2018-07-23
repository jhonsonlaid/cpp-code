#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
	while (getline(cin, str)){
	    for(int i = 0; i < str.size(); i++){
			int last = 0;
            for(int j = 0; j < str.size() - i; j++){
                if(isalpha(str[j])){
                    if(isalpha(str[last]) && tolower(str[last]) > tolower(str[j])){
                        swap(str[last], str[j]);
                    }
	    			last = j;
                }
            }
        }
        cout << str << endl;
	}
}
