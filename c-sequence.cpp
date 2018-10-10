// Easy.
// For every sequence, we have to output a series of 1s in the beginning since gcd(1, ...) = 1.
// gcd(2,3...) = 1. gcd(3,4...) = 1. gcd(4,5) = 1.
// Whenever there is one odd number and any set of even numbers gcd will be 1.
// And since there are n/2 even numbers, it will take n/2 removals to get to a gcd of 2.
// To get a gcd better than 2 in n/2 numbers then it has to be an odd number.
// Can only do that if we take out all even numbers
// gcd(1,3...) is still 1, thus 2 is the best gcd.
// Now we can recurse on n/2 version (after multiplying by 1/2)

#include <iostream>
#include <cmath>

using namespace std;

void helper(int n, int two_power) {
    if (n == 1) {
        int x = 1;
        cout << x*pow(2, two_power);
        return;
    }

    if (n == 2) {
        int x = 1;
        int y = 2;
        cout << x*pow(2, two_power) << " " << y*pow(2, two_power);
        return;
    }

    if (n == 3) {
        int x = 1;
        int y = 3;
        cout << x*pow(2, two_power) << " " << x*pow(2, two_power) << " " << y*pow(2, two_power);
        return;
    }

    // odd length, includes middle, even length, includes all
    for (int i=0; i<(n+1)/2; i++) {
        cout << "1 ";
    }
    helper(n/2, two_power+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    helper(n, 0);

    cout << "\n";
}

