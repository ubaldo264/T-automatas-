#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool esCadenaValida(const char* cadena) {
    int i = 0;

    while (cadena[i] == 'a') {
        i++;
    }

    while (cadena[i] == 'b') {
        i++;
    }

    if (cadena[i] != 'c') {
        return false;
    }
    i++;

    if (cadena[i] != 'd') {
        return false;
    }
    while (cadena[i] == 'd') {
        i++;
    }

    if (cadena[i] != 'e') {
        return false;
    }
    i++;

    if (cadena[i] != '\0') {
        return false;
    }

    return true;
}

int esCadenaValidaExpresion(char cadena[]) {
    int i = 0;
    int tieneOperador = 0;
    int tieneNumero = 0;

    if (strlen(cadena) == 0 || cadena[0] == '\n') {
        return 0;
    }

    if (!isdigit(cadena[i]) && cadena[i] != '+' && cadena[i] != '-') {
        return 0;
    }

    while (cadena[i] != '\0' && cadena[i] != '\n') {
        if (isdigit(cadena[i])) {
            tieneNumero = 1;
            while (isdigit(cadena[i])) {
                i++;
            }
        } else if (cadena[i] == '+' || cadena[i] == '-' || cadena[i] == '*') {
            tieneOperador = 1;
            i++;
            while (cadena[i] == ' ') {
                i++;
            }
            if (!isdigit(cadena[i])) {
                return 0;
            }
        } else if (cadena[i] == ' ') {
            i++;
        } else {
            return 0;
        }
    }

    return tieneNumero && tieneOperador;
}

bool validar_cadena(const char* str) {
    int i = 0;
    
    // Comprobar las repeticiones de 'a' y 'b' (ab)*
    while (str[i] == 'a') {
        i++;
    }

    while (str[i] == 'b') {
        i++;
    }

    // Verificar que la cadena contenga 'c'
    if (str[i] != 'c') {
        return false;
    }
    i++;

    // A partir de aquí, debe haber al menos un 'de'
    if (str[i] != 'd') {
        return false;
    }

    while (str[i] == 'd') {
        i++;
    }

    if (str[i] != 'e') {
        return false;
    }
    i++;

    // Asegurar que la cadena termine correctamente después de 'de'
    if (str[i] != '\0') {
        return false;
    }

    return true;
}

void validarCadena() {
    char cadena[100];
    printf("Ingrese una cadena para validar (expresion regular a*b*c+d+e): ");
    scanf("%s", cadena);

    if (esCadenaValida(cadena)) {
        printf("La cadena \"%s\" es valida.\n", cadena);
    } else {
        printf("La cadena \"%s\" es invalida.\n", cadena);
    }
}

void validarExpresion() {
    char cadena[100];
    printf("Ingresa una expresion para verificar (operadores +, -, *, números): ");
    fgets(cadena, sizeof(cadena), stdin);  // Usamos fgets para que permita entradas con espacios

    if (esCadenaValidaExpresion(cadena)) {
        printf("La cadena ingresada es valida.\n");
    } else {
        printf("Error: La cadena ingresada no es válida.\n");
    }
}

void validarPatron() {
    char str[100];
    printf("Ingresa una cadena para verificar el patrón ((ab)*c(de)+): ");
    scanf("%s", str);

    if (validar_cadena(str)) {
        printf("La cadena \"%s\" es valida.\n", str);
    } else {
        printf("La cadena \"%s\" es invalida.\n", str);
    }
}

int main() {
    int opcion;

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Verificar cadena a*b*c+d+e\n");
        printf("2. Verificar la expresion regular (+/-/*)d+\n");
        printf("3. Verificar la cadena (ab)*c(de)+\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                validarCadena();
                break;
            case 2:
                validarExpresion();
                break;
            case 3:
                validarPatron();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
