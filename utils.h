#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>



// This function sleep the program//
void sleep(size_t m_s){
    m_s = m_s/1000;
    clock_t initial_time = time(NULL); //Tiempo inicial//
    clock_t desired_time = initial_time + m_s ;
    for(clock_t current_time = initial_time; current_time < desired_time; current_time = time(NULL) ){};
}

//selectAWord//

//randomNumber
char list[3][6]={ "", "", ""};


int randomNumber(int maxNumber){
        
        int number = rand()%maxNumber + 1;
        return number;
}

//printFileList//
void printFileList(char* path  ){
        FILE* file =  fopen(path, "r");
        char currentLine[10];

        while (  fscanf(  file, "%s", currentLine ) != EOF  )
        {
                printf("line: %s\n",currentLine );
        }
        
        fclose(file);
}

//This function gets a path file  and select a randon line
// output: "Mexico"
char* selectRandomLine(char* path){
        FILE* file =  fopen(path, "r"); //path file
        char* currentLine  = (char*)malloc(sizeof(char)*10  );
        int number = randomNumber(20);
        int iterator = 1;

        // This bucle run into file and  get the random line
        while (  fscanf(  file, "%s", currentLine ) != EOF  )
        {
                if(iterator == number ){ 
                    return  currentLine;
                }
                
                iterator++;
        }        
}

//Ths function get len
int  len(char* str){
        int tam = 0;
        for( ;*str ; tam++, str++ ){};
        return tam;
}

char* copyStr( char* str){
        char* cmpStr = (char*)malloc(sizeof(char)*len(str));
        for(int i = 0; i<len(str); i++){
                char Caracter = (int)str[i];
                cmpStr[i] =  Caracter;
        };
        return cmpStr;
}

char* encodeCountry(   char* country, int* addresVariable   ){

        //Math for a hint//
        
        int lenght = len(country);
        int nHint =  round(  lenght/3 ) + 1;
        char* encodedStr =  (char*)malloc(sizeof(char)*len(country));
        encodedStr = (char*)malloc(sizeof(char)*len(country));
        *addresVariable = nHint;
        for( int i = 0;  i< len(country); i++  ){
                // encodedStr[i] = '*';
                if(nHint && i%2 == 0){
                        encodedStr[i]  = country[i];
                        nHint--;
                }else{
                        encodedStr[i] = '*';
                }
                
        }
        
        return encodedStr;
}


bool compareIndexCharacterString(char* wordToCheck, int index, char character ){
        return wordToCheck[index] == character  ?  true: false;
}