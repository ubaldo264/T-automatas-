#include <stdio.h>
#include <string.h>
#include <ctype.h>

void interpretar_gramatica(char numero[]) {
    int i;
    int len = strlen(numero);  
    
    
    for (i = 0; i < len; i++) {
        if (!isdigit(numero[i])) {  
            printf("El numero ingresado no cumple con las reglas de la gramatica.\n");
            return;
        }
    }

    
    printf("Derivaciones segun la gramatica:\n");
    printf("EN -> DR\n");

    
    for (i = 0; i < len; i++) {
        if (i == 0) {
            printf("D -> %c\n", numero[i]);  
        } else {
            printf("R -> DR -> %cR\n", numero[i]);  
        }
    }
    printf("R -> vacio\n"); 
    printf("Resultado final: %s\n", numero); 
}

int main() {
    char numero[100];  

    printf("Ingresa un nimero en notacion cientifica (sin exponentes): ");
    scanf("%s", numero);

  
    interpretar_gramatica(numero);  

    return 0;
}
