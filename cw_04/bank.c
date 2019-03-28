#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum transfer_type {outgoing, incoming} transfer_type;

typedef struct transfer {
    int amount;
    transfer_type type;
} transfer;

bool are_valid (int initial_amount, transfer* transfers, int n) {
    int amount =initial_amount;
    for(int i=0; i<n; i++){
        if(transfers[i].type==outgoing) amount-=transfers[i].amount;
        else amount+=transfers[i].amount;
        
        if(amount<0) return 0;
    }
    return 1;
}

int main() {
    int initial_amount, n;
    scanf("%d", &initial_amount);
    scanf("%d", &n);
    transfer* transfers = malloc(n*sizeof(transfer));
    char direction;
    for (int i=0; i<n; i++) {
        scanf(" %c", &direction);
        transfers[i].type = (direction == 'I' ? incoming : outgoing);
        scanf("%d", &transfers[i].amount);
    }
    printf(are_valid(initial_amount, transfers, n) ? "YES\n" : "NO\n");
    free(transfers);
}