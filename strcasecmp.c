#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char *argv[]) {
    const char s1[] = "Hello";
    const char s2[] = "hello";
    printf("strcasecmp('%s','%s') = %u\n", s1, s2, strcasecmp(s1, s2));
    return (EXIT_SUCCESS);
}
