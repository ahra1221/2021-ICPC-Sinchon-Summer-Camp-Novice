#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[21] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int st, end;

	for (int cnt = 0; cnt < 10; cnt++) {
		cin >> st >> end;

		int a = end - st + 1;
		int temp = 0;

		for (int i = 0; i < a/2; i++) {
			temp = arr[st + i];
			arr[st + i] = arr[end - i];
			arr[end - i] = temp;
		}
	}

	for (int cnt = 1; cnt <= 20; cnt++) {
		cout << arr[cnt] << " ";
	}

	return 0;
}
