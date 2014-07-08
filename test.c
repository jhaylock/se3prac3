#include <stdio.h>
#include "2048.h"


int line_vector_test(int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} left yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}

int board_vector_test(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4, int (*func)(int,int *))
{
    int board[16] = {ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4};
    if (msg) printf("%s - ",msg); 
    else {
      printf("Tilting {%d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d} "
              "left yields {%d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d} - ",
             ia1,ia2,ia3,ia4,ib1,ib2,ib3,ib4,ic1,ic2,ic3,ic4,id1,id2,id3,id4,
               oa1,oa2,oa3,oa4,ob1,ob2,ob3,ob4,oc1,oc2,oc3,oc4,od1,od2,od3,od4);
    }
    fflush(stdout);
    func(4,board);
    if ((board[0]!=oa1)||(board[1]!=oa2)||(board[2]!=oa3)||(board[3]!=oa4)||
        (board[4]!=ob1)||(board[5]!=ob2)||(board[6]!=ob3)||(board[7]!=ob4)||
        (board[8]!=oc1)||(board[9]!=oc2)||(board[10]!=oc3)||(board[11]!=oc4)||
        (board[12]!=od1)||(board[13]!=od2)||(board[14]!=od3)||(board[15]!=od4))
      {
        printf("FAILED: {%d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d} "
                "became {%d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d} instead of"
               " {%d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d,\n %d,%d,%d,%d}\n",
               ia1,ia2,ia3,ia4,ib1,ib2,ib3,ib4,ic1,ic2,ic3,ic4,id1,id2,id3,id4,
                board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],
                board[8],board[9],board[10],board[11],board[12],board[13],board[14],board[15],
               oa1,oa2,oa3,oa4,ob1,ob2,ob3,ob4,oc1,oc2,oc3,oc4,od1,od2,od3,od4);
        return -1;
      } 
    printf("PASSED.\n");
    return 0;
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int ttbr_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, tilt_board_right);
}

int ttbl_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, tilt_board_left);
}

int trl90_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, rotate_left90);
}

int trl180_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, rotate_left180);
}

int trl270_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, rotate_left270);
}

int ttbu_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, tilt_board_up);
}

int ttbd_vector(int ia1, int ia2, int ia3, int ia4, 
                        int ib1, int ib2, int ib3, int ib4,
                        int ic1, int ic2, int ic3, int ic4,
                        int id1, int id2, int id3, int id4, char *msg,
                        int oa1, int oa2, int oa3, int oa4,
                        int ob1, int ob2, int ob3, int ob4,
                        int oc1, int oc2, int oc3, int oc4,
                        int od1, int od2, int od3, int od4)
{
    return board_vector_test(ia1, ia2, ia3, ia4, 
                        ib1, ib2, ib3, ib4,
                        ic1, ic2, ic3, ic4,
                        id1, id2, id3, id4, msg,
                        oa1, oa2, oa3, oa4,
                        ob1, ob2, ob3, ob4,
                        oc1, oc2, oc3, oc4,
                        od1, od2, od3, od4, tilt_board_down);
}

int test_tilt_left()
{
  int e=0;
  printf("\nTILT LINE LEFT TESTS:\n");
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(0,0,1,1,NULL,2,0,0,0);
  e|=ttl_vector(4,0,1,1,NULL,4,2,0,0);
  e|=ttl_vector(2,0,1,1,NULL,2,2,0,0);
  //e|=ttl_vector(0,0,1,1,"Move left without combining",1,1,0,0);
  //e|=ttl_vector(0,1,0,1,"Move left without combining",1,1,0,0);
  //e|=ttl_vector(1,0,0,1,"Move left without combining",1,1,0,0);
  e|=ttl_vector(4,0,4,4,NULL,8,4,0,0);
  e|=ttl_vector(2,2,4,4,"Combinations don't cascade 2",4,8,0,0);
  e|=ttl_vector(2,2,4,0,"Combinations don't cascade 3",4,4,0,0);
  return e;
}

