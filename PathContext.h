#ifndef PATH_CONTEXT_H_
#define PATH_CONTEXT_H_
#include <vector>
class PathContext {
public:
	std::vector<fs::path>* targetDirs;
	path pathToRoot;
	path pathFromRoot;
	PathContext(const PathContext & p, fs::path fromRoot) :pathFromRoot(fromRoot),pathToRoot(p.pathToRoot)
	{
		targetDirs = p.targetDirs;
	}
	PathContext(std::vector<fs::path>* targets, fs::path toRoot, fs::path fromRoot)
		:pathFromRoot(fromRoot),pathToRoot(toRoot)
	{
		targetDirs = targets;
	}
};
#endif
