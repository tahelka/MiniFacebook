#ifndef __ENTITIES_H
#define __ENTITIES_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#pragma warning (disable: 4996)

#include "Board.h"
#include "PictureStatus.h"
#include "VideoStatus.h"

// Forward declaration:
class Member;

class Entities
{
protected:
	std::string name;
	std::vector<Member*> members;
	Board board;

public:
	Entities(const std::string& name);
	Entities(std::ifstream& in)
	{
		in >> *this;
	}
	virtual ~Entities() {};

	// Setters 
	void setName(const std::string& name);
	void setBoard(const Board& board);
	void setMembers(const std::vector<Member*>& members);
	
	// Getters
	const std::string& getName()					const;
	int getMembersSize()							const;
	Board& getBoard();

	// Methods
	// This function disconnects the member from the entity (page/member)
	virtual bool removeMember(Member* const m) = 0;
	// This function prints all the members of the entity (page/member)
	virtual void showAllMembers()					const;

	// Files support methods
	// This function writes the other fields of member/page if exist
	virtual void toOs(std::ostream& os) const {}
	// This function reads the other fields of member/page if exist
	virtual void fromOs(std::istream& in) = 0;

	friend std::ostream& operator<<(std::ostream& os, const Entities& entity)
	{
		int boardSize = entity.board.getStatusesSize();
		os << entity.name << std::endl; // Member/Page Name << std::endl << Number of members << std::endl
		os << boardSize << std::endl; // Number of ststuses
		for (int i = 0; i < boardSize; i++)
		{
			os << *(entity.board.getStatus(i)); // Status details: type, time, date, content, video/pic (extra)
		}
		entity.toOs(os); // other fields of member/page if exist (pages, dayOfBitrh)
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Entities& entity)
	{
		int numOfStatuses;
		std::string statusType;
		std::string tmp;

		std::getline(in, entity.name);
		
		in >> numOfStatuses;
		std::getline(in, tmp); // for enter

		for (int i = 0; i < numOfStatuses; i++)
		{
			Status* status;

			std::getline(in, statusType);

			if (statusType.compare(typeid(Status).name() + SKIP) == EQUAL) 
			{
				status = new Status(in);
			}
			else if (statusType.compare(typeid(PictureStatus).name() + SKIP) == EQUAL) // PictureStatus
			{
				status = new PictureStatus(in);
			}
			else // VideoStatus
			{
				status = new VideoStatus(in);
			}
			entity.getBoard().addStatusToBoard(status);
		}

		return in;
	}

};

#endif 
