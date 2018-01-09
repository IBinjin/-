#include <stdio.h>

#define MAX_N	46
int memo[MAX_N] = {0};

int fib(int n){
//1, 1, 2, 3, 5, 8, 13, 21, ...
	if (n < 0)				return 0;
	if (n == 0 || n == 1)	return 1;
	if (memo[n] > 0)		return memo[n];

	return (memo[n] = fib(n-1) + fib(n-2));
}

int main(void){
	int n = 0;

	//はじまり	
	while(1){
		printf("n = ");
		fflush(stdout);
		scanf("%d", &n);
		getchar();

		if (n > MAX_N) {
			printf("\"n=46\"以内にして下さい\n");
			continue;
		}
		break;
	}

	//アナウンス
	printf("フィボナッチ数列を表示します。\n");
	getchar();

	//フィボナッチ数列
	for(int i=0; i<n; i++){
		printf("%d番目 ： %d\n", i+1, fib(i));
	}

	//おわり
	printf("おわり\n");
	getchar();

	return 0;
}