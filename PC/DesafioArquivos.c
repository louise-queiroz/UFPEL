#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numero (char *c);

int main (){

    FILE *fp;
    char texto[100], num[50]={"90052.txt"};
    char *result, *word="Next nothing is";
    int prox, op=0;

    while (op!=1){
        fp = fopen(num, "r");
        result = fgets(texto, 100, fp);
        if(strstr(result, word) != NULL) {
            prox = numero(result);
            sprintf(num, "%d.txt", prox); 
        }
        else {
        op = 1; }
    }
    printf("%s", result);
    return 0;
}

int numero(char *c){
    int i, z=0, num=0;
    for(i=0; c[i]!='\0'; i++){
        if(isdigit(c[i])){
            num += (int)(c[i])-'0';
		    num *= 10;
        }
    }
    num /= 10;
    return num;
}