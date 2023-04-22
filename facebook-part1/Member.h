#ifndef __MEMBER_H
#define __MEMBER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Board.h"
#include "Entities.h"
#include "PictureStatus.h"
#include "VideoStatus.h"

#pragma warning (disable: 4996)

enum class Answers { NO = -1 };

// Forward declarations:
class Date;
class Page;

class Member : public Entities
{
private:
	Date dayOfBirth;
	std::vector<Page*> pages;
	std::vector<std::string> namesOfMembers;
	std::vector<std::string> namesOfPages;

	// Private functions:

	// This function is a helper function for removerMember function
	void removeMemberHelper(const std::vector<Member*>::const_iterator& itr);
	// This function is a helper function for removerPage function
	void removePageHelper(const std::vector<Page*>::const_iterator& itr);
	// This function is a helper function for addMember function
	void addMemberHelper(Member* const m);

public:
	Member(const std::string& name, const Date& dayOfBirth) : Entities(name), dayOfBirth(dayOfBirth) {};
	Member(std::ifstream& in) : Entities(in), dayOfBirth(in)
	{
		fromOs(in);
	}

	// Setters:
	void setPages(const std::vector<Page*>& pages);
	void setDayOfBirth(const Date& dayOfBirth);

	// Getters:
	Page* getPage(int index) const;
	const Date& getDayOfBirth()					const;
	const std::vector<std::string>& getNamesOfMembers() const;
	const std::vector<std::string>& getNamesOfPages() const;

	// Methods:

	// This function checks if two members are already connected (friends) on facebook,  if "this" connected to m, 
	// if not: returns -1 , and if yes: returns the index of m in "this" members array
	int areMembersConnected(const Member* const m) const;
	// This function adds in a mutual manner a member to their friends list.
	bool addMember(Member& m);
	// This function add a page to member's pages arr and also adds the member as a fan of the page
	bool addPageToMember(Page* const page);
	// This function removes a page from member's pages arr and also removes the member as a fan of the page
	bool removePage(Page* const page);
	// This function checks if the member is already a fan of the page
	int isLikedPageAlready(const Page* const page) const;
	// This function prints 10 latest statuses of a member
	void show10StatusesOfMembers()		const;
	// Adds the name of the member to the vector
	void addMemberName(std::string& name);
	// Adds the name of the page to the vector
	void addPageName(std::string& name);

	
	// inherited methods
	// This function removes in a mutual manner a member from their friends list
	bool removeMember(Member* const m) override;

	// Operators overloading
	// const bool& operator+=(Member& other);
	// const bool& operator+=(Page& page);
	// const int& operator>(const Member& otherMember);  // 0 - num of members is equal. positive - member1 has more members. negative - member2 has more members.
	// const int& operator>(Page& page);  // 0 - num of members is equal. positive - member has more members. negative - page has more members.
	bool operator+=(Member& other);
	bool operator+=(Page& page);
	bool operator>(const Member& otherMember);
	bool operator>(Page& page);

	void toOs(std::ostream& os) const override;
	void fromOs(std::istream& in) override;


};

#endif // !__MEMBER_H

