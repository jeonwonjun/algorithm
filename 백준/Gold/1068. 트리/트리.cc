#include <iostream>
#include <vector>
using namespace std;

#define MAX 51

vector<int> tree[MAX];
int parent[MAX];
int n, remove_node, root;
int ans = 0;

void dfs(int node) {
    if (node == remove_node) return; // 삭제된 노드는 건너뜀

    if (tree[node].empty()) {
        ans++;
        return;
    }

    bool has_child = false;
    for (int child : tree[node]) {
        if (child != remove_node) {
            dfs(child);
            has_child = true;
        }
    }

    // 자식이 모두 삭제된 경우, 현재 노드가 리프 노드가 됨
    if (!has_child) ans++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p == -1) {
            root = i;
        } else {
            tree[p].push_back(i);
        }
    }

    cin >> remove_node;

    if (remove_node == root) {
        cout << 0 << '\n'; // 트리 전체 삭제됨
    } else {
        dfs(root);
        cout << ans << '\n';
    }

    return 0;
}
