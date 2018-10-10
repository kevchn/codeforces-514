// Medium. 
// n <= 1e3 so n^3 should run in 1e9 or 1 sec, which is too slow, need n^2 = O(nm) solution.
// Thus we need to have an O(1) check we can perform on each square to determine if it's fillable.
// To fill a square, we must forge from the center on a neighbor square
// But if a square has a blank, then we cannot forge from the center on any neighboring squares.
// So every fillable square must have one neighbor which has no blank neighbors, which is a constant check (24 cells) per cell.
// Blank neighbor checks overlap, so we use bottom up DP to fill out if cells have no blank neighbors (valid to forge from there), or 1+ blank neighbors (invalid). 
// TODO: use std::vector or custom solution for bounds checking, maybe monad style
// TODO: cin leaves things in buffers, should probably just use cstdio from now on
// O(NM) time

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    cin.ignore();

    char cells[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin.get(cells[i][j]);
        }
        cin.ignore();
    }

    bool forgeable[n][m]; // from center i.e can fill 8 neighbor cells
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                forgeable[i][j] = false;
                continue;
            }

            if (cells[i+1][j+1] != '#' || cells[i+1][j] != '#' || cells[i+1][j-1] != '#' ||
                cells[i][j-1] != '#' || cells[i][j+1] != '#' ||
                cells[i-1][j-1] != '#' || cells[i-1][j] != '#' || cells[i-1][j+1] != '#') {
                forgeable[i][j] = false;
                continue;
            }

            forgeable[i][j] = true;
        }
    }

    bool res = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (cells[i][j] == '#') { 
                // corners
                if (i > 0 && j > 0) 
                    if (forgeable[i-1][j-1] == true)
                        continue;
                if (i > 0 && j < m-1) 
                    if (forgeable[i-1][j+1] == true)
                        continue;
                if (i < n-1 && j > 0) 
                    if (forgeable[i+1][j-1] == true)
                        continue;
                if (i < n-1 && j < m-1) 
                    if (forgeable[i+1][j+1] == true)
                        continue;

                // sides
                if (i > 0)
                    if (forgeable[i-1][j] == true)
                        continue;
                if (i < n-1) 
                    if (forgeable[i+1][j] == true)
                        continue;
                if (j > 0)
                    if (forgeable[i][j-1] == true)
                        continue;
                if (j < m-1)
                    if (forgeable[i][j+1] == true)
                        continue;

                res = false;
            }
        }
    }

    if (res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}