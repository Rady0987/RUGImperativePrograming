/* file: code.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON Sep 23 2019 */
/* version: 1.0 */
/* Description: This program simulates the execution of a machine code program that consists of some instructions.*/

#include <stdio.h>
#include <stdlib.h>

void LCS(int n, int *R){ //loads a value n in the specified register
	*R=n;
}

void OUT(int Rx){ //prints the value of the corresponding register on the output 
	printf("%d\n", Rx);	
}

void INC(int *Rx){ //increments the value of the specified register
	*Rx=*Rx+1;
}

void DEC(int *Rx){ //decrements the value of the specified register
	*Rx=*Rx-1;
}

void ADD(int Rx, int *Ry){ //Ry = Rx + Ry
	*Ry=*Ry+Rx;
}

void SUB(int Rx, int *Ry){ //Ry = Rx - Ry
	*Ry=Rx-*Ry;
}

void MUL(int Rx, int *Ry){ //Ry = Rx * Ry
	*Ry=Rx*(*Ry);
}

int main(int argc, char*argv[]){
	int R1,R2,n,numRx,numRy;
	char function,findR;
	while(function !='E'){ //until it isn't introduces "END" loops
		scanf("%c",&function); //gets the first letter of the function name
		findR ='\0'; numRx=0; //resets the values 
		if ((function=='S') || (function=='M') || (function=='A')){ //in case of functions with 3 atributes
			while (findR != 'R'){ //skips all the characters until first "R"
				findR=getchar();
			}
			scanf("%d",&numRx); //scans Rx
			getchar(); //skips 2 characters
			getchar();
			scanf("%d",&numRy); // scans Ry
		}
		if ((function=='I') || (function=='O') || (function=='D')){ //in case of functions with 2 atributes
			while (findR != 'R'){ //skips all the characters until first "R"
				findR=getchar(); //reads every character
			}
			scanf("%d",&numRx);	// scans Rx
		}
		if (function=='L'){ //in cacs LCS function
			while (findR != 'R'){
				findR=getchar();
			}
			scanf("%d",&numRx); //scans Rx
			getchar();
			scanf("%d",&n); //scans the constant "n"
		}
		switch (function){ //cases with all functions
		case 'L': // LCS trigger
			if (numRx==1){ // in case imput goes to R1
				LCS(n,&R1);
			}
			if (numRx==2){ // in case imput goes to R2
				LCS(n,&R2);
			}
			break;
		case 'O': //OUT trigger
			if (numRx==1){
				OUT(R1);
			}else{
				OUT(R2);
			}
			break;
		case 'I':  //INC trigger
			if (numRx==1){
				INC(&R1);
			}else{
				INC(&R2);
			}
			break;
		case 'D': //DEC trigger
			if (numRx==1){
				DEC(&R1);
			}else{
				DEC(&R2);
			}
			break;
		case 'A': //ADD trigger
			if ((numRx==1) && (numRy==2)){ //in case imput is ADD R1 to R2
				ADD(R1, &R2);
			}else if (numRx == 1 && numRy == 1){ //in case imput is ADD R1 to R1
				ADD(R1, &R1);
			}else if (numRx == 2 && numRy == 2){ //in case imput is ADD R2 to R2
				ADD(R2, &R2);
			}else if ((numRx==2) && (numRy==1)){ //in case imput is ADD R2 to R1
				ADD(R2, &R1);
			}
			break;
		case 'S':  //SUB trigger
			if ((numRx==1) && (numRy==2)){ //similar to ADD
				SUB(R1, &R2);
			}else if (numRx == 1 && numRy == 1){
				SUB(R1, &R1);
			}else if (numRx == 2 && numRy == 2){
				SUB(R2, &R2);
			}else if ((numRx==2) && (numRy==1)){
				SUB(R2, &R1);
			}
			break;
		case 'M': 
			if ((numRx==1) && (numRy==2)){ //similar to MUL
				MUL(R1, &R2);
			}else if (numRx == 1 && numRy == 1){
				MUL(R1, &R1);
			}else if (numRx == 2 && numRy == 2){
				MUL(R2, &R2);
			}else if ((numRx==2) && (numRy==1)){
				MUL(R2, &R1);
			}
			break;
		case 'E': //if it reads "END"
			break;
		}
	}
	return 0;
}
