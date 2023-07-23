#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    char *p;
    long li;
//    s = {"1252","12m52","+24.12","-45"};
    for (int i=0;i<=sizeof(argv);i++){
        li = strtol(*(argv+i),&p,10);
        printf("strtol(\"%s\",&p,10) :\n",*(argv+i));
        if(*p != '\0') {
            printf("\tCaractère erronné : '%c'\n",*p);
            // p pointe vers le caractère en erreur
        }
        printf("\tValeur convertie : \"%s\" -> %ld\n",*(argv+i),li);
    }


    return(EXIT_SUCCESS);
}