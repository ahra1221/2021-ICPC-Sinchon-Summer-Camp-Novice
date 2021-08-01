#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans=987654321;
int power[21][21];
bool team[21];

void dfs(int num, int cnt){ // cnt가 현재 뽑은 팀원 수 
	if (cnt == n / 2) { // 팀원 분배가 완료된 상황
		vector<int> start, link;
		for (int i = 0; i < n; i++){
			if (team[i]) start.push_back(i);
			else link.push_back(i);
		} // 팀원 번호 vector에 각각 넣기

		int stat_start = 0, stat_link = 0;
		for (int i = 0; i < start.size(); i++)
		{
			for (int j = i + 1; j < start.size(); j++)
			{
				int start_x = start[i], start_y = start[j];
				int link_x = link[i], link_y = link[j];
				stat_start += power[start_x][start_y] + power[start_y][start_x];
				stat_link += power[link_x][link_y] + power[link_y][link_x];
			}
		} // 스타트팀과 링크 팀 각각의 능력치 합 구하기

		ans = min(ans, abs(stat_start - stat_link)); // 능력치 차이의 최솟값 구하기
		return;
	}
	for (int i = num + 1; i < n; i++){
		if (team[i] == false){ // 아직 선택이 안된 팀원이라면
			team[i] = true;
			dfs(i, cnt + 1); // 재귀호출로 백트래킹
			team[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> power[i][j];
		}
	}

	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}
