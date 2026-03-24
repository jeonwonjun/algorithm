#include <iostream>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bitset<20>> train(n, 0);
    set<unsigned long> answer;
    for (int j = 0; j < m; j++) {
        int comand;
        cin >> comand;
        if (comand == 1) {
            int train_number, x;
            cin >> train_number >> x;
            train[train_number - 1].set(20 - x);
        } else if (comand == 2) {
            int train_number, x;
            cin >> train_number >> x;
            train[train_number - 1].reset(20 - x);
        } else if (comand == 3) {
            int train_number;
            cin >> train_number;
            train[train_number - 1] >>= 1;
            train[train_number - 1].reset(19);
        } else if (comand == 4) {
            int train_number;
            cin >> train_number;
            train[train_number - 1] <<= 1;   
            train[train_number - 1].reset(0);
        }
    } 
    
    for (int i = 0; i < n; i++) {
        answer.insert(train[i].to_ulong());
    }

    cout << answer.size();
    
    return 0;
}