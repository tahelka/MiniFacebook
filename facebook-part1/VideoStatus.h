#ifndef __VIDEOSTATUS_H
#define __VIDEOSTATUS_H
#include "Status.h"

class VideoStatus : public Status
{
private:
	std::string videoName;

public:
	VideoStatus(const std::string& content, std::string videoName) : Status(content), videoName(videoName) {};
	VideoStatus(std::istream& in) : Status(in)
	{
		fromOs(in);
	}

	// Setters
	void setVideoName(const std::string videoName);
	// Getters
	const std::string getVideoName();
	//inhetited methods
	const  std::string getType();

	// Files support methods
	void toOs(std::ostream& os) const override;
	void fromOs(std::istream& in) override;
};

#endif
