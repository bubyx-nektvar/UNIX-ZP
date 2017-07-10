#ifndef PATH_H_
#define PATH_H_
#include <string>
#include <sstream>
#include <vector>

#define PathSplitter '/'

class path
{
private:
	std::vector<std::string> parts;
	void appendPart(std::string x) {
		this->parts.push_back(x);
	}
public:
	path(std::string path);
	path(const std::vector<std::string> parts) :parts(parts) {

	}
	path(const path* x, const path* y):parts(x->parts) {
		for (auto it = y->parts.begin(); it != y->parts.end(); ++it) {
			this->parts.push_back(*it);
		}
	}
	~path();
	std::string str() const;
	const char* c_str() const
	{
		return str().c_str();
	}
	path operator/ (path other) const{
		return path(this,&other);
	}
	path operator/ (std::string value) const{
		return operator/(path(value));
	}
	bool isRelative() {
		return parts[0] == "";
	}
	bool isAbsolute() {
		return !isRelative();
	}
	path parent() const
	{
		std::vector<std::string> p;
		for(int i =0;i<parts.size()-1;++i)
		{
			p.push_back(parts[i]);
		}
		return path(p);
	}
};



#endif // !PATH_H_
