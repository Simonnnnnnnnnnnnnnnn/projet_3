/*
 * List of First Week exercices
 *
 * reminder: read the exercices carefully, some ask to write the body only, some the prototype & the body etc...
 */

/* [S1] Absolute value
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s1_absolute_value
 *
 * The absolute value of a number is defined as |n| = n if n >= 0, |n| = -n else.
 * Write the body of the function absval returning the absolute value of i.
 */
int absval(int i){
    return i<0 ? -i : i;
}

/*
 * [S1] Factorial
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s1_factorial
 *
 * The factorial of an integer n! is defined as n! = 1*2*3*...*(n-1)*n, with 0! = 1.
 * Write your own function factorial which takes as parameter an integer and returns an integer value. Your function must be named factorial.
 * Provide below the prototype and the body of this function.
 */
int factorial (int n){
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac = fac*i;
    }
    return fac;
}

/*
 * [S1] Through the array
 *
 * https://inginious.info.ucl.ac.be/course/LEPL1503/s1_tab_find
 *
 * In C, an array is a set of variables sharing the same data type : int array[3] = {42, 1337, 0};.
 * An item of an array can be retrieved through its index. For example array[1] gives the second element of the array (here 1337).
 * Write the body of the function tab_find :
    @tab : an array of int
    @len : the number of int in tab
    @elem : the elem looked for
    @return : return the index at which elem is found, else returns -1 if not found.
*/
int tab_find(int tab[], int len, int elem){
    // the following code is using a for-loop
    for(int i=0; i < len; i++){
        if(tab[i]==elem) return i;
    }
    return -1;

    // the following code is using while-loop
    int i = 0;
    while (i<len){
        if(tab[i] == elem){
            return i;
        }
        else{i++;}
    }
    return -1;
}



