#include "PictureStatus.h"

// Setters
void PictureStatus::setPictureName(const std::string& pictureName)
{
	this->pictureName = pictureName;
}

// Getters
const std::string PictureStatus::getPictureName()
{
	return pictureName;
}

//inhetited methods
const  std::string PictureStatus::getType()
{
	return "PictureStatus";
}

// Files support methods
void PictureStatus::toOs(std::ostream& os) const 
{
	os << pictureName << std::endl;
}

void PictureStatus::fromOs(std::istream& in) 
{
	std::getline(in, pictureName);
}