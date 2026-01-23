#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'
int main() {

    int sz, a, b, c;
    cin >> sz;
    while(sz--){
    	cin >> a >> b >> c;
    	cout << min(a, min(b, c)) << endl;
	}
    return 0;
}