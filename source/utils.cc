#include "utils.hh"

void assertf(bool condition, const char *format, ...)
{
#ifndef RELEASE
	if (!condition) {
		char output[512];
		va_list args;
		va_start(args, format);
		vsnprintf(output, 512, format, args);
		va_end(args);
		std::string outputStr = output;
		outputStr += '\n';
		throw std::runtime_error(outputStr);
	}
#endif
}

void debug(const char *format, ...)
{
#ifndef RELEASE
	char output[512];
	va_list args;
	va_start(args, format);
	vsnprintf(output, 512, format, args);
	va_end(args);

	std::ofstream debug_fstr;
	debug_fstr.open("debug.txt");
	debug_fstr << output << std::endl;
	debug_fstr.close();
#endif
}

