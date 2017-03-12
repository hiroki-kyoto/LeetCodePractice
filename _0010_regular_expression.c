/************************
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
************************/

bool isMatch(char* s, char* p) {
    int * si, * sk, * sc; // i, k, counter
    char * sf, * se; // delayed flag and element
    int i, k, n, ns, ik[2], ef[2]; // begin and end
    bool f;
    char c;
    
    // parse exp str:
    n = 0;
    while ( p[n] ) {
        ++n;
    }
    ++n; // the end char '\0'
    
    ns = 0;
    while ( s[ns] ) {
    	++ns;
    }
    ++ns; // the end char '\0'
    
    si = (int*)malloc(sizeof(int)*n);
    sk = (int*)malloc(sizeof(int)*n);
    sf = (char*)malloc(sizeof(char)*n);
    se = (char*)malloc(sizeof(char)*n);
    
    ik[0] = 0; // front
    ik[1] = 0; // tail
    ef[0] = 0; // front
    ef[1] = 0; // tail
    n = 0;
    f = false;
    while ( p[n] ) {
        if ( !f ) {
            c = p[n];
            ++n;
            f = true;
        } else {
            if ( p[n] == '*' ) {
                se[ef[1]] = c; // element to match
                sf[ef[1]] = 1; // delayed
                ef[1]++;
                ++n;
                f = false;
            } else {
                se[ef[1]] = c; // element to match
                sf[ef[1]] = 0; // no delay
                ef[1]++;
                c = p[n];
                ++n;
            }
        }
    }
    
    if ( f ) {
        se[ef[1]] = c; // element to match
        sf[ef[1]] = 0; // no delay
        ef[1]++;
    }

    // add end match
    se[ef[1]] = '\0'; // end element to match
    sf[ef[1]] = 0; // no delay
    ef[1]++;

    // begin match
    i = k = 0;
	f = 1;
    while ( k<ef[1] || i<ns ) { // when regexp and str is both scaned completely
        if ( sf[k] ) { // if has delay
            // push this state
            si[ik[1]] = i;
            sk[ik[1]] = k;
            ++ik[1];
            ++k; 
        } else { // if no delay, match immediately
            if ( ( se[k] == '.' && s[i]!=0 ) || se[k] == s[i] ) {
                ++k;
                ++i;
            } else { // when not matched
                // check if reach end
                if ( ik[0] == ik[1] ) { // empty stack to regret steps
			f = 0;
			break;
                } else {
                    // regret
		            if ( ( se[sk[ik[1]-1]] == '.' && s[si[ik[1]-1]] != 0 ) || 
                        se[sk[ik[1]-1]] == s[si[ik[1]-1]] ) {
		                i = si[ik[1]-1]; // pop out
		                k = sk[ik[1]-1]; // pop out
		                si[ik[1]-1]++; // modify
		                ++i; // move to next
		                ++k; // move to next match operator
		            } else { // not matched, means this delay is used up	            	
		            	--ik[1]; // pop out and try next
		            }
                }
            }
        }
    }
    
	// memory cleaning job
	free(si);
	free(sk);
	free(sf);
	free(se);
	
    return f;
}
