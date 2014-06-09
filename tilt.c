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

int tilt_board_left(int size,int *board)
{
    tilt_line_left(size, board);
    tilt_line_left(size, board+4);
    tilt_line_left(size, board+8);
    tilt_line_left(size, board+12);
    return 0;
}

int tilt_board_right(int size,int *board)
{
    rotate_left180(size, board);
    tilt_board_left(size,board);
    rotate_left180(size,board);
    return 0;
}

int tilt_board_up(int size,int *board)
{
    rotate_left90(size,board);
    tilt_board_left(size,board);
    rotate_left270(size,board);
    return 0;
}

int tilt_board_down(int size,int *board)
{
    
    return 0;
}

int rotate_left90(int size,int *board)
{
    int oldBoard[size*size];
    int k = 0;
    for(; k<size*size; k++) {
        oldBoard[k] = board[k];
    }
    int i = 0;
    int n = 3;
    while(i<4) {
        board[i] = oldBoard[n];
        i++;
        n+=4;
    }
    n = 2;
    while(i<8) {
        board[i] = oldBoard[n];
        i++;
        n+=4;
    }
    n = 1;
    while(i<12) {
        board[i] = oldBoard[n];
        i++;
        n+=4;
    }
    n = 0;
    while(i<16) {
        board[i] = oldBoard[n];
        i++;
        n+=4;
    }
    return 0;
}

int rotate_left180(int size,int *board)
{
    rotate_left90(size, board);
    rotate_left90(size, board);
    return 0;
}

int rotate_left270(int size,int *board)
{
    rotate_left90(size, board);
    rotate_left90(size, board);
    rotate_left90(size, board);
    return 0;
}