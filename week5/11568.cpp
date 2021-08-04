#include <iostream>
using namespace std;

int card[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> card[i];

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < i; j++) {
			if (card[i] > card[j]) { // 뒤에 있는 원소가 더 큰 경우
				if (dp[j] > tmp) tmp = dp[j];
        // 앞에 있는 원소까지 제시할 수 있는 수열의 원소 개수가 0보다 크면 tmp 갱신
			}
		}
		dp[i] = tmp + 1; // 자기 자신까지 포함하여 넣어주어야 하므로 1 더해서 넣기
		if (dp[i] > ans) ans = dp[i]; // 최댓값 갱신
	}

	cout << ans << "\n";

	return 0;
}

// dp에 해당 원소까지 제시할 수 있는 수열 원소의 최대 개수가 저장된다.
