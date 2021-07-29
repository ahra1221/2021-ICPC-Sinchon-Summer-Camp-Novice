#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int N;
int arr[1001];
int pos, len;
int first = 1001, last, longest;
int result;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	while (N--){
		cin >> pos >> len;
		arr[pos] = len;
		if (last < pos) last = pos;
		if (first > pos) first = pos;
		if (len > arr[longest]) longest = pos;
	} // 각 위치를 인덱스로 갖는 배열의 값에 길이 대입해주고, first, last, longest 값 찾기

	// first부터 longest 사이의 넓이 구하기 (longest 기준 왼쪽 부분)
	for (int i = first; i <= longest; i++){
		if (arr[i]){ // arr[i]가 0이 아니라면, 즉 입력받은 기둥이라면
			if (st.empty()) st.push(arr[i]);
			else if (arr[i] > st.top()) st.push(arr[i]);
			// 스택의 top보다 큰 경우에만 스택에 넣기
		}
		result += st.top(); // 한 번 실행할때마다 스택의 top = 기둥 넓이 더해주기
	}
	
	while (!st.empty()) st.pop(); //스택 비워주기

	// longest+1부터 last 사이의 넓이 구하기 (longest 기준 오른쪽 부분)
	for (int i = last; i>longest; i--){
		if (arr[i]){
			if (st.empty()) st.push(arr[i]);
			else if (arr[i] > st.top()) st.push(arr[i]);
		}
		result += st.top();
	}

	cout << result; 

	return 0;
}

// 처음에 막막했는데 문제 이해하고 stack 사용할 방향 잡으니까 풀만한 문제였다!
