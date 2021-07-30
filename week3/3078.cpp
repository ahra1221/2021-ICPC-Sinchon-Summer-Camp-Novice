#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	long long cnt = 0; // 8byte 범위 갖는 정수
	queue<int>q[21];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;

		int len = name.length();

		while (!q[len].empty() && i - q[len].front() > K) {
			q[len].pop();
			// 이름의 길이가 같은 사람이 없거나 등수 차이가 K보다 크면 pop
		}
		cnt += q[len].size(); //cnt = 좋은 친구의 쌍
		q[len].push(i);
	}
	cout << cnt << "\n";
	return 0;
}
