#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>

class Filereader
{
protected:
	std::ifstream _file;
	std::string _path;

	int ReadNodes(std::string);
	int ReadEdges(std::string);
	
	int CreateNode(std::string);
	int CreateProbe(std::string);
	int CreateInput(std::string);

public:
	Filereader(std::string Path);
	~Filereader();
	int Read();
};

#endif // _FILEREADER_H