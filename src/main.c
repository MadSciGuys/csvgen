// Travis Whitaker 2013
// twhitak@its.jnj.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <csvgen.h>

int main(int argc,char *argv[])
{
	//Pointers for file access:
	FILE *inputfile;
	FILE *outputfile;

	//Allocate memory for file names:
	char *inputfilename = malloc(MAXFILENAME);
	if(inputfilename == NULL)
	{
		printf("Couldn't allocate memory for *inputfilename\nFATAL ERROR\n");
		free(inputfilename);
		return 0;
	}
	char *outputfilename = malloc(MAXFILENAME);
	if(outputfilename == NULL)
	{
		printf("Couldn't allocate memory for *outputfilename\nFATAL ERROR\n");
		free(inputfilename);
		free(outputfilename);
		return 0;
	}

	//Ensure that there is one and only one argument:
	if(argv[1] == NULL)
	{
		printf("Too few arguments\nUsage: csvgen filename\n");
		free(inputfilename);
		free(outputfilename);
		return 0;
	}
	if(argv[2] != NULL)
	{
		printf("Too many arguments\nUsage: csvgen filename\n");
		free(inputfilename);
		free(outputfilename);
		return 0;
	}

	//Copy the argument to *inputfile and compute the output filename:
	strncpy(inputfilename,argv[1],(MAXFILENAME-1));
	*(inputfilename+(MAXFILENAME-1)) = '\0';
	outputFilename(inputfilename,outputfilename);

	//Open the files:
	inputfile = fopen(inputfilename,"r");
	if(inputfile == NULL)
	{
		printf("Couldn't open %s\nFATAL ERROR\n",inputfilename);
		free(inputfilename);
		free(outputfilename);
		return 0;
	}
	free(inputfilename);
	outputfile = fopen(outputfilename,"w");
	if(outputfile == NULL)
	{
		printf("Couldn't open %s\nFATAL ERROR\n",outputfilename);
		free(inputfilename);
		free(outputfilename);
		return 0;
	}
	free(outputfilename);

	//Generate the true CSV file:
	parseCSV(inputfile,outputfile);

	//Close the files:
	fclose(inputfile);
	fclose(outputfile);
	return 0;
}
