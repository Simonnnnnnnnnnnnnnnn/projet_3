/*
 * List of Second Week exercices
 *
 * reminder: read the exercices carefully, some ask to write the body only, some the prototype & the body etc...
 */

/* [S2] Printing data
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_printf
 *
 * In this exercise, you will familiarize yourself with the functions printf (printing on the standard output) and
 * sprintf <`printf (text formatting).
 * Consult the documentation before coding to learn how to use these functions properly.
 */
// Question 1: Digital
// printf can also print the content of a variable. Write the body of the function print_digit.
/* print_digit
 * @n: an integer
 *
 * result: print to stdout "The magic number is NUMBER.\n"
 */
void print_digit(int number) {
    printf("The magic number is %u.\n", number);
}

// Question 2: Floating away
// printf is a powerful formatting tool which can handle several data types, and several formatting parameters.
// What would the following call print to stdout ?
// float PI = 3.1415926;
// printf("pi = %.4f", PI);
//
// Answer: pi = 3.1416

//Question 3: Foo
//The function printf writes data to the standard output stream (stdout).
//Write the body of the function print_foo which will print
// "foo\n" (without the quotes, the symbol '\n' represents a line feed,i.e. the end of a line) to stdout.
void print_foo() {
    printf("foo\n");
}

//Question 4: sprintf
//sprintf is a variant of printf which doesn't write to stdout, but instead writes to a buffer.
//Write the body of the function format_str.
/* format_str, example:
 * format_str(buf, 42, "Olivier", 'B') will write into buf
 * the string "Mister Olivier B. has 42 eggs" (no line feed)
 * The given buffer is guaranteed to be big enough
 */
void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer, "Mister %s %c. has %u eggs", name, initial, d);
}


/*[S2] strcat
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_strcat
 *
 * La libraire string(3) implémente un grand nombre de fonctions de manipulation des strings qui vous seront utiles lors de
 * différents projets de programmation.
 * Pour cette tâche, nous vous demandons de réimplémenter la fonction strcat(3).
 * Don't hesitate to consult its man page.
 *
 * Write the body of the function strcat which concatenates the strings dest and src in the dest pointer !
 * As the documentation says, you have to overwrite the '\0' character that terminates the dest string and
 * then add a new '\0' at the end of the concatenated string.
 * In this way, the src string will follow the dest string but the result will be considered as a unique entire string.
 * You have to return the pointer to the resulting string dest.
 */
char *strcat(char *dest, const char *src) {
#include <string.h>

    strcpy(dest + strlen(dest), src);
    return dest;

    // another solution is:
#include <stdio.h>
#include <string.h>

    size_t destlen = strlen(dest);
    size_t i = 0;
    while (src[i] != '\0') {
        dest[destlen + i] = src[i];
        i++;
    }
    dest[destlen + strlen(src)] = '\0';
    return dest;
}

/* [S2] strlen
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_strlen
 *
 * Write the body of the function strlen which outputs the length of the string given as argument.
 *
 */

size_t strlen(const char *s) {
    int len = 0;
    while (s[len] != 0) {
        len++;
    }
    return len;
}


/*[S2] strcasecmp (the code can be found separately on strcasecmp.c)
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_strcasecmp
 *
 * Write the body of the function strcasecmp which
 * returns an integer less than, equal to, or greater than zero if s1 is found, respectively,
 * to be less than, to match, or be greater than s2, ignoring the cases of the characters.
 * You don't have access to existing functions
 * so you have to use this table (https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/ASCII-Table-wide.svg/2000px-ASCII-Table-wide.svg.png)
 */
int strcasecmp(const char *s1, const char *s2) {
    int rc = 0;
    int i = 0;
    if (s1 == s2)
        return 0;

    do {
        char S1 = *(s1 + i), S2 = *(s2 + i);
        if (97 <= S1 && S1 <= 122) { S1 = S1 - 32; }//A-Z::65-90 et a-z::97-122
        if (97 <= S2 && S2 <= 122) { S2 = S2 - 32; }
        rc = S1 - S2;
        if (*(s1 + i) == '\0' || *(s2 + i) == '\0') {
            break;
        }
        i += 1;
    } while (rc == 0);
    return rc;
}

