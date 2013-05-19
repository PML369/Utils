#Utils
##A collection of c++ functions
These functions were written because they were useful in the application I was making at the time.
I'm not saying that they are the best or the fastest, but they do the job.
I've arranged them all in their own namespace - "utils" - so they shouldn't clash with any other functions.
Where necessary, all the functions can be compiled for both Windows and Linux, since I often like to move code around between the two.

I have also included libraries pre-compiled (both static and dynamic) for you to use if you want.

Here are the functions it provides:

- FileExists - check if the path passed exists and is a file  
```bool	FileExists(std::string strFilename);```
- PathExists - check if the path passed exists and is a directory  
```bool	PathExists(std::string pathtocheck);```
- mkdir - A cross-platform directory making function (mode is only used on linux)  
```void	mkdir(std::string path, int mode);```
- sleep - A cross-platform sleep function  
```void	sleep(int milliseconds);```
- exec - A cross-platform function to execute shell commands  
```std::string exec(std::string command);```
- err - Sleeps for 20 secs, then exits the program (useful for seeing error messages in console applications)  
```void	err(int returnvalue);```
- ifnoexistmake - Create a directory if it doesn't already exist (recursive adds functionality similar to mkdir -p on linux)  
```void	ifnoexistmake(std::string dir, bool recursive=false);```
- linecount - count the number of lines in a file (name is a human-readable name to print in errors)  
```int	linecount(std::string filename, std::string name="the");```
- GetIntVal - return the integer value of a text number  
```int	GetIntVal(std::string strConvert);```
- int_to_hex - return a number in hexadecimal format  
```template <typename T>	std::string int_to_hex( T i);```  
Templates included are:
 - int
 - short
 - long
- readvector - Read a given file into the vector pointed to by vectname - each line of the file is 1 element  
```template <class any>	void readvector(std::string filename,std::vector<any> *vectname);```  
Templates included are:
 - float
 - long
 - short
 - int
 - double
 - long double
 - std::string
- readvectorspace - like readvector, but the lines can include spaces (this means it can only use a vector of strings)  
```void	readvectorspace(std::string filename,std::vector<std::string> *vectname);```
- PrintVector - print every element in a vector to the stream given, separated by delimiter  
```template <typename T>	void PrintVector(std::ostream& ostr, const std::vector<T>& t, const std::string& delimiter);```  
Templates included are:
 - int
 - char
 - wchar_t
 - float
 - double
 - long double
 - long
 - short
 - std::string
 
 ##Contact
If you have any requests for future releases, feel free to email plpub2@gmail.com 

##Copyright
This code is Copyright (C) 2013  Peter Lotts. 
It is released under the GNU General Public Licence version 3. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details. 