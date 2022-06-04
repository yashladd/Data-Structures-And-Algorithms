#include <iostream>
#include <vector>
using namespace std;

void toh(int n, int a, int b, int c){
    if (n>0){
        toh(n-1, a, c, b);
        cout << a << " to " << c << endl;
        toh(n-1, b, a, c);
    }
}

int main () {

    toh(3, 1, 2, 3);
    // cout << pow(2,3) << endl;

    int n;

    cin >> n;

    vector<int> a {1,2,4,13,-1};

    auto it = max_element(begin(a), end(a));

    for (int i = 0; i < n; i++){
        cout  << a[i] << "  ";
    }
    cout << *(max_element(a.begin(), a.end()));

    return 0;
}