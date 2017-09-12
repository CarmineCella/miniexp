// miniexp.cpp

#include "miniexp.h"

namespace miniexp {
    // search for regexp at beginning of text
    bool match_here (char* regexp, char* text) {
        if (regexp[0] == '\0') return true;
        if (regexp[1] == '*') return match_star (regexp[0], regexp + 2, text);
        if (regexp[0] == '$' && regexp[1] == '\0') return *text == '\0';
        if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) {
            return match_here (regexp + 1, text + 1);
        }
        return false;
    }
    // leftmost longest search for c*regexp */
    int match_star (int c, char *regexp, char *text) {
        char *t;

        for (t = text; *t != '\0' && (*t == c || c == '.'); t++)
            ;
        do {    /* * matches zero or more */
            if (match_here(regexp, t)) return true;
        } while (t-- > text);
        return false;
    }
    // search for regexp anywhere in text
    bool match (char* regexp, char* text) {
        if (regexp[0] == '^')
            return match_here (regexp + 1, text);
        do {
            if (match_here (regexp, text)) return true;
        } while (*text++ != '\0');
        return false;
    }
}

// EOF
