/*

Project 01

Digital Clock

*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



void digitprint(char digit, int position, int color);                                       //Function prototype
void colon(int position, int color);
int place(int position);
int colorDigit(char* input);
void printClock(int color);

int main(int argc, char *argv[]){
  
  int option;
  
  int flagCount=0;                                                                              //This varaible return value of switch loop which is inside getopt function

  int clockColor;
  int cLength=0;

//Execute program with flags

while((option= getopt(argc,argv, ":ch"))!= -1){
  
  switch(option){
 
  
  case 'c':                                                   //-c flag
  
  flagCount=1; 
  
  for(int j=0; j<argc-1; j++){                            //Count -c 
  if(strcmp(argv[j], "-c")==0){
  cLength++;
  }
  }
  
  for(int i=argc-1; 0<=i; i--){                               //Search from end to begin of arguments to display clock with last color entered with -c flag
  if(strcmp(argv[i], "-c")==0){
  if(argc ==i+1){                                             //If only c flag is give as last argument  " -c "  print usage 
  
  
  printf("Invalid use of arguments\n");
  printf("usage : colck -h                quick help on cmd\n");
  printf("usage : clock -c <color>        print colck with a color\n");
  return 0; 
  
  }
  
  
  else if (argc!=i+1){                                             //if -c flag given before the last argument
  
  clockColor = colorDigit(argv[i+1]);
                                                   
  if(clockColor == 10){                //check whether next argument is color or not
  
  printf("%s :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n", argv[i+1]); 
  return 0;
  }
   

   else{                  //if next argument is not a color , print usages
   printClock(clockColor);
   return 0;
   } 
   }
   }
   }
  
  break;
  

  case 'h':                                                  //-h flag     
  
  flagCount=2;   
   
  printf("usage : colck -h                quick help on cmd\n");                                       //print help usage menu
  printf("usage : clock -c <color>        print colck with a color\n");
  printf("<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n");  
  return 0;                                               
  break;
  
  
  case '?':                                                 //-x(any other flag)
  
  flagCount=3;  
  
  printf("Invalid use of arguments\n");                                                             //print usage with error message
  printf("usage : colck -h                quick help on cmd\n");
  printf("usage : clock -c <color>        print colck with a color\n");     
  return 0;                                            
  break;
  
   
  }
  }
  
  
  if(flagCount==0){                                                //Default White clock ( when there are no flags)
  
  printClock(7);
  }
  
  
  
  return 0;
  
  }
  
  
  



// Digit print function
//This function print digits of clock

void digitprint(char digit,int position, int color){
    
    int digitArray[5][6];{}
 
if(digit==':'){

    colon(position, color);  //print colon at it's position
    
    }
    
    
else{
    
   if(digit=='0'){
		 int digitArray0[5][6]={			// 0
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
  memcpy(digitArray, digitArray0, 5*6*sizeof(int));
	}

	else if(digit=='1'){
		 int digitArray1[5][6]={			// 1
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
  memcpy(digitArray, digitArray1, 5*6*sizeof(int));
	}

	else if(digit=='2'){
		 int digitArray2[5][6]={			// 2
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1}
	};
  memcpy(digitArray, digitArray2, 5*6*sizeof(int)); 
	}

	else if(digit=='3'){
		 int digitArray3[5][6]={			// 3
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
 memcpy(digitArray, digitArray3, 5*6*sizeof(int));
	}

	else if(digit=='4'){
		 int digitArray4[5][6]={			// 4
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
 memcpy(digitArray, digitArray4, 5*6*sizeof(int));
	}

	else if(digit=='5'){
		 int digitArray5[5][6]={			// 5
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
 memcpy(digitArray, digitArray5, 5*6*sizeof(int));
	}

	else if(digit=='6'){
		 int digitArray6[5][6]={			// 6
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
 memcpy(digitArray, digitArray6, 5*6*sizeof(int));
	}

	else if(digit=='7'){
		 int digitArray7[5][6]={			// 7
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
 memcpy(digitArray, digitArray7, 5*6*sizeof(int));
	}

	else if(digit=='8'){
		 int digitArray8[5][6]={			// 8
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
 memcpy(digitArray, digitArray8, 5*6*sizeof(int));
	}

	else if(digit=='9'){
		 int digitArray9[5][6]={			// 9
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
 memcpy(digitArray, digitArray9, 5*6*sizeof(int));
	}
 
 
 
 for(int row=0; row<5; row++){
 for(int column=0; column<6; column++){
 
 printf("\033[%d;%dH", row+2, column+place(position)); //cursor adjusment
 
 if(digitArray[row][column]==1){
 
 printf("\033[4%dm", color);  //color setting for digits
 printf(" ");
 printf("\033[0m");   //reset after printing
 
 }
 
 else if(digitArray[row][column]==0){
 
 printf(" ");
 
 }
 }
 
 printf("\n");
 
}
}
}


 



//Function for printing colon
//this function prints colon of the clock

void colon(int position, int color){


int colon[5][6]={    //:
	{0,0,0,0,0,0},
	{0,0,1,1,0,0},
	{0,0,0,0,0,0},
	{0,0,1,1,0,0},
  {0,0,0,0,0,0}
};

for(int row=0; row<5; row++){
for(int column =0; column<6; column++){

printf("\033[%d;%dH", row+2, column+position); //cursor adjustment


if(colon[row][column]==1){


 printf("\033[4%dm", color);   //color ssetting for colon
 printf(" ");
 printf("\033[0m");   //reset color after printing
 }
 
 else if(colon[row][column]==0){
 printf(" ");
 }
 }
 
 printf("\n");
 
 }
 }






// finding digit's place
// This function return position of digits in clock


int place(int position){



if(position==0){
   return 2;
   }
   
else if(position==1){
   return 9;
   }
   
   
else if(position==3){
   return 21;
   }
   
else if(position==4){
   return 28;
   }
   
else if(position==6){
   return 40;
   }
   
else if(position==7){
   return 47;
   }
   
return 0;
}





// Determine the color of digits
//This function determine whether the entered argument is color, if not return 10

int colorDigit(char* input){

char*colors[256] ={"black","red","green","yellow","blue","magenta","cyan","white"}; // available colors

int count;

for(int i=0 ; i<8; i++){
if(strcmp(input, colors[i])==0){
   count = i;
   return count;
  }
  
}
return 10;     //if not in colors return 10 
}








//Function to print clock with given color

void printClock(int color){

  char timeArray[256];                                                                     //Initializing string for time
  char dateArray[256];                                                                     //Initializing array for date
  /*
  int color;

  color=colorDigit(colorStr);        //determine color
  */
printf("\033[1;1H\033[2J");                      //clear screen
printf("\033[?25l");                             //Hiding th cursor
  
   
   
//print current time
  
while(1){  


  time_t timeNow;
  timeNow=time(NULL);

     
     strftime(timeArray,256, "%X\n",localtime(&timeNow) );                       //current time as string
                                         
     
     strftime(dateArray,256, "%Y-%m-%d\n",localtime(&timeNow) );                 //current date time as string
     
                
       
     //Printing date
     
     printf("\033[8;23H");   //bring cursor under the time
     
     printf("\033[3%dm", color);
     printf("%s\n", dateArray);
     printf("\033[37m");
     
     
     //Print time in with digitprint function
     
     
     for(int i=0; i<2; i++){
     digitprint(timeArray[i],i,color);
     }
     
     digitprint(timeArray[2],15,color);
     
     for(int i=3; i<5; i++){
     digitprint(timeArray[i],i,color);
     }
     
     digitprint(timeArray[5],34,color);
     
     for(int i=6; i<8; i++){
     digitprint(timeArray[i],i,color);
     }
  
    printf("\n");
         
        sleep(1);   //wait 1 second 
    }   
system("clear");



}




































