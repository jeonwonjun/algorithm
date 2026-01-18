#include <iostream>
using namespace std;

int main() {

    string str;
    while (true) {
        cin >> str;
        if (str == "0") break;
        
        bool flag = true;
        for (int i=0; i<=(str.size()-1)/2; i++) {
            if (str[i] != str[str.size()-1-i])
                flag = false;
        }

        if (flag) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }    
    return 0;
}