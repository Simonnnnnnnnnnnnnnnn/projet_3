/**
 * [INGInious] url for submitting : https://inginious.info.ucl.ac.be/course/LEPL1503/s3_commandetest#
 *
 * build this via gcc or IDE
 * in a console/terminal, you can call the program using the following command
 *          .\test.exe arg1 -ne arg2
 *
 * if you want to get some information printed out remove the comment made on (line 12) #define DISPLAY_PRINT;
 * this will activate all the printf inside the code
 */

//#define DISPLAY_PRINT;//uncomment this if you want some console.print via printf
#include <stdlib.h>
#ifdef DISPLAY_PRINT
    #include <stdio.h>
#endif
#include <string.h>

/**
 * struct for mapping the evaluation to perform and its method to call
 */
typedef struct {
    char *value;

    int (*methodString)(char *, char *);
} Mapping;

/**
 * struct to store 2 numbers
 */
typedef struct {
    int a;
    int b;
} Numbers;


/**
 * code behind '-eq'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int equals(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) == 0) ? 0 : 1;
}


/**
 * code behind '-gt'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int greater_than(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) > 0) ? 0 : 1;
}


/**
 * code behind '-ge'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int greater_or_equal(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) >= 0) ? 0 : 1;
}

/**
 * code behind '-ne'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int not_equal(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) == 0) ? 1 : 0;
}

/**
 * code behind '-lt'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int less_than(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) < 0) ? 0 : 1;
}
/**
 * code behind '-le'
 * @param arg1 first string
 * @param arg2 second string
 * @return 0 if the evaluation is true, 1 if false
 */
static inline int less_or_equal(char *arg1, char *arg2) {
    return (strcmp(arg1, arg2) <= 0) ? 0 : 1;
}
/**
 * Converts given arguments into a struct of numbers->
 * @param arg1 the first string to convert into number
 * @param arg2 the second string to convert into number
 * @param result the result of number conversions
 *      a : conversion of arg1
 *      b : conversion of arg2
 * @return 1 if both can be converted into numbers, 0 if not.
 * note : code snippet found in https://sites.uclouvain.be/SyllabusC/notes/Theorie/C/linker.html#pointeurs (search for strtol)
 */
static inline int convertArgsToNumbers(char *arg1, char *arg2, Numbers* result) {
    char *p;
    long li;
    result->a = strtol(arg1, &p, 10);
    // we don't mind to convert arg2 if arg1 cannot be converted...
    // we check if p contains the null terminated string after the conversion of arg1
    // if p = '\0' then we try to get the conversion of arg2 else we just set b to 0
    // ternary condition:: (condition) ? (true expression) : (false expression)
    result->b = (*p == '\0' ? strtol(arg2,&p, 10) : 0);
    return *p == '\0';
}

/**
 * Evaluates 2 numbers->
 * @param eval one of "-eq", "-ne", "-lt", "-le", "-gt", "-ge"
 * @param numbers pointer to numbers to evaluate
 * @return 0 if the evaluation is true, 1 if false
 * if eval not found, then return 1;
 */
static inline int evaluateNumbers(char *eval, Numbers* numbers) {
    // "-eq", "-ne", "-lt", "-le", "-gt", "-ge"
    if (strcmp("-eq", eval) == 0) {
        return numbers->a == numbers->b ? 0 : 1;
    }
    if (strcmp("-ne", eval) == 0) {
        return numbers->a != numbers->b ? 0 : 1;
    }
    if (strcmp("-gt", eval) == 0) {
        return numbers->a > numbers->b ? 0 : 1;
    }
    if (strcmp("-ge", eval) == 0) {
        return numbers->a >= numbers->b ? 0 : 1;
    }
    if (strcmp("-lt", eval) == 0) {
        return numbers->a < numbers->b ? 0 : 1;
    }
    if (strcmp("-le", eval) == 0) {
        return numbers->a <= numbers->b ? 0 : 1;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    //// initializing list of mappings expression vs methodString to call
    Mapping mappings[6] = {
            {.value="-eq", .methodString=&equals},
            {.value="-ne", .methodString=&not_equal},
            {.value="-lt", .methodString=&less_than},
            {.value="-le", .methodString=&less_or_equal},
            {.value="-gt", .methodString=&greater_than},
            {.value="-ge", .methodString=&greater_or_equal}
    };

    //// get the size of our array of mappings
    const int size = sizeof(mappings) / sizeof(mappings[0]);

#ifdef DISPLAY_PRINT
    const char *expressionsList = "-eq, -ne, -lt, -le, -gt, -ge";
#endif

    //// declaring a pointer to a function that will be used to evaluate strings
    int (*evaluateString)(char *, char *) = NULL;

    //// check if we have the correct number of arguments
    ////      keep in mind the first argument is the program itself
    if (argc != 4) {

#ifdef DISPLAY_PRINT
        printf("arguments exception, command needs 3 arguments");
#endif

        exit(1);
    }

#ifdef DISPLAY_PRINT
    printf("%u arguments:\n\t1. %s\n\t2. %s\n\t3. %s\n\t4. %s\n\n", argc, argv[0], argv[1], argv[2], argv[3]);
#endif

    Numbers* numbers=(Numbers*)malloc(sizeof(Numbers));
    //// check if both argv[1] & argv[3] are numbers
    if (convertArgsToNumbers(argv[1], argv[3], numbers)) {

#ifdef DISPLAY_PRINT
        printf("evaluateNumbers('%s', {.a= %u, .b=%u}) = %u\n", argv[2], numbers->a, numbers->b, evaluateNumbers(argv[2], numbers));
#endif

        //// note; if we free numbers before calling evaluateNumbers, we might lose our values that were stored into our struct
        const int rc = evaluateNumbers(argv[2], numbers);
        free(numbers);//// free memory before exit
        exit(rc);
    }
    free(numbers);//// we don't need numbers anymore, free it here

    //// loop to get the correct method to call. once found, we get out of the loop.
    for (int i = 0; i < size; i++) {
        evaluateString = mappings[i].methodString;

#ifdef DISPLAY_PRINT
        printf("iteration %u: strcmp(\"%s\", \"%s\") = %u\n", i + 1, argv[2], mappings[i].value,
               strcmp(argv[2], mappings[i].value));
#endif

        if (strcmp(argv[2], mappings[i].value) == 0) break;
        evaluateString = NULL;// reset evaluateString if we didnt break into loop
    }
    if (evaluateString != NULL) {
        //// we found the evaluation method to perform.

#ifdef DISPLAY_PRINT
        printf("evaluateString(\"%s\", \"%s\") with \"%s\" = %u", argv[1], argv[3], argv[2], evaluateString(argv[1], argv[3]));
#endif

        exit(evaluateString(argv[1], argv[3]));
    } else {

#ifdef DISPLAY_PRINT
        printf("3rd argument should be one of [ %s]", expressionsList);
#endif

        exit(1);
    }
}