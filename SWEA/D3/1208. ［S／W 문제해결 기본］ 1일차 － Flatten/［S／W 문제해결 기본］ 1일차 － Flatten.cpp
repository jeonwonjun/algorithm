#include<iostream>

using namespace std;

int max_idx = 0;
int min_idx = 0;
void find_idx(int* box) {
	for (int i = 0; i<100; i++) {
    	if (box[i] > box[max_idx]) {
        	max_idx = i;
        }
        if (box[i] < box[min_idx]) {
        	min_idx = i;
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
    {
        int dump;
        cin >> dump;
        
        int box[101] = {0, };
        for(int i=0; i<100; i++) {
            cin >> box[i];
        }
        
        for(int i=0; i<dump; i++) {
        	find_idx(box);
            box[max_idx]--;
            box[min_idx]++;
        }
        
        find_idx(box);
        
        cout << "#" << test_case << " " << box[max_idx] - box[min_idx] << '\n';

	}
	return 0;
}