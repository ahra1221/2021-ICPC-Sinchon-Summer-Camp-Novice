/*
30의 배수가 되려면 숫자의 합이 3의 배수이고,
마지막 자리가 0으로 끝나야 한다.
각 자리의 합이 3의 배수인지, 0이 있는지 비교후에 sort
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
	if (a > b) {
		return true;
	}
	return false;
}

int main() {
	string N;
	cin >> N;

	int sum = 0;
	bool zero = false;
	for (int i = 0; i < N.size(); i++) {
		sum += (N[i] - '0');
		if (!(N[i] - '0')) zero = true; // 0이 있으면 true
	}

	if (sum % 3 || !zero) { 
		cout << "-1" << "\n";
	}
	else {
		sort(N.begin(), N.end(),cmp); 
    // 내림차순 sort를 위해 cmp 생성, 기본값은 오름차순 정리
		cout << N << "\n";
	}

	return 0;
}
