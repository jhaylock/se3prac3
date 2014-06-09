#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int i = 0;
  int j = i;
  while(i<length) {
    while(j>=0 && line[j] == 0 && j+1 < length && line[j+1] >0) {
	  line[j] = line[j+1];
	  line[j+1] = 0;
	j--;
    }
    //combining
    if(j>=0 && j+1 < length && line[j] >0 && line[j] == line[j+1]) {
	line[j] = line[j]*2;
	line[j+1] = 0;
    }

    i++;
    j=i;
  }
  
  


  return 0;
}

int tilt_line_right(int length,int *line)
{
    
 return 0;  
}

int tilt_board_left(int size,int *board)
{
    tilt_line_left(size, board);
    tilt_line_left(size, board+4);
    tilt_line_left(size, board+8);
    tilt_line_left(size, board+12);
    return 0;
}

int rotate_left90(int size,int *board)
{
    
}