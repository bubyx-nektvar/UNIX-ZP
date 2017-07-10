#include "path.h"

path::path(std::string path) {
	auto it = path.begin();
	auto sb = std::stringbuf();

	while (it != path.end()) {
		if (*it == PathSplitter) {
			parts.push_back(sb.str());
			sb = std::stringbuf();
		}
		else sb.sputbackc(*it);
	}
	auto x = sb.str();
	if (x.size() > 0)parts.push_back(x);
}

std::string path::str() const{
	auto ss = std::stringstream();
	for (auto it = parts.begin(); it != parts.end(); it++) {
		if (it != parts.begin())
			ss << PathSplitter;
		ss << *it;
	}
	return ss.str();
}