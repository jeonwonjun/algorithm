#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double h;
    cin >> h;

    cout << fixed << setprecision(4) << h - 0.3 << endl;

    return 0;
}