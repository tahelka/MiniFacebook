#ifndef __PICTURESTATUS_H
#define __PICTURESTATUS_H
#include "Status.h"

class PictureStatus : public Status
{
private:
	std::string pictureName;

public:
	PictureStatus(const std::string& content, std::string pictureName) : Status(content), pictureName(pictureName) {};
	PictureStatus(std::istream& in) : Status(in)
	{
		fromOs(in);
	}

	// Setters
	void setPictureName(const std::string& pictureName);
	// Getters
	const std::string getPictureName();
	//inhetited methods
	const  std::string getType();

	// Files support methods
	void toOs(std::ostream& os) const override;
	void fromOs(std::istream& in) override;
};

#endif
