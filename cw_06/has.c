#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
// #define DEBUG 1 
#define MAX_CHARS 30

typedef unsigned int uint;

typedef struct Node {
	char text[MAX_CHARS];
	struct Node *next;
} Node;

uint hashfunc(const char* txt) {
	int p = 1491;
	uint h = 0;
	for (int i = 0; i < strlen(txt); i++)
		h = h*p + txt[i];
	return h;
}

void add_to_hashtable(Node** hashtable, int n, const char* txt) {
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->text, txt);
	uint hash = hashfunc(txt) % n;
	node->next = hashtable[hash];
	hashtable[hash] = node;
}

bool check_if_exists(Node** hashtable, int n, const char* txt) {
	if (n == 0) return false; 
	uint hash = hashfunc(txt) % n;
	Node* ptr;	
	ptr = hashtable[hash];
	while (ptr != NULL) {
		if (strcmp(ptr->text, txt) == 0) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

void free_memory(Node** hashtable, int n) {
	Node *ptr, *nxt;	
	for (int i = 0; i < n; i++) {
		ptr = hashtable[i];
		while (ptr != NULL) {
			nxt = ptr->next;
			free(ptr);
			ptr = nxt;
		}
	}
	free(hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
	#ifdef DEBUG
		Node* ptr;	
		for (int i = 0; i < n; i++) {
			printf("%d: ", i);
			ptr = hashtable[i];
			while (ptr != NULL) {
				printf("%s | ", ptr->text);
				ptr = ptr->next;
			}
			printf("\n");
		}
	#endif
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {
		int n, k;
		char tmp[MAX_CHARS];

        scanf("%d", &n);
        scanf("%d", &k);

		Node** hashtable = (Node**)calloc(n, sizeof(Node*));

		for (int i = 0; i < n; i++)
			hashtable[i] = NULL;

		for (int i = 0; i < n; i++) {
			scanf("%s", tmp);
			add_to_hashtable(hashtable, n, tmp);
		}

		debug_print_hashtable(hashtable, n);

		for (int i = 0; i < k; i++) {
			scanf("%s", tmp);
			if (check_if_exists(hashtable, n, tmp)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		free_memory(hashtable, n);
	}
}

