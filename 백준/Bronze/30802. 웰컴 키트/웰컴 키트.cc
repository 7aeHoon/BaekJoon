#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, bundleOfShirt = 0, bundleOfPencil = 0;
    int size[6];
    ll shirtResult = 0;

    cin >> n;

    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }

    cin >> bundleOfShirt >> bundleOfPencil;

    for (int i = 0; i < 6; i++) {
        shirtResult += size[i] / bundleOfShirt;
        if(size[i] % bundleOfShirt != 0) {
            shirtResult++;
        }
    }

    cout << shirtResult << '\n';
    cout << n / bundleOfPencil << ' ' << n % bundleOfPencil << '\n';

    return 0;
}