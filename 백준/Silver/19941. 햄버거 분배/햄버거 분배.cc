#include <iostream>
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    string desk;
    cin >> desk;
    
    int answer = 0;
    for (int i=0; i<N; i++) {
      if (desk[i] == 'P') {
          for (int j=max(0, i-K); j<=min(N-1, i+K); j++) {
            if (desk[j] == 'H') {
              answer++;
              desk[j] = 'X';
              break;
            }
          }
        }
      }
    
    cout << answer;
    
    return 0;
}