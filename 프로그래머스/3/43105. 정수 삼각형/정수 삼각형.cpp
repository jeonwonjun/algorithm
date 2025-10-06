#include <string>
#include <vector>
#include <iostream>

using namespace std;
int d[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    d[0][0]=triangle[0][0];
    for(int i=1; i<triangle.size(); i++){
        d[i][0] = d[i-1][0] + triangle[i][0];
        for(int j=1; j<=i; j++){
            d[i][j] = max(d[i-1][j]+triangle[i][j], d[i-1][j-1]+triangle[i][j]);
            }
    }
    
    for(int i=0; i<triangle.size(); i++){
        answer = max(answer, d[triangle.size()-1][i]);
    }
    
    return answer;
}