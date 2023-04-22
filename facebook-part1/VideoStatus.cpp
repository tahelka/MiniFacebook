#include "VideoStatus.h"

// Setters
void VideoStatus::setVideoName(const std::string videoName)
{
	this->videoName = videoName;
}

// Getters
const std::string VideoStatus::getVideoName()
{
	return videoName;
}

//inhetited methods
const  std::string VideoStatus::getType()
{
	return "VideoStatus";
}

// Files support methods
void VideoStatus::toOs(std::ostream& os) const 
{
	os << videoName << std::endl;
}

void VideoStatus::fromOs(std::istream& in)
{
	std::getline(in, videoName); 
}