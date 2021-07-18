#include <iostream>
using namespace std;

int main() {
	int cnt, a, b;
	int ball = 1; // ball의 위치를 저장하기 위한 변수
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		cin >> a >> b;
		if (a == ball) { // 만약 볼이 있는 위치가 a면
			ball = b; // 입력받은 또 다른 장소가 볼의 위치로 갱신
		}
		else if (b == ball) { // 만약 b면
			ball = a; // a로 공의 위치 갱신
		}
	}

	cout << ball << "\n"; // 볼의 위치를 출력

	return 0;
}

/* 이 문제에서 배열로 풀어야 하나..? 고민을 많이 했었는데 
너무 간단하게 공이 있는 위치만 보면 되는거였음 !!
공이 있는 위치가 입력된 값 중에 없으면 중요하지 않음.
만약 위치가 입력된 값 중에 일치하는게 있으면 그때 위치를 
*/
