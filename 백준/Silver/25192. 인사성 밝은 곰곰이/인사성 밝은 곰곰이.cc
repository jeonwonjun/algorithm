#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 0;
    
    map<string, int> member;
    for (int i=0; i<N; i++) {
        string name;
        cin >> name;
        if (name == "ENTER")
            member.clear();
        else {
            member[name]++;
            if (member[name] <= 1) {
                answer++;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}