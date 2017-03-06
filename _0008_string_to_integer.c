/*********************
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, please click the reload button
to reset your code definition.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace 
character is found. Then, starting from this character, takes an optional initial plus or minus sign 
followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored 
and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such 
sequence exists because either str is empty or it contains only whitespace characters, no conversion 
is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the 
range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
**********************/
int myAtoi(char* str) {
    int i, n;
    char c;
    int is_in_seq, is_pos;
    long long x, m;
    i=0;
    c = str[i++];
    is_in_seq = 0;
    is_pos = 1;
    x = 0;
    m = 1;
    m <<= 31;
    while ( c ) {
        // check if it is a whitespace
        if ( !is_in_seq ) {
            if ( c != ' ' ) { // begin sequence now
                if ( c == '+' ) {
                    is_pos = 1;
                } else if ( c == '-' ) {
                    is_pos = 0;
                } else if ( c>='0' && c<='9' ) {
                    is_pos = 1;
                    x = 10 * x + (c-'0');
                } else {
                    return 0;
                }
                is_in_seq = 1;
            }
        } else { // within a sequence
            if ( c>='0' && c<='9' ) {
                x = 10 * x + (c-'0');
                if ( is_pos ) {
                    if ( x>=m-1 ) {
                        return m-1;
                    }
                } else {
                    if ( x>=m ) {
                        return -m;
                    }
                }
            } else {
                break;
            }
        }
        c = str[i++];
    }
    if ( !is_in_seq ) {
        return 0;
    }
    if ( is_pos ) {
        if ( x > m - 1 ) {
            return m-1;
        } else {
            return x;
        }
    } else {
        if ( x > m ) {
            return -m;
        } else {
            return -x;
        }
    }
}
