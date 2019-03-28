#include <stdio.h>
#include <stdlib.h>

void encrypt(char* message, int n) {

  for(int i=0; message[i]!='\0' ;i++)
    {
      if(message[i]==' ') continue;
      message[i]+=3;
      if(message[i]>'z')
	{
	  message[i]+=('a'-'z'-1);
	}
	
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char* message = (char*) malloc((n+1) * sizeof(char));
    fgets(message, n+1, stdin); // reads \n
    fgets(message, n+1, stdin);
    encrypt(message, n);
    printf("%s\n", message);
    free(message);
}
