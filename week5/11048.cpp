#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < n; i++) dp[i][0] += dp[i - 1][0]; // 첫 번째 줄 값 미리 정리
	for (int j = 1; j < m; j++) dp[0][j] += dp[0][j - 1]; // 각 줄의 첫 번째 칸 미리 정리

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] += max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] });
		} // 가능한 3방향에서의 최댓값을 구해서 더해준다.
	}

	cout << dp[n - 1][m - 1] << "\n"; // 위치가 (N,M)인 원소 

	return 0;
}
