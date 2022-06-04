#include <iostream>
using namespace std;

int fibit(int n){
    int t0 = 0, t1 = 1, s;
    if (n<=1){
        return n;
    }
    for (int i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int ncr(int n, int r){
    

    if (n==r || r==0) return 1;

    return ncr(n-1, r-1) + ncr(n-1, r);

}


// TODO: memoized fib
// int fib(int n) {

//     // int *a = new int[n];
//     // a[0] = 0;
//     // a[1] = 1;

//     if (n <= 1) {
//         return a[n];
//     }

//     int l,r;

    

//     return fib(n-1) + fib(n-2);
// }

int main () {

    cout << fibit(3) << endl;
    cout << fibit(4) << endl;
   
    cout << ncr(6,2) << endl;



    return 0;
}