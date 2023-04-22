using namespace std;
#pragma warning (disable: 4996)
#include <iostream>
#include "Utils.h"
#include "Interaction.h"
#include <fstream>

int main()
{	
	Facebook facebook;
	Interaction interaction;
	ifstream inMembersFile("members.txt");
	ifstream inPagesFile("pages.txt");

	beforeRun(facebook, inMembersFile, inPagesFile);
	interaction.Menu(facebook);
	ofstream outMembersFile("members.txt", ios::trunc);
	ofstream outPagesFile("pages.txt", ios::trunc);
	saveEntitiesToFile(facebook, outMembersFile, outPagesFile);
	
    outMembersFile.close();
	outPagesFile.close();
 	inMembersFile.close(); 
	inPagesFile.close();
}