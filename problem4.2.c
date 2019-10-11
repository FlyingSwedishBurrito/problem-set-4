#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deCompress (char*);
int main (void){
    char* compressedFile = "991826112431225121399";
    deCompress(compressedFile);
    return 0;
}

void deCompress (char* m){
    int rowCount = 0;//counts up to 9 to put \n in pixel
    
    for (int i = 0, n = strlen(m); i < n; i++){
        int r = m[i] - '0';//takes value of each individual compression value
        for (int q = 0; q < r; q++){//loops value of above
            rowCount++;
            
            if(i%2 == 0){
                printf("1");
            } else {
                printf("0");
            }
            
            if (rowCount == 9){
                rowCount -= 9;
                printf("\n");
            }
            
            
        }
    }
    printf("\n\n");
}
