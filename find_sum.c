#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CARD_LENGTH		5
int target_sum = 0;
int card[MAX_CARD_LENGTH] = {1, 2, 4, 7};

int find_sum(int depth, int sum, int max_depth, int *ans, int *ans_length){
	if( depth == max_depth ){
		return (sum == target_sum);
	}
	if( find_sum(depth+1, sum,					max_depth,		ans,	ans_length) ){
		return true;
	}
	if( find_sum(depth+1, sum+ card[depth],	max_depth,		ans+1,	ans_length) ){
		*ans	= card[depth];
		(*ans_length) += 1;
		return true;
	}

	return false;
}

int main(){
	fflush(stdout);
	scanf("%d", &target_sum);

	int max_depth = MAX_CARD_LENGTH;
	int ans[MAX_CARD_LENGTH] = {0};
	int ans_length = 0;
	if( find_sum(0, 0, max_depth, ans, &ans_length) ){
		printf("yes.\n");
		for(int i=0; i<ans_length; i++){
			if(i != 0){
				printf(" + ");
			}
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	else{
		printf("no.\n");
	}

	return 0;
}
