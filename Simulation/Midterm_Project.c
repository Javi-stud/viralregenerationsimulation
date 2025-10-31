
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int rows = 20;
int columns = 20;
int box[20][20];

void Grid() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            box[i][j] = 0; 
        } 
    }
}

void printGrid() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            if (box[i][j]) {
                printf("O ") ;
            } else {
                printf(". ") ;
            } 
        } 
        printf("\n") ;
    }
}

int Neighborscount(int i, int j) {
    int num = 0;
    
    if(i>0 && j>0 && box[i-1][j-1] == 1){
        num++;
    }
    if(i>0 && box[i-1][j] == 1){
        num++;
    }
    if(i>0 && j<columns - 1 && box[i-1][j+1] == 1){
        num++;
    }
    if(j>0 && box[i][j-1] == 1){
        num++;
    }
    if(j<columns - 1 && box[i][j+1] == 1){
        num++;
    }
    if(i<rows - 1 && j>0 && box[i+1][j-1] == 1){
        num++;
    }
    if(i<rows - 1 && box[i+1][j] == 1){
        num++;
    }
    if(i<rows - 1 && j<columns - 1 && box[i+1][j+1] == 1){
        num++;
    }
    
    return num;
}

void newGrid() {

    int num;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            num = Neighborscount(i, j) ;
            
            if(num < 2 || num > 3) {
                box[i][j] = 0;
            } 
            if(num == 3 || num == 2) {
                box[i][j] = 1;
            }
        }
    }
}

int main () {
    int num = 0;
    int stop = 0;
    int virus = 0;
    
    printf("How many viruses do you want alive? (50-400)\n");
    scanf(" %d", &virus) ;
    system("clear") ;
    
    srand(time(0)) ;
    
    Grid() ; 
    
    for(int i = 0; i < virus; i++) {
        int loc1, loc2;
        
        loc1 = rand() % rows;
        loc2 = rand() % columns;
        if (box[loc1][loc2] == 0) {
            box[loc1][loc2] = 1;
        } else {
            i--;
        } 
    } 
    
    printGrid() ;
    
    sleep(1) ;
    
    system("clear") ;
    
    
    while(1) {
        newGrid() ; 
        printGrid() ;  
        
        sleep(1) ;
        system("clear") ;
    }
    
    return 0;
}
    
