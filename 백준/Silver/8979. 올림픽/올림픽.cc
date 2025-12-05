#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int gold[1001] = {0,};
    int silver[1001] = {0,};
    int bronze[1001] = {0,};
    int answer = 0;
    
    for (int i=0; i<N; i++) {
        int index;
        cin >> index;
        cin >> gold[index] >> silver[index] >> bronze[index];
    }
    
    for (int i=1; i<=N; i++) {
        if (gold[i] > gold[K]) {
            answer++;
        }
        else if (gold[i] == gold[K]) {
            if (silver[i] > silver[K]) {
                answer++;
            }
            else if (silver[i] == silver[K]) {
                if (bronze[i] < bronze[K]) {
                    answer++;
                }
            }
        }
    }
    
    cout << answer + 1 <<'\n';
    return 0;
}