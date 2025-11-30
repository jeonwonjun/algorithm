#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 16
int L, C;
char ans[MAX];

bool check(char* ans) {
    int consonants = 0; // 자음 개수
    int vowels = 0; // 모음 개수
    for (int i = 0; i < L; i++){
        if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') vowels++;
        else
            consonants++;
    }
    return consonants >= 2 && vowels >= 1;
}

// 1. C개의 문자 중 L개의 문자열을 조합한다. O(C!/(L!*(C-L)!))
void dfs(char* arr, int idx, int depth) {

    if (depth == L) {
        if (check(ans)) {
            for (int i = 0; i < L; i++)
                cout << ans[i];
            cout << '\n';
        }
        return;
    }
    
    for (int i = idx; i < C; i++) {
        ans[depth] = arr[i];
        dfs(arr, i+1, depth+1);
    }
}

int main() {
    cin >> L >> C;
    
    char arr[MAX];
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+C);
    dfs(arr, 0, 0);
    
    return 0;
}