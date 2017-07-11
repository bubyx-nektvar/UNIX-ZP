#ifndef FILE_STRUCTURE_H_
#define FILE_STRUCTURE_H_
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include "core/diff/ChunkType.h"

template<typename T> class FileStructure;

#include "File.h"
#include "core/base.h"
#include "core/diff/ILogger.h"
#include "core/diff/ChangeLogger.h"
#include "core/diff/VersionChange.h"
#include "core/diff/TemporarySubsequenceData.h"

using namespace std;
typedef unique_ptr<vector<TemporarySubsequenceData>> temporary_data_unique_ptr;
typedef vector<TemporarySubsequenceData> temporary_data;

template<typename T>
class FileStructure : public myfs::File
{
public:
	FileStructure(std::string fileName):chunks_length(0),File(fileName) { }
	//najde index v souboru ktery ma stejny obsah jako paramtert line, nalezeny index je vetsi nez searchStartIndex
	//pokud nenajde tak vrati null
	shared_ptr<list<int>> GetIndexes(T readedChunk) {
		auto it = chunk_to_line_index.find(readedChunk);
		if (it == chunk_to_line_index.end())return nullptr;
		else return it->second;
		//return chunk_to_line_index[readedChunk];
	}
	std::unique_ptr<ILogger> GetLogger()override {
		return std::make_unique<ChangeLogger<T>>();
	}
	void AppednChunk(T& chunk) {
		chunks.push_back(chunk);
		shared_ptr<list<int>> x=chunk_to_line_index[chunk];
		if (x == nullptr) {
			x = make_shared<list<int>>();
			chunk_to_line_index[chunk] = x;
		}
		x->push_back(chunks_length++);
		
	}
	Index LastChunk()
	{
		return chunks.size() - 1;
	}
	void RemoveWithLog(ChangeLogger<T>& logger, Index i)
	{
		shared_ptr<list<int>> x = chunk_to_line_index.at(chunks[i]);
		x->remove(i);
		moveIndex(i, -1);
		chunks.erase(chunks.begin()+i);
		logger.LogRemoveChunk(i);
	}
	void AddLogged(ChangeLogger<T>& logger, T chunk, Index index) {
		moveIndex(index, 1);
		chunks.insert(chunks.begin()+index, chunk);
		chunks_length = chunks.size();
		logger.LogAdd(chunk, index);
	}
	//nascte strukturu z log fileu
	virtual void LoadFromLog(path logFile,Version v) override{
		std::cout << ">>Loading " << logFile;
		auto ch = readFileChunks(logFile);
		for (auto it = ch->begin(); it != ch->end(); ++it) {
			chunks.push_back(*it);
		}
		recalculate_map();
		std::cout << "...Loaded" << std::endl;
	}
	virtual void Init(PathContext& paths) override{
		auto ch=std::move(readFileChunks(pathToOriginFile));
		chunks.clear();
		Index position = 0;
		for (auto it = ch->begin(); it != ch->end(); ++it,++position) {
			chunks.push_back(*it);
		}
		log_init(targets,fromRoot);
		recalculate_map();
		if (targets->begin() != targets->end()) {
			recompute_hash(*targets->begin(), fromRoot);
		}
	}
	//targetFolder - cilove slozky
	//pathToCurrentFolder - cesta v teto strukture k tomuto souboru, od zdrojove slozky 
	//rootPath - cesta ke koreni struktury (to co bylo pridano ke kontrole)
	unique_ptr<vector<T>> readFileChunks(path file) {
		std::unique_ptr<std::vector<T>> r = std::make_unique<vector<T>>();
		unix::FileStream fileReader = T::openFile(file.str());
		if (!fileReader.fail()) {
			while (!fileReader.eof()) {
				r->push_back(T::readChunk(fileReader));
			}
		}
		fileReader.close();
		return move(r);
	}
	virtual bool check_files_change(PathContext & paths) override {
		unique_ptr<vector<BaseNumberType>> latest_change_definition;
		path latest_change_file;
		unique_ptr<vector<T>> latest_change_chunks;
		Version continue_version=setting->GetActualVersion();
		//kontrola v originalnim souboru
		unique_ptr<vector<T>> chunks = move(readFileChunks(paths.pathToCurrentModifiedFile);
		auto change = move(this->GetReusableChunks(chunks));
		if (is_change(change.get())) {
			latest_change_definition = move(change);
			latest_change_file = paths.pathToRoot;
			latest_change_chunks = move(chunks);

		}

		if (!latest_change_file.empty()) {
			if (setting->GetActualVersion() != continue_version) //bylo vice diferenci
			{
				setting->CreateNewVersion(continue_version);
			}
			Update(latest_change_chunks.get(), latest_change_definition.get(), paths.targetDirs, paths.pathFromRoot);
			used_path = latest_change_file;
			return true;
		}
		else {
			return false;
		}
	}
	//vrati vector kde na pozici i-teho radku je index radeku, ktery se reuseuje ze stare verze, nebo maximalni hodnota
	unique_ptr<vector<BaseNumberType>> GetReusableChunks(unique_ptr<vector<T>> & checked_file)
	{
		if (checked_file->size() > 0) {
			//hledani nejdelsi rostouci podposloupnosti
			BaseNumberType subsequence_length = 1;
			//[*,0]...delka podposloupnosti
			//[*,1]...pouzity index
			vector<temporary_data_unique_ptr> temporary(checked_file->size());

			//filling last column
			Index i = checked_file->size() - 1;
			temporary[i] = make_unique<temporary_data>();
			auto checked_file_last_line = GetIndexes((*checked_file)[i]);
			if (checked_file_last_line != nullptr) {
				for (auto cfit = checked_file_last_line->begin(); cfit != checked_file_last_line->end(); ++cfit)
				{
					temporary[i]->push_back(TemporarySubsequenceData(*cfit, i));
				}
			}

			while (i>0)
			{
				--i;
				temporary[i] = make_unique<temporary_data>();

				auto i_list = GetIndexes((*checked_file)[i]);
				if (i_list != nullptr) {
					for (auto i_value = i_list->begin(); i_value != i_list->end(); ++i_value)
					{
						auto tmp_data = TemporarySubsequenceData(*i_value, i);
						for (Index_u j = i + 1; j < checked_file->size(); ++j)
						{
							auto j_item = (*temporary[j]);
							for (Index_u j_i = 0; j_i < j_item.size(); ++j_i) {
								auto j_list_item = j_item[j_i];
								if (tmp_data.value < j_list_item.value &&tmp_data.length < j_list_item.length + 1)
								{
									tmp_data.length = j_list_item.length + 1;
									tmp_data.next_index = j;
									tmp_data.inside_next_index = j_i;
								}
							}
						}
						temporary[i]->push_back(tmp_data);
					}
				}
			}
			bool tmp_max_is_null=true;
			vector<TemporarySubsequenceData>::iterator tmp_max;
			for (auto it = temporary.begin(); it != temporary.end(); ++it) {
				if (it->get() != nullptr&&it->get()->size()>0)
				{
					tmp_max = it->get()->begin();
					tmp_max_is_null = false;
				}

			}
			for (auto it = temporary.begin(); it != temporary.end(); ++it)
			{
				for (auto in_it = it->get()->begin(); in_it != it->get()->end(); ++in_it)
				{
					if (in_it->length > tmp_max->length) {
						tmp_max = in_it;
						tmp_max_is_null = false;
					}
				}
			}
			unique_ptr<vector<Index>> result = make_unique<vector<Index>>(vector<Index>(temporary.size(), numeric_limits<Index>::max()));
			if (!tmp_max_is_null) {
				TemporarySubsequenceData act = (*tmp_max);
				while (act.length > 1) {
					(*result)[act.index] = act.value;
					act = (*temporary[act.next_index].get())[act.inside_next_index];
				}
				(*result)[act.index] = act.value;
			}
			return result;
		}
		else {
			return make_unique<vector<Index>>();
		}
	}
	//difference - je vector vracen metodou Differer.GetReusableChunks(...)
	//targets - jsou cilove slozky
	//pathFromRoot - je cesta ve strukture
	void Update( vector<T>* checked_file, vector<BaseNumberType>* differences,vector<path>* targets,path pathFromRoot) {
		ChangeLogger<T> logger;
		StartUpdate(logger,targets,pathFromRoot);
		RemoveNotReused(logger,differences);
		AddNew(logger, checked_file, differences);
		EndUpdate(logger);
	}
	void StartUpdate(ChangeLogger<T>& logger, vector<path>* targets, path pathFromRoot) {
		logger.Open(targets, pathFromRoot/file_name);
	}
	void EndUpdate(ChangeLogger<T>& logger) {
		logger.Close();
		recalculate_map();
	}
	void RemoveNotReused(ChangeLogger<T>& logger, vector<BaseNumberType>* differences) {
		auto last = this->LastChunk() + 1;
		for (Index i = differences->size()-1; i >= 0; --i)
		{
			if ((*differences)[i] != std::numeric_limits<BaseNumberType>::max())
			{
				for (auto x = last - 1; x >(*differences)[i]; --x)
				{
					this->RemoveWithLog(logger,x);
				}
				last = (*differences)[i];
			}
		}
		for (auto x = last - 1; x >= 0; --x)
		{
			this->RemoveWithLog(logger,x);
		}
	}
	void AddNew(ChangeLogger<T>& logger, vector<T>* checked_file,vector<BaseNumberType>* differences) {
		for (Index_u i = 0; i < differences->size(); ++i)
		{
			if ((*differences)[i] == numeric_limits<BaseNumberType>::max()) {
				this->AddLogged(logger,(*checked_file)[i], i);
			}
		}
	}
	virtual void Remove(std::vector<path>& targets, path fromRoot)  override{
		ChangeLogger<T> logger;
		logger.Open(&targets,fromRoot/path(file_name));
		logger.LogDelete();
		logger.Close();
		for_each(targets.begin(), targets.end(), [this, fromRoot](path x) {this->recompute_hash(x, fromRoot); });
	}
protected:
	virtual void WriteChunks(path file) override {
		unix::FileStream s = T::openFile(file.string(),unix::OpenMode::Trunc|unix::OpenMode::Out);
		Write(s);
		s.close();
	}
	virtual void log_init(std::vector<path>* targets,const path & fromRoot) override {
		ChangeLogger<T> logger;
		logger.Open(targets, fromRoot / path(file_name));
		logger.LogCreate();
		logger.LogVersion(0, setting->GetActualVersion());
		Index position = 0;
		for (auto it = chunks.begin(); it != chunks.end(); ++it, ++position) {
			logger.LogAdd(*it, position);
		}
		logger.Close();
	}
private:
	//vygeneruje soubor podle teto struktury
	void Write(unix::FileStream & output) {
		if (chunks.begin() != chunks.end()) {
			if (chunks.size() > 1) {
				for (auto it = chunks.begin(); it != chunks.end(); ++it) {
					it->Write(output,it==chunks.end()-1);
				}
			}
			else {
				chunks.begin()->Write(output, true);
			}
		}
	}
	void moveIndex(Index fromIndex, int byNumber) {
		for (auto it = chunk_to_line_index.begin(); it != chunk_to_line_index.end(); ++it) 
		{
			for (auto v_it = it->second->begin(); v_it != it->second->end();++v_it)
			{
				if ((*v_it) >= fromIndex) {
					(*v_it)+=byNumber;
				}
			}
		}
	}
	void load_version(unix::FileStream &f, Version new_version) {
		chunks.clear();
		std::vector<std::string> lines;
		
		std::string line=f.getline();
		while (line != nullptr)
		{
			lines.push_back(line);
		}

		std::unordered_set<Version> used_versions;
		used_versions.emplace(new_version);
		Version prev_version=new_version;

		std::size_t start_position;
		std::size_t del_position;
		bool del_found=false, start_found=false;
		for (auto it = lines.rbegin(); it != lines.rend();++it)
		{
			auto c1 = it->find(';');
			string p1 = it->substr(0, c1);
			if (p1 == "version") {
				auto c2 = it->find(';', c1+1);
				string p2 = it->substr(c1 + 1, c2 - (c1 + 1));
				string p3 = it->substr(c2 + 1);
				Version from_v,v;
				istringstream p2s(p2);
				p2s >> from_v;
				istringstream p3s(p3);
				p3s >> v;
				if (v == prev_version) {
					prev_version = from_v;
					used_versions.emplace(from_v);
				}

			}
			else if (p1 == "deleted") {
				del_found = true;
				del_position = lines.size() - (it - lines.rbegin()+1);
			}
			else if (p1 == "created") {
				start_found = true;
				start_position =lines.size()-(it -lines.rbegin()+1) ;
			}
		}
		bool use_version=false;
		if (start_found&&((!del_found)|| start_position > del_position)) {
			for (auto it = lines.begin() + start_position;it!=lines.end(); ++it) {
				auto c1 = it->find(';');
				string p1 = it->substr(0, c1);
				auto c2 = it->find(';', c1+1);
				string p2 = it->substr(c1+1, c2-(c1+1));
				string p3 = it->substr(c2+1);
				if (use_version) {
					if (p1 == "add") {
						long position;
						istringstream (p2)>> position;
						T chunk = T::parseChunk(p3);
						chunks.insert(chunks.begin()+position, chunk);
					}
					else if (p1 == "remove") {
						long position;
						istringstream(p2) >> position;
						chunks.erase(chunks.begin()+position);
					}
				}
				if (p1 == "version") {
					Version v;
					istringstream(p3) >> v;
					if (used_versions.find(v) != used_versions.end()) use_version = true;
					else use_version = false;
				}
			}
		}
		recalculate_map();
	}
	void recalculate_map() {
		chunk_to_line_index.clear();
		Index i = 0;
		for (auto it = chunks.begin(); it != chunks.end(); ++it,++i) {
			shared_ptr<list<int>> x = chunk_to_line_index[(*it)];
			if (x == nullptr) {
				x = std::make_shared<list<int>>();
				x->push_back(i);
				chunk_to_line_index[(*it)] = x;
			}
			else {
				x->push_back(i);
			}
		}
	}
	map<T, shared_ptr<list<int>>,typename T::Comparer> chunk_to_line_index;
	vector<T> chunks;
	size_t chunks_length;
};
#endif
