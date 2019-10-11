#include <stdio.h>


char* encodeFile (int);
void writeFile (char*);
int main (void){
    char* file = "111111111000000000100000000110000001011000011101100111110110111000000000111111111";
    char* compressedFile;
    
    
    int count = 0;
    int count2 = 0;
    char sto = file[0];
    
    for(int i = 0, n = strlen(file); i < n; i++){
        
        if (file[i] == sto){
            count++;
        }
        
        if (file[i] != sto || i == n-1){
            compressedFile = encodeFile(count);
            count2++;
            sto = file[i];
            count = 1;//reset count while includng this iteration
        }
    }
    
    writeFile(compressedFile);
    return 0;
}

char* encodeFile (int count){
    char* compressedFile;
    static int c2 = 0;
    compressedFile[c2] = count + '0';
    c2++;
    return compressedFile;
}

void writeFile (char* compressed){
    FILE *writeFile;
    writeFile = fopen("compressed.txt", "w");
    
    char c;
    int i = 0;
    while((c = compressed[i++]) != '\0'){
      fputc(c, writeFile);
    }

    if(writeFile) fclose(writeFile);
}
