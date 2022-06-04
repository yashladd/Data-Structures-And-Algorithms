#include <iostream>
#include <vector>
using namespace std;


int bs(vector<int> a, int t) {
    
    int l = 0, r = a.size()-1;

    while (l <= r)
    {
        /* code */
        int mid = (l+r)/2;
        if (a[mid] == t) return mid;
        else if (t < a[mid])
        {
            /* code */
            r = mid -1;
        } else l = mid + 1;
        
    }

    return -1;
}

int bins(vector<int> a, int l, int r, int t) {

    if (l > r) return -1;

    int mid = (l + r)/2;

    if (a[mid] == t) return mid;
    else if (a[mid] < t) return bins(a, mid + 1, r, t);
    else return bins(a, l, mid-1, t);

}

int main () {

    // toh(3, 1, 2, 3);
    // cout << pow(2,3) << endl;

    vector<int> x = {1,2,4,5};

    cout << bs(x, 2) << endl;
    cout << bins(x, 0, x.size(), 6) << endl;


    return 0;
}