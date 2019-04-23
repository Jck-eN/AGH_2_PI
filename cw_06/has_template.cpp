#include <iostream>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
// #define DEBUG 1 

using namespace std;


struct Node
{
    string text;
    Node *next;
};

uint hashfunc(string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

void add_to_hashtable(Node** hashtable, int n, string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

bool check_if_exists(Node** hashtable, int n, string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

void free_memory(Node** hashtable, int n) {
    Node *ptr, *nxt;    
    for (int i = 0; i < n; i++) {
        ptr = hashtable[i];
        while (ptr != NULL) {
            /**********************
            * PLACE FOR YOUR CODE *
            **********************/
        }
    }
    delete[](hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
    #ifdef DEBUG
        Node* ptr;  
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            ptr = hashtable[i];
            while (ptr != NULL) {
                cout << ptr->text << " | ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    cin >> Z;

    while (Z--) {
        int n, k;
        string tmp;

        cin >> n;
        cin >> k;

        Node** hashtable = new Node*[n]();

        for (int i = 0; i < n; i++)
            hashtable[i] = NULL;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            add_to_hashtable(hashtable, n, tmp);
        }

        for (int i = 0; i < k; i++) {
            cin >> tmp;
            if (check_if_exists(hashtable, n, tmp)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        free_memory(hashtable, n);

    }

}
