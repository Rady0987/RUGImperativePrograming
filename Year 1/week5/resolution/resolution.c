/* file: resolution.c */
/* author: Radu Rusu (rusu@student.rug.nl) */
/* date: MON OCT 7 2019 */
/* version: 1.0 */
/* Description: This program  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *safeMalloc(int n) {//allocates memory for an array
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

void readArray(char *string){ //reads the imput
	char s,r ;
	int c=0,i=0;
	scanf("%c",&r);
	while(c < 2){
		s=getchar();
		if (s=='~'){
			string[i]=s;
			scanf("%c", &s);
			string[i+1]=s;
			i++;
		}
		if (s>='A' && s<='Z'){
			string[i]=s;
			i++;
		}
		if (s == ']'){
			c++;
		}
	}
}

int checker(char c, char *string){
	int l,ver = 0,rez;
	l=strlen(string);
	
	printf("lenght%d\n",l);
	printf("string%s\n", string);
	ver = 0;
	for(int i=0; i<l; i++){
		printf("i=%d\n",i);
		if (c == string[i]){
			if(string[i-1]=='~'){
				rez++;
			}
			ver++;
		}
		printf("c=%c\n",c);
			printf("stribgi=%c\n",string[i]);
	}
	printf("ver=%d\n",ver);
		if (ver==1){
			rez++;
		}else{
			rez=0;
		}
		if (c=='~' && ver<2){
		rez=-1;
		}
	return rez;		
	}
	


void rezClause(char *src, char *dest, int slength){
	int save;
	dest[0]='[';
	for(int i=0; i<slength; i++){
		for (int j=i+1; j<slength; j++){
			if (src[i]==src[j] && (src[i-1]=='~' || src[j-1]=='~')){
				//printf("src[j%d]=%c\n",j, src[j]);
				//printf("src[i%d]=%c\n",i, src[i]);
				break;
			}
			if (src[i]==src[j] && src[i] != '~' && src[i-1] !='~' && src[j-1]!='~'){
				//printf("src[j%d]=%c\n",j, src[j]);
				//printf("src[i%d]=%c\n",i, src[i]);
				dest[i+1]=src[j];
				dest[i+2]=',';
				save=i+2;
				break;
			}
			}
		if(checker(src[i],src)==1){
			printf("trebuieeeee%c\n", src[i]);
			dest[save+1]=src[i];
			dest[save+2]=',';
			save+=2;
		}else if(checker(src[i],src)<1){
			printf("trebuieeeee%c\n", src[i]);
			dest[save+1]='~';
			dest[save+2]=src[i];
			dest[save+3]=',';
			save+=3;
		}
		
		if(checker(src[i],src)==-1){
		printf("NO RESOLVENT\n");
		exit(0);
		}
	}
	dest[slength-1]=']';
	printf("rez=%s\n", dest);
}			

int main(int argc, char *argv[]) { 
	int l;
	char *str, *rezstr;
	str=safeMalloc((1+52)*sizeof(char));
	rezstr=safeMalloc((1+26)*sizeof(char));
	readArray(str);
	l=strlen(str);
	rezClause(str, rezstr, l);

	return 0;
}	
