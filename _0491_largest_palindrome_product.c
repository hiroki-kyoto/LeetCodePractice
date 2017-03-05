/**********************
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
***************************/
// extend power function
unsigned long long power_llu( int x, int y ) {
    unsigned long long p = 1;
    while( y>0 ) {
        p *= x;
        y--;
    } 
    return p;
}

// reverse a number
unsigned long long reverse( unsigned long long x ) {
    int d[256];
    int i, n;
    unsigned long long y;
    unsigned long long x1;
    x1 = x;
    n = 0;
    while ( x1/10 ) {
        y = x1;
        x1 /= 10;
        d[n++] = y - 10*x1;
    }
    d[n++] = x1;
    y = 0;
    for ( i=0; i<n; i++ ) {
        y = 10 * y + d[i];
    }
    y += power_llu(10, n)*x;
    return y;
}

unsigned long long largestPalindrome(int n) {
    unsigned long long mx = power_llu(10, n) - 1;
    unsigned long long mn = power_llu(10, n-1);
    unsigned long long mxp = mx * mx;
    unsigned long long mnp = mn * mn;
    unsigned long long div = power_llu(10, n);
    unsigned long long lf = mxp/div;
    unsigned long long rt = mnp%div;
    unsigned long long p = mxp;
    unsigned long long a, b, c;
    if( n==1 ) {
        return 9;
    }
    if ( lf == rt ) {
        return mxp%1337;
    }
    if ( lf > rt ) {
        --lf;
    }
    p = reverse(lf);
    
    while ( p>=mnp ) {
        // check if this number is a production of two n-digit number
        a=p/mn;
        c = p/mx;
        if ( a>mx ) {
            a = mx;
        }
        if ( c<mn ) {
            c = mn;
        }
        for ( ; a>=c; --a ) {
            b = p/a;
            if ( b*a == p ) {
                return p%1337;
            }
            if ( b > a ) {
                break;
            }
        }
        // try next
        --lf;
        p = reverse(lf);
    }
    return -1;
}
