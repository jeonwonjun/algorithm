#include <iostream>
using namespace std;

int main() {

    string erase_number;
    cin >> erase_number;
    int idx = 0;
    
    for (int i=1; ; i++) {
        string number = to_string(i);
        
        for (char c : number) {
            if (c == erase_number[idx]) idx++;
            if (idx == erase_number.size()) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}