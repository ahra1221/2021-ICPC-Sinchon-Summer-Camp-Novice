#include <iostream>
using namespace std;

int n, S;
int result = 0;
int arr[20];

void subset(int idx, int sum) {
	sum += arr[idx];
	if (idx >= n) return;
	if (sum == S) result++;

	subset(idx + 1, sum - arr[idx]);
	// 해당 원소를 포함하지 않은 subset 구하기
	subset(idx + 1, sum);
	// 해당 원소를 포함한 subset 구하기
}

int main() {
	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	subset(0, 0);
	cout << result << "\n";
	return 0;
}

// 처음에는 원소가 몇 개인지 경우를 나눠야하는지도 생각했었는데 재귀호출로 쓰니까 꽤 간단한 문제였다,,,
