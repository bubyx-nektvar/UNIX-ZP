##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UNIX-ZP
ConfigurationName      :=Debug
WorkspacePath          := "/home/bubyx/Documents/github/UNIX-ZP"
ProjectPath            := "/home/bubyx/Documents/github/UNIX-ZP"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=bubyx
Date                   :=11/07/17
CodeLitePath           :="/home/bubyx/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UNIX-ZP.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/core_Connection.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RunParamException.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ServerAdress.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/tests_Test.cpp$(ObjectSuffix) $(IntermediateDirectory)/diff_ChunkType.cpp$(ObjectSuffix) $(IntermediateDirectory)/diff_VersionChange.cpp$(ObjectSuffix) $(IntermediateDirectory)/diff_ChangeLogger.cpp$(ObjectSuffix) $(IntermediateDirectory)/fileStructure_FileInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/fileStructure_File.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_ClientMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_ModeBuilder.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_CheckoutMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_UpdateMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_ServerMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_CommitMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/mode_AddFileMode.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_path.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_ConnectionWrapper.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/io_IOException.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_DirectoryInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_StreamWrapper.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_FileStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_FileInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/io_FileSystem.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/core_Connection.cpp$(ObjectSuffix): src/core/Connection.cpp $(IntermediateDirectory)/core_Connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/Connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_Connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_Connection.cpp$(DependSuffix): src/core/Connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_Connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_Connection.cpp$(DependSuffix) -MM "src/core/Connection.cpp"

$(IntermediateDirectory)/core_Connection.cpp$(PreprocessSuffix): src/core/Connection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_Connection.cpp$(PreprocessSuffix) "src/core/Connection.cpp"

$(IntermediateDirectory)/core_RunParamException.cpp$(ObjectSuffix): src/core/RunParamException.cpp $(IntermediateDirectory)/core_RunParamException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/RunParamException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RunParamException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RunParamException.cpp$(DependSuffix): src/core/RunParamException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RunParamException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RunParamException.cpp$(DependSuffix) -MM "src/core/RunParamException.cpp"

$(IntermediateDirectory)/core_RunParamException.cpp$(PreprocessSuffix): src/core/RunParamException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RunParamException.cpp$(PreprocessSuffix) "src/core/RunParamException.cpp"

$(IntermediateDirectory)/core_ServerAdress.cpp$(ObjectSuffix): src/core/ServerAdress.cpp $(IntermediateDirectory)/core_ServerAdress.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/ServerAdress.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ServerAdress.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ServerAdress.cpp$(DependSuffix): src/core/ServerAdress.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ServerAdress.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ServerAdress.cpp$(DependSuffix) -MM "src/core/ServerAdress.cpp"

$(IntermediateDirectory)/core_ServerAdress.cpp$(PreprocessSuffix): src/core/ServerAdress.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ServerAdress.cpp$(PreprocessSuffix) "src/core/ServerAdress.cpp"

$(IntermediateDirectory)/core_main.cpp$(ObjectSuffix): src/core/main.cpp $(IntermediateDirectory)/core_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_main.cpp$(DependSuffix): src/core/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_main.cpp$(DependSuffix) -MM "src/core/main.cpp"

$(IntermediateDirectory)/core_main.cpp$(PreprocessSuffix): src/core/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_main.cpp$(PreprocessSuffix) "src/core/main.cpp"

$(IntermediateDirectory)/tests_Test.cpp$(ObjectSuffix): src/tests/Test.cpp $(IntermediateDirectory)/tests_Test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/tests/Test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tests_Test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tests_Test.cpp$(DependSuffix): src/tests/Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tests_Test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tests_Test.cpp$(DependSuffix) -MM "src/tests/Test.cpp"

$(IntermediateDirectory)/tests_Test.cpp$(PreprocessSuffix): src/tests/Test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tests_Test.cpp$(PreprocessSuffix) "src/tests/Test.cpp"

$(IntermediateDirectory)/diff_ChunkType.cpp$(ObjectSuffix): src/core/diff/ChunkType.cpp $(IntermediateDirectory)/diff_ChunkType.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/diff/ChunkType.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/diff_ChunkType.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/diff_ChunkType.cpp$(DependSuffix): src/core/diff/ChunkType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/diff_ChunkType.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/diff_ChunkType.cpp$(DependSuffix) -MM "src/core/diff/ChunkType.cpp"

$(IntermediateDirectory)/diff_ChunkType.cpp$(PreprocessSuffix): src/core/diff/ChunkType.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/diff_ChunkType.cpp$(PreprocessSuffix) "src/core/diff/ChunkType.cpp"

