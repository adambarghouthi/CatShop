
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM ","

int main(int argc, char* argv[])
{
	///in MAIN METHOD
	//initialize variables to textbox inputs 
	//C algorithm: takes username & compare it to everything in members.csv 
	//if that is valid- 
	//check is password is valid 
	//LIIMIT username to less than 50 characters
	//use malloc to initialize these 
	char usernameInputted[50]; 
	char usernameMembers[50];

	int x=validPairOrNo(usernameInputted, passwordinputted);
	if(x==1)
	{
		//print catalogue page
	}
	if(x!=1)
	{
		//print error page
	}
}

//this method will check if username & password the user enterred is valid
//returns 1 if yes & adds user to logged in users file 
//displays catalogue page
//returns 0 & displays error page otherwise


int validPairOrNo(char[] username, char[] pwd)
{

	FILE *members;
	members=fopen("members.csv", "r");

	char currLine[3000]; //represents 1 line of members.csv file
	
	while(fgets(currLine, sizeof(currLine), members))
	{
		char *token;
		token=strtok(members, DELIM); //token set to 1st element of the currentl ine of members
		token=strtok(NULL, DELIM); //token set to 2nd element of currentl ine, token=username listed in members.csv

		if(stringcmp(username,token)==0) //this means the username matched 1 from Members.csv
		{  //now check is password matched
			//if password didn't match: break to return error page
			//if we find password return 1



			return 1;
		}
		//if we never returned 1 or broke from while: then username they enterred wasn't found
		//return 0 - 
	return 0;
	}

}



// hello\n 