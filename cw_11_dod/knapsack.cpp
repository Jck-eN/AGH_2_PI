#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    double value, weight;
};

bool cmp (Item i,Item j) { 
    double i_d = (double)i.value/i.weight;
    double j_d = (double)j.value/j.weight;
    return (i_d>j_d); 
    }

struct Knapsack {
    Item* items;
    int n_elems;
    double capacity;
};

double max_profit(Knapsack knapsack) {
    int cap = knapsack.capacity;
    sort (knapsack.items, knapsack.items+knapsack.n_elems, cmp);
 //   for(int i=0; i<knapsack.n_elems; i++){
   //     cout << knapsack.items[i].weight
    //}
    double profit=0;
    for(int i=0; i<knapsack.n_elems; i++){
        if(cap==0) return profit;
        if(knapsack.items[i].weight<=cap){
            cap-=knapsack.items[i].weight;
            profit+=knapsack.items[i].value;
        }
        else{
            profit+=knapsack.items[i].value*cap/knapsack.items[i].weight;
            cap=0;
        }
    }
    return cap;
}

int main() {
    int N, cap;
    cin >> N >> cap;
    Knapsack k;
    k.n_elems = N;
    k.capacity = cap;
    k.items = new Item[N];
    for (int i=0; i<N; i++) {
        cin >> k.items[i].value >> k.items[i].weight;
    }

    cout << max_profit(k);
    delete[] k.items;
}