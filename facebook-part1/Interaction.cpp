#include <iostream>
#include "Interaction.h"
using namespace std;

// setters:

void Interaction::setIsFirstChoice(bool choice)
{
	isFirstChoice = choice;
}

void Interaction::setContinueUseFacebook(bool choice)
{
	continueUseFacebook = choice;
}

// getters:

bool Interaction::getContinueUseFacebook()		const
{
	return continueUseFacebook;
}

bool Interaction::getIsFirstChoice()			const
{
	return isFirstChoice;
}

// methods:

void Interaction::Menu(Facebook& facebook)
{
	setIsFirstChoice(true);
	setContinueUseFacebook(true);
	int choice;

	while (getContinueUseFacebook())
	{
		if (getIsFirstChoice())
		{
			setIsFirstChoice(false);
			cout << "Welcome to Facebook!" << endl;
		}
		choice = userChoice();

		switch (choice) {
		case 1: // Add a new member to Facebook.
		{
			addNewMemberToFacebook(facebook);
			break;
		}
		case 2: // Add a new fan page to Facebook.
		{
			addNewPageToFacebook(facebook);
			break;
		}
		case 3: // Add a new status to a member / fan page.
			addNewStatusToMemberOrPage(facebook);
			break;
		case 4: // Show all ststuses of a specific member or fan page.
		{
			showAllStatusesOfMemberOrPage(facebook);
			break;
		}
		case 5: // Show the 10 latest statuses of the members of a specific member.
			show10LastStatusesOfMember(facebook);
			break;
		case 6: // Create friendship between 2 members.
		{
			createFriendShipBetween2Members(facebook);
			break;
		}
		case 7: // Cancel friendship between 2 members.
		{
			cancelFriendship(facebook);
			break;
		}
		case 8: // Add a fan (member) to a page.
		{
			addAMemberToAPage(facebook);
			break;
		}
		case 9: // Remove a fan (member) from a page.
		{
			removeMemberFromAPage(facebook);
			break;
		}
		case 10: // Show all members and pages in Facebook.
			showMembersAndPagesInFacebook(facebook);
			break;
		case 11: // Show all members of a specific member / fan page.
		{
			showMembersOfASpecificMemberOrPage(facebook);
			break;
		}
		case 12: // Exit
			exitMenu();
			break;
		}
	}
}

int Interaction::userChoice()		const
{

	cout << endl << "Please choose one option (1-12): " << endl;
	cout << "(1)  - Add a new member to Facebook." << endl;
	cout << "(2)  - Add a new fan page to Facebook." << endl;
	cout << "(3)  - Add a new status to a member / fan page." << endl;
	cout << "(4)  - Show all statuses of a specific member or fan page." << endl;
	cout << "(5)  - Show the 10 latest statuses of the members of a specific member." << endl;
	cout << "(6)  - Create friendship between 2 members." << endl;
	cout << "(7)  - Cancel friendship between 2 members." << endl;
	cout << "(8)  - Add a fan (member) to a page." << endl;
	cout << "(9)  - Remove a fan (member) from a page." << endl;
	cout << "(10) - Show all members and pages in Facebook." << endl;
	cout << "(11) - Show all members of a specific member / fan page." << endl;
	cout << "(12) - Exit" << endl;

	int choice = getChoiceFromUser((int)Range::MIN_CHOICE, (int)Range::MAX_CHOICE);
	
	return choice;
}

void Interaction::isValueInRange(int min, int max, int value)  const
{
	if (value > max || value < min)
	{
		throw RangeException(min,max);
	}
}

int Interaction::getChoiceFromUser(int min, int max) const
{
	int choice;
	bool keepGoing = true;

	while (keepGoing)
	{
		try
		{
			cin >> choice;
			cin.ignore();
			isValueInRange(min, max, choice);
			keepGoing = false;
		}
		catch (Exception& e)
		{
			cout << e.what() << endl << "Please try again by choosing an integer number between " << min << " and "  << max << ": ";
		}
	}

	return choice;
}

void Interaction::getContent(string& statusContent)	const
{
	getline(cin, statusContent);

	if (statusContent.length() == EMPTY)
	{
		throw ContentException();
	}
}

int Interaction::getMemberNameFromUser(Facebook& facebook) const
{
	string name;
	bool keepGoing = true;
	int index;

	while (keepGoing)
	{
		try
		{
			getline(cin, name);
			index = facebook.isMemberInSystem(name, true);
			keepGoing = false;
		}
		catch (Exception& e)
		{
            cout << e.what() << endl << "Please enter a different name: ";
		}
	}

	return index;
}