$(IntermediateDirectory)/diff_VersionChange.cpp$(ObjectSuffix): src/core/diff/VersionChange.cpp $(IntermediateDirectory)/diff_VersionChange.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/diff/VersionChange.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/diff_VersionChange.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/diff_VersionChange.cpp$(DependSuffix): src/core/diff/VersionChange.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/diff_VersionChange.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/diff_VersionChange.cpp$(DependSuffix) -MM "src/core/diff/VersionChange.cpp"

$(IntermediateDirectory)/diff_VersionChange.cpp$(PreprocessSuffix): src/core/diff/VersionChange.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/diff_VersionChange.cpp$(PreprocessSuffix) "src/core/diff/VersionChange.cpp"

$(IntermediateDirectory)/diff_ChangeLogger.cpp$(ObjectSuffix): src/core/diff/ChangeLogger.cpp $(IntermediateDirectory)/diff_ChangeLogger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/diff/ChangeLogger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/diff_ChangeLogger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/diff_ChangeLogger.cpp$(DependSuffix): src/core/diff/ChangeLogger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/diff_ChangeLogger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/diff_ChangeLogger.cpp$(DependSuffix) -MM "src/core/diff/ChangeLogger.cpp"

$(IntermediateDirectory)/diff_ChangeLogger.cpp$(PreprocessSuffix): src/core/diff/ChangeLogger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/diff_ChangeLogger.cpp$(PreprocessSuffix) "src/core/diff/ChangeLogger.cpp"

$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(ObjectSuffix): src/core/fileStructure/FileInfo.cpp $(IntermediateDirectory)/fileStructure_FileInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/fileStructure/FileInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(DependSuffix): src/core/fileStructure/FileInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(DependSuffix) -MM "src/core/fileStructure/FileInfo.cpp"

$(IntermediateDirectory)/fileStructure_FileInfo.cpp$(PreprocessSuffix): src/core/fileStructure/FileInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fileStructure_FileInfo.cpp$(PreprocessSuffix) "src/core/fileStructure/FileInfo.cpp"

$(IntermediateDirectory)/fileStructure_File.cpp$(ObjectSuffix): src/core/fileStructure/File.cpp $(IntermediateDirectory)/fileStructure_File.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/fileStructure/File.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fileStructure_File.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fileStructure_File.cpp$(DependSuffix): src/core/fileStructure/File.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fileStructure_File.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fileStructure_File.cpp$(DependSuffix) -MM "src/core/fileStructure/File.cpp"

$(IntermediateDirectory)/fileStructure_File.cpp$(PreprocessSuffix): src/core/fileStructure/File.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fileStructure_File.cpp$(PreprocessSuffix) "src/core/fileStructure/File.cpp"

