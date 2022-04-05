#include <iostream>
#include "mystack.h"
int main()
{
	int N;
	scanf_s("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);
	int* answer = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	dstack* stack = CreateStack();

	for (int i = N - 1; i >= 0; i--) {
		while (!isEmptyStack(stack) && top(stack) <= arr[i])
			pop(stack);

		if (isEmptyStack(stack))
			answer[i] = -1;
		else
			answer[i] = top(stack);

		push(stack, arr[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", answer[i]);
	}

	deleteStack(stack);
	free(arr);
	free(answer);
	return 0;
}