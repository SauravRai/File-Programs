#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define BLOCKSIZE 1000
int jenskin_hash(char*,int);
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
		    hash=jenskin_hash(line, strlen(line));
			printf("The value of the hash function is %d\n",abs(hash));
    		fprintf(fptr, "%d\n", abs(hash));
    	}
	
	free(line);
	fclose(stream);
	fclose(fptr);
return  0;
}

int jenskin_hash(char *line,int count) 
{
	int hash= 0, i;
	for (i= 0; i < count; i++)
	{
   	   	hash += line[i];
  	 	hash += (hash << 10);
      	hash ^= (hash >> 6);
      	printf("%c",line[i]);
	}
   	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	printf("\n");
	return hash;
}
