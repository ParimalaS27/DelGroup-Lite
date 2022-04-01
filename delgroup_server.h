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

void delgroup(char [],char*,char*);
void update_file(char * , char * , int , int, char*, char* );
int primary_group(char[],char *);
