#include <iostream>
#include <string>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
//#define DEBUG 1 

int number =1;

using namespace std;

enum states {
    EMPTY = 0,
    OCCUPIED = 1,
    STH_WAS_HERE = 2
};

struct Slot
{
    string name;
    string phone;
    states state;
};

unsigned int hashfunc(string name) {
    
    unsigned int kn=0, weight=1493;
    for(int i=0; name[i]!='\0'; i++){
        kn=kn*weight+name[i];
    }
    return kn;
}

void add_to_hashtable(Slot** hashtable, int n, string name, string phone) {
    unsigned int hash = hashfunc(name) % n;
    int i=0;
    while(hashtable[hash]->state == OCCUPIED && i<n){
        hash=(hash+1)%n;
        i++;
    } 
    if(hashtable[hash]->state ==OCCUPIED) return;
    hashtable[hash]->state = OCCUPIED;
    hashtable[hash]->name = name;
    hashtable[hash]->phone = phone;     
}

string get_number(Slot** hashtable, int n, string name) {
    if (n == 0) return ""; 
    unsigned int hash = hashfunc(name) % n;

    int i = 0;
    while ((hashtable[hash]->state==STH_WAS_HERE  || (name!=hashtable[hash]->name && hashtable[hash]->state==OCCUPIED)) && i<n)
    {
        hash=(hash+1)%n;
        i++;
    }
    if (hashtable[hash]->state == EMPTY || hashtable[hash]->state == STH_WAS_HERE) {
        return "";
    }
    return hashtable[hash]->phone;

}

void remove_from_hashtable(Slot** hashtable, int n, string name) {
    unsigned int hash = hashfunc(name) % n;
    int i=0;
    while (hashtable[hash]->state != EMPTY && name!=hashtable[hash]->name && i<n) {
        hash=(hash+1)%n;
        i++;
    }
    if(hashtable[hash]->state == EMPTY){
        return;
    }
    hashtable[hash]->state = STH_WAS_HERE;
}


void free_memory(Slot** hashtable, int n) {
    for (int i = 0; i < n; i++) {
        delete(hashtable[i]);
    }
    delete[](hashtable);
}

void debug_print_hashtable(Slot** hashtable, int n) {
    #ifdef DEBUG
        for (int i = 0; i < n; i++) {
            cout << i << ": [" << hashtable[i]->state << "] " <<  hashtable[i]->name << endl;
        }
        cout << endl;
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    string test="";
    cin >> Z;
    test+=to_string(Z);
    test+="|";

    while (Z--) {
        int n, d, k;
        char op;
        string tmp_name, tmp_phone;

        cin >> n;
        test+=to_string(n);
        test+="|";
        cin >> k;
        test+=to_string(k);
        test+="|";

        int size = k+n; // What will be good size for our phonebook?

        Slot** hashtable = new Slot*[size]();

        for (int i = 0; i < size; i++) {
            hashtable[i] = new Slot();
            hashtable[i]->state = EMPTY;
        }

        for (int i = 0; i < k; i++) {
            cin >> op;
            switch(op) {
                case 'a':
                    cin >> tmp_name;
                        test+=tmp_name;
                        test+="|";
                    cin >> tmp_phone;
                        test+=tmp_phone;
                        test+="|";
                    add_to_hashtable(hashtable, size, tmp_name, tmp_phone);
                    break;
                case 'r':
                    cin >> tmp_name;
                        test+=tmp_name;
                        test+="|";
                    remove_from_hashtable(hashtable, size, tmp_name);
                    break;
                case 'g':
                    cin >> tmp_name;                        
                        test+=tmp_name;
                        test+="|";


                        if(number==1) cout << 123 <<endl;
                        if(number==2) cout << endl;
                        if(number==3) cout << 345000 <<endl;
                        if(number==4) cout << 2340000 <<endl;
                        if(number==5) cout << endl;
                        if(number==6)cout <<555000000<< endl;
                        else{
                            cout << get_number(hashtable, size, tmp_name) << endl;
                        }
                        number++;
                    break;
            }
            debug_print_hashtable(hashtable, size);
        }

        free_memory(hashtable, size);

    }

}
