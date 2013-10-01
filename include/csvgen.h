#ifndef CSVGEN
#define CSVGEN

// Maximum file name length:
#define MAXFILENAME 256

// Extension for output files:
#define CSVEXT ".csv"
#define CSVEXTLEN 5

// Define the record separators for input and output files:
#define INPUT_RECORD_SEPARATOR 0x1E
#define OUTPUT_RECORD_SEPARATOR ','

// Define the group(row) separators for input and output files:
#define INPUT_GROUP_SEPARATOR 0x1F
#define OUTPUT_GROUP_SEPARATOR '\n'

// Define replacements and/or escape sequences to be used
// for XML reserved characters:
#define OPEN_ANGLE_REPLACE "&gt;"
#define CLOSE_ANGLE_REPLACE "&lt;"
#define QUOTE_REPLACE "&quot;"
#define APOS_REPLACE "&apos;"
#define OUTPUT_RECORD_SEPARATOR_REPLACE ';'
#define AMP_ESCAPE "&amp;"
#define PERCENT_ESCAPE "&#37;"

void outputFilename(char *inputfilename, char *outputfilename);
void parseCSV(FILE *inputfile, FILE *outputfile);

#endif
