#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> bits(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> bits[i];
    }

    // find parity positions
    vector<int> parity_bits;
    for (int p = 1; p <= n; p <<= 1) {
        parity_bits.push_back(p);
    }

    cout << "Parity bits positions are: ";
    for (auto p : parity_bits) cout << p << " ";
    cout << endl;

    int errorPos = 0;

    // check each parity bit
    for (auto p : parity_bits) {
        int parity = 0;
        cout << "Parity bit at position " << p << " checks: ";
        for (int i = 1; i <= n; i++) {
            if (i & p) {
                cout << i << " ";
                parity ^= bits[i];
            }
        }
        cout << endl;
        if (parity != 0) {
            cout << "Parity check FAILED for position " << p << endl;
            errorPos += p;
        } else {
            cout << "Parity check passed for position " << p << endl;
        }
    }

    if (errorPos == 0) {
        cout << "No error detected" << endl;
    } else {
        cout << "Error at position " << errorPos << endl;
        bits[errorPos] ^= 1; // correct the error
        cout << "Corrected codeword: ";
        for (int i = 1; i <= n; i++) cout << bits[i] << " ";
        cout << endl;
    }

    return 0;
}
