/*
merge sort 문제
*/

#include <iostream>
using namespace std;

int a[1048577];
int b[1048577]; // 임시배열
int n, k;

void merge(int st, int end) {
	if (end - st > n / k) return;
	/* 현재 정렬중인 리스트의 크기가 
	전체 배열 크기가 입력받은 인원 수로 나눈 값보다 크면 return*/

	int mid = (st + end) / 2;
	int i = st, j = mid + 1, t = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) b[t++] = a[i++];
		else b[t++] = a[j++];
	}
	while (i <= mid) b[t++] = a[i++];
	while (j <= end) b[t++] = a[j++];
	
	for (int i = st; i <= end; i++) {
		a[i] = b[i - st];
	}
}

void merge_sort(int st, int end) {
	if (st == end) return; // 처음과 끝이 같으면 종료
	int mid = (st + end) / 2;
	merge_sort(st, mid); // 처음부터 중간까지 sort
	merge_sort(mid+1, end);  // 중간부터 끝까지 sort
	merge(st, end); // 그 다음에 합치기
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	merge_sort(0, n - 1);
	for (int j = 0; j < n-1; j++) {
		cout << a[j] << " ";
	}
	cout << a[n-1] << "\n";
	return 0;
}
