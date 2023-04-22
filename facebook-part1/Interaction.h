#ifndef __INTERACTION_H
#define __INTERACTION_H

#include "Member.h"
#include "Page.h"
#include "Status.h"
#include "Facebook.h"
#include "NameException.h"
#include "RangeException.h"
#include "DateException.h"
#include "ContentException.h"
#include "PictureStatus.h"
#include "VideoStatus.h"

enum class Range { MIN_CHOICE = 1, MAX_CHOICE = 12 };
enum class UserChoice { PAGE_CHOICE = 0, MEMBER_CHOICE = 1};

class Interaction
{
private:
	bool isFirstChoice;
	bool continueUseFacebook;

public:

	// Setters:

	void setIsFirstChoice(bool choice);
	void setContinueUseFacebook(bool choice);

	// Getters:

	bool getIsFirstChoice()				const;
	bool getContinueUseFacebook()		const;

	// Methods:

	// This function is responsible for the menu logic
	void Menu(Facebook& facebook);
	// This function prints the main menu and gets user choice
	int userChoice()		const;

	// Menu options:
	void addNewMemberToFacebook(Facebook& facebook) throw(NameException); // case 1
	void addNewPageToFacebook(Facebook& facebook) throw(NameException); // case 2
	void addNewStatusToMemberOrPage(Facebook& facebook) throw(NameException); // case 3
	void showAllStatusesOfMemberOrPage(Facebook& facebook)  const; // case 4
	void show10LastStatusesOfMember(Facebook& facebook)		const; // case 5
	void createFriendShipBetween2Members(Facebook& facebook); // case 6
	void cancelFriendship(Facebook& facebook); // case 7
	void addAMemberToAPage(Facebook& facebook); // case 8
	void removeMemberFromAPage(Facebook& facebook); // case 9
	void showMembersAndPagesInFacebook(Facebook& facebook)	const; // case 10
	void showMembersOfASpecificMemberOrPage(Facebook& facebook)	const; // case 11
	void exitMenu(); // case 12

	// This function checks if value is between min (includes) and between max (includes)
	void isValueInRange(int min, int max, int value) const throw(RangeException);
	// This function gets user's choice
	int getChoiceFromUser(int min, int max) const;
	// This function get content from user
	void getContent(std::string& statusContent)	const	throw(ContentException);
	// This function gets a member name from user and returns its index in the vector of all members
	int getMemberNameFromUser(Facebook& facebook) const;
	// This function gets a page name from user and returns its index in the vector of all pages
	int getPageNameFromUser(Facebook& facebook) const;
	// This function checks if two names are the same
	void areNamesEqual(const std::string& name1, const std::string& name2) const throw(NameException);
	// This method adds the test status to the board and prints appropriate message
	void statusAdding(Facebook& facebook, int choice, int index, const std::string& name, Status* status);
	// This function manage the text part of the status
	void textStatusMgt(std::string& statusContent);
	//This function gets the text from the user and throws appropriate error if needed
	void textHandling(std::string& statusContent);
	// This function manage the picture part of the status
	void pictureStatusMgt(std::string& pictureName);
	// This function manage the video part of the status
	void videoStatusMgt(std::string& videoName);

};

#endif