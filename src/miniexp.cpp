// miniexp.cpp

#include "miniexp.h"

namespace miniexp {
    // search for regexp at beginning of text
    bool match_here (char* regexp, char* text) {
        if (regexp[0] == '\0') return true;
        if (regexp[1] == '*') return match_star (regexp[0], regexp + 2, text);
        if (regexp[0] == '$' && regexp[1] == '\0') return *text == '\0';
        if (*text!='\0' && (regexp[0] =='.' || regexp[0] == *text)) {
            return match_here (regexp + 1, text + 1);
        }
        return false;
    }
    // search for c*regexp at beginning of text
    bool match_star (int c, char* regexp, char* text) {
        do {
            if (match_here (regexp, text)) return true;
        } while (*text != '\0' && (*text++ == c || c == '.'));
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
