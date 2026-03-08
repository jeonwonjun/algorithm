#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	
	while (true) {
		string str;

		getline(cin, str);

		if (str == "#") break;

		// String을 StringStream 형으로 변환한 strs 선언
		stringstream strs(str);

		string tmp;

		// strs 에서 " " 단위로 하나씩 추출하여 tmp에 저장
		while (strs >> tmp) {
			reverse(tmp.begin(), tmp.end());
			cout << tmp << " ";
		}
		cout << "\n";
	}

	return 0;
}