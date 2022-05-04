
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED             "\e[0;31m"
#define B_RED           "\e[1;31m"
#define GREEN           "\e[0;32m"
#define B_GREEN         "\e[1;32m"
#define YELLOW          "\e[0;33m"
#define B_YELLOW        "\e[1;33m"
#define BLUE            "\e[0;34m"
#define B_BLUE          "\e[1;34m"
#define MAGENTA         "\e[0;35m"
#define B_MAGENTA       "\e[1;35m"
#define CYAN            "\e[0;36m"
#define B_CYAN          "\e[1;36m"
#define WHITE           "\e[0;37m"
#define B_WHITE         "\e[1;37m"
#define RESET           "\e[0m"



void printImageBytes(unsigned char *buffer, unsigned int len){
  printf("const unsigned char IMAGE = {");
  for(int i = 0; i < len; i++){
    
    if(i == len-1){
      printf("0x%x", buffer[i]);
      break;
    }
    
    printf("0x%x, ", buffer[i]);
  }
  printf("};\n");
}



int main(int argc, char *argv[]){
  
  if((argc == 1) || (strcmp("-h", argv[1]) == 0) || (strcmp("-help", argv[1]) == 0)){
    printf(GREEN "\n----------------------------------------\n\n");
    printf(B_WHITE "Usage: \n");
    printf(B_YELLOW "\t- Print byte array of image:\n");
    printf(YELLOW "\t  imgbyte <path/to/file.extension>\n");
    printf("\n");
    printf(B_YELLOW "\t- Get to this help menu:\n");
    printf(YELLOW "\t  imgbyte -h   ||   imgbyte -help\n");
    printf(GREEN "\n----------------------------------------\n\n");
    return 0;
  }

  FILE *file = fopen(argv[1], "rb");

  if(file == NULL){
    fprintf(stderr, "FILE NOT FOUND!\n");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  const long len = ftell(file);
  fseek(file, 0, SEEK_SET);
  
  unsigned char buffer[len];
  
  fread(buffer, 1, len, file);

  printImageBytes(buffer, len);
  
  return 0;
}