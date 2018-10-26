#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>
#include <time.h>

#define T 35

	int getSize(FILE *file);
	int cipher(BYTE *fileData, int fileSize, char *key);

int main()
{

	FILE *file;

	char key[] = {"Vª╣Ù#A*~#═¸Ù#3¢kéî¤F¾°sú▀wtèklsy±?Çd¤■7┴iß'üÆÍE©æ¬Ë╚░╝Øz?fFò"}; 

	char fileName[] = {"teste.txt"};
	int fileSize;
	BYTE *fileData;

	printf("KEY>>%s\n", key);

		file = fopen(fileName, "rb");

		fileSize = getSize(file);

		fileData = (BYTE *)malloc((fileSize+1)*sizeof(BYTE));

		fread(fileData, fileSize, 1, file);

		fclose(file);

		cipher(fileData, fileSize, key);

	return 0;
}

int cipher(BYTE *fileData, int fileSize, char *key)
{
	int i, j = 0;
	char newFileName[] = {"t3st3.txt"};

	FILE *file = fopen(newFileName, "wb");

	for (i = 0; i < fileSize; ++i){
		fileData[i] = fileData[i] ^ key[j];
		if (j == strlen(key)){ j = 0; }
	}

	fwrite(fileData, 1, fileSize, file);

	free(fileData);
	fclose(file);
	
	return 0;
}

int getSize(FILE *file)
{
	if (file == NULL){
		return 1;
	}
	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	rewind(file);
	return fileSize;
}

