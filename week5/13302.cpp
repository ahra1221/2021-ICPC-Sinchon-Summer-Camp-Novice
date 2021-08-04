#include <iostream>
#include <algorithm> // min 함수
#include <cstring> // memset 
using namespace std;

int n, m;
int d[101][101];
bool rest[101];// 수영이가 쉬는날

int resort(int day, int coupon) { // 현재 날짜와 쿠폰 개수
	if (day >= n + 1) return 0; // 현재날짜가 n을 넘으면 return

	int &ret = d[day][coupon]; // 참조변수 ret 선언
	if (ret != -1) return ret;

	if (rest[day]) ret = resort(day + 1, coupon); // 쉬는날이면 다음날짜로 return
	else {
		ret = 0x3f3f3f3f;
    // 처음에 이 부분을 틀려서 고생했음,,, 무한대를 선언할때 많이 사용.
		ret = min(ret, resort(day + 1, coupon) + 10000); // 다음날 하루 이용권 쓰는 경우
		ret = min(ret, resort(day + 3, coupon + 1) + 25000); // 연속 3일권 쓰는 경우->쿠폰 +1
		ret = min(ret, resort(day + 5, coupon + 2) + 37000); // 연속 5일권 쓰는 경우->쿠폰 +2

		if (coupon >= 3) { // 만약 쿠폰이 3개 이상이라면 쓸 수 있음!!
			ret = min(ret, resort(day + 1, coupon - 3));
      // 다음날을 쿠폰을 쓰는것과 쓰지 않는 것 중 최솟값 구하기
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	while (m--) {
		int x;
		cin >> x;
		rest[x] = true; // 쉬는 날짜를 인덱스로 가진 rest 배열의 값은 true로 바꿔주기
	}
	memset(d, -1, sizeof(d));

	cout << resort(1, 0) << '\n';
  // 현재는 1일이고 쿠폰개수는 0개.
}

// 그냥 경우 나눠서 하면 되는 꽤 간단한 문제였다. 처음에 이런 방향을 생각못해서 어려웠지만 구현은 막상 어렵지 않았음!
