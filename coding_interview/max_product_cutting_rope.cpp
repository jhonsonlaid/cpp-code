#include <isotream>
#include <vector>

using namespace std;

int max_product_cutting_rope(int n){
    if(n <= 1) return 0;
    vector<int> res(n, 0);
    res[1] = 1;
    for(int i = 2; i < n; i++){
        int max_product = 0;
        for(int j = 1; j <= i/2; j++){
            product = res[j] * res[i - j]; 
            max_product = product > max_product ? product : max_product;
        }
        res[i] = max_product;
    }
    return products[n];
}

int main(){
    int mpcr = max_product_cutting_rope(4);
    cout << mpcr << endl;
    return 0;
}
