#include <iostream>
#include <algorithm>
using namespace std;

int straw[1000001]; // 입력받을 빨대의 길이 배열

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> straw[i];
	}
	sort(straw + 1, straw + n + 1); 
  // 입력한 n개의 straw 길이를 오름차순 정리
	for (int i = n; i >= 2; i--){
		int c = straw[i]; // 가장 긴 변
		int a = straw[i - 1];
		int b = straw[i - 2];
		if (a + b > c){ 
      // 나머지 두 변의 합이 가장 긴 변보다 크면 삼각형
			cout << a + b + c << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}
