#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    char dict[26][2] = {1};
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            dict[str[i]-'a'][0] += 1;
            if(dict[str[i]-'a'][0] >= 3){
                cout << str[i] << endl;
                return 0;
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            dict[str[i]-'A'][1] += 1;
            if(dict[str[i]-'A'][1] >= 3){
                cout << str[i] << endl;
                return 0;
            }
        }
    }
    return 0;
}
