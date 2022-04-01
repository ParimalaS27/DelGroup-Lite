//PROGRAMME TO MIMIC THE "delgroup" COMMAND IN LINUX USING C

/*This program asks the user to input a groupname and the group's information from the two files named
group,gshadow will be removed.If the group is not present it will not edit the file.If present , it deletes 
the references to the group if its not the users primary group.*/

/*STEPS TO BE FOLLOWED BEFORE AND DURING EXECUTION
1. Place group,gshadow and password files in the path provided by environment variable PFILE. Put the files in that specific folder.
2. In case of Windows, it is by default set as PFILE = C:\PESU. It can be changed if user wishes.
3. For Ubuntu user, the provision has been done to change the value of the environment variable as per their file path in ubuntu.
The corresponding code line is commented.Just uncomment it to run on Ubuntu
4. Command for executing make file on windows: 
mingw32-make -f makefile_windows.mak
on Ubuntu: make -f makefile_ubuntu.mk 
5.Two makefiles have been made : one for ubuntu with file extension .mk and one for windows with file extension .mak.
6. After executing this line, enter delgroup <groupname> to view the required results for windows. Enter _delgroup_ <groupname> for Ubuntu. 
Here, the first word is changed because if we enter “delgroup” in ubuntu , Linux will consider the system command delgroup and not our executable file.
*/


#include"delgroup_server.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])						//main function takes the groupname as the main command line argument
{  
  char *temp,*groupname;						//pointer variable declared to store groupname and environment variable value 
  char p_group [80], p_gshadow [80];					//variables to store path of files
  
  if(argc==2)								//Validation of Input entered
  	groupname = argv[1];
  else if(argc<2)							//Handling error when there are less no of arguments
  {
    printf("INVALID INPUT : Less Arguments given!\n Key in the command in the format\n delgroup groupname");
    exit(1);
  }
  else 									//Handling error when there are more no of arguments
  {
    printf("INVALID INPUT : Too Many Arguments given!\n Key in the command in the format\n delgroup groupname");
    exit(1);
  }
  putenv("PFILE=C:\\PESU");						//setting the environment variable by default to C:\PESU in case of windows
									 
  //setenv("PFILE","\\home\\desktop",1);				
									/*uncomment the above statement to make it work absolutely error free
									 on Ubuntu - setting a diffrent suitable PFILE value for Ubuntu*/
  if ((temp = getenv ("PFILE")) == NULL)
    {
        printf ("The environment variable PFILE has not been set\n");	//error handling if PFILE is not set
        exit (1);
    }
  sprintf (p_group, "%s\\%s", temp, "group");				//Setting the path-filenames of group and gshadow to PFILE
  sprintf (p_gshadow, "%s\\%s", temp, "gshadow");
  
  delgroup(groupname,p_group,p_gshadow);				//Function Call to delgroup
  return 0;
}
