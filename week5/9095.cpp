#include<iostream>
using namespace std;

int main() {
	int n , T, ans;
	cin >> T;
	int dp[11];
	dp[1] = 1; // 1을 만드는 방법 = 1가지 (1)
	dp[2] = 2; // 2를 만드는 방법 = 2가지 (1+1,2)
	dp[3] = 4; // 4를 만드는 방법 = 4가지 (1+1+1,1+2,2+1,3)

	for (int i = 0; i < T; i++) {
		cin >> n; 
		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n]<<"\n";
	} // 입력받은 수까지 dp를 채우고 해당하는 값을 출력하기

	return 0;
}

// 어차피 1,2,3만 가지고 만드는 것이기 때문에 쪼개서 구하면 된다!