int test_tilt_board_right()
{
  int e=0;
  printf("\nTILT BOARD RIGHT TESTS:\n");
  e|=ttbr_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Empty board is empty after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbr_vector(0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,"Value on right stays on right after shift",
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1);
    e|=ttbr_vector(1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,"Value on left shifts to right edge after shift",
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1);
    e|=ttbr_vector(0,0,1,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,1,0,0,"Value in middle shifts to right edge after shift",
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1);
    e|=ttbr_vector(1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4,"Distinct values don't combine",
                    1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4);
    e|=ttbr_vector(1,1,1,1,
                    2,2,2,2,
                    4,4,4,4,
                    8,8,8,8,"Combinations don't cascade",
                    0,0,2,2,
                    0,0,4,4,
                    0,0,8,8,
                    0,0,16,16);
    e|=ttbr_vector(4,0,4,4,
                    4,0,4,4,
                    2,2,0,2,
                    0,0,0,0,"More combine tests",
                    0,0,4,8,
                    0,0,4,8,
                    0,0,2,4,
                    0,0,0,0);
    e|=ttbr_vector(1,0,2,2,
                    4,4,4,4,
                    2,0,2,0,
                    0,0,0,0,"More combine tests",
                    0,0,1,4,
                    0,0,8,8,
                    0,0,0,4,
                    0,0,0,0);
  
  return e;
}

int test_tilt_board_left()
{
    int e=0;
    printf("\nTILT BOARD LEFT TESTS:\n");
    e|=ttbl_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Empty board is empty after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbl_vector(1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,"Value on left stays on left after shift",
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0);
    e|=ttbl_vector(0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,
                    0,0,0,1,"Value of right shifts to left edge after shift",
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0);
    e|=ttbl_vector(0,0,1,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,1,0,0,"Value in middle shifts to left edge after shift",
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0,
                    1,0,0,0);
    e|=ttbl_vector(1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4,"Distinct values don't combine",
                    1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4);
    e|=ttbl_vector(1,1,1,1,
                    2,2,2,2,
                    4,4,4,4,
                    8,8,8,8,"Combinations don't cascade",
                    2,2,0,0,
                    4,4,0,0,
                    8,8,0,0,
                    16,16,0,0);
    return e;
}

int test_rotate()
{
    int e=0;
    printf("\nROTATE BOARD TESTS:\n");
    e|=trl90_vector(1,1,1,1,
                    2,2,2,2,
                    4,4,4,4,
                    8,8,8,8,"Rotate 90 degrees left",
                    1,2,4,8,
                    1,2,4,8,
                    1,2,4,8,
                    1,2,4,8);
    e|=trl90_vector(2,1,2,1,
                    4,8,4,8,
                    1,4,1,4,
                    8,2,8,2,"Rotate 90 degrees left",
                    1,8,4,2,
                    2,4,1,8,
                    1,8,4,2,
                    2,4,1,8);
    e|=trl180_vector(1,1,1,1,
                    2,2,2,2,
                    4,4,4,4,
                    8,8,8,8,"Rotate 180 degrees left",
                    8,8,8,8,
                    4,4,4,4,
                    2,2,2,2,
                    1,1,1,1);
    e|=trl270_vector(1,1,1,1,
                    2,2,2,2,
                    4,4,4,4,
                    8,8,8,8,"Rotate 270 degrees left",
                    8,4,2,1,
                    8,4,2,1,
                    8,4,2,1,
                    8,4,2,1);
    return e;
}

