#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: ./add-nbo file_name1 file_name2\n");
        exit(1);
    }

    uint32_t file1_data, file2_data, result = 0;
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if(file1 == NULL || file2 == NULL){
        printf("File not found.\n");
        exit(1);
    }

    fread(&file1_data, sizeof(file1_data), 1, file1);
    fread(&file2_data, sizeof(file2_data), 1, file2);
    fclose(file1);
    fclose(file2);

    file1_data = ntohl(file1_data);
    file2_data = ntohl(file2_data);
    result = file1_data + file2_data;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", file1_data, file1_data, file2_data, file2_data, result, result);
}