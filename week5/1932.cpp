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
			if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);

			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";

	return 0;
}
