#include <iostream>

using namespace std;

int num_of_one(int n){
    int count = 0;
    while(n){
        count++;
        n = (n - 1) & n;
    }
    return count;
}

int main(){
    cout << num_of_one(0xFFFFFFFF) << endl;
    return 0;
}
