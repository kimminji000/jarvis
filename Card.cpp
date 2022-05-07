#include <iostream>
#include <deque>

int main() {

	int N, k;
	int* num;

	std::deque<int> d;

	std::cin >> N;

	num = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		std::cin >> num[i];
	}
	
	for (int i = N - 1; i >= 0; i--) {
		if (num[i] == 1) {
			d.push_front(N - i);
		}
		else if (num[i] == 2) {
			k = d.front();
			d.pop_front();
			d.push_front(N - i);
			d.push_front(k);
		}
		else {
			d.push_back(N - i);
		}
	}
	
	for (int i = 0; i < N; i++) {
		std::cout << d[i] << " ";
	}

	free(num);
}
