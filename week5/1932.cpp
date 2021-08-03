#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;
	int dp[501][501] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i][j]; // 각 줄에 있는 첫번째 값
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j]; // 각 줄에서 제일 마지막에 있는 값
			else dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]); 
			// 위의 두 경우가 아니라 가운데에 있는 원소라면 왼쪽 위의 값과 오른쪽 위의 값 중 최댓값을 구해서 더해준다.

			ans = max(ans, dp[i][j]); // 최댓값 계속 
		}
	}
	cout << ans << "\n";

	return 0;
}
