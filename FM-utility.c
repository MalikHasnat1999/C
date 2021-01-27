#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


/* 1-Create File Method */
void create(FILE *fp)
{
    char fname[20];
    char ch;
    char buffer[10];

    printf("\n\tEnter file name >>> ");
    scanf("%s", &fname);
    if((fp = fopen(fname,"w+")) == NULL){
        printf("\n\tError: File already exist");   // Error message
    }
    else{
       	printf("\n\t<<<File created>>>\n"); 	
    }
    fclose(fp);
}


/* 2-removes file */
void  removeFile()
{
    char fname[20];
    int n;
    printf("\n\tFile name >>> ");
    scanf("%s",&fname);

    if((n = remove(fname)) == 0)
    {
        printf("\n\t---File remove successfully---\n");
    }
    else
    {
	printf("\n\tError: ");
        printf("\t%s",fname);         // Error message
        printf(" File does not exist\n");
    }
}


/*3-renaming the file */
void renameFile()
{
    char oldName[20];
    char newName[20];
    int n;
    printf("\n\tcurrent name >>> ");
    scanf("%s", oldName);
    printf("\tNew name >>> ");
    scanf("%s",newName);
    if((n = rename(oldName,newName)) == 0){
        printf("\n\t<<<renamed successfully>>>\n");
    }
    else{
        printf("\n\tError: File dose not exist\n");
    }
}

/* 4-concatenating two files */
void concat()
{
    char f1[20], f2[20];
    char ch;
    FILE *fp1, *fp2;

    printf("\n\tFile1 >>> ");
    scanf("%s",&f1);
    printf("\tFile2 >>> ");
    scanf("%s",&f2);

    if((fp1 = fopen(f1,"r+")) == NULL){
        printf("\n\tError: %s does not exist\n", f1);
        return;
	}
    if((fp2 = fopen(f2,"r+")) == NULL){
        printf("\n\tError: %s does not exist\n", f2);
        return;
	}

    fseek(fp1, 0, SEEK_END);
    while(!feof(fp2))
    {
        ch = fgetc(fp2);
        if(ch == EOF)
            break;
        fputc(ch, fp1);
    }

    printf("\n\t---Merged successfully---\n");

    fclose(fp1);
    fclose(fp2);
}



/* 5-shows details of a file*/
void details(FILE *fp)
{
    char fname[20];
    char *ext;
    char ch[500];
    char c;
    struct stat buffer;
    struct tm dt;
    int lines = 0 ;

    printf("\n\tFile name >>> ");
    scanf("%s",fname);
    if((fp = fopen(fname,"r")) == NULL){
        printf("\n\tError: File does not exist");
        return;
    }

    // file Extention
    printf("\n\tExtention:\t");
    ext = strrchr(fname, '.');
    if(!ext){
        printf("unknown");
    }
    else{
        printf("%s",ext+1);
    }

    //  File size
    stat(fname,&buffer);
    printf("\n\tFile size:\t%d(bytes)",buffer.st_size);

    //  total lines
    rewind(fp);
    while(!feof(fp))
    {
        c = fgetc(fp);
        if(c == '\n')
            lines++;
    }
    printf("\n\tTotal lines:\t%d",lines);

    // Date Created
    printf("\n\tCreation time:\t");
    dt = *(gmtime(&buffer.st_ctime));
    printf("%d-%d-%2d", dt.tm_mday, dt.tm_mon+1, dt.tm_year+1900);

    // permission
    printf("\n\tPermissions:");
    printf("\t%o OR -",buffer.st_mode);
            //user
    if(buffer.st_mode & S_IRUSR)
	printf("r");
    else
	printf("-");
    if(buffer.st_mode & S_IWUSR)
	printf("w");
    else
	printf("-");
    if(buffer.st_mode & S_IXUSR)
	printf("x");
    else
	printf("-");
            //group
    if(buffer.st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");

    if(buffer.st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buffer.st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
            //other
    if( buffer.st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if(buffer.st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if(buffer.st_mode & S_IXOTH)
        printf("x\n");
    else
        printf("-\n");

    fclose(fp);
}

/* 6- changing the permissions of a file rwx*/
void chMode()
{
    char mode[8];
    char fname[20];
    int md;
    FILE *fp;

    printf("\n\tFile name >>> ");
    scanf("%s",&fname);

    if((fp = fopen(fname,"r")) == NULL){
        printf("\n\tError: file does not exist\n");
        return;
    }

    printf("\n\tmode >>> ");
    scanf("%s", &mode);

    md = strtol(mode,0,8);
    if (chmod (fname,md) < 0)
        printf("\n\tError: cannot change mode\n");
    else
        printf("---Permissions changed successfully---\n");
}



int main(int argc, char *argv)
{
    int n;
    FILE *fp;

    printf("_______________________________________________");
    printf("_______________________________________________");

    printf("\n\n\t\t\t\t <<<<| File Manipulation Utility |>>>>\n");

    printf("\n->\t\t1- Create File\n");
    printf("\t\t\t - creates a new file you can choose if you want write within the file or not\n");
    printf("->\t\t2- Remove ile\n");
    printf("\t\t\t - if the file exist in the same directory specify the name\n");
    printf("->\t\t3- Rename File\n");
    printf("\t\t\t - to rename the file write current name and new name of the file\n");
    printf("->\t\t4- Concatenate two Files\n");
    printf("\t\t\t - appends the contents of second file to the first file\n");
    printf("->\t\t5- File details\n");
    printf("\t\t\t - shows different properties(size, lines, file extention etc) of a file\n");
    printf("->\t\t6- Permissions\n");
    printf("\t\t\t - changes file permission you must specify mode in the form of 0777, 0444 etc\n");
    printf("->\t\t0- Exit\n");
    printf("\t\t\t -closes the program\n\n");

	while(1)
	{
	    printf("\nChoose a Option = ");
	    scanf("%d", &n);
	    switch(n)
	    {
		case 0:
		    printf("\n\t\t\t\t\t\t<<<| Good Bye! |>>>\n\n");
		    printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
		    return 0;
		case 1:
		    create(fp);
		    break;
		case 2:
		    removeFile();
		    break;
		case 3:
		    renameFile();
		    break;
		case 4:
		    concat();
		    break;
            	case 5:
               	    details(fp);
               	    break;
            	case 6:
                     chMode();
               	     break;
		default:
		    printf("\n\tWrong selection.\n");
		    break;
	}
    }
}