int test_tilt_board_up()
{
  int e=0; 
  printf("\nTILT BOARD UP TESTS:\n");
  e|=ttbu_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Empty board is empty after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbu_vector(1,1,1,1,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Value on top stay on top after shift",
                    1,1,1,1,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbu_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    1,1,1,1,"Value on bottom shift to top edge after shift",
                    1,1,1,1,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbu_vector(1,0,0,0,
                    0,1,0,0,
                    0,0,0,1,
                    0,0,1,0,"Value in middle shifts to top edge after shift",
                    1,1,1,1,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbu_vector(1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4,"Distinct values don't combine",
                    1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4);
    e|=ttbu_vector(8,4,2,1,
                    8,4,2,1,
                    8,4,2,1,
                    8,4,2,1,"Combinations don't cascade",
                    16,8,4,2,
                    16,8,4,2,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbu_vector(0,0,0,4,
                    0,1,2,4,
                    1,1,0,2,
                    0,0,2,2,"More combine tests",
                    1,2,4,8,
                    0,0,0,4,
                    0,0,0,0,
                    0,0,0,0);
  
  return e;
}

int test_tilt_board_down()
{
  int e=0;  
  printf("\nTILT BOARD DOWN TESTS:\n");
  e|=ttbd_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Empty board is empty after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0);
    e|=ttbd_vector(0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    1,1,1,1,"Value on bottom stay on bottom after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    1,1,1,1);
    e|=ttbd_vector(1,1,1,1,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,"Value on top shift to bottom edge after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    1,1,1,1);
    e|=ttbd_vector(1,0,0,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,0,0,1,"Value in middle shifts to top edge after shift",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    1,1,1,1);
    e|=ttbd_vector(1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4,"Distinct values don't combine",
                    1,2,4,8,
                    8,4,2,1,
                    4,2,1,8,
                    2,1,8,4);
    e|=ttbd_vector(8,4,2,1,
                    8,4,2,1,
                    8,4,2,1,
                    8,4,2,1,"Combinations don't cascade",
                    0,0,0,0,
                    0,0,0,0,
                    16,8,4,2,
                    16,8,4,2);
    e|=ttbd_vector(0,0,0,4,
                    0,1,2,4,
                    1,1,0,2,
                    0,0,2,2,"More combine tests",
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,8,
                    1,2,4,4);
  
  return e;
}

////
// WHITE BOX TESTS START HERE

// Testing parse_input() input check
//    6 paths: input: invalid,'l','r','u','d', or blank
int test_parse_input()
{
  printf("\nPARSE INPUT TESTS:\n");
  int e=99;
  
  //path 1 - invalid input
  e=parse_input("x");
  if(e==INVALID_INPUT)
    printf("Path 1 passed\n");
  else
    printf("Path 1 failed\n");  
  
  //path 2 - go left
  e=parse_input("l");
  if(e==GO_LEFT)
    printf("Path 2 passed\n");
  else
    printf("Path 2 failed\n");  
  
  //path 3 - right
  e=parse_input("r");
  if(e==GO_RIGHT)
    printf("Path 3 passed\n");
  else
    printf("Path 3 failed\n");  
  
  //path 4 - up
  e=parse_input("u");
  if(e==GO_UP)
    printf("Path 4 passed\n");
  else
    printf("Path 4 failed\n");  
  
  //path 5 - down
  e=parse_input("d");
  if(e==GO_DOWN)
    printf("Path 5 passed\n");
  else
    printf("Path 5 failed\n");  
  
  //path 6 - blank
  e=parse_input("");
  if(e==GO_NOWHERE)
    printf("Path 6 passed\n");
  else
    printf("Path 6 failed\n");  
  
  return e;
}

//board_create() test path 1: valid input (>=1, <=255)
int test_board_create_PATH_ONE(int size)
{
  int **board=board_create(size);
  if(board!=NULL)
    printf("Path 1 passed\n");
  else
    printf("Path 1 failed\n");
  return 0;
}

//board_create() test path 2: invalid input (<1, >255)
int test_board_create_PATH_TWO(int size)
{
  int **board=board_create(size);
  if(board==NULL)
    printf("Path 2 passed\n");
  else
    printf("Path 2 failed\n");
  return 0;
}

//Testing board_create() size check
//    Boundary Tests for board size check
int test_board_create()
{
  printf("\nBOARD CREATE TESTS:\n");
  test_board_create_PATH_ONE(1);
  test_board_create_PATH_ONE(2);
  test_board_create_PATH_ONE(255);
  test_board_create_PATH_ONE(254);
  test_board_create_PATH_TWO(0);
  test_board_create_PATH_TWO(256);
  return 0;
}

//tilt_line_left() test path 1: valid input (>=1, <=255)
int test_tilt_line_left_PATH_ONE(int length, int *line)
{
  int e = tilt_line_left(length,line);
  if(e==0)
    printf("Path 1 passed\n");
  else
    printf("Path 1 failed\n");
  return e;
}

//tilt_line_left() test path 2: invalid input (<1, >255)
int test_tilt_line_left_PATH_TWO(int length, int *line)
{
  int e = tilt_line_left(length,line);
  if(e==-1)
    printf("Path 2 passed\n");
  else
    printf("Path 2 failed\n");
  return e;
}

//Testing tilt_line_left() length check
//  Boundary tests for line length check
int test_tilt_line_left_WHITE()
{
  printf("\nTILT LINE LEFT BOUNDARY TESTS:\n");
  int line[256] = {0};
  test_tilt_line_left_PATH_ONE(1,line);
  test_tilt_line_left_PATH_ONE(255,line);
  test_tilt_line_left_PATH_ONE(2,line);
  test_tilt_line_left_PATH_ONE(254,line);
  test_tilt_line_left_PATH_TWO(0,line);
  test_tilt_line_left_PATH_TWO(256,line);
  return 0;
}

// WHITE BOX TESTS END HERE
////


int main(int argc,char **argv)
{
  int e=0;
  
  e|=test_tilt_left();
  e|=test_tilt_board_left();
  e|=test_rotate();
  e|=test_tilt_board_right();
  e|=test_tilt_board_up();
  e|=test_tilt_board_down();  
  
  // WHITE BOX TESTS //
  printf("\n****WHITE BOX TESTS****\n");
  e|=test_parse_input();
  e|=test_board_create();
  e|=test_tilt_line_left_WHITE();
  
  return e;
}


