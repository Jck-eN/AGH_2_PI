#include <stdio.h>
#include <stdlib.h>

int change_int(int amount, int* coins, int coins_count, int* result, int prev_coin, int depth, int* min_global){
  // for(int i=0; i<depth; i++){
  //  printf(" ");
  //  }
  //  printf("%d:%d ",depth, prev_coin);
    int res, min_num=100;
    if(depth>=20 || amount<0) return -1;
    if(amount==0) {
  //      printf("!");
        return depth;
    }

    for(int i=0; i<coins_count; i++){
        if(coins[i]>=prev_coin) {
            res = change_int(amount-coins[i], coins, coins_count, result, coins[i], depth+1, min_global);
         //   printf("\n");
            if(res!=-1 && res <= *min_global){
                *min_global=res;
                min_num=res;
                result[*min_global-(depth+1)]=coins[i]; //reverse: result[depth]=coins[i];
            }
        }
    }
    if(min_num == 100) {
        return -1;
    }
    return min_num;
}

int change(int amount, int* coins, int coins_count, int* result) {
    if(amount==0) return 0;
    int* min=malloc(sizeof(int));
    *(min)=100;

    change_int(amount, coins, coins_count, result, -1, 0, min);
    int res=(*(min));
    free(min);
    if(res==100) return 0;
    return res;

}

int main() {
    int RESULT_LIMIT = 20;
    int *results = malloc(RESULT_LIMIT*sizeof(int));
    int N, C;
    scanf("%d", &N); // number of test cases
    scanf("%d", &C); // number of coins
    int* coins = malloc(C*sizeof(int));
    for(int i=0; i<C; i++) scanf("%d", &coins[i]);

    int change_to_give, results_count;
    for(int i=0; i<N; i++) {
        scanf("%d", &change_to_give);
        results_count = change(change_to_give, coins, C, results);
        for(int i=0; i<results_count; i++) printf("%d ", results[i]);
        printf("\n");
    }

    free(results);
    free(coins);
}