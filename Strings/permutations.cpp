#include <iostream>
#include <vector>
using namespace std;

void perm(char *s, int k) {
    static int A[10] = {0};
    static char res[10];

    if (s[k] == '\0') {
        res[k] = '\0';
        cout << res << endl;
        return;
    }

    for (int i = 0; s[i]; i++) {
        if (A[i] == 0){
            res[k] = s[i];
            A[i] = 1;
            perm(s, k+1);
            A[i] = 0;
        }
    }
}

void swap(char s[], int i, int j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}

void perm2(char s[], int l, int h){
    int i;
    if (l == h){
        cout << s << endl;
        return;
    }

    for (i = l; i <= h ; i++) {
        swap(s, l, i);
        perm2(s, l + 1, h);
        swap(s, i, l);
    }

}


int main () {
    char s[] = "ABC";

    // perm(s, 0);
    perm2(s, 0, 2);
    
    return 0;
}