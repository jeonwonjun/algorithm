#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin >> T;
    	const int N = 100;
    	int board[N][N];

        for (int i = 0; i < N; ++i) {
        	for (int j = 0; j < N; ++j) {
            	cin >> board[i][j];
        	}
    	}

    	int answer = -1;

    	for (int startCol = 0; startCol < N; ++startCol) {
        	if (board[0][startCol] != 1) continue;

       		int x = 0;
        	int y = startCol;

        	while (x < N - 1) {
            	if (y > 0 && board[x][y - 1] == 1) {
                	while (y > 0 && board[x][y - 1] == 1) {
                    	y--;
                	}
            	}

            	else if (y < N - 1 && board[x][y + 1] == 1) {
                	while (y < N - 1 && board[x][y + 1] == 1) {
                    	y++;
                	}	
            	}
            	x++;
        	}

        	if (board[x][y] == 2) {
            	answer = startCol;
            	break;
        	}
    	}
		cout << "#" << T << " " << answer << '\n';
	}
	return 0;
}