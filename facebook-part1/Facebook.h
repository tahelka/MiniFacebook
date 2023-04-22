#ifndef __FACEBOOK_H
#define __FACEBOOK_H
#include <vector>
#include <string>
#include "Member.h"
#include "Page.h"
#include "NameException.h"

enum class Connection { DISCONNECT = 0, CONNECT = 1};
constexpr int maxMembersOnFacebook = 1000;

class Facebook
{
private:
	std::vector<Member> members;
	std::vector<Page> pages;

public:
	Facebook() { members.reserve(maxMembersOnFacebook); };
	~Facebook() = default;

	// Setters:

	void setMembers(const std::vector<Member>& members);
	void setPages(const std::vector<Page>& pages);

	// Getters:

	// This function returns the size of the members vector
	int getMembersSize() const;
	// This function returns a reference to a member in the members vector
	Member& getMember(int index);
	// This function returns the size of the pages vector
	int getPagesSize() const;
	// This function returns a reference to a page in the pages vector
	Page& getPage(int index);

	// Methods:

	// This function checks if a name does exist as a member on facebook
	int isMemberInSystem(const std::string& name, bool shouldBeInSystem)	const throw(NameException);
	// This function checks if a name does exist as a page on facebook
	int isPageInSystem(const std::string& name, bool shouldBeInSystem) const throw(NameException);
	// This function adds a new member to facebook system
	void addNewMemberToFacebook(const Member& newMember);
	// This function adds a new page to facebook system
	void addNewPageToFacebook(const Page& newPage);
	// This function prints all members in facebook system
	void printAllMembersInTheSystem()	const;
	// This function prints all pages in facebook system
	void printAllPagesInTheSystem()		const;
};

#endif // !__FACEBOOK_H