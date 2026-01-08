#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

namespace Console {
	inline const char* reset() { return "\033[0m"; }
	inline const char* red() { return "\033[31m"; }
	inline const char* green() { return "\033[32m"; }
	inline const char* yellow() { return "\033[33m"; }
	inline const char* blue() { return "\033[34m"; }
	inline const char* magenta() { return "\033[35m"; }
	inline const char* cyan() { return "\033[36m"; }

	inline bool useColor() {
		static int cached = -1;
		if (cached < 0) {
			cached = (std::getenv("NO_COLOR") == 0) ? 1 : 0;
		}
		return cached == 1;
	}

	inline const char* color(const char* code) {
		return useColor() ? code : "";
	}

	inline std::string leetify(const std::string& input) {
		std::string out;
		out.reserve(input.size());
		for (std::string::size_type i = 0; i < input.size(); ++i) {
			char c = input[i];
			switch (c) {
			case 'a':
			case 'A':
				out += '4';
				break;
			case 'e':
			case 'E':
				out += '3';
				break;
			case 'i':
			case 'I':
				out += '1';
				break;
			case 'o':
			case 'O':
				out += '0';
				break;
			case 's':
			case 'S':
				out += '5';
				break;
			case 't':
			case 'T':
				out += '7';
				break;
			case 'b':
			case 'B':
				out += '8';
				break;
			case 'g':
			case 'G':
				out += '9';
				break;
			default:
				out += c;
				break;
			}
		}
		return out;
	}

	inline void log(const char* tone, const std::string& tag, const std::string& msg, bool leet = true) {
		std::cout << color(tone) << "[" << tag << "] "
				  << (leet ? leetify(msg) : msg)
				  << color(reset()) << std::endl;
	}
}

#endif
