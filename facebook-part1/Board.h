#ifndef __BOARD_H
#define __BOARD_H
#include <iostream>
#include <vector>
#include "Status.h"

#pragma warning (disable: 4996)

const int LATEST_STATUSES = 10;

class Board // Bulletin Board 
{
private:
	std::vector<Status*> statuses;
public:
	// Getters:
	// This function returns the statuses vecotr size	
	int getStatusesSize()						const;
	// This function returns the status in the index
	Status* getStatus(int index)				const;

	// Setters:
	void setStatuses(const std::vector<Status*>& statuses);

	// Methods:
	// This function adds status to board
	void addStatusToBoard(Status* const newStatus);
	// This function prints statuses
	void printStatuses(const std::string& memberName, bool only10)												const;
	// This function prints the pictures and videos parts if exist
	void pictureAndvideoPrinting(const std::string& memberName, std::vector<Status*>::const_iterator itrEnd)	const;
	// This function open the pictures if exist
	void showPictures(const std::string& memberName, std::vector<Status*>::const_iterator itrEnd)				const;
	// This function open the videos if exist
	void showVideos(const std::string& memberName, std::vector<Status*>::const_iterator itrEnd)				const;
};
#endif
