#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	const char* toWrite = getenv("DOCKER_NAME");
	char timeStr[26];
	struct tm* tm_info;
	time_t timer;

	time(&timer);
	tm_info = localtime(&timer);

	strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

	FILE* fileToWrite = fopen("/write-file/write-file.txt", "a+");
	fputs(toWrite, fileToWrite);
	fputs(" ", fileToWrite);
	fputs(timeStr, fileToWrite);
	fputs("\n", fileToWrite);
	fseek(fileToWrite, 0, SEEK_SET);	
	char c = fgetc(fileToWrite);
	while (c != EOF) {
		printf ("%c", c);
		c = fgetc(fileToWrite);
	}
 		
}
