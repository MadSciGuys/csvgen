// Travis Whitaker 2013
// twhitak@its.jnj.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <csvgen.h>

//This function computes the output filename:
void outputFilename(char *inputfilename, char *outputfilename)
{
	for(unsigned register int i=0;i<(MAXFILENAME-CSVEXTLEN);i++)
	{
		if(*(inputfilename+i) == '\0')
		{
			break;
		}
		else
		{
			switch(*(inputfilename+i))
			{
			case '.':
				strncpy(outputfilename+i,CSVEXT,CSVEXTLEN);
				*(outputfilename+(MAXFILENAME-1)) = '\0';
				return;
				break;
			default:
				*(outputfilename+i) = *(inputfilename+i);
				break;
			}
		}
	}
	return;
}

//This function generates the true CSV file based on the Informatica-sourced
//CSV-like file, replacing the weird delimiters and escaping or replacing all
//XML-reserved characters:
void parseCSV(FILE *inputfile, FILE *outputfile)
{
	char cursor;
	do
	{
		cursor = fgetc(inputfile);
		switch(cursor)
		{
		case '#':
		case '\r':
			break;
		case INPUT_RECORD_SEPARATOR:
			fputc(OUTPUT_RECORD_SEPARATOR,outputfile);
			break;
		default:
			fputc(cursor,outputfile);
			break;
		}
	} while(cursor != '\n');
	do
	{
		cursor = fgetc(inputfile);
		switch(cursor)
		{
		case '\r':
		case '\n':
		case EOF:
			break;
		case INPUT_RECORD_SEPARATOR:
			fputc(OUTPUT_RECORD_SEPARATOR,outputfile);
			break;
		case INPUT_GROUP_SEPARATOR:
			fputc(OUTPUT_GROUP_SEPARATOR,outputfile);
			break;
		case '<':
			fprintf(outputfile,OPEN_ANGLE_REPLACE);
			break;
		case '>':
			fprintf(outputfile,CLOSE_ANGLE_REPLACE);
			break;
		case ',':
			fputc(OUTPUT_RECORD_SEPARATOR_REPLACE,outputfile);
			break;
		case '&':
			fprintf(outputfile,AMP_ESCAPE);
			break;
		case '%':
			fprintf(outputfile,PERCENT_ESCAPE);
			break;
		case '"':
			fprintf(outputfile,QUOTE_REPLACE);
			break;
		case '\'':
			fprintf(outputfile,APOS_REPLACE);
			break;
		default:
			fputc(cursor,outputfile);
			break;
		}
	} while(cursor != EOF);
	return;
}
