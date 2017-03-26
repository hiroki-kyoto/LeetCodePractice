/**********************************************
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range 
from 1 to 3999.
**********************************************/
char* intToRoman(int num) {
    char I[4] = { 'I', 'X', 'C', 'M' };
    char V[4] = { 'V', 'L', 'D', 'U' };
    int size = 32;
    char * r1 = (char*)malloc(size);
    char * r2 = (char*)malloc(size);
    memset((char*)r1, 0, size);
    memset((char*)r2, 0, size);
    
    int x, f, i, k;
    f = 0;
    while ( num > 0 ) {
        x = num % 10;
        if ( x>0 && x<4 ) {
            for(i=0; i<x; ++i) {
                sprintf(r2, "%c%s", I[f], r1);
                memmove(r1, r2, size);
            }
        } else if ( x==4 ) {
            sprintf(r2, "%c%s", V[f], r1);
            memmove(r1, r2, 64);
            sprintf(r2, "%c%s", I[f], r1);
            memmove(r1, r2, size);
        } else if ( x==5 ) {
            sprintf(r2, "%c%s", V[f], r1);
            memmove(r1, r2, size);
        } else if ( x>5 && x<9 ) {
            for (i=0; i<x-5; ++i) {
                sprintf(r2, "%c%s", I[f], r1);
                memmove(r1, r2, size);
            }
            sprintf(r2, "%c%s", V[f], r1);
            memmove(r1, r2, size);
        } else if ( x==9 ) {
            sprintf(r2, "%c%s", I[f+1], r1);
            memmove(r1, r2, size);
            sprintf(r2, "%c%s", I[f], r1);
            memmove(r1, r2, size);
        }
        num /= 10;
        ++f;
    }
    return r2;
}
