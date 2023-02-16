#include <bits/stdc++.h>
using namespace std;

int n, a[101];

bool win(int k) {
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= k) {
			pos = i;
		}
	}
	// cout << k << ": ";
	int end = 0;
	for (int i = pos; i >= end; i--) {
		int index = i;
		while (index > end && a[index] > k) {
			index--;
		}
		if (a[index] <= k) {
			k--;
		}
		i = index;
		end++;
	}
	// cout << "\n";
	return k == 0;
}

void test_case() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int low = 0, high = 100, ans = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (win(mid)) {
			// cout << mid << " ";
			ans = max(ans, mid);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	// cout << "\n";
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case();
	}
}
