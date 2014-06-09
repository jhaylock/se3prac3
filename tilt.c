#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int i = 0;
  while(i<length) {
    int j = i;
    while(j>=0 && line[j] == 0 && line[j+1] >0) {
	  line[j] = line[j+1];
	  line[j+1] = 0;
	j--;
    }

    if(line[j] >0 && line[j] == line[j+1]) {
	line[j] = line[j]*2;
	line[j+1] = 0;
    }

    i++;
  }
  
  


  return 0;
}

int tilt_line_right(int length,int *line)
{
    
 return 0;  
}

