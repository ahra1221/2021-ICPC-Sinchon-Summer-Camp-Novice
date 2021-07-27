#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	deque<int>card; //쌓여진 카드의 번호를 넣는 덱
	vector<int>v; // 사용한 기술 번호 저장하는 벡터

	int n, t;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	reverse(v.begin(), v.end());

	int input = 1;
	for (int i = 0; i < n; i++) {
		if(v[i]==1) card.push_back(input); // 1번 기술이면 뒤에 넣기
		else if (v[i] == 2) { // 2번 기술이면
			int temp = card[card.size() - 1]; // 제일 마지막 카드 번호 temp에 저장해 놓고
			card.pop_back(); // pop해서 지운다.
			card.push_back(input); // input을 먼저 덱에 넣고
			card.push_back(temp); // temp를 그 뒤에 넣어준다.
		}
		else if (v[i] == 3) { //3번 기술이면
			card.push_front(input); // 제일 앞에 넣어준다.
		}
		input++;
	}

	while (!card.empty()) { /
		cout << card[card.size() - 1] << " ";
		card.pop_back();
	}// 카드 덱을 뒤에서부터 출력해야 내가 갖고 있는 카드 상태가 된다.

	return 0;
}
