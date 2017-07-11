#ifndef FS_FILE_H_
#define FS_FILE_H_
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include "unix/io/FileStream.h"

namespace myfs {
	class File;
}
#include "core/base.h"
#include "core/diff/ILogger.h"
#include "core/diff/VersionChange.h"
#include "core/fileStructure/PathContext.h"
using namespace std;
namespace myfs {
	class File
	{
	public:
		File(){}
		File(const File& that) = delete;
		File & operator=(const File&) = delete;
		//virtual void CreateVersion(VersionChange & ver, PathContext &paths) = 0;
		//nacte strukturu
		//vytvori log file s pridanim chunku
		//vytvori hash
		virtual void Init(PathContext& paths)= 0;
		//nascte strukturu z log fileu
        // logFile - plna cesta
		virtual void LoadFromLog(path logFile,Version v) = 0;
		virtual std::unique_ptr<ILogger> GetLogger() = 0;
	protected:
		// zpracuje zmeny v souboru
		// return - true pokud se nejaky soubor upravoval
		virtual bool check_files_change(PathContext & paths) = 0;

		bool is_change(vector<BaseNumberType>* change_description);
		void RewriteSVNFile(const PathContext& paths); 
        void RewriteCurrentFile(const PathContext& paths);
        void RewriteAll(const PathContext& paths);
		virtual void log_init(std::vector<path>* targets, const path & fromRoot) = 0;
		virtual void WriteChunks(path file) = 0;
	};
}
#endif

