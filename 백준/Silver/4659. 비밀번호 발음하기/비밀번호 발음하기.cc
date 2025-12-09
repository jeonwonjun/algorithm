#include <iostream>
using namespace std;

bool accept;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool checkMo(string password) {
    for (char c : password) {
        if (isVowel(c)) {
            return true;
        }
    }
    
    return false;
}

bool checkTriple(string password) {
    if (password.length() < 3) {
        return false;
    }
    int vowelCnt = 0;
    int consCnt = 0;
    
    for (char c : password) {
        if (isVowel(c)) {
            vowelCnt++;
            consCnt = 0;
        } else {
            consCnt++;
            vowelCnt = 0;
        }
        
        if (vowelCnt >= 3 || consCnt >= 3) {
            return true;
        }
    }
    
    return false;
}

bool checkDuoble(string password) {
    if (password.length() < 2) {
        return false;
    }

    for (int i=0; i<password.length()-1; i++) {
        char cmp = password[i];
        if (cmp == 'e' || cmp == 'o') continue;
        if (password[i+1] == cmp) {
            return true;
        }
    }
    
    return false;
}

int main() {
    string password;
    
    while(cin >> password) {
        accept = true;
        if (password == "end") break;
        
        if (!checkMo(password)) accept = false;
        if (checkTriple(password)) accept = false;
        if (checkDuoble(password)) accept = false;
        
        if (accept) {
            cout << "<" << password << "> is acceptable.\n";
        } else {
            cout << "<" << password << "> is not acceptable.\n";
        }
    }

    return 0;
}