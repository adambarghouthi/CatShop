
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM ","


//method validPair returns 1 if username & password enterred are valid & 0 otherwise

int validPair(char username[], char pwd[])
{

	FILE *members;
	members=fopen("Members.csv", "r");

	char currLine[3000]; //represents 1 line of members.csv file
	
	while(fgets(currLine, sizeof(currLine), members))
	{
		char *token;
		token=strtok(currLine, DELIM); //token set to 1st element of the current line of members
		token=strtok(NULL, DELIM); //token set to 2nd element of currentl ine, so token=username listed in members.csv

		if(strcmp(username,token)==0) //check if valid username, if valid check password:
		{  
			token=strtok(NULL,DELIM); //make token password stored at current line (3rd entry of currLine)
			char s[2]="\n";
			char *pwdMembers;
			pwdMembers=strtok(token, s); //to remove the \n from the last word in the current line
			if(strcmp(pwd, pwdMembers)==0) //check if user enterred right password
			{
				return 1; //user logged in correctly
			}
		}
	}
	return 0; //invalid username password combination enterred
}

//void main(int argc, char* argv[])
int main()
{

	//initialize variables to textbox inputs 
	//use malloc to initialize these 

	char usernameInputted[50]="saghda";
	char pwdInputted[50]="hello";

	int x=validPair(usernameInputted, pwdInputted);
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



