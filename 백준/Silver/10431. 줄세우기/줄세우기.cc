#include <iostream>
#include <vector>
using namespace std;

int answer;

void lineup(vector<int>& height, int i) {
    for (int k=i; k>=0;k--){
        int smaller = k;
        for (int j=k-1; j>=0; j--) {
            if (height[k] < height[j]) {
                smaller = j;
            } 
    }
    
    height.insert(height.begin()+smaller, height[k]);
    height.erase(height.begin()+(k+1));
    answer += (k-smaller);
    }
}

int main() {
    int p;
    cin >> p;
    
    while (p--) {
        int t;
        cin >> t;
        answer = 0;
        vector<int> height;
        for (int i=0; i<20; i++) {
            int student;
            cin >> student;
            height.push_back(student);
            lineup(height, i);
        }

        cout << t << " " << answer << '\n';
    }

    return 0;
}