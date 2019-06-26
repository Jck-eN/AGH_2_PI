#include <iostream>
#include <algorithm>

using namespace std;

struct Event {
    int start, end;
};

bool cmp (Event i,Event j) { 
    return (i.start<j.start); 
}

int how_many_rooms (Event* events, int N) {
    sort (events, events+N, cmp);
    int max=0;
    for(int i=0; i<N; i++){
        int max_temp=1;
        for(int j=0; j<i; j++){
            if(events[j].end>events[i].start) max_temp++;
        }
        if(max<max_temp)max=max_temp;
    }
    return max;
}

int main() {
    int N;
    cin >> N;
    Event e[N];
    for (int i=0; i<N; i++) cin >> e[i].start >> e[i].end;

    cout << how_many_rooms(e, N) << endl;
    cin.get();
    cin.get();
}