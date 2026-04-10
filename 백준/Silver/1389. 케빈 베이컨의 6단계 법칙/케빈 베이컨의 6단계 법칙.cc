#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

int N, M, person=101, ans=INT_MAX;
int cnt[101];
vector<vector<int>> v;  

void dfs(int n, int num) {
  if(cnt[num] != 0) {
    cnt[num] = min(n, cnt[num]);
  } else {
    cnt[num] = n;
  }

  for(int j=0; j<v[num].size(); j++) {
    int next = v[num][j];
    if(cnt[next] == 0 || cnt[next] > n+1) {
      dfs(n+1, next);
    }
  }
}

int main() {
  cin >> N >> M; 

  v.resize(N+1);

  int fr1, fr2;
  for(int i = 0; i < M; i++) {
    cin >> fr1 >> fr2;
    v[fr1].push_back(fr2);
    v[fr2].push_back(fr1);
  }

  for(int i = 1; i <= N; i++) {
    memset(cnt, 0, sizeof(cnt));

    for(int j=0; j<v[i].size(); j++) {
      dfs(1, v[i][j]);
    }

    int temp = 0;
    for(int j=1; j<=N; j++) {
      if(j==i) {
        continue;
      }
      temp += cnt[j];
    }

    if(ans > temp) {
      ans = temp;
      person = i;
    } else if(ans == temp) {
      person = min(person, i);
    }
  }

  cout << person;

  return 0;
}