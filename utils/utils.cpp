// This is the main Library file.
#define BUILD_LIBUTILS
#include "utils.h"

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdlib.h>

 std::fstream utils::stream;

// Requires: sys/stat.h, string
bool utils::FileExists(std::string strFilename)
{
	struct stat stFileInfo;
	bool blnReturn;
	int intStat;
	
	// Attempt to get the file attributes
	intStat = stat(strFilename.c_str(),&stFileInfo);
	if(intStat == 0)
	{
		// We were able to get the file attributes
		// so the file obviously exists.
		blnReturn = true;
	}
	else
	{
		// We were not able to get the file attributes.
		// This may mean that we don't have permission to
		// access the folder which contains this file. If you
		// need to do that level of checking, lookup the
		// return values of stat which will give you
		// more details on why stat failed.
		blnReturn = false;
	}
	return(blnReturn);
}

//Depends: utils::mysleep
void utils::err(int returnvalue)
{
	sleep(20000);
	exit(returnvalue);
}

// Depends: PathExists, mymkdir
// Requires: string
// Can use '/' or '\' for directories - must end in one or the other
void utils::ifnoexistmake(std::string dir, bool recursive)
{
	if (recursive)
	{
		size_t offset=0, forward, back;
		while (offset != dir.length())
		{
			forward=dir.find_first_of('/',offset);
			back=dir.find_first_of('\\',offset);
			if ((forward == std::string::npos) && (back == std::string::npos)) { break; }
			if (forward < back)
			{
				ifnoexistmake(dir.substr(0,forward));
				offset=forward+1;
			}
			else
			{
				ifnoexistmake(dir.substr(0,back));
				offset=back+1;
			}
		}
	}
	else
	{
		if ( PathExists(dir) == false)
		{
			mkdir(dir,0777);
		}
	}
}

// Depends: err
// Requires: string, fstream, iostream
int utils::linecount(std::string filename, std::string name)
{
	int rows=0;
	std::string line;
	// Open file:
	stream.open(filename.c_str(),std::ios::in);
	// Test for faliure:
	if (stream.fail())
	{
		std::cout << "Could not open " << name << " file!!!" << std::endl;
		err(5);
	}
	else
	{
		// Count lines:
		while ( getline(stream,line))
		{
			rows++;
		}
	}
	stream.close();
	return rows;
}

// Requires: fstream, string, vector
void utils::readvectorspace(std::string filename,std::vector<std::string> *vectname)
	{
		stream.open(filename.c_str(),std::ios::in);
		int num=0; 
		std::string tmp;
		while (getline(stream,tmp))
			{
				vectname->push_back(tmp);
				num++;
			}
		stream.close();
	}

// Requires: fstream, string, vector
template <class any>
void utils::readvector(std::string filename,std::vector<any> *vectname)
	{
		stream.open(filename.c_str(),std::ios::in);
		int num=0; 
		any tmp;
		while (stream >> tmp)
			{
				vectname->push_back(tmp);
				stream.get();
				num++;
			}
		stream.close();
	}
template void utils::readvector<float>(std::string filename,std::vector<float> *arrname);
template void utils::readvector<long>(std::string filename,std::vector<long> *arrname);
template void utils::readvector<short>(std::string filename,std::vector<short> *arrname);
template void utils::readvector<int>(std::string filename,std::vector<int> *arrname);
template void utils::readvector<double>(std::string filename,std::vector<double> *arrname);
template void utils::readvector<long double>(std::string filename,std::vector<long double> *arrname);
template void utils::readvector<std::string>(std::string filename,std::vector<std::string> *arrname);

