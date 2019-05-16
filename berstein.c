#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define BLOCKSIZE 1000
int bernstein_hash(char *,int);
int main(void)
{
	FILE *stream,*fptr;
	char disk_file[256];
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
 	int hash= 0;
	
	stream = fopen("input.txt", "r");
    
    if (stream == NULL)
		exit(EXIT_FAILURE);
 	
	/* Get the output Disk filename from the user */
        printf("Enter your output disk file name:");
        scanf("%s", disk_file);
	
	/* disk file in write mode */
    
    if ((fptr=fopen(disk_file,"w"))==NULL) {
        printf("Unable to open the output file!!\n");
         exit(3);
		}
	
	while ((read = getline(&line, &len, stream)) != -1)
	    {
	    	printf("Retrieved line of length %zu :\n", read);
		    hash=bernstein_hash(line, strlen(line));
			printf("The value of the hash function is %d\n",abs(hash));
    		fprintf(fptr, "%d\n", abs(hash));
    	}
	
	free(line);
	fclose(stream);
	fclose(fptr);
return  0;
}

int bernstein_hash(char *line,int count)
 {
	int hash= 0, i;
		for (i= 0; i < count; i++)
			hash+= ((hash << 5) + hash) + line[i];
	return hash;
 }	
	
	
	
	
