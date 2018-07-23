#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < str.size()-1-i; i++){
            if(isalpha(str[j]) && isalpha(str[j+1])){
                if(to_lower(str[j]) > to_lower(str[j+1])){
                    swap(str[j], str[j+1]);
                }
            }
        }
    }
    cout << str << endl;
}
