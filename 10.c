#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int get_new_input();
int StringToInt();

int main(){
	bool take_inputs=1, first_input=1;
	int last_num, positive=0, negative=0, zeros=0;
	
	while(take_inputs){
		
		//counting up the different numbers
		int curr_num;
		curr_num = get_new_input();
		
		if(curr_num>0)
			positive++;
		else if (curr_num==0)
			zeros++;
		else
			negative++;
			
		if(curr_num==last_num && !first_input)
			take_inputs=0;
		else
			last_num=curr_num;
		
		first_input=0;
	}
	
	//printing out the different amount of ints
	printf("positive: %d \n" "zeros: %d \n" "negative: %d \n", positive, zeros, negative);
	       
	getchar ();
}


int StringToInt(char a[]) {
  int c, sign, offset=0, n;
  bool negative=0;


// check if negative
  if (a[0] == '-') {  
    offset=1;
	negative=1;
  }


  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (negative)
    n = -n;

  return n;
}

int get_new_input(){
	
	char curr_input[20];
	bool error=1;
	
	//nuskaitymas iki kol nuskaitomas teisingas skaicius
		while(error){
			printf("input an integer: \n");
			scanf("%s", curr_input);
			error=0;
			
			//skaiciuojamas input string ilgis
			int len=0;
			while(curr_input[len] != '\0')
				len++;
				
			for(int i=0; i<len; i++){
				//tikriname ar skaicius neigiamas
				if(i==0 && curr_input[0]=='-')
					i++;
					
					//string[] neveike tikrinime todel reikejo pirma pasiversti i char
					char curr_char = curr_input[i];
				if(curr_char<'0' || curr_char>'9'){
					printf("invalid input try again \n");
					error=1;
					break;
				}
			}
		}
		int k = StringToInt(curr_input);
		return k;
}

