#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
    }
    cout << s;
    return 0;
}
