// utils.h

#pragma once
#ifndef BUILD_LIBUTILS
#pragma comment(lib, "Utils/bin/libutils.lib")
#endif

#include <string>
#include <vector>
#include <fstream>

namespace utils
{
	bool	FileExists(std::string strFilename);
	bool	PathExists(std::string pathtocheck);
	void	mkdir(std::string path, int mode);
	void	sleep(int milliseconds);
	std::string exec(std::string command);
	void	err(int returnvalue);
	void	ifnoexistmake(std::string dir, bool recursive=false);
	int		linecount(std::string filename, std::string name="the");
	int		GetIntVal(std::string strConvert);
	
	template <typename T>	std::string	int_to_hex( T i/*, bool pre_def_len */);
	template <class any>	void		readvector(std::string filename,std::vector<any> *vectname);
							void		readvectorspace(std::string filename,std::vector<std::string> *vectname);
	template <typename T>	void		PrintVector(std::ostream& ostr, const std::vector<T>& t, const std::string& delimiter);

	extern std::fstream stream;
}