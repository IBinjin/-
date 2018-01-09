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

	//�͂��܂�	
	while(1){
		printf("n = ");
		fflush(stdout);
		scanf("%d", &n);
		getchar();

		if (n > MAX_N) {
			printf("\"n=46\"�ȓ��ɂ��ĉ�����\n");
			continue;
		}
		break;
	}

	//�A�i�E���X
	printf("�t�B�{�i�b�`�����\�����܂��B\n");
	getchar();

	//�t�B�{�i�b�`����
	for(int i=0; i<n; i++){
		printf("%d�Ԗ� �F %d\n", i+1, fib(i));
	}

	//�����
	printf("�����\n");
	getchar();

	return 0;
}