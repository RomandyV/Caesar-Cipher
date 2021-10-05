//A Caesar Cipher Program
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	//The encryption table relative from A.
	int cryptionTable[26];
	//The file being read and the file that is being encrypted or decrypted.
	FILE *fileRead, *fileWrite;
	//Array to isolate letters
	char*  key;
	//Used to access the array
	char c,ch;
	//size of the key
	int size;
	//used to keep track of the index of the array.
	int i;
	//used to determine how far the letter is from 'A' or 'a'.
	int j;
	//Used to cycle the cryption table
	int index;
	//Used for the decryption process.
	int match;

	 //Error Check to see if console inputs are invalid (not 5)
	if (argc != 5){
		printf("Invalid input: There should be 5 augments\n");
		exit(1);
	}

	//Gets the file and error Checks to see if the file exists.
	fileRead = fopen(argv[1],"r");
	fileWrite = fopen(argv[3],"w");

	if(fileRead == NULL || fileWrite == NULL){
		printf("File could not be opened!\n");
		exit(1);
	}

	//Gets the user's key and changes the encryption table.
	key = argv[2];
	size = strlen(argv[2]);
	i = 0;
	c = key[i];
	while(i < size){
		//Checks the letter distance relative to A.
		if(isupper(c)){
			j  = c  - 'A';
		}

		if(islower(c)){
			j  = c - 'a';
		}
		//Adds to the table and gets the next index and letter ready.
		cryptionTable[i] = j;
		i++;
		c = key[i];
	} 

	//j is now used to determine the left over letters.
	j = 25;
	//Used to check if j matches any letters that already exist in the array
	int ii;
	//Used to determine if there is already a matching letter.
	int b;

	while ( i < 26){
		//Assume there is currently no matching letter.
		b = 1;
		//Checks to see if j matches with the previous letters
		for (ii = 0; ii<size; ii++){
			if(j == cryptionTable[ii]){
				//When there is a matching letter.
				b = 0;
				break;
			}
		}

		//When there is no matching letter
		if(1 == b){
			cryptionTable[i] = j;
			i++;
		}
		j--;

		}
	//Encrypts or Decrypts according to argument.
	if( strcmp(argv[4], "d") == 0){
		while (fscanf(fileRead, "%c", &c) !=EOF){
			ch = c;
			if (isupper(ch)){
			match = ch - 'A';
			for(index  = 0; index < 26; index++){
				if(cryptionTable[index] == match){
					ch = index + 'A';
				}
			}
		}
	if (islower(ch)){
		match = ch - 'a';
		for(index = 0; index < 26; index++){
			if(cryptionTable[index] == match){
				ch = index + 'a';
				}
			}
		}
			fprintf(fileWrite, "%c", ch);
		}
	}

	if(strcmp(argv[4],"e") == 0){
		while(fscanf(fileRead, "%c", &c) != EOF){
			ch = c;
			if (isupper(ch)){
				index = ch - 'A';
				ch = cryptionTable[index] + 'A';
			}
			if(islower(ch)){
				index =  ch - 'a';
				ch = cryptionTable[index] + 'a';
			}
			fprintf(fileWrite, "%c", ch);
			
		}
		/*fprintf(fileWrite, "\n");
		for (i = 0; i < 26; i++){
			fprintf(fileWrite, "%c", cryptionTable[i] + 65);
		
		}*/
	}

	//End of the program.
	fclose(fileRead);
	fclose(fileWrite);
	return 1;
}












	

