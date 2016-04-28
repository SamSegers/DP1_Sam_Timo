#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>

class Filereader
{
protected:
	FILE *pFile;
	std::string _path;
public:
	Filereader(std::string Path);
	~Filereader();
	void Read();
};

#endif // _FILEREADER_H