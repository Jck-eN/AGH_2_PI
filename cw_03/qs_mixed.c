#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SWAP(a, b)   \
    do               \
    {                \
        int tmp = a; \
        a = b;       \
        b = tmp;     \
    } while (0)

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
#ifdef STACK
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

void quickSort(int tab[], int left, int right)
{
    stack *st = malloc(sizeof(stack));
    init(st, (right - left + 1) * 2);
    push(st, left);
    push(st, right);
    while (!is_empty(st))
    {
        right = pop(st);
        left = pop(st);
        int q = partition(tab, left, right);
        if (q > left)
        {
            push(st, left);
            push(st, q - 1);
        }
        if (q + 1 < right)
        {
            push(st, q + 1);
            push(st, right);
        }
    }
    free(st);
    return;
}
#else
void quickSort(int tab[], int left, int right)
{
    if (right <= left)
        return;
    int q = partition(tab, left, right);
    quickSort(tab, left, q - 1);
    quickSort(tab, q + 1, right);
    return;
}
#endif

int main()
{

    struct timeval start, end;

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

        gettimeofday(&start, NULL);
        for(int i=0; i<10000; i++){
                quickSort(tab, 0, n - 1);
        }
        gettimeofday(&end, NULL);

        printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

        for (int i = 0; i < n; i++)
        {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
    system("pause");
}