int Interaction::getPageNameFromUser(Facebook& facebook) const
{
	string name;
	bool keepGoing = true;
	int index;

	while (keepGoing)
	{
		try
		{
			getline(cin, name);
			index = facebook.isPageInSystem(name, true);
			keepGoing = false;
		}
		catch (Exception& e)
		{
            cout << e.what() << endl << "Please enter a different name: ";
		}
	}

	return index;
}

void Interaction::areNamesEqual(const std::string& name1, const std::string& name2) const
{
	if (name1.compare(name2) == EQUAL)
	{
		throw NameException();
	}
}

void Interaction::statusAdding(Facebook& facebook, int choice, int index, const std::string& name, Status* status)
{
	if (choice) // member status
	{
		facebook.getMember(index).getBoard().addStatusToBoard(status);
		cout << "The status for member " << name << " was added successfully." << endl;
	}
	else // page status
	{
		facebook.getPage(index).getBoard().addStatusToBoard(status);
		cout << "The status for page " << name << " was added successfully." << endl;
	}
}

void Interaction::textStatusMgt(string& statusContent)
{
	cout << "What's on your mind? Please write your status: " << endl;
	textHandling(statusContent);
}

void Interaction::textHandling(string& content)
{
	bool keepGoing = true;

	while (keepGoing)
	{
		try {
			getContent(content);
			keepGoing = false;
		}
		catch (Exception& e)
		{
			cout << e.what() << endl;
		}
	}
}

void Interaction::pictureStatusMgt(string& pictureName)
{
	cout << "Please type the name of your picture:";
	textHandling(pictureName);
}

void Interaction::videoStatusMgt(string& videoName)
{
	cout << "Please type the name of your video:";
	textHandling(videoName);
}

// menu options:

// case 1
void Interaction::addNewMemberToFacebook(Facebook& facebook) 
{
	{		
		string name;
		cout << "Please enter the member's name: ";

		bool keepGoing = true;

		while (keepGoing)
		{
			try
			{
				getline(cin, name);
				facebook.isMemberInSystem(name, false);
				keepGoing = false;
			}
            catch (Exception& e)
            {
                cout << e.what() << endl << "Please enter a different name: ";
            }
		}
		int day, month, year;

		keepGoing = true;
		Date date;

		while (keepGoing)
		{
			cout << "Please enter the member's day of birth in the following format: DD MM YYYY ";
			try
			{
				cin >> day >> month >> year;
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				keepGoing = false;
			}
			catch (Exception& e)
			{
				cout << e.what() << endl;
			}
		}
		Member newMember(name, date);
		facebook.addNewMemberToFacebook(newMember);
		cout << endl << "The member: " << name << " was added successfully." << endl;
	}
}
// case 2
void Interaction::addNewPageToFacebook(Facebook& facebook) 
{
	string name;
	cout << "Please enter the page's name: ";

	bool keepGoing = true;

	while (keepGoing)
	{
		try
		{
			getline(cin, name);
			facebook.isPageInSystem(name, false);
			keepGoing = false;
		}
        catch (Exception& e)
        {
            cout << e.what() << endl << "Please enter a different name: ";
        }
	}
	
	Page newPage(name);
	facebook.addNewPageToFacebook(newPage);
	cout << "The page: " << name << " was added successfully." << endl;
}
// case 3
void Interaction::addNewStatusToMemberOrPage(Facebook& facebook) 
{
	int choice;
	int ststusChoice;
	cout << "Would you like to add a new status to a member / page? For member type: \"1\" for page type: \"0\": ";

	choice = getChoiceFromUser((int)UserChoice::PAGE_CHOICE, (int)UserChoice::MEMBER_CHOICE);

	string name;
	string statusContent;
	string pictureName;
	string videoName;
	int index;
	bool keepGoing = true;

	cout << "Please choose the one you want to add a status for from the list below." << endl;

	if (choice)
		facebook.printAllMembersInTheSystem();
	else
		facebook.printAllPagesInTheSystem();
		
	cout << "Type a name - Case sensitive:" << endl;

	while (keepGoing)
	{
		try
		{
			getline(cin, name);

			if (choice)
				index = facebook.isMemberInSystem(name, true);
			else
				index = facebook.isPageInSystem(name, true);

			keepGoing = false;
		}
        catch (Exception& e)
        {
            cout << e.what() << endl << "Please enter a different name: ";
        }
	}

	cout << "Please choose the type of your ststus: (1) - Text only (2) - Text and picture (3) - Text and video." << endl;
	ststusChoice = getChoiceFromUser((int)Range::MIN_CHOICE, (int)Range::MAX_CHOICE);
	textStatusMgt(statusContent);
	switch (ststusChoice)
	{
	case 1: // text only
	{	
		Status* status = new Status(statusContent);
		statusAdding(facebook, choice, index, name, status);
		break;
	}
	case 2: // text and picture
	{
		pictureStatusMgt(pictureName);
		Status* pictureStatus = new PictureStatus(statusContent, pictureName);
		statusAdding(facebook, choice, index, name, pictureStatus);
		break;
	}
	case 3: // text and video
	{
		videoStatusMgt(videoName);
		Status* videoStatus = new VideoStatus(statusContent, videoName);
		statusAdding(facebook, choice, index, name, videoStatus);
		break;
	}
	default:
		break;
	}
}

