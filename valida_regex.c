/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

char* extrair_numeros_cpf(const char* cpf) {
    regex_t regex;
    regcomp(&regex, "[^0-9]", REG_EXTENDED);
    
    char* result = malloc(strlen(cpf) + 1);
    regfree(&regex);
    
    int j = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            result[j++] = cpf[i];
        }
    }
    result[j] = '\0';
    
    return result;
}


int validar_valor_brl(const char* valor) {
    regex_t regex;
    regcomp(&regex, "^[Rr]\\$\\s?\\d{1,3}(\\.\\d{3})*(,\\d{2})?$", REG_EXTENDED);
    
    int result = regexec(&regex, valor, 0, NULL, 0);
    regfree(&regex);
    
    return result == 0;
}


int validar_numero_telefone(const char* telefone) {
    regex_t regex;
    regcomp(&regex, "^\\(\\d{2,3}\\)\\s?\\d{4,5}(?:-|\\s?)?\\d{4}$", REG_EXTENDED);

    int result = regexec(&regex, telefone, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}

int main() {
    
    const char* cpfComPontos = "123.456.789-10";
    char* cpfApenasNumeros = extrair_numeros_cpf(cpfComPontos);
    printf("CPF Apenas Números: %s\n", cpfApenasNumeros);
    free(cpfApenasNumeros);

    
    const char* valorBRL1 = "R$ 1000,10";
    const char* valorBRL2 = "r$123.456,78";
    const char* valorInvalido = "R$abc";

    printf("Validação BRL 1: %d\n", validar_valor_brl(valorBRL1));  
    printf("Validação BRL 2: %d\n", validar_valor_brl(valorBRL2));  
    printf("Validação BRL Inválida: %d\n", validar_valor_brl(valorInvalido));  

    const char* telefone1 = "(43)35428000";
    const char* telefone2 = "(43) 3542 8000";
    const char* telefone3 = "(43) 99999-000";
    const char* telefoneInvalido = "(123) 4567";

    printf("Validação Telefone 1: %d\n", validar_numero_telefone(telefone1));  
    printf("Validação Telefone 2: %d\n", validar_numero_telefone(telefone2));  
    printf("Validação Telefone 3: %d\n", validar_numero_telefone(telefone3));  
    printf("Validação Telefone Inválido: %d\n", validar_numero_telefone(telefoneInvalido));

    return 0;
}
