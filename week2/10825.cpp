/*
한 사람마다 이름, 국어, 영어 ,수학 점수를 모두 갖고있음
-> 여기서 구조체를 떠올리자 !! (struct)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct INF {
	string name;
	int kor, eng, math;
};

// sort 할 때 필요한 함수 정의
bool cmp(INF a, INF b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
  // 국어, 영어, 수학 점수가 모두 같으면 이름이 사전순으로 증가하는 순서(아스키코드 큰 순서)
	else if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
  // 국어, 영어 수학 점수가 같으면 수학 점수가 감소하는 순서
	else if (a.kor == b.kor) return a.eng < b.eng;
  // 국어 점수만 같으면 영어 점수가 증가하는 순서
	else return a.kor > b.kor;
  // 국어 점수가 감소하는 순서
}

int main() {
	int N;
	cin >> N;
	vector<INF>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), cmp); // cmp 함수에 따라 sort
	for (int j = 0; j < N; j++) {
		cout << v[j].name << "\n"; // 이미 sort되었기 때문에 출력해주면 된다.
	}
	return 0;
}
