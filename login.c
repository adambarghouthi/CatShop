
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM ","


int validPairOrNo(char[] username, char[] pwd)
{

	FILE *members;
	members=fopen("members.csv", "r");

	char currLine[3000]; //represents 1 line of members.csv file
	
	while(fgets(currLine, sizeof(currLine), members))
	{
		char *token;
		token=strtok(members, DELIM); //token set to 1st element of the current line of members
		token=strtok(NULL, DELIM); //token set to 2nd element of currentl ine, so token=username listed in members.csv

		if(stringcmp(username,token)==0) //this means the username matched 1 from Members.csv
		{  //now check is password matched
			//if password didn't match: break to return error page
			//if we find password return 1
			token=strtok(NULL,DELIM); //now token is the password of the current line
			char s[2]="\n";
			pwdMembers=strtok(token, s); //to remove the \n from the last word in the current line
			//or pwdMembers=strtok(token, '\n');
			if(stringcmp(pwd, pwdMembers)==0)
			{
				return 1; //user logged in correctly
			}
			
		}
		//if we never returned 1 or broke from while: then username they enterred wasn't found
	
	return 0;
	}

}

//void main(int argc, char* argv[])
int main()
{
	///in MAIN METHOD
	//initialize variables to textbox inputs 
	//C algorithm: takes username & compare it to everything in members.csv 
	//if that is valid- 
	//check is password is valid 
	//LIIMIT username to less than 50 characters
	//use malloc to initialize these 
	
	char usernameInputted[50]="saghda";
	char passwordMembers[50]="hello";

	int x=validPairOrNo(usernameInputted, passwordinputted);
	if(x==1)
	{
		printf("Logged In User \n");
		return 1;
		//add user to logged in users csv
		//print catalogue page
	}
	if(x!=1)
	{
		printf("User Not Found \n");
		return 0;
		//display error page
	}
}



