#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<int>s;

	int n , k;
	string command; // 입력받을 명령어 string으로 선언
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command; 
		if (command == "push") { // 명령어가 push인 경우
			cin >> k; // push할 숫자 추가로 입력받고
			s.push(k); // push 함수 이용하여 넣기
		}
		else if (command == "pop") {// 명령어가 pop인 경우
			if (s.empty()) cout << "-1" << "\n"; 
			// 스택이 비어있으면 pop할 수 없으므로 -1 출력
			else {
				cout << s.top() << "\n";
				// 가장 위에 있는 값을 출력하고
				s.pop(); // pop해주기
			}
		}
		else if (command == "size") cout << s.size() << "\n"; //size 출력
		else if (command == "empty") { //empty인지 확인
			if (s.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (command == "top") { //top 출력
			if (s.empty()) cout << "-1" << "\n";
			// 스택이 비어있으면 top이 없으므로 -1 출력
			else cout << s.top() << "\n";
		}
	}

	return 0;
}
