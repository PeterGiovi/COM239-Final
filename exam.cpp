int main(void){
	
	int minOut = 0;
	int maxOut = 12;

	int e; //the number of exams.
	int n; //the number of questions.
	int d = 64; //the detail value.
	int q; // the value of the current number being generated.

	printf("How many exams do you want? ");
	scanf("%d", &e);
	printf("How many questions do you want per exam? ");
	scanf("%d", &n);

	int exams[e][n][2]; //creates 'e' exams with 'n' questions of '2' numbers in an array.
	int examSeed[e]; //creates an array to store the exam seeds in.

	for(int i = 0; i < e; i++){//loop cycles for each exam.
		examSeed[i] = time(0);//seed generation for exam.
		srand(examSeed[i]);
		examSeed[i] = rand() + d;

		for(int j = 0; j < n; j++){//loop cycles for each question.
			exams[i][j][0] = ((( examSeed[i] + d) + 64) % maxOut) + minOut;
			if(exams[i] != 0 && exams[i][j][0] == exams[i][j - 1][0])
				exams[i][j][0] = (exams[i][j][0] + d) % maxOut;
			exams[i][j][1] = (((examSeed[i] + (d + exams[i][j][0 + 1])) + 64) % maxOut) + minOut;
			if(exams[i] != 0 && exams[i][j][1] == exams[i][j - 1][1])
				exams[i][j][1] = (exams[i][j][1] + d) % maxOut;
			d += exams[i][j][1];
		}
	}
	for(int i = 0; i < e; i++){ //print method for testing purposes.
		printf("Seed for exam %d: %d\n\n", i + 1, examSeed[i]);
		for(int j = 0; j < n; j++){
			printf("Q%d) %d X %d = ____\n", j, exams[i][j][0], exams[i][j][1]);
		}
	}
}