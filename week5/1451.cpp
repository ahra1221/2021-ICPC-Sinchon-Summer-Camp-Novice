#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long  ans = -1;
long long  rec[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	char str[101]; 
	for (int i = 1; i <= n; i++) {
		cin >> str; 
		for (int j = 1; j <= m; j++) {
			rec[i][j] = str[j - 1] - '0';
		}
	}
	// 입력 예시를 보면 띄어쓰기로 구분이 안되어있어서 sting으로 받고 숫자로 바꿔서 배열에 넣어주기

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rec[i][j] = rec[i][j] + rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1];
		}
	} // 기존의 값에 왼쪽과 위의 값은 더하고 대각선의 값은 빼서 다시 넣어준다.

  // 하나의 직사각형을 세개의 직사각형으로 나눌 수 있는 경우는 총 6가지
	for (int a = 1; a < n; a++) { // 가로, 세로 섞여서 
		for (int b = 1; b < m; b++) {
			ans = max(ans, rec[a][b] * (rec[n][b] - rec[a][b])*(rec[n][m] - rec[n][b]));
			ans = max(ans, rec[n][b] * (rec[a][m] - rec[a][b])*(rec[n][m] - rec[n][b] - rec[a][m] + rec[a][b]));
			ans = max(ans, rec[a][m] * (rec[n][b] - rec[a][b])*(rec[n][m] - rec[n][b] - rec[a][m] + rec[a][b]));
			ans = max(ans, rec[a][b] * (rec[a][m] - rec[a][b])*(rec[n][m] - rec[a][m]));
		}
	}

	for (int a = 1; a <= m - 2; a++) { // 세로로 3개
		for (int b = a + 1; b <= m - 1; b++) {
			ans = max(ans, rec[n][a] * (rec[n][b] - rec[n][a])*(rec[n][m] - rec[n][b]));
		}
	}

	for (int a = 1; a <= n - 2; a++) { // 가로로 3개
		for (int b = a + 1; b <= n - 1; b++) {
			ans = max(ans, rec[a][m] * (rec[b][m] - rec[a][m])*(rec[n][m] - rec[b][m]));
		}
	}

	cout << ans << "\n";
	return 0;
}

// 경우의 수가 6가지라서 하나씩 다 해보면서 넓이 곱의 최댓값을 직접 구했다.
