#include <stdio.h>
#include <stdlib.h>

int main(){
    char *V[5];

    printf("\nIngrese 5 nombres: ");
    for (int i = 0; i < 5; i++)
    {
        V[i]= (char*)malloc(sizeof(char) * 100);
        printf("\nNombre nº %d: ",i+1);
        gets(V[i]);
        printf("\n------------");
        
    }
    printf("\nAhora mostrare los nombres:");
        for (int i = 0; i < 5; i++)
    {
        printf("\nNombre nº %d: %s ",i+1,V[i]);
        printf("\n------------");
        
    }
    //libero la memoria
    for (int i = 0; i < 5; i++) {
    free(V[i]);
  }

    
    return 0;
}