#include <iostream>
#include <vector>
using namespace std;


int main () {
    char s[] = "cutieepie";
    long int H,x = 0;

    for (int i = 0; s[i]; i++) {
        x = 1;
        x = x << (s[i]-97);
        if ((x & H )> 0) {
            cout << s[i] << " is duplicate" << endl;
        }
        else{
            H = x | H;
        }

    }
   

    return 0;
}