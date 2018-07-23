#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<string, int> mats;
    string m;
    while(cin >> m){
        if(mats.find(m) == mats.end())
            mats[m] = 1;
    }
    
    map<string, int>::iterator it;
    int count = 0;
    for(it = mats.begin(); it != mats.end(); it++){
        count += it->second;
    }
    cout << count << endl;
    return 0;
}
