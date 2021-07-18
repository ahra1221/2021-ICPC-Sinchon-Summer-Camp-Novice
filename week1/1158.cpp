#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <int> q;
	int cnt, n;
	cin >> cnt >> n;

	for (int i = 1; i <= cnt; i++) {
		q.push(i); // 1부터 차례대로 큐에 넣는다.
	}

	cout << "<";
	for (int i = 1; i <= cnt-1; i++) { // for문을 돌면서
		for (int j = 0; j < n - 1; j++) {
			q.push(q.front()); // 앞에 있는 숫자들은 큐 뒤로 넘기고
			q.pop(); // pop해준다.
		} 
		cout << q.front() << ", "; // 그 숫자 차례가 되면 출력하고
		q.pop(); //pop해준다.
	}
	cout << q.front() <<  ">\n"; // 마지막에 남은 값까지 출력

	return 0;
}

// 요세푸스 문제 큐로 푸는 방법 완전 이해 완료!
