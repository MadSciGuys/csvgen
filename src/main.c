// Travis Whitaker 2013
// twhitak@its.jnj.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <csvgen.h>

int main(int argc,char *argv[])
{
	FILE *inputfile;
	FILE *outputfile;

	char *inputfilename = malloc(256);
	if(inputfilename == NULL)
	{
		printf("Couldn't allocate memory for *inputfilename\nFATAL ERROR\n");
		return 0;
	}
	char *outputfilename = malloc(256);
	if(outputfilename == NULL)
	{
		printf("Couldn't allocate memory for *outputfilename\nFATAL ERROR\n");
		return 0;
	}

	if(argv[1] == NULL)
	{
		printf("Too few arguments\nUsage: csvgen filename\n");
		return 0;
	}
	if(argv[2] != NULL)
	{
		printf("Too many arguments\nUsage: csvgen filename\n");
		return 0;
	}

	strncpy(inputfilename,argv[1],255);
	*(inputfilename+255) = '\0';
	outputFilename(inputfilename,outputfilename);

	inputfile = fopen(inputfilename,"r");
	if(inputfile == NULL)
	{
		printf("Couldn't open %s\nFATAL ERROR\n",inputfilename);
		return 0;
	}
	free(inputfilename);
	outputfile = fopen(outputfilename,"w");
	if(outputfile == NULL)
	{
		printf("Couldn't open %s\nFATAL ERROR\n",outputfilename);
		return 0;
	}
	free(outputfilename);

	parseCSV(inputfile,outputfile);

	fclose(inputfile);
	fclose(outputfile);
	return 0;
}
