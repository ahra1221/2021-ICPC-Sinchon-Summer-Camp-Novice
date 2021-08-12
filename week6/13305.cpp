#include <iostream>
using namespace std;

int city[100001];
int dis[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> dis[i];
	for (int i = 0; i < n; i++) cin >> city[i];

	long long max = city[0];
	for (int i = 0; i < n - 1; i++) {
		if (city[i] < max) max = city[i];
		ans += max*dis[i];
	}// 주유소 기름 가격이 더 작은 값으로 max 갱신해주고 계산
	cout << ans << "\n";

	return 0;
}
