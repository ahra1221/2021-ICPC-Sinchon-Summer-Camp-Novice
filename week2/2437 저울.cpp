/*
그리디 알고리즘
: 매순간 최적이라고 생각되는 것을 선택해 나가는 방식으로,
앞의 선택이 이후 선택에 영향을 주지 않는다,
문제 전체에 대한 최적해가 부분 문제에 대해서도 최적해가 된다.
ex) 한정된 교실 공간 내에 최대 수업 배정(종료 시간 빠른 수업 먼저 배치)

이 문제도 저울에 최대한 많은 저울을 올려야 한다 -> 그리디 알고리즘 생각해내기
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int sum = 0;
	cin >> N;
	int arr[1001 //저울 추 무게 입력받을 배열
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); // 추 무게 오름차순 정렬
	for (int i = 0; i <= N; i++) {
		if (arr[i] > sum + 1) {
			break; 
    } // 다음에 등장하는 숫자가 누적합+2 이상이라면 기존 숫자들로 표현 불가능
		sum += arr[i]; // 만약 누적합 +1 보다 작거나 같으면 sum 계속 갱신
	}
	cout << sum + 1 << endl; // 마지막에는 sum+1 출력
	return 0;
}
          
/*
ex) 
input 1 2 4 8 16 33
process: 1 +1=2, 3 +1=4, 7 +1=8, 15 +1=16, 31 +1<33
output 32(31+1)
*/
