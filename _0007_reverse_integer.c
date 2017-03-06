/*********************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

Subscribe to see which companies asked this question.

Show Tags
Show Similar Problems
*********/

int reverse(int x) {
    long long int m, n;
    if ( x<10 && x >-10 ) {
        return x;
    }
    if ( x>0 ) {
        m = x;
    } else {
        m = -x;
    }
    if ( m == (1<<31) ) {
        return 0;
    }
    n = m % 10;
    m = m / 10;
    while ( m ) {
        n = 10 * n + (m % 10);
        m /= 10;
    }
    m = 1;
    m <<= 31;
    m -= 1;
    if ( n > m ) {
        return 0;
    }
    if ( x > 0 ) {
        return n;
    } else {
        return -n;
    }
}
