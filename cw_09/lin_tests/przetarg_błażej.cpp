#include <stdio.h>
#include <list>

using namespace std;

int n;
list<int> *graph;
int lines_idx;
list<int> *lines;

void euler(int u, bool &eulerian, int &lines_idx)
{
    while (!graph[u].empty())
    {
        int v = graph[u].front();    
        graph[v].remove(u);
        graph[u].pop_front();
        euler(v, eulerian, lines_idx);
    }
    
    if (!eulerian && u == 0)
        lines_idx++;
    else
        lines[lines_idx].push_back(u);
}

int main() {
    int Z;
    
    scanf("%d", &Z);
    
    while (Z--) {
        int m, u, v;
        scanf("%d %d", &n, &m);
        
        graph = new list<int>[n+2];
        lines = new list<int>[n+2];
        
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool eulerian = true;
        for(int i = 1; i <= n; i++)
            if(graph[i].size() % 2 != 0)
            {
                graph[i].push_back(0);
                graph[0].push_back(i);
                eulerian = false;
            }
        
        lines_idx = 0;
        
        if(eulerian)
            euler(1, eulerian, lines_idx);
        else
            euler(0, eulerian, lines_idx);
        
        int lines_number = 0;
        
        for(int i = 0; i <= lines_idx; i++)
            if(lines[i].size()>1)
                lines_number++;
        
        printf("%d\n", lines_number);
        
        for(int i = 0; i <= lines_number; i++)
        {
            if(lines[i].size() > 1)
            {
                printf("%lu ", lines[i].size());
                for (list<int>::iterator it = lines[i].begin(); it != lines[i].end(); it++)
                {
                    printf("%d ", *it);
                }
                printf("\n");
            }
        }
        
        delete[] graph;
        delete[] lines;
    }
}
