#include "Board.h"
#include "Utils.h"
#include "PictureStatus.h"
#include "VideoStatus.h"

using namespace std;

// Getters:

int Board::getStatusesSize() const
{
	return statuses.size();
}

Status * Board::getStatus(int index) const
{
	return statuses[index];
}

// Setters:
void Board::setStatuses(const vector<Status*>& statuses)
{
	this->statuses = statuses;
}

// Methods:
// This function adds status to board
void Board::addStatusToBoard(Status* newStatus)
{
	statuses.push_back(newStatus);
}

// This function prints statuses
void Board::printStatuses(const std::string& memberName, bool only10) const
{
	vector<Status*>::const_iterator	itr = statuses.begin();
	vector<Status*>::const_iterator	itrEnd = statuses.end();

	if (itr == itrEnd)
	{
		cout << "There are no statuses yet!" << endl;
		return;
	}

	cout << "The statuses are: " << endl;

	if (only10 && statuses.size() > LATEST_STATUSES)
	{
		itr = itrEnd - LATEST_STATUSES;
	}

	while (itr != itrEnd)
	{
		--itrEnd;
		cout << endl << "Status #" << (itrEnd - statuses.begin() + 1) << ": " << endl;
		(*itrEnd)->getDate().show();
		cout << " ";
		(*itrEnd)->getTime().show();
		cout << endl;
		cout << (*itrEnd)->getTextStatus();
		cout << endl;
		pictureAndvideoPrinting(memberName, itrEnd);
	}
}

void Board::pictureAndvideoPrinting(const std::string& memberName, vector<Status*>::const_iterator	itrEnd) const
{
	if ((*itrEnd)->getType().compare("PictureStatus") == 0)
	{
		cout << "Picture Name is: ";
		cout << ((PictureStatus*)(*itrEnd))->getPictureName() << endl;
		showPictures(memberName, itrEnd);
	}
	else if ((*itrEnd)->getType().compare("VideoStatus") == 0)
	{
		cout << "Video Name is: ";
		cout << ((VideoStatus*)(*itrEnd))->getVideoName() << endl;
		showVideos(memberName, itrEnd);
	}
}

void Board::showPictures(const std::string& memberName, vector<Status*>::const_iterator itrEnd) const
{
	if (memberName.compare("Eden Harati") == 0)
	{
		system("start avocadoYay.jpg");
	}
	else if (memberName.compare("Tahel Karavani") == 0)
	{
		system("start coolDog.jpg");
	}
}

void Board::showVideos(const std::string& memberName, vector<Status*>::const_iterator itrEnd) const
{
	if (memberName.compare("Roni Makaroni") == 0)
	{
		system("start cat.mov");
	}
	else if (memberName.compare("GOGO") == 0)
	{
		system("start rainbow.mov");
	}
}