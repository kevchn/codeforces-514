// Easy. 
// We can just count the number of breaks between customers + their treat times (treat intervals as skips).
// O(N) time

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L, a;
    cin >> n >> L >> a;

    if (n == 0) {
        cout << L / a << "\n";
        return 0;
    }

    int t[n], l[n];
    for (int i=0; i<n; i++) {
        cin >> t[i] >> l[i];
    }

    int breaks = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) {
            breaks += t[0] / a;
            continue;
        }

        breaks += (t[i] - t[i-1] - l[i-1]) / a;
    }
    breaks += (L - t[n-1] - l[n-1]) / a;
    
    cout << breaks << "\n";
}
