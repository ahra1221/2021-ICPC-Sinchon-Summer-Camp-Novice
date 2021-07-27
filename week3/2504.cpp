#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	stack<char>s;
	bool wrong = false; // 올바른 괄호열 여부
	int sum = 1;
	int output = 0;
	string par; // 괄호열
	cin >> par;

	for (int i = 0; i < par.length(); i++) {
		if (par[i] == '(') { // 열린 소괄호이면
			s.push(par[i]); // 스택에 넣고
			sum *= 2; // sum에 2배 해주기
		}
		else if (par[i] == '[') {// 열린 대괄호이면
			s.push(par[i]); // 스택에 넣고
			sum *= 3; // sum에 3배 해주기
		}
		else if (par[i] == ')') {// 닫힌 소괄호인 경우
			if (s.empty()) { // 만약 스택이 비어있으면
				wrong = true; // 잘못된 문자열
				break;
			}
			else if (s.top() == '(') { // 만약 top이 열린 소괄호인 경우
				if (par[i - 1] == '(') output += sum;
				// 만약 앞에 있는 문자열도 열린 소괄호면 output에 지금까지 구한 sum을 더해주고
				s.pop(); 
				sum /= 2; //sum을 2로 나눠주기
			}
			else {
				wrong = true;
				break;
			}
		}
		else if (par[i] == ']') {// 닫힌 대괄호인 경우
			if (s.empty()) {
				wrong = true;
				break;
			}
			else if (s.top() == '[') {
				if (par[i - 1] == '[') output += sum;
				s.pop();
				sum /= 3;
			}
			else {
				wrong = true;
				break;
			}
		}
	}
	if (wrong || !s.empty()) { // 만약 잘못된 문자열이거나 empty가 아니면
		cout << 0 << endl; // 0 출력
	}
	else {
		cout << output << endl;
	}
	return 0;
}

// 열린괄호와 닫힌 괄호가 붙어있을때와 괄호 사이에 다른 괄호들이 있을때 계산법이 다르다는것!!
