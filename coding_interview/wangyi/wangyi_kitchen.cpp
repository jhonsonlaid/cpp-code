#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    set<string> mats;
    string m;
    while(cin >> m){
        mats.insert(m);
    }
    cout << mats.size() << endl;
    return 0;
}
