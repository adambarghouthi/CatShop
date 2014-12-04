
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


//to accept input via CGI. POST method
//from: http://www.cs.tut.fi/~jkorpela/forms/cgic.html 

void unencode(char *src, char *last, char *dest)
{
 for(; src != last; src++, dest++)
   if(*src == '+')
     *dest = ' ';
   else if(*src == '%') {
     int code;
     if(sscanf(src+1, "%2x", &code) != 1) code = '?';
     *dest = code;
     src +=2; }     
   else
     *dest = *src;
 *dest = '\n';
 *++dest = '\0';
}

//void main(int argc, char* argv[])

int main()
{

	//initialize variables to textbox inputs 
	//use malloc to initialize these 

	long len; 

	char usernameInputted[50]="goon";
	char pwdInputted[50]="sanam";

	int x=validPair(usernameInputted, pwdInputted);

	if(x==1)
	{
		printf("Logged In User \n");
		FILE *loggedIn;

		loggedIn=fopen("LoggedIn.csv", "w+");

		//append usernameInputted to LoggedIn.csv
		fprintf(loggedIn, "%s", usernameInputted);
		fprintf(loggedIn, "s", ",");
		fclose(loggedIn);

		//print catalogue page

		printf("Content-type: text/html\n\n");
		printf("<html>")

		//print catalogue page


		printf("</html>")
		return 1;
	}

	if(x!=1)
	{
		//create error page

		printf("User Not Found \n");
		printf("Content-type: text/html\n\n");
		printf("<html>")

		
		printf("</html>'')
		return 0;
		
	}
}



