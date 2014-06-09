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
                        int od1, int od2, int od3, int od4)
{
    
    return 0;
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int ttr_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_right);
}

int ttb1_vector()
{
    
}

int test_tilt_left()
{
  int e=0;
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(0,0,1,1,NULL,2,0,0,0);
  e|=ttl_vector(4,0,1,1,NULL,4,2,0,0);
  e|=ttl_vector(2,0,1,1,NULL,2,2,0,0);
  e|=ttl_vector(0,0,1,1,"Move left without combining",1,1,0,0);
  e|=ttl_vector(0,1,0,1,"Move left without combining",1,1,0,0);
  e|=ttl_vector(1,0,0,1,"Move left without combining",1,1,0,0);
  e|=ttl_vector(4,0,4,4,NULL,8,4,0,0);
  return e;
}

int test_tilt_right()
{
  int e=0;
  e|=ttr_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttr_vector(0,0,0,1,"Value on right stays on right after shift",0,0,0,1);
  e|=ttr_vector(1,0,0,0,"Value on left shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(0,1,0,0,"Value in middle shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttr_vector(1,1,1,1,"Combinations don't cascade",0,0,2,2);
  e|=ttr_vector(0,0,1,1,NULL,0,0,0,2);
  e|=ttr_vector(4,0,1,1,NULL,0,0,4,2);
  e|=ttr_vector(2,0,1,1,NULL,0,0,2,2);
  e|=ttr_vector(4,0,4,4,NULL,0,0,4,8);
  
  return e;
}

int test_tilt_board_left()
{
    
    
}

int main(int argc,char **argv)
{
  int e=0;
  e|=test_tilt_left();
  return e;
}
