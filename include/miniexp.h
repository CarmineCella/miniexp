#ifndef MINIEXP_H
#define MINIEXP_H

#include <string>

namespace miniexp {
	bool match (char* regexp, char* text);
	bool match_star (int c, char* regexp, char* text);
	bool match (char* regexp, char* text);
}

#endif // MINIEXP_H