#include "Member.h"
#include "Page.h"
#include "Utils.h"
#include <vector>
using namespace std;

// Setters:

void Member::setDayOfBirth(const Date& dayOfBirth)
{
	this->dayOfBirth = dayOfBirth;
}

void Member::setPages(const vector<Page*>& pages)
{
	this->pages = pages;
}

// Getters:


Page *Member::getPage(int index) const
{
	return pages[index];
}

const Date &Member::getDayOfBirth() const
{
	return dayOfBirth;
}

const std::vector<std::string>& Member::getNamesOfMembers() const
{
	return namesOfMembers;
}

const std::vector<std::string>& Member::getNamesOfPages() const
{
	return namesOfPages;
}

// Methods:
// connecting and disconnecting between members, functions:

bool Member::addMember(Member& m)
{
	if (this->areMembersConnected(&m) == (int)Answers::NO)
	{
		this->addMemberHelper(&m);
		m.addMemberHelper(this);
		return true;
	}
	return false;
}

void Member::addMemberHelper(Member* const m)
{
	members.push_back(m);
}

int Member::areMembersConnected(const Member* const m) const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator	itrEnd = members.end();

	for (; itr != itrEnd; ++itr) 
	{
		if (*itr == m) 
		{
			int index (itr - members.begin());
			return index;
		}
	}
	return (int)Answers::NO;
}

bool Member::removeMember(Member* const m)
{
	vector<Member*>::iterator itr = members.begin();
	vector<Member*>::iterator itrEnd = members.end();
	vector<Member*>::iterator idx = m->members.begin();

	if (int index = this->areMembersConnected(m) != (int)Answers::NO)
	{
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == m)
			{
				this->removeMemberHelper(itr);
				index = m->areMembersConnected(this);
				for (int j = 0; j < index; j++)
				{
					++idx;
				}
				m->removeMemberHelper(idx);
				return true;
			}
		}
	}
	return false;
}

void Member::removeMemberHelper(const vector<Member*>::const_iterator& itr)
{
	members.erase(itr);
}

// Connecting and disconnecting between a member and a page, functions:

bool Member::addPageToMember(Page* const page)
{
	bool res = false;
	if (isLikedPageAlready(page) == (int)Answers::NO)
	{
		this->pages.push_back(page);
		res = true;
		if (page->isMemberLikedPageAlready(this) == (int)Answers::NO)
		{
			page->addMember(this);
		}
	}
	return res;
}

bool Member::removePage(Page* const page)
{
	vector<Page*>::iterator itr = pages.begin();
	vector<Page*>::iterator	itrEnd = pages.end();

	int index = isLikedPageAlready(page);
	if (index != (int)Answers::NO)
	{
		for (; itr != itrEnd; ++itr)
		{
			if ((*itr) == page)
			{
				removePageHelper(itr);
				break;
			}
		}
		page->removeMember(this);
		return true;
	}
	return false;
}

void Member::removePageHelper(const vector<Page*>::const_iterator& itr) 
{
	pages.erase(itr);
}

int Member::isLikedPageAlready(const Page* const page) const
{
	vector<Page*>::const_iterator itr = pages.begin();
	vector<Page*>::const_iterator	itrEnd = pages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr) == page)
		{
			int index = (itr - pages.begin());
			return index;
		}
	}
	return (int)Answers::NO;
}

/* Print functions */

void Member::show10StatusesOfMembers()	const
{
	vector<Member*>::const_iterator	itr = members.begin();
	vector<Member*>::const_iterator	itrEnd = members.end();

	if (itr == itrEnd)
	{
		cout << name << " has no friends yet." << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
	{
		cout << endl << "Statuses of " << this->getName() << "'s friend " << (*itr)->getName() << ": " << endl;
		(*itr)->getBoard().printStatuses((*itrEnd)->getName(), true);
	}
}

// Operators overloading:

bool Member::operator+=(Member& other) {
	return addMember(other);
}
bool Member::operator+=(Page& page) {
	return addPageToMember(&page);
}
bool Member::operator>(const Member& otherMember) {
	return (this->members.size() > otherMember.members.size());
}
bool Member::operator>(Page& page) {
	return (this->members.size() > page.getMembersSize());
}

// Files support methods
void Member::toOs(std::ostream& os) const
{
	int i = 0;
	int membersSize = members.size();
	int numOfPages = pages.size();
	os << dayOfBirth << std::endl; // day of birth << endl
	os << membersSize << std::endl; // number of members << endl
	for (i = 0; i < membersSize; i++)
	{
		os << members.at(i)->getName() << std::endl; // All the members names seperated by std::endl 
	}
	
	os << numOfPages << std::endl; // number of pages << endl
	for (int i = 0; i < numOfPages; i++)
	{
		os << pages[i]->getName() << std::endl; // page name << endl
	}
}


void Member::fromOs(std::istream& in)
{
	int numOfPages, numOfMembers, i;
	std::string tmp;

	in >> numOfMembers; // reads the num of members
	std::getline(in, tmp); // for enter

	for (i = 0; i < numOfMembers; i++)
	{
		std::getline(in, tmp);
		addMemberName(tmp); // reads the members names
	}

	in >> numOfPages; // reads the num of pages
	std::getline(in, tmp); // for enter

	for (i = 0; i < numOfPages; i++)
	{
		std::getline(in, tmp);
		addPageName(tmp); // reads the pages names
	}
}

void Member::addMemberName(std::string& name)
{
	namesOfMembers.push_back(name);
}
void Member::addPageName(std::string& name)
{
	namesOfPages.push_back(name);
}