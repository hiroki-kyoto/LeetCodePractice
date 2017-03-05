/*************************
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**********************************/
int lengthOfLongestSubstring(char* s) {
    int a, b, i, k, m, is_repeat;
    char substr[256];
    char x;
    i = a = b = 0;
    if ( s[0] == 0 ) {
        return 0;
    } else {
        if ( s[1] == 0 ) {
            return 1;
        }
    }
    substr[b++] = s[i++];
    x = s[i++];
    while ( x ) {
        // check if repeats
        is_repeat = false;
        for ( k=0; k<b; k++ ) {
            if ( substr[(k+a)%256] == x ) { // repeats
                is_repeat = true;
                // store the last substring
                if ( b > m ) {
                    m = b;
                }
                a = (k + a + 1) % 256;
                b -= k;
                substr[(a+b-1)%256] = x;
                break;
            }
        }
        // if not repeat
        if ( !is_repeat ) {
            substr[(a+b)%256] = x;
            b++;
        }
        x = s[i++];
    }
    // check last substring
    if ( b > m ) {
        m = b;
    }
    return m;
}
