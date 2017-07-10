#include "path.h"
#include <algorithm>

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

path path::removePrefix(path& removedPart)
{
    for(int i =0;i < removedPart.parts.size();++i)
    {
        if(removedPart[i]!=parts[i]){
            //TODO fail
            throw ArgumentException();
        }
    }
    return subpath(removedPart.size());
}

int path::indexOfLastPart(std::string partText)
{
    for(int i = parts.size()-1;i>= 0;++i){
        if(parts[i]==partText) return i;
    }
    return -1;
}

path path::subpath(int i)
{
    std::vector<std::string> np(parts.size()-i);
    std::copy(parts.begin()+i,parts.end(),np.begin());
    return path(np);
}

std::string path::getEnding()
{
    auto i = parts[parts.size()-1].find_last_of('.');
    if(i<=0) return "";
    return parts[parts.size()-1].substr(i);
}
