#ifndef __PAGE_H
#define __PAGE_H
#include <iostream>
#include <vector>
#include <string>
#include "Board.h" 
#include "Member.h" 
#include "Entities.h"

#pragma warning (disable: 4996)

// Forward declarations:
class Member;

class Page : public Entities
{
	std::vector<std::string> namesOfMembers;
public:
	Page(const std::string& name) : Entities(name) {};
	Page(std::ifstream& in) : Entities(in)
	{
		fromOs(in);
	}

	// Methods:
	// This function adds a member as a fan of this page and also adds the page to this member's liked pages arr
	bool addMember(Member* const m);
	// This function checks if the member is already a fan of the page
	int isMemberLikedPageAlready(const Member* const m)  const;
	// This function adds a member name to the namesOfMembers vector
	void addMemberName(const std::string& name);

	// inherited methods
	// This function removes a member as a fan of this page and also removes the page from this member's liked pages arr
	bool removeMember(Member* const m) override;

	// Operators overloading
	bool operator+=(Member& member);
	bool operator>(const Page& otherPage);
	bool operator>(Member& member);

	// Files support methods
	void toOs(std::ostream& os) const override;
	void fromOs(std::istream& in) override;

};

#endif 