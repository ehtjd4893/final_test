#include <stdio.h>

void fileCopy(char * r, char * g){
	
	// variable
	FILE * root = fopen(r, "rb");
	FILE * goal = fopen(g, "wb");
	FILE * error = NULL;
	char buffer[1024];
	int readCount;
	
	if(root == NULL || goal == NULL) {
		error = fopen("error.txt", "wt");
		fputs("파일을 생성하거나 접근할 수 없습니다.\n", error);
		if (error != NULL) fclose(error);
		return;
	}	// end if
	
	while(1) {
		readCount = fread(buffer, sizeof(char), sizeof(buffer), root);
		if(readCount < sizeof(buffer)) {
			  fwrite(buffer, sizeof(char), readCount, goal);
			  break;
		} else {
			fwrite(buffer, sizeof(char), sizeof(buffer), goal);
		}

	}	// end while

	if (root != NULL) fclose(root);
	if (goal != NULL) fclose(goal);
}

int main(void){

	fileCopy("dog.mp4", "dog_copy.mp4");

	return 0;
}