$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(ObjectSuffix): src/core/fileStructure/FilesStructure.cpp $(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/fileStructure/FilesStructure.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(DependSuffix): src/core/fileStructure/FilesStructure.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(DependSuffix) -MM "src/core/fileStructure/FilesStructure.cpp"

$(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(PreprocessSuffix): src/core/fileStructure/FilesStructure.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fileStructure_FilesStructure.cpp$(PreprocessSuffix) "src/core/fileStructure/FilesStructure.cpp"

$(IntermediateDirectory)/mode_ClientMode.cpp$(ObjectSuffix): src/core/mode/ClientMode.cpp $(IntermediateDirectory)/mode_ClientMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/ClientMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_ClientMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_ClientMode.cpp$(DependSuffix): src/core/mode/ClientMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_ClientMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_ClientMode.cpp$(DependSuffix) -MM "src/core/mode/ClientMode.cpp"

$(IntermediateDirectory)/mode_ClientMode.cpp$(PreprocessSuffix): src/core/mode/ClientMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_ClientMode.cpp$(PreprocessSuffix) "src/core/mode/ClientMode.cpp"

$(IntermediateDirectory)/mode_ModeBuilder.cpp$(ObjectSuffix): src/core/mode/ModeBuilder.cpp $(IntermediateDirectory)/mode_ModeBuilder.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/ModeBuilder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_ModeBuilder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_ModeBuilder.cpp$(DependSuffix): src/core/mode/ModeBuilder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_ModeBuilder.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_ModeBuilder.cpp$(DependSuffix) -MM "src/core/mode/ModeBuilder.cpp"

$(IntermediateDirectory)/mode_ModeBuilder.cpp$(PreprocessSuffix): src/core/mode/ModeBuilder.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_ModeBuilder.cpp$(PreprocessSuffix) "src/core/mode/ModeBuilder.cpp"

$(IntermediateDirectory)/mode_CheckoutMode.cpp$(ObjectSuffix): src/core/mode/CheckoutMode.cpp $(IntermediateDirectory)/mode_CheckoutMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/CheckoutMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_CheckoutMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_CheckoutMode.cpp$(DependSuffix): src/core/mode/CheckoutMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_CheckoutMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_CheckoutMode.cpp$(DependSuffix) -MM "src/core/mode/CheckoutMode.cpp"

$(IntermediateDirectory)/mode_CheckoutMode.cpp$(PreprocessSuffix): src/core/mode/CheckoutMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_CheckoutMode.cpp$(PreprocessSuffix) "src/core/mode/CheckoutMode.cpp"

$(IntermediateDirectory)/mode_UpdateMode.cpp$(ObjectSuffix): src/core/mode/UpdateMode.cpp $(IntermediateDirectory)/mode_UpdateMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/UpdateMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_UpdateMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_UpdateMode.cpp$(DependSuffix): src/core/mode/UpdateMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_UpdateMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_UpdateMode.cpp$(DependSuffix) -MM "src/core/mode/UpdateMode.cpp"

$(IntermediateDirectory)/mode_UpdateMode.cpp$(PreprocessSuffix): src/core/mode/UpdateMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_UpdateMode.cpp$(PreprocessSuffix) "src/core/mode/UpdateMode.cpp"

$(IntermediateDirectory)/mode_ServerMode.cpp$(ObjectSuffix): src/core/mode/ServerMode.cpp $(IntermediateDirectory)/mode_ServerMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/ServerMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_ServerMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_ServerMode.cpp$(DependSuffix): src/core/mode/ServerMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_ServerMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_ServerMode.cpp$(DependSuffix) -MM "src/core/mode/ServerMode.cpp"

$(IntermediateDirectory)/mode_ServerMode.cpp$(PreprocessSuffix): src/core/mode/ServerMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_ServerMode.cpp$(PreprocessSuffix) "src/core/mode/ServerMode.cpp"

$(IntermediateDirectory)/mode_CommitMode.cpp$(ObjectSuffix): src/core/mode/CommitMode.cpp $(IntermediateDirectory)/mode_CommitMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/CommitMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_CommitMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_CommitMode.cpp$(DependSuffix): src/core/mode/CommitMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_CommitMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_CommitMode.cpp$(DependSuffix) -MM "src/core/mode/CommitMode.cpp"

$(IntermediateDirectory)/mode_CommitMode.cpp$(PreprocessSuffix): src/core/mode/CommitMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_CommitMode.cpp$(PreprocessSuffix) "src/core/mode/CommitMode.cpp"

$(IntermediateDirectory)/mode_AddFileMode.cpp$(ObjectSuffix): src/core/mode/AddFileMode.cpp $(IntermediateDirectory)/mode_AddFileMode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/core/mode/AddFileMode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mode_AddFileMode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mode_AddFileMode.cpp$(DependSuffix): src/core/mode/AddFileMode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mode_AddFileMode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mode_AddFileMode.cpp$(DependSuffix) -MM "src/core/mode/AddFileMode.cpp"

$(IntermediateDirectory)/mode_AddFileMode.cpp$(PreprocessSuffix): src/core/mode/AddFileMode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mode_AddFileMode.cpp$(PreprocessSuffix) "src/core/mode/AddFileMode.cpp"

$(IntermediateDirectory)/io_path.cpp$(ObjectSuffix): src/unix/io/path.cpp $(IntermediateDirectory)/io_path.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/path.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_path.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_path.cpp$(DependSuffix): src/unix/io/path.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_path.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_path.cpp$(DependSuffix) -MM "src/unix/io/path.cpp"

$(IntermediateDirectory)/io_path.cpp$(PreprocessSuffix): src/unix/io/path.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_path.cpp$(PreprocessSuffix) "src/unix/io/path.cpp"

$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(ObjectSuffix): src/unix/io/ConnectionWrapper.cpp $(IntermediateDirectory)/io_ConnectionWrapper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/ConnectionWrapper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(DependSuffix): src/unix/io/ConnectionWrapper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(DependSuffix) -MM "src/unix/io/ConnectionWrapper.cpp"

$(IntermediateDirectory)/io_ConnectionWrapper.cpp$(PreprocessSuffix): src/unix/io/ConnectionWrapper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_ConnectionWrapper.cpp$(PreprocessSuffix) "src/unix/io/ConnectionWrapper.cpp"

$(IntermediateDirectory)/io_IOException.cpp$(ObjectSuffix): src/unix/io/IOException.cpp $(IntermediateDirectory)/io_IOException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/IOException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_IOException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_IOException.cpp$(DependSuffix): src/unix/io/IOException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_IOException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_IOException.cpp$(DependSuffix) -MM "src/unix/io/IOException.cpp"

$(IntermediateDirectory)/io_IOException.cpp$(PreprocessSuffix): src/unix/io/IOException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_IOException.cpp$(PreprocessSuffix) "src/unix/io/IOException.cpp"

$(IntermediateDirectory)/io_DirectoryInfo.cpp$(ObjectSuffix): src/unix/io/DirectoryInfo.cpp $(IntermediateDirectory)/io_DirectoryInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/DirectoryInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_DirectoryInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_DirectoryInfo.cpp$(DependSuffix): src/unix/io/DirectoryInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_DirectoryInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_DirectoryInfo.cpp$(DependSuffix) -MM "src/unix/io/DirectoryInfo.cpp"

$(IntermediateDirectory)/io_DirectoryInfo.cpp$(PreprocessSuffix): src/unix/io/DirectoryInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_DirectoryInfo.cpp$(PreprocessSuffix) "src/unix/io/DirectoryInfo.cpp"

$(IntermediateDirectory)/io_StreamWrapper.cpp$(ObjectSuffix): src/unix/io/StreamWrapper.cpp $(IntermediateDirectory)/io_StreamWrapper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/StreamWrapper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_StreamWrapper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_StreamWrapper.cpp$(DependSuffix): src/unix/io/StreamWrapper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_StreamWrapper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_StreamWrapper.cpp$(DependSuffix) -MM "src/unix/io/StreamWrapper.cpp"

$(IntermediateDirectory)/io_StreamWrapper.cpp$(PreprocessSuffix): src/unix/io/StreamWrapper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_StreamWrapper.cpp$(PreprocessSuffix) "src/unix/io/StreamWrapper.cpp"

$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(ObjectSuffix): src/unix/io/AddressInfoWrapper.cpp $(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/AddressInfoWrapper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(DependSuffix): src/unix/io/AddressInfoWrapper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(DependSuffix) -MM "src/unix/io/AddressInfoWrapper.cpp"

$(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(PreprocessSuffix): src/unix/io/AddressInfoWrapper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_AddressInfoWrapper.cpp$(PreprocessSuffix) "src/unix/io/AddressInfoWrapper.cpp"

$(IntermediateDirectory)/io_FileStream.cpp$(ObjectSuffix): src/unix/io/FileStream.cpp $(IntermediateDirectory)/io_FileStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/FileStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_FileStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_FileStream.cpp$(DependSuffix): src/unix/io/FileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_FileStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_FileStream.cpp$(DependSuffix) -MM "src/unix/io/FileStream.cpp"

$(IntermediateDirectory)/io_FileStream.cpp$(PreprocessSuffix): src/unix/io/FileStream.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_FileStream.cpp$(PreprocessSuffix) "src/unix/io/FileStream.cpp"

$(IntermediateDirectory)/io_FileInfo.cpp$(ObjectSuffix): src/unix/io/FileInfo.cpp $(IntermediateDirectory)/io_FileInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/FileInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_FileInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_FileInfo.cpp$(DependSuffix): src/unix/io/FileInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_FileInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_FileInfo.cpp$(DependSuffix) -MM "src/unix/io/FileInfo.cpp"

$(IntermediateDirectory)/io_FileInfo.cpp$(PreprocessSuffix): src/unix/io/FileInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_FileInfo.cpp$(PreprocessSuffix) "src/unix/io/FileInfo.cpp"

$(IntermediateDirectory)/io_FileSystem.cpp$(ObjectSuffix): src/unix/io/FileSystem.cpp $(IntermediateDirectory)/io_FileSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bubyx/Documents/github/UNIX-ZP/src/unix/io/FileSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_FileSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_FileSystem.cpp$(DependSuffix): src/unix/io/FileSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_FileSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/io_FileSystem.cpp$(DependSuffix) -MM "src/unix/io/FileSystem.cpp"

$(IntermediateDirectory)/io_FileSystem.cpp$(PreprocessSuffix): src/unix/io/FileSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_FileSystem.cpp$(PreprocessSuffix) "src/unix/io/FileSystem.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


