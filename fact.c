#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGIT 10000

void display(char *result){
    printf("%s\n", strrev(result));
}

void scientificDisplay(char *result){
    int length = strlen(result) - 1;

    printf("%c.", result[0]);
    for(int i = 1; i < 7; i++){
        printf("%c", result[i]);
    }
    printf("e+%d\n", length);
}

void freeMem(char *result){
    free(result);
}

void multiply(char *result, int digit){
    int carry = 0;
    int length = strlen(result) - 1;

    for(int i = 0; i <= length; i++){
        int mult = (result[i] - '0') * digit + carry;
        result[i] = (mult % 10) + '0';
        carry = mult / 10;
    }

    while(carry){
        result[length + 1] = (carry % 10) + '0';
        carry /= 10;
        length++;
    }
    result[length + 1] = '\0';
}

void factorial(int n){
    char *result;
    result = calloc(MAX_DIGIT, sizeof(char*));
    result[0] = '1';
   
    for(int i = 2; i <= n; i++){
        multiply(result, i);
    }

    display(result);
    scientificDisplay(result);
    freeMem(result);
}

int main(){
    int n;
    scanf("%d", &n);

    factorial(n);
}