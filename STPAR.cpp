#include <bits/stdc++.h>
using namespace std;

int t = 1, n, k;

int main() {
	while (cin >> n) {
		if(n == 0) break;
		stack <int> pilha;
		int numDaVez = 1;
		for (int i = 0; i < n; i++) {
			cin >> k;

			if (k == numDaVez) {
				numDaVez++;
			} else {
				pilha.push(k);
			}

			while (!pilha.empty() && pilha.top() == numDaVez) {
				numDaVez++;
				pilha.pop();
			}
		}

		cout << (pilha.empty() ? "yes" : "no") << endl;
	}

	return 0;
}