// case 4
void Interaction::showAllStatusesOfMemberOrPage(Facebook& facebook)		const 
{
	cout << "Would you like to see all statuses of a member / page? For member type: \"1\" for page type: \"0\": ";

	int choice = getChoiceFromUser((int)UserChoice::PAGE_CHOICE, (int)UserChoice::MEMBER_CHOICE);
	
	string name;
	string statusContent;
	int index;
	bool keepGoing = true;

	if (choice) // member statuses
	{
		cout << "Please choose the member you want to see their statuses from the list below." << endl;
		facebook.printAllMembersInTheSystem();
	}
	else // page statuses
	{
		cout << "Please choose the page you want to see its statuses from the list below." << endl;
		facebook.printAllPagesInTheSystem();
	}
	cout << "Type a name - Case sensitive:" << endl;

	while (keepGoing)
	{
		try
		{
			getline(cin, name);
			if(choice)
				index = facebook.isMemberInSystem(name, true);
			else
				index = facebook.isPageInSystem(name, true);

			keepGoing = false;
		}
        catch (Exception& e)
        {
            cout << e.what() << endl << "Please enter a different name: ";
        }
	}

	if(choice)
		facebook.getMember(index).getBoard().printStatuses(facebook.getMember(index).getName(), false);
	else 
		facebook.getPage(index).getBoard().printStatuses(facebook.getMember(index).getName(), false);
}
// case 5
void Interaction::show10LastStatusesOfMember(Facebook& facebook)  const 
{
	string memberName;
	string statusContent;
	int index;
	cout << "Please choose the member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the member's name - Case sensitive:" << endl;

	bool keepGoing = true;
	while (keepGoing)
	{
		try
		{
			getline(cin, memberName);
			index = facebook.isMemberInSystem(memberName, true);
			keepGoing = false;
		}
        catch (Exception& e)
        {
            cout << e.what() << endl << "Please enter a different name: ";
        }
	}
	facebook.getMember(index).show10StatusesOfMembers(); 
}
// case 6
void Interaction::createFriendShipBetween2Members(Facebook& facebook) 
{
	string member1Name, member2Name;
	int index1, index2;
	cout << "Please choose the first member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the first member's name - Case sensitive:" << endl;

	index1 = getMemberNameFromUser(facebook);
	member1Name = facebook.getMember(index1).getName();

	cout << "Please choose the second member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the second member's name - Case sensitive:" << endl;

	try 
	{
		index2 = getMemberNameFromUser(facebook);
		member2Name = facebook.getMember(index2).getName();
		areNamesEqual(member1Name, member2Name);
	}
	catch (Exception& e)
	{
		cout << e.what() << endl;
		return;
	}
	
	if (facebook.getMember(index1) += (facebook.getMember(index2)))
	{
		cout << member1Name << " and " << member2Name << " are friends now." << endl;
	}
	else
	{
		cout << "Members are already friends." << endl;
	}
}
// case 7
void Interaction::cancelFriendship(Facebook& facebook) 
{
	string member1Name, member2Name;
	int index1, index2;
	cout << "Please choose the first member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the first member's name - Case sensitive:" << endl;

	index1 = getMemberNameFromUser(facebook);
	member1Name = facebook.getMember(index1).getName();

	cout << "Please choose the second member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the second member's name - Case sensitive:" << endl;

	try
	{
		index2 = getMemberNameFromUser(facebook);
		member2Name = facebook.getMember(index2).getName();
		areNamesEqual(member1Name, member2Name);
	}
	catch (Exception& e)
	{
		cout << e.what() << endl;
		return;
	}

	if (facebook.getMember(index1).areMembersConnected(&(facebook.getMember(index2))) == (int)Answers::NO)
	{
		cout << member1Name << " and " << member2Name << " are not members. Nothing has changed." << endl;
	}
	else
	{
		facebook.getMember(index1).removeMember(&(facebook.getMember(index2)));
		cout << "Membership removal between " << member1Name << " and " << member2Name << " is done." << endl;
	}
}
// case 8
void Interaction::addAMemberToAPage(Facebook& facebook) 
{
	string memberName, pageName;
	int memberIndex, pageIndex;
	cout << "Please choose the member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the member's name - Case sensitive:" << endl;

	memberIndex = getMemberNameFromUser(facebook);
	memberName = facebook.getMember(memberIndex).getName();

	cout << "Please choose the page from the list below." << endl;
	facebook.printAllPagesInTheSystem();
	cout << "Type the page's name - Case sensitive:" << endl;

	pageIndex = getPageNameFromUser(facebook);
	pageName = facebook.getPage(pageIndex).getName();

	if (facebook.getMember(memberIndex) += (facebook.getPage(pageIndex)))
	{
		cout << memberName << " is a fan of " << pageName << " now." << endl;
	}
	else
	{
		cout << "Member " << memberName << " is already a fan of " << pageName << "." << endl;
	}
}
// case 9
void Interaction::removeMemberFromAPage(Facebook& facebook) 
{
	string memberName, pageName;
	int memberIndex, pageIndex;
	cout << "Please choose the member from the list below." << endl;
	facebook.printAllMembersInTheSystem();
	cout << "Type the member's name - Case sensitive:" << endl;
	
	memberIndex = getMemberNameFromUser(facebook);
	memberName = facebook.getMember(memberIndex).getName();

	cout << "Please choose the page from the list below." << endl;
	facebook.printAllPagesInTheSystem();
	cout << "Type the page's name - Case sensitive:" << endl;

	pageIndex = getPageNameFromUser(facebook);
	pageName = facebook.getPage(pageIndex).getName();

	if ((facebook.getPage(pageIndex).isMemberLikedPageAlready(&(facebook.getMember(memberIndex))) == (int)Answers::NO))
	{
		cout << memberName << " is not a fan of " << pageName << ". Nothing has changed." << endl;
	}
	else
	{
		facebook.getPage(pageIndex).removeMember(&(facebook.getMember(memberIndex)));
		cout << "Member " << memberName << " has been removed as a fan of " << pageName << "." << endl;
	}
}
// case 10
void Interaction::showMembersAndPagesInFacebook(Facebook& facebook)	const
{
	cout << endl << "The members in Facebook are: " << endl;
	facebook.printAllMembersInTheSystem();
	cout << endl << "The pages in Facebook are: " << endl;
	facebook.printAllPagesInTheSystem();
}
// case 11
void Interaction::showMembersOfASpecificMemberOrPage(Facebook& facebook) const
{
	string name;
	int index;

	cout << "Would you like to see all members of a member / page? For member type: \"1\" for page type: \"0\": ";

	int choice = getChoiceFromUser((int)UserChoice::PAGE_CHOICE, (int)UserChoice::MEMBER_CHOICE);

	if (choice) // show member members
	{

		cout << "Please choose the member you want to see his members from the list below." << endl;
		facebook.printAllMembersInTheSystem();
		cout << "Type the member's name - Case sensitive:" << endl;

		index = getMemberNameFromUser(facebook);
		name = facebook.getMember(index).getName();

		if (facebook.getMember(index).getMembersSize() == EMPTY)
		{
			cout << "Member " << name << " does not have friends yet." << endl;
		}
		else
		{
			cout << endl << "The members of " << name << " are: " << endl;
			facebook.getMember(index).showAllMembers();
		}
	}
	else // show page members
	{

		cout << "Please choose the page you want to see his members from the list below." << endl;
		facebook.printAllPagesInTheSystem();
		cout << "Type the page's name - Case sensitive:" << endl;

		index = getPageNameFromUser(facebook);
		name = facebook.getPage(index).getName();

		if (facebook.getPage(index).getMembersSize() == EMPTY)
		{
			cout << "Page " << name << " does not have fans yet." << endl;
		}
		else
		{
			cout << "The members are: " << endl;
			facebook.getPage(index).showAllMembers();
		}
	}
}
// case 12
void Interaction::exitMenu() 
{
	cout << "Good bye! See you soon!" << endl;
	setContinueUseFacebook(false);
}

