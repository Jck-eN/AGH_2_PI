#include <iostream>
#include <string>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
// #define DEBUG 1 
using namespace std;


struct Node
{
    string text;
    Node *next;
};

unsigned int hashfunc(string txt) {
    unsigned int kn=0, weight=1493;
    for(int i=0; txt[i]!='\0'; i++){
        kn=kn*weight+txt[i];
    }
    return kn;
}

void add_to_hashtable(Node** hashtable, int n, string txt) {
    unsigned int hash = hashfunc(txt) % n;

    Node* p=new Node;
    p->text=txt;
    p->next=hashtable[hash];    
    hashtable[hash]=p;
  }

bool check_if_exists(Node** hashtable, int n, string txt) {
    if(n==0)return false;
    unsigned int hash = hashfunc(txt) % n;
    Node* tmp=hashtable[hash];

    while(tmp!=NULL){
        if(tmp->text==txt) return true;
        tmp=tmp->next;
    }
    return false;

}

void free_memory(Node** hashtable, int n) {
    Node *ptr, *nxt, *tmp;  
    tmp=ptr;
    for (int i = 0; i < n; i++) {
        ptr = hashtable[i];
        while (ptr != NULL) {
            nxt=ptr->next;
            delete ptr;
            ptr=nxt;
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
            debug_print_hashtable(hashtable, n);
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
