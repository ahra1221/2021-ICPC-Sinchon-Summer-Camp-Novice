#include <iostream>
#include <deque>
using namespace std;

deque<int>deck[2], ground[2];
//2개의 덱과 2개의 ground 선언

int win_check() {
	// 우선 종을 칠 때 비어있는 덱이 있어서는 안된다.
	if (ground[0].size() && ground[0].front() == 5) return 0; // do
	if (ground[1].size() && ground[1].front() == 5) return 0; // do
	if (ground[0].size() && ground[1].size() && ground[0].front() + ground[1].front() == 5) return 1; // su
	return -1; 
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		deck[0].push_front(a); // do의 카드
		deck[1].push_front(b); // su의 카드
	}

	int turn = 0; // turn이 0이면 do의 차례
	for (int i = 0; i < m; ++i) {
		ground[turn].push_front(deck[turn].front()); // 덱에 있는 카드 ground로 가져오기
		deck[turn].pop_front(); //덱에서는 pop해주기
		if (deck[turn].empty()) { // 만약 덱이 비었으면 패배이므로 출력 후 종료
			cout << (turn ? "do" : "su") << '\n'; 
			return 0;
		}
		int w = win_check();
		if (w != -1) {
			int l = 1 - w; // 종을 친 사람이 아닌 상대
			while (ground[l].size()) {
				deck[w].push_back(ground[l].back()); // 상대편 ground를 자신의 덱으로 가져오기
				ground[l].pop_back();
			}
			while (ground[w].size()) {
				deck[w].push_back(ground[w].back()); // 자신의 ground 카드도 덱으로 가져오기
				ground[w].pop_back();
			}
		}
		turn = 1 - turn; // 다음 사람으로 turn 넘어감
	}
	if (deck[0].size() > deck[1].size()) cout << "do" << '\n'; 
	else if (deck[0].size() < deck[1].size()) cout << "su" << '\n';
	else cout << "dosu" << '\n';

	return 0;
}
