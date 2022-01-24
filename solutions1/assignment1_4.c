#include <stdio.h>
#define HEIGHT 5
#define BASE   9

/*

I was originally going to stipulate that the triangle
should be translating, therefore I've written the the 
code to include an offset, which I'm setting to zero.


               *
              ***
             *****
            *******
           *********
          *         *    
         ***       ***   
        *****     *****  
       *******   ******* 
      ********* *********


 */

void triangle( int offset ) {
  int i,j;
  for( i=HEIGHT; i>0; i-- ) {
    for( j=offset+i-1; j>0; j-- ) {
      putchar(' ');
    }
    for( j=2*(HEIGHT-i)+1; j>0; j-- ) {
      putchar('*');
    }
    putchar('\n');
  }
}


void triangle2( int offset  ) {
  int i,j;
  for( i=HEIGHT; i>0; i-- ) {
    for( j=offset+i-1; j>0; j-- ) {
      putchar(' ');
    }
    for( j=2*(HEIGHT-i)+1; j>0; j-- ) {
      putchar('*');
    }
    for( j=BASE-2*(HEIGHT-i); j>0; j-- ) {
      putchar(' ');
    }
    for( j=2*(HEIGHT-i)+1; j>0; j-- ) {
      putchar('*');
    }
    putchar('\n');
  }

}

int main( ) {
  int offset = 0;
  triangle(HEIGHT*(offset+1));
  triangle2(HEIGHT*(offset));

}
