#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;


void euler(list<int> graph[], list<int>* &line, int u) {
    while (!graph[u].empty())
    {
        int v = graph[u].front();    
        graph[v].remove(u);
        graph[u].pop_front();
        euler(graph, line, v);
    }
    line->push_back(u);

}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int m, u, v, n;
        scanf("%d %d", &n, &m);

        list<int> *graph = new list<int>[n+1];
        list<int> *line = new list<int>;

    
        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool eulerian = true;
        for (int i = 1; i <= n; i++)
        {
            if (graph[i].size() % 2)
            {
                graph[i].push_back(0);
                graph[0].push_back(i);
                eulerian=false;
            }
        }
        if(eulerian) euler(graph, line, 1);
        else {
            euler(graph, line, 0);
            line->pop_front(); //delete zero'es from line->begin and line->end
            line->pop_back();
        }
        
        //counting zero'es in list line:
        int lines_number=1;

        for (list<int>::iterator it = line->begin(); it != line->end(); it++)
        {
            if(*it==0) lines_number++;
        }

        list<int>::iterator prev= line->begin();

        cout << lines_number << endl;
        for(int i = 0; i < lines_number; i++)
        {
            list<int>::iterator zero = find(prev, line->end(), 0);
            cout << distance(prev, zero) << " ";
            while(prev!=zero)
            {
                cout << *prev << " ";
                ++prev;
            }
            cout << endl;
            prev=(++zero);
        }

        cout << endl;

        delete [] graph;
        delete line;
    }
}
