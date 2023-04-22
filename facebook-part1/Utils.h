#ifndef __UTILS_H
#define __UTILS_H

#include "Member.h"
#include "Page.h"
#include "Status.h"
#include "Facebook.h"

// This function initials prepared data as instructed
void beforeRun(Facebook& facebook, std::ifstream& inMembersFile, std::ifstream& inPagesFile);
// This function saves the data to files on exit
void saveEntitiesToFile(Facebook& facebook, std::ofstream& outMembersFile, std::ofstream& outPagesFile);
// This function reads the data from files at program start
void readDataFromFiles(Facebook& facebook, std::ifstream& inMembersFile, std::ifstream& inPagesFile);
// This function creates connections between members and pages
void createConnections(Facebook& facebook);
#endif