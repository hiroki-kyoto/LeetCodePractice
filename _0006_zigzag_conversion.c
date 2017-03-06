/*****************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
******************/
char* convert(char* s, int numRows) {
    int i, m, n, d, irow; // n is length of total, d is direction flag
    char * t;
    int * c;
    if ( numRows == 1 ) {
        return s;
    }
    n = 0;
    while ( s[n] ) {n++;}
    t = (char*)malloc(sizeof(char) * (n+1)); // returned string
    t[n] = 0;
    c = (int*)malloc(sizeof(int)*n); // indexes of line
    irow = 0;
    d = 1; // positive direction: from upside to downside
    d = -1; // negative direction: from downside to upside
    for ( i=0; i<n; i++ ) {
        c[i] = irow;
        if ( irow == (numRows-1) ) {
            d = -1;
        } else if ( irow == 0 ) {
            d = 1;
        }
        irow += d;
    }
    // now try to write to output string
    m = 0;
    for ( d=0; d<numRows; d++ ) {
        for ( i=0; i<n; i++ ) {
            if ( c[i] == d ) { 
                t[m] = s[i];
                m++;
            }
        }
    }
    return t;
}

