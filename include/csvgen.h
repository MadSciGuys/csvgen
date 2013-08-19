#ifndef CSVGEN
#define CSVGEN

#define MAXFILENAME 256

#define CSVEXT ".csv"
#define CSVEXTLEN 5

#define INPUT_RECORD_SEPARATOR 0x1E
#define OUTPUT_RECORD_SEPARATOR ','

#define INPUT_GROUP_SEPARATOR 0x1D
#define OUTPUT_GROUP_SEPARATOR '\n'

#define OPEN_ANGLE_REPLACE '{'
#define CLOSE_ANGLE_REPLACE '}'
#define OUTPUT_RECORD_SEPARATOR_REPLACE ';'
#define AMP_ESCAPE "&amp;"
#define PERCENT_ESCAPE "&#37;"

void outputFilename(char *inputfilename, char *outputfilename);
void parseCSV(FILE *inputfile, FILE *outputfile);

#endif
