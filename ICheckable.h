#ifndef I_CHECKABLE_H_
#define I_CHECKABLE_H_
#include <vector>
#include <filesystem>
namespace fs = std::experimental::filesystem;
class ICheckable {
public:
	//zkontroluje pripadne zpracuje zmeny a aktualizuje dany element
	//targetDirs - koreny cilovych slozek
	//pathToCurrentDir - cesta do slozky v niz je slozka korespondujici teto instanci
	virtual void Check(const std::vector<fs::path> &targetDirs, fs::path pathToCurrentDir)=0;
};
#endif
