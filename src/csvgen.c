#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <csvgen.h>

void outputFilename(char *inputfilename, char *outputfilename)
{
	for(unsigned register int i=0;i<251;i++)
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
				strncpy(outputfilename+i,".csv",5);
				*(outputfilename+255) = '\0';
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

void parseCSV(FILE *inputfile, FILE *outputfile)
{
	char cursor;
	do
	{
		cursor = fgetc(inputfile);
		switch(cursor)
		{
		case '#':
		case 0x0D:
			break;
		case 0x1E:
			fputc(',',outputfile);
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
		case 0x0D:
		case '\n':
		case EOF:
			break;
		case 0x1E:
			fputc(',',outputfile);
			break;
		case 0x1D:
			fputc('\n',outputfile);
			break;
		case '<':
			fputc('{',outputfile);
			break;
		case '>':
			fputc('}',outputfile);
			break;
		case ',':
			fputc(';',outputfile);
			break;
		case '&':
			fprintf(outputfile,"&amp;");
			break;
		case '%':
			fprintf(outputfile,"&#37;");
			break;
		default:
			fputc(cursor,outputfile);
			break;
		}
	} while(cursor != EOF);
	return;
}
