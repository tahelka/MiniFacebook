#include "Page.h"
#include "Member.h"
#include "Utils.h"

using namespace std;

// Methods:

bool Page::addMember(Member* const m)
{
	if ((isMemberLikedPageAlready(m) == (int)Answers::NO))
	{
		members.push_back(m);
		if (m->isLikedPageAlready(this) == (int)Answers::NO)
		{
			m->addPageToMember(this);
		}
		return true;
	}

	return false;
}

int Page::isMemberLikedPageAlready(const Member* const m)   const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator	itrEnd = members.end();

	for (; itr != itrEnd; ++itr)
	{
		if (*itr == m) 
		{
			int index = (itr - members.begin());
			return index;
		}
	}
	return (int)Answers::NO;
}

bool Page::removeMember(Member* const m)
{
	vector<Member*>::iterator itr = members.begin();
	vector<Member*>::iterator	itrEnd = members.end();

	int index = isMemberLikedPageAlready(m);
	if (index != (int)Answers::NO)
	{
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == m)
			{
				members.erase(itr);
				m->removePage(this);
				return true;
			}
		}
	}
	return false;
}

void Page::addMemberName(const std::string& name)
{
	namesOfMembers.push_back(name);
}

// Operators overloading

bool Page::operator+=(Member& member) {
	return addMember(&member);
}
bool Page::operator>(const Page& otherPage) {
	return (this->members.size() > otherPage.members.size());
}
bool Page::operator>(Member& member) {
	return (this->members.size() > member.getMembersSize());
}

// Files support methods
void Page::toOs(std::ostream& os) const
{
	int i = 0;
	int membersSize = members.size();
	os << membersSize << std::endl; // number of members
	for (i = 0; i < membersSize; i++)
	{
		os << members.at(i)->getName() << std::endl; // All the members names seperated by std::endl
	}
}

void Page::fromOs(std::istream& in)
{
	int numOfMembers;
	in >> numOfMembers; // reads the num of members
	std::string tmp;
	getline(in, tmp); // for enter

	for (int i = 0; i < numOfMembers; i++)
	{
		getline(in, tmp);
		addMemberName(tmp); // reads the names of the members
	}
}