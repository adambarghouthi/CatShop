
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM1 ","
#define DELIM2 "\n"
#define DELIM3 "&"
#define DELIM4 "="


//function validPair takes in two char arrays & checks if they make valid username pwd pair
//if valid: appends username to LoggedIn.csv & returns 1. else: return 0

int validPair(char username[], char pwd[])
{

	FILE *members;
	members=fopen("../members.csv", "rt");

	char currLine[1000]; //represents 1 line of members file
	
	while(fgets(currLine, sizeof(currLine), members))
	{
		char *token;
		token=strtok(currLine, DELIM1); 
		token=strtok(NULL, DELIM1); //token points to 2nd element of currLine (the username)

		//if username is valid, check password

		if(strcmp(username,token)==0) 
		{  
			//now check if password is correct
			token=strtok(NULL,DELIM1); //make token point to 3rd entry of currLine (the password)
			
			//in csv file (and thus in currLine) the last entry of the line has a \n at the end
			//so password is stored like this: password\n
			//we need to do our string comparison for the password without the \n

			char *pwdMembers;
			pwdMembers=strtok(token, DELIM2); 

			//if passwords match, then user logged in correctly, append username to LoggedIn.csv and return 1. 
			if(strcmp(pwd, pwdMembers)==0) 
			{
				FILE *loggedIn;
				loggedIn=fopen("../LoggedIn.csv", "a");
				fclose(loggedIn);
				fclose(members); 
				return 1; 
			}
		}
	}

	fclose(members);
	return 0; //invalid username password combination entered
}


int main(void)
{
	int length=atoi(getenv("CONTENT_LENGTH"));

	//create space to store whole string, then space to store the inputted username & passwords
	char *data=malloc(sizeof(char)*(length+1))); 
	char *usernameIn=malloc(100*sizeof(char));
	char *pwdIn=malloc(100*sizeof(char));

	char *tokenU; //for username partition
	char *tokenP; //for password partition
	char *token1;
	char *token2;
	int j=0;
	char c=getchar();

	//first we read each char into data array & then add null char to end

	while(c!=EOF && j<length)
	{
		data[j]=c;
		c=getchar();
		j++;
	}
	data[j]='\0';

	//data is now int his form: "username=usernameIn&password=pwdIn\0"
	//tokenize data to separate username and password
		
	tokenU=strtok(data,DELIM3); //tokenU points to this "username=usernameIn"
	tokenP=strtok(NULL,DELIM3); //tokenP points to this "password=pwdInputted"
	
	token1=strtok(tokenU,DELIM4); //token1 points to "username"
	usernameIn=strtok(NULL,DELIM4); //usernameIn points to usernameInputted
	//printf("%s\n",usernameIn); 
	
	token2=strtok(tokenP,DELIM4); //token2 points to "password"
	pwdIn=strtok(NULL,DELIM4); //this gets pwdIn\0
	//printf("%s\n",pwdIn);
	
	//now that username and password inputted variables are set, we call our validPair function
	
	int x=validPair(usernameIn,pwdIn);
	
	//should we make these html prints like this:
	//printf("%s\n\n","Content-type:text/html\n\n");
	
	if(x==1)
	{
		printf("Content-type:text/html\n\n");
		printf("<html>");
		printf("<head>");
		printf("<body>");
		printf("<input type=\"hidden\" name=\"usernameIn\">");//inserts hidden field, assigns usernameIn to field
		printf("<p>Link to CAT-alogue. Happy shopping!</p>");//display catalogue page instead of this
	
	}
	
	else
	{
		printf("Content-type:text/html\n\n");
		printf("<html>");
		printf("<head>");
		printf("<title>The CatShop</title>");
		printf("<body>");
		printf("<p>Sorry. The username & password combination you entered is incorrect.</p>");
		printf("<br>");
		printf("<p>Link to login, link to home.</p>"); //need these links!
	}
	
	printf("</body>");
	printf("</head>");
	printf("</html>");
	return 0;

}