// Requires: sstream, string, iomanip
template< typename T >
std::string utils::int_to_hex( T i/*, bool pre_def_len */)
{
	std::stringstream sstream;
	sstream << std::setfill ('0');
	/*if (pre_def_len)
	{
		sstream << std::setw(2);
	}
	else
	{
		sstream << std::setw(sizeof(T)*2);
	} */
	sstream << std::hex << i;
	return sstream.str();
}
template std::string utils::int_to_hex<int>(int i/*, bool pre_def_len*/);
template std::string utils::int_to_hex<short>(short i/*, bool pre_def_len*/);
template std::string utils::int_to_hex<long>(long i/*, bool pre_def_len*/);

// Requires: string
int utils::GetIntVal(std::string strConvert)
{ 
	int intReturn; 
	// NOTE: You should probably do some checks to ensure that 
	// this string contains only numbers. If the string is not 
	// a valid integer, zero will be returned. 
	intReturn = atoi(strConvert.c_str()); 
	return(intReturn); 
}

// Requires: vector, iterator, string
template <typename T>
void utils::PrintVector(std::ostream& ostr, const std::vector<T>& t, const std::string& delimiter)
{
	std::copy(t.begin(), t.end(), std::ostream_iterator<T>(ostr, delimiter.c_str()));
}
template void utils::PrintVector<int>(std::ostream& ostr, const std::vector<int>& t, const std::string& delimiter);
template void utils::PrintVector<char>(std::ostream& ostr, const std::vector<char>& t, const std::string& delimiter);
template void utils::PrintVector<wchar_t>(std::ostream& ostr, const std::vector<wchar_t>& t, const std::string& delimiter);
template void utils::PrintVector<float>(std::ostream& ostr, const std::vector<float>& t, const std::string& delimiter);
template void utils::PrintVector<double>(std::ostream& ostr, const std::vector<double>& t, const std::string& delimiter);
template void utils::PrintVector<long double>(std::ostream& ostr, const std::vector<long double>& t, const std::string& delimiter);
template void utils::PrintVector<long>(std::ostream& ostr, const std::vector<long>& t, const std::string& delimiter);
template void utils::PrintVector<short>(std::ostream& ostr, const std::vector<short>& t, const std::string& delimiter);
template void utils::PrintVector<std::string>(std::ostream& ostr, const std::vector<std::string>& t, const std::string& delimiter);


// ########################### OS-specific ###########################

#if defined (__WIN32__) || (_MSC_VER)/* || (__CYGWIN32__)*/
//bool windows=true;
#include <direct.h>
#include <Windows.h>


// Requires: string, direct.h
bool utils::PathExists(std::string pathtocheck)
{
	int ret = _chdir(pathtocheck.c_str()) ;
	return (ret == 0) ;
}

// Requires: Windows.h
void utils::sleep(int milliseconds)
{
	Sleep(milliseconds);
}

// Requires: string, direct.h
void utils::mkdir(std::string path, int mode)
{
	_mkdir(path.c_str());
}

// Requires: string, Windows.h?
std::string utils::exec(std::string command)
{
	const char* cmd=command.c_str();
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) return "ERROR";
	char buffer[256];
	std::string result = "";
	while(!feof(pipe))
	{
		if(fgets(buffer, 256, pipe) != NULL)
			result += buffer;
	}
	_pclose(pipe);
	return result;
}


#else
//bool windows=false;
#include <unistd.h>


// Requires: string, unistd.h
bool utils::PathExists(std::string pathtocheck)
{
	int ret = chdir(pathtocheck.c_str()) ;
	return (ret == 0) ;
}

// Requires: ?
void utils::sleep(int milliseconds)
{
	sleep(milliseconds);
}

// Requires: ?
void utils::mkdir(std::string path, int mode)
{
	mkdir(path.c_str(),mode);
}

// Requires: string
std::string utils::exec(std::string command)
{
	const char* cmd=command.c_str();
	FILE* pipe = popen(cmd,"r");
	if (!pipe) return "ERROR";
	char buffer[256];
	std::string result = "";
	while(!feof(pipe))
	{
		if(fgets(buffer, 256, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	return result;
}


#endif