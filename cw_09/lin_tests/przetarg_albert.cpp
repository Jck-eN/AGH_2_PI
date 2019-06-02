#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>
#include <algorithm>

using namespace std;

void euler(list<int> graph[], list<int> &line, int u) {
    while (!graph[u].empty())
    {
        int v = graph[u].front();    
        graph[v].remove(u);
        graph[u].pop_front();
        euler(graph, line, v);
    }
    line.push_back(u);
}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int m, u, v, n;
        scanf("%d %d", &n, &m);

        list<int> graph[n+1];
        list<int> line;

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool eulerian = true;
        for(int i = 1; i <= n; i++){
            if(graph[i].size() % 2)
            {
                graph[i].push_back(0);
                graph[0].push_back(i);
                eulerian = false;
            }
        }
        
        euler(graph, line, (int)eulerian);
        if(!eulerian){
            line.pop_front();
            line.pop_back();
        }

        int num = std::count_if(line.begin(), line.end(), [](int x){
            return !x;
        }) + 1;

        printf("%d\n", num);
        auto prev = line.begin();
        for(int i = 0; i < num; i++){ //until prev == line.end()?

            auto zero = find(prev, line.end(), 0);
            printf("%d ", distance(prev, zero));
            while(prev != zero){
                printf("%d ", *prev);
                ++prev;
            }
  
            printf("\n");
            prev = (++zero);

        }
        printf("\n");
    }
}
