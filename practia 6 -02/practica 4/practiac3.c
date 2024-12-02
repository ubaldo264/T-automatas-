#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


bool F(const char **input);
bool Es(const char **input);
bool EN(const char **input);
bool R(const char **input);
bool D(const char **input);
bool S(const char **input);
void log_step(const char *rule);


int step_count = 0;


void log_step(const char *rule) {
    printf("%d: %s\n", ++step_count, rule);
}

bool F(const char **input) {
    log_step("F -> Es.E_N");
    const char *start = *input;

    if (Es(input) && **input == '.') {
        (*input)++;
        log_step("E_N -> .E_N");

        if (EN(input)) {
            return true;
        }
    }
    *input = start; 
    return false;
}

// Es -> S.E_N
bool Es(const char **input) {
    log_step("Es -> S.E_N");
    const char *start = *input;

    if (S(input) && EN(input)) {
        return true;
    }

    *input = start; 
    return false;
}

// EN -> R | ε
bool EN(const char **input) {
    const char *start = *input;

    if (R(input)) {
        return true;
    }

    *input = start;
    log_step("EN -> vacio");
    return true; 
}

// R -> D.R | ε
bool R(const char **input) {
    const char *start = *input;

    if (D(input)) {
        log_step("R -> D.R");
        if (R(input)) {
            return true;
        }
    }

    *input = start; 
    log_step("R -> vacio");
    return true; 
}

// D -> 0|1|2|...|9
bool D(const char **input) {
    if (isdigit(**input)) {
        char digit[2] = {**input, '\0'};
        char rule[16];
        sprintf(rule, "D -> %s", digit);
        log_step(rule);
        (*input)++;
        return true;
    }
    return false;
}

// S -> +|-|ε
bool S(const char **input) {
    if (**input == '+' || **input == '-') {
        char sign[2] = {**input, '\0'};
        char rule[16];
        sprintf(rule, "S -> %s", sign);
        log_step(rule);
        (*input)++;
        return true;
    }

    log_step("S -> vacio");
    return true; 
}


int main() {
    char input[256];
    printf("Ingresa una cadena a evaluar segun la gramatica: ");
    scanf("%s", input);

    const char *ptr = input;
    step_count = 0;

    printf("\nProcesando la cadena: %s\n", input);
    if (F(&ptr) && *ptr == '\0') {
        printf("\nResultado: La cadena es valida.\n");
    } else {
        printf("\nResultado: La cadena es invalida.\n");
    }

    return 0;
    
    }

