/*
 Copyright (C) 2013  Peter Lotts

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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