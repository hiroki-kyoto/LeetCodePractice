/**********
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
**********/

int is_palindrome( char * s, int a, int b ) {
    int i, c;
    c = (b-a)/2;
    for ( i=0; i<=c; i++ ) {
        if ( s[a+i]!=s[b-i] ) {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int n, m; // length, max length of palindromic substring
    int a, b, ma, mb; // a: begin and b: end
    n = 0;
    while(s[n]) {n++;}
    if (n==1) {
        return s;
    } else if (n==2) {
        if (s[0]==s[1]) {
            return s;
        } else {
            s[1] = 0;
            return s;
        }
    }
    // directly 
    m = 1;
    ma = mb = 0;
    for ( a=0; a<n; a++ ) {
        // find the palindromic substring with such begin index
        for ( b=n-1; b>=(a+m); b-- ) {
            if ( is_palindrome(s, a, b) ) {
                if ( b-a+1 > m ) {
                    ma = a;
                    mb = b;
                    m = b - a + 1;
                }
            }
        }
    }
    s[ma+m] = 0;
    return s + ma;
}
