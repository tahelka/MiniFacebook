#include "Entities.h"
#include "Member.h" 
using namespace std;

Entities::Entities(const std::string& name)
{
	setName(name);
}

// Setters:

void Entities::setName(const string& name)
{
	this->name = name;
}

void Entities::setMembers(const vector<Member*>& members)
{
	this->members = members;
}

void Entities::setBoard(const Board& board)
{
	this->board = board;
}

// Getters:

const string& Entities::getName()			const
{
	return name;
}

int Entities::getMembersSize() const
{
	return members.size();
}

Board& Entities::getBoard()
{
	return board;
}

// Methods

void Entities::showAllMembers()		const
{
	vector<Member*>::const_iterator	itr = members.begin();
	vector<Member*>::const_iterator	itrEnd = members.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr)->getName() << endl;
	}
}