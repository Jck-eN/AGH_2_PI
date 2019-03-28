#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b)   \
    do               \
    {                \
        int tmp = a; \
        a = b;       \
        b = tmp;     \
    } while (0)

typedef struct stack
{
    int top;
    int size;
    int *tab;
} stack;

void init(stack *st, int size)
{
    st->top = -1;
    st->tab = malloc(sizeof(int) * size);
    st->size = size;
}
void push(stack *st, int val)
{
    if (st->top < st->size - 1)
    {
        st->tab[++st->top] = val;
    }
}
int pop(stack *st)
{
    return st->tab[st->top--];
}

int is_empty(stack *st)
{
    return st->top < 0;
}

int partition(int *tab, int left, int right)
{
    int x = tab[right];
    int j = left - 1;

    for (int i = left; i < right; i++)
    {
        if (tab[i] < x)
        {
            j++;
            SWAP(tab[i], tab[j]);
        }
    }
    j++;
    SWAP(tab[right], tab[j]);
    return j;
}

void quickSort(int tab[], int left, int right)
{
    stack *st = malloc(sizeof(stack));
    init(st, (right-left+1)*2);
    push(st, left);
    push(st, right);
    while (!is_empty(st))
    {
        right = pop(st);
        left = pop(st);
        int q = partition(tab, left, right);
        if (q-1 > left)
        {
            push(st, left);
            push(st, q-1);
        }
        if(q+1<right){
            push(st, q+1);
            push(st, right);
        }
    }
    free(st);
    return;
}

int main()
{
    int Z;

    scanf("%d", &Z);

    int val;

    while (Z--)
    {

        int n;
        scanf("%d", &n);
        int *tab = malloc(n * sizeof(n));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tab[i]);
        }

        quickSort(tab, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
    printf("\n----------\n");
    system("pause");
}
