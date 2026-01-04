#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double d, h, w;
    cin >> d >> h >> w;
    
    int h_answer = floor(d/sqrt((h*h) + (w*w))*h);
    int w_answer = floor(d/sqrt((h*h) + (w*w))*w);
    
    cout << h_answer << " " << w_answer;
}