#include <iostream>
#include <vector>
using namespace std;

int main() {
    int kbs1_idx = 0, kbs2_idx = 0;
    int n;
    cin >> n;
    vector<string> channer;
    string answer = "";
    for (int i=0; i<n; i++) {
        string media;
        cin >> media;
        if (media == "KBS1")
            kbs1_idx = i;
        else if (media == "KBS2")
            kbs2_idx = i;
        channer.push_back(media);
    }
    
    for (int i=0; i<kbs1_idx; i++) {
        answer += '1';
    }
    
    for (int i=kbs1_idx; i>0; i--) {
        answer += '4';
    }
    
    if (kbs1_idx > kbs2_idx)
        kbs2_idx++;
    
    for (int i=0; i<kbs2_idx; i++) {
        answer += '1';
    }
    
    for (int i=kbs2_idx; i>1; i--) {
        answer += '4';
    }
        
    cout << answer << '\n';

    return 0;
}