#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;

        vector<vector<int>> v(N, vector<int>(N, 0));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> v[j][k];
            }
        }

        vector<vector<int>> v90(N, vector<int>(N, 0));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                v90[j][k] = v[N - k - 1][j];
            }
        }

        vector<vector<int>> v180(N, vector<int>(N, 0));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                v180[j][k] = v[N - j - 1][N - k - 1];
            }
        }

        vector<vector<int>> v270(N, vector<int>(N, 0));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                v270[j][k] = v[k][N - j - 1];
            }
        }

        cout << '#' << i << '\n';

        vector<vector<vector<int>>> mats = {v90, v180, v270};

        for (int r = 0; r < N; r++) {
            for (int m = 0; m < 3; m++) {
                for (int c = 0; c < N; c++) {
                    cout << mats[m][r][c];
                }
                if (m < 2) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
