#include "Utils.h"

using namespace std;
#include <string>
#include "PictureStatus.h"
#include "VideoStatus.h"
#include <fstream>

void beforeRun(Facebook& facebook, ifstream& inMembersFile, ifstream& inPagesFile)
{
	readDataFromFiles(facebook, inMembersFile, inPagesFile);
	createConnections(facebook);
}

void saveEntitiesToFile(Facebook& facebook, std::ofstream& outMembersFile, std::ofstream& outPagesFile)
{
	int i, j = 0;
	int membersSize = facebook.getMembersSize();
	int pagesSize = facebook.getPagesSize();
	outMembersFile << membersSize << endl;
	outPagesFile << pagesSize << endl;

	for (i = 0; i < membersSize; i++)
	{
		outMembersFile << facebook.getMember(i);
	}

	for (j = 0; j < pagesSize; j++)
	{
		outPagesFile << facebook.getPage(j);
	}
}

void createConnections(Facebook& facebook)
{
	int i, j, k, memberIndex, pageIndex = 0;
	int numOfMembers = facebook.getMembersSize();
	int numOfPages = facebook.getPagesSize();

	
	for (i = 0; i < numOfMembers; i++)
	{
		// Add connections between members
		for (j = 0; j < facebook.getMember(i).getNamesOfMembers().size(); j++)
		{
			memberIndex = facebook.isMemberInSystem(facebook.getMember(i).getNamesOfMembers().at(j), true);
			facebook.getMember(i) += facebook.getMember(memberIndex);
		}

		// Add connections between members and pages
		for (k = 0; k < facebook.getMember(i).getNamesOfPages().size(); k++)
		{
			pageIndex = facebook.isPageInSystem(facebook.getMember(i).getNamesOfPages().at(k), true);
			facebook.getMember(i) += facebook.getPage(pageIndex);
		}
	}
}

void readDataFromFiles(Facebook& facebook, ifstream& inMembersFile, ifstream& inPagesFile)
{
	int numOfMembers, numOfPages, i;
	string tmp;

	inMembersFile >> numOfMembers; // gets the numbers of Members in file
	std::getline(inMembersFile, tmp); // for enter
	for (i = 0; i < numOfMembers; i++)
	{
		Member member(inMembersFile);
		facebook.addNewMemberToFacebook(member);
	}

	inPagesFile >> numOfPages; // gets the numbers of Pages in file
	std::getline(inPagesFile, tmp); // for enter
	for (i = 0; i < numOfPages; i++)
	{
		Page page(inPagesFile);
		facebook.addNewPageToFacebook(page);
	}
}