#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <int> q;
	int cnt, n;
	cin >> cnt >> n;

	for (int i = 1; i <= cnt; i++) {
		q.push(i);
	}

	cout << "<";
	for (int i = 1; i <= cnt-1; i++) {
		for (int j = 0; j < n - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() <<  ">\n";

	return 0;
}
