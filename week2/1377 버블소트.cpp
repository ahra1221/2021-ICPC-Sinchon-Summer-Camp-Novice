/*
bubble sort는 한 번 진행될 때마다 각 숫자 좌측으로 한 칸씩 이동
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i; // 숫자의 인덱스를 pair의 second에 저장
	}
	sort(v.begin(), v.end()); // 숫자 오름차순 정렬
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, v[i].second - i);
   	  //result와 처음인덱스와 현재 인덱스의 차이의 max값으로 result 갱신
	  //해당 숫자에 저장되어있는 인덱스와 정렬 기준 인덱스를 뺀 값=(좌측으로 이동한 횟수-1)
  }
	cout << result + 1 << '\n';
	return 0;
}
