#include <iostream>
using namespace std;

// template <class T>
double taylor(int x, int n){
    static double p = 1, f=1;
    double r;
    // static double f = 1;

    cout << p << "------->" << f << "pf" << endl;

    if (n==0){
        return 1;
    }
    
    r = taylor(x, n-1);
    p *= x;
    f *= n;
    return p/f + r;
    
}

double eiter(int x , int n){

    double s;

    for (; n > 0; n--){
        s = 1 + x*s/n;
    }

    return s;
}

double e(int x, int n) {
    
    static double s;
    // cout << s << endl;

    if (n==0) {
        return s;
    }

    s = 1 + x * s / n;
    // cout  << s << n << endl;
    
    return e(x, n-1);
}

int f (int &x, int c) 

{

        c--; 

if (c == 0) return 1; 

x = x + 1; 

cout << "x, c " << x << "  " << c  << endl;

return f(x,c) * x;

}

int fun (int n)

       { 

int x=1, k; 

if (n==1) return x; 

for (k=1; k<n; ++k) 

x=x + fun (k) * fun (n-k); 

return x; 

        }

int main () {

    // double a = taylor(1, 10);
    // double b = taylor(1, 15);
    // double c = taylor(2, 10);

    // cout << a << endl;
    // printf("%lf \n", b);
    // cout << c << endl;

    // cout << e(1, 15) << endl;
    // cout << e(1, 10) << endl;

    // cout << e(2, 15) << endl;
    // cout << e(3, 15) << endl;

    // cout << e(4, 15) << endl;

    int p = 5;
    // cout << "asdaf" << f(p,p) << endl;
    cout << "eac" << fun(5) << endl;



    return 0;
}