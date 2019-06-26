#include <iostream>

using namespace std;

int how_many_ways(string map, int N) {
    int ways[N];
    for(int &i : ways) i=0;
    ways[0]=1;
    for(int i=0; i<N; i++){
        if(map[i]=='1'){
            for(int j=1;j<=6; j++){
                if(i+j<N && map[i+j]=='1') ways[i+j]+=ways[i];
            }
        }
    }
    return ways[N-1];
}

int main() {
    int N;
    cin >> N;
    string map;
    cin >> map;
    if (map.size() != N) {
        cout << "Incorrect map size" << endl;
        return -1;
    }
    cout << how_many_ways(map, N) << endl;
    cin.get();
    cin.get();
}