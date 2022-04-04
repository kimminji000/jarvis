#include <stdio.h>
#include "mystack.h"

int main()
{
    int T, k;
    scanf("%d", &T); //횟수

    for (int i = 0; i < T; i++) {

        char n[51];
        scanf("%s", n, sizeof(n)); //괄호 문자열

        dstack* stack = CreateStack();

        for (int j = 0; j < 51; j++) {
            if (n[j] == '(')
                push(stack, n[j]);
            else if (n[j] == ')') {
                k = pop(stack);
                if (k == -1)
                    break;
            }
            else if (n[j] == '\0')
                break;
        }

        if (k == -1)
            printf("NO\n");
        else if (top(stack) != -1)
            printf("NO\n");
        else
            printf("YES\n");
        deleteStack(stack);
    }
}