#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int last = 0;
    for(int i = 0; i < t.size(); i++){
        bool found = false;
        for(int j = last; j < s.size(); j++){
            if(s[j] ==  t[i]){
                last = j+1;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
