#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdexcept>
#include <cstdarg>
#include <ofstream>

void assertf(bool condition, const char *format, ...);
void debug(const char *format, ...);

#endif

