#include "Facebook.h"
#include "Utils.h"

using namespace std;

// Setters:

void Facebook::setMembers(const vector<Member>& members)
{
	this->members = members;
}

void Facebook::setPages(const vector<Page>& pages)
{
	this->pages = pages;
}

// Getters:

int Facebook::getMembersSize() const {
	return members.size();
}

Member& Facebook::getMember(int index)
{
	return members[index];
}

int Facebook::getPagesSize() const {
	return pages.size();
}

Page& Facebook::getPage(int index)
{
	return pages[index];
}

// Methods:

void Facebook::addNewPageToFacebook(const Page& newPage)
{
	pages.push_back(newPage);
}

void Facebook::addNewMemberToFacebook(const Member& newMember) 
{
	members.push_back(newMember);
}

int Facebook::isMemberInSystem(const string& name, bool shouldBeInSystem) const
{
	int index = (int)Answers::NO;

	vector<Member>::const_iterator	itr = members.begin();
	vector<Member>::const_iterator	itrEnd = members.end();

	for (; itr != itrEnd; ++itr)
	{
		if (!((*itr).getName().compare(name))) 
		{
			index = (itr - members.begin());
			break;
		}
	}

	if ((shouldBeInSystem && index == (int)Answers::NO) || (!shouldBeInSystem && index != (int)Answers::NO))
		throw NameException();

	return index;
}

int Facebook::isPageInSystem(const string& name, bool shouldBeInSystem) const
{
	int index = (int)Answers::NO;

	vector<Page>::const_iterator	itr = pages.begin();
	vector<Page>::const_iterator	itrEnd = pages.end();

	for (; itr != itrEnd; ++itr)
	{
		if (!((*itr).getName().compare(name)))
		{
			index = (itr - pages.begin());
			break;
		}
	}

	if ((shouldBeInSystem && index == (int)Answers::NO) || (!shouldBeInSystem && index != (int)Answers::NO))
		throw NameException();

	return index;
}

void Facebook::printAllMembersInTheSystem()	const
{
	vector<Member>::const_iterator	itr = members.begin();
	vector<Member>::const_iterator	itrEnd = members.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr).getName();
		cout << endl;
	}
}

void Facebook::printAllPagesInTheSystem() const
{
	vector<Page>::const_iterator	itr = pages.begin();
	vector<Page>::const_iterator	itrEnd = pages.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr).getName();
		cout << endl;
	}
}
