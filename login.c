
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM ","


//method validPair returns 1 if username & password enterred are valid & 0 otherwise

int validPair(char username[], char pwd[])
{

	FILE *members;
	members=fopen("Members.csv", "r");

	char currLine[1000]; //represents 1 line of members file
	
	while(fgets(currLine, sizeof(currLine), members))
	{
		char *token;
		token=strtok(currLine, DELIM); 
		token=strtok(NULL, DELIM); //token points to 2nd element of currLine (the username)

		//check if valid username

		if(strcmp(username,token)==0) 
		{  
			//now check if password is correct
			token=strtok(NULL,DELIM); //make token point to 3rd entry of currLine (the password)
			
			//in csv file (and thus in currLine) the last entry of the line has a \n at the end
			//so password is stored like this: password\n
			//we need to do our string comparison for the password without the \n

			char s[2]="\n"; 
			char *pwdMembers;
			pwdMembers=strtok(token, s); 

			//if passwords match, then user logged in correctly - return 1. 
			if(strcmp(pwd, pwdMembers)==0) 
			{
				fclose(members); 
				return 1; 
			}
		}
	}

	fclose(members);
	return 0; //invalid username password combination entered
}

//void main(int argc, char* argv[])
int main()
{

	//initialize variables to textbox inputs 
	//use malloc to initialize these 

	char usernameInputted[50]="goon";
	char pwdInputted[50]="sanam";

	int x=validPair(usernameInputted, pwdInputted);

	if(x==1)
	{
		printf("Logged In User \n");
		FILE *loggedIn;
		loggedIn=fopen("LoggedIn.csv", "rw");
		//now to apend usernameInputted to LoggedIn.csv
		//print catalogue page
		fclose(loggedIn);
		return 1;
	}

	if(x!=1)
	{
		printf("User Not Found \n");
		return 0;
		//display error page
	}
}



