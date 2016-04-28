#include "Filereader.h"

Filereader::Filereader(std::string Path)
{
	this->_path = Path;
}

Filereader::~Filereader()
{

}

void Filereader::Read()
{
	fopen_s(&this->pFile, this->_path.c_str(), "r");



	fclose(this->pFile);
}
