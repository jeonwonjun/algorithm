#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> Tshirts;
    for (int i =0; i<6; i++) {
        int T_size;
        cin >> T_size;
        Tshirts.push_back(T_size);
    }
    int t, p;
    cin >> t >> p;

    int T_answer = 0;
    for (int i=0; i<6; i++) {
        T_answer += Tshirts[i] / t;
        if (Tshirts[i] % t != 0) {
            T_answer++;
        }
    }
    
    int P_answer = n / p;
    int oneP_answer = n % p;

    cout << T_answer << '\n';
    cout << P_answer << ' ' << oneP_answer;
    
    return 0;
}