/* [S2] Palindrome
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_palindrome
 *
 * Palindrome are strings of text which read the same backward as forward, i.e. : "racecar", "a man a plan a canal panama" or "kayak".
 * Write the body of the function pal which
 *  - tells if the given string is a palindrome or not.
 *  - Ignore spaces: for example, "kay a k" should be considered a palindrome.
 *  - An empty string is considered a palindrome.
 * You can use all the functions that are defined in string.h.
 * You can't modify the initial string.
 */
/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str) {
    if (str == NULL) {
        return -1;
    }
    int rc = 1;
    int idx = 0;
    int jndex = strlen(str) - 1;
    int strLength = strlen(str);

    for (idx = 0; idx < (int) strLength / 2 && jndex > (int) strLength / 2; idx++, jndex--) {
        while (str[idx] == ' ') { idx += 1; } // don't consider any space, take the following letter for the half right
        while (str[jndex] == ' ') { jndex -= 1; }// don't consider any space, take the following letter for the half left
        // printf("%c is it equal to %c\n",str[idx],str[jndex]);
        if (str[idx] != str[jndex]) { // the last letter considered is not the same left vs right
            rc = 0;
            break;
        }
    }
    return rc;


    // another way to implement it

    if (str == NULL) { // the string is null
        return -1;
    }
    int len = strlen(str);
    if (len == 0) { //the string is empty, its length ==0
        return 1;
    }
    int left = 0;
    int right = len - 1;
    while (left < right) {
        char str_left = str[left];
        char str_right = str[right];

        if (str_left == ' ') { //ignore space on half left
            left++;
        } else if (str_right == ' ') { // ignore space on half right
            right--;
        } else if (str_left != str_right) { //left and right are different
            return 0; //so it is NOT a palindromic string
        } else { //continue on the other following letters to check if it's a plaindrome
            left++;
            right--;
        }
    }
    return 1; //yeah this a palindrome!
}

/* [S2] Reading arguments
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_main_argc
 *
 * When you execute a C program, its function main() is called with, as parameters,
 * the name of the program and the arguments after the executable's name.
 * The signature of the main() function must be the following : int main(int argc, char **argv)
 *
 Write a complete C program containing a main.
 Your program should print one argument out of two (starting with the first), and return 0.
 Each argument shall be separated by a space, and
 the output shall be terminated by a new line just after the last argument printed (so without any additional space).
 This new line should be added even if you don't print any argument.
 Don't forget the required includes for your program.*
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv){
    int main (int argc, char **argv ){
        for(int i = 1; i<argc; i+=2){
            printf("%s", argv[i]);
            if(i+2<argc){
                printf(" ");
            }
        }
        printf("\n");
        return 0;
    }
}

/* [S2] Swap my integers
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_swap2int
 *
 * Write the body of the function swap which exchanges the values pointed by i and j.
 */
void swap(int *i, int *j) {
    int k = *i;
    *i = *j;
    *j = k;
}

/* [S2] Echange de valeurs de fractions
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s2_swap
 *  Soit la définition de la structure représentant des fractions entières suivante:
 *  struct fract_t {
        int num;
        int denum;
};
 On veut pouvoir swapper (échanger) les valeurs de deux fractions en utilisant la fonction
  void swap(struct fract_t *a, struct fract_t *b).
 Ecrivez le code de cette fonction.
 *
 */
void swap(struct fract_t *a, struct fract_t *b){
    struct fract_t k;
    k=*b;
    *b=*a;
    *a=k;

    // another implementation here under
//    int uno = a->num;
//    int deuxio = a->denum;
//    a->num = b->num;
//    a->denum = b->denum;
//    b->num = uno;
//    b->denum = deuxio;
}