// Medium.
// One point must be on x axis. Circle is always valid if points are on same side of x-axis.
// So center is radius R away from x axis, and all points are also <= R away from center.
// Now we just do min cover circle problem where circle starts at y axis

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int animals;
    cin >> animals;

    int x[animals], y[animals];
    for (int i=0; i<animals; i++) {
        cin >> x[i] >> y[i];
    }

    int positives = 0;
    int negatives = 0;
    for (int i=0; i<animals; i++) {
        if (y[i] > 0) {
            positives += 1;
        } else if (y[i] < 0) {
            negatives += 1;
        }
        if (positives > 0 && negatives > 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    if (negatives > 0) {
        for (int i=0; i<animals; i++) {
            y[i] = -y[i];
        }
    }

    // TODO: randomized circle cover from 651

    cout << 0;
}