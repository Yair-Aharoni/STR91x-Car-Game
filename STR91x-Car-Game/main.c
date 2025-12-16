
#include <91x_lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LED GPIO7->DR[0x3FC]
#define SW GPIO3->DR[0x3FC]

int measure(void);
void dly(int i);
int clear (int R);

 
 void dly(int i)  //dly func
{
 int j,k;
 for (j=1;j<100;j++)
 {
 for(k=0;k<i;k++);
 }
}

       int measure(void) // a to d converter
{
 ADC->CR         &= 0xFF7f;
      ADC->CR         = 0x0002;

      ADC->CR         |= 0x0001;
dly(100);

      while( ((ADC->CR) & 0x8000)==0); // wait for end of converge

       return ((ADC->DR0) & 0x03FF);
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////
int MoveCar (int R)    //moving the car between line '0' and '1'
 {
    if (R==0)
     {
       lcd_clear();
       R++;
     }
    else
     {
       lcd_clear();
       R--;
     }
  return R;
 }
int MoveBlock (int rb)   //randomly putting block in lines '0' or '1'
{
int rowrand;
int rand();

rowrand=rand();
if (rowrand % 3 == 0)
rb= 0;
else
rb =1;
return rb;
}


void Clean(cb,rb)   //cleans the last position of the blocks
{
set_cursor(cb,rb);
lcd_putchar(0x20);
}

int Crash(int R, int rb,int lives) //if there is a crash lower lives
{
if (R==rb)
{
lives--;
LED=255;
dly(20000);
}
return lives;
}

int main (void)
{
    unsigned int R=0,lives=3 ,rb=0,cb=16,cb2=7,rb2=0,td=10000, NLED=1,i=0,score=0,lives2; //rb-block row,cb-block collum ,NLED-led moving lights;
    float v=0;
    char car='>',block1='#',block2='*',str [12];

    int rand();
    Intio();
    Int_a2d();
    lcd_init();
    lcd_write_cmd(0xc);

      set_cursor(0,0);
      lcd_print("Welcome to");       //start menu
      set_cursor(0,1);
      lcd_print("!!CAR GAME!!");
      dly(30000);
      lcd_clear();
      set_cursor(0,0);
      lcd_putchar(car);
      set_cursor(cb,rb);
      lcd_putchar(block1);
 while (lives != 0)//game loop runs until you loose 3 times
 {
    v=measure();
td=10000/v;
  if (cb != 0 && cb2!=0)//
{
               //td=10*v;//if enable ..the more voltage you give the slower the pace
td= 1000000/(v+10);
LED = NLED;
NLED*=2;
if (NLED==256) NLED=1;
if((SW&0x40) == 0)//if buttom clicked car switch lines
           {
    dly(6000);
             R=MoveCar(R);
             set_cursor(0,R);
             lcd_putchar(car);
           }
    Clean(cb,rb);
    cb--;
    set_cursor(cb,rb);
    lcd_putchar(block1);
dly(td);
          Clean(cb2,rb2);
    cb2--;
    set_cursor(cb2,rb2);
    lcd_putchar(block2);
dly(td);

}
if((SW&0x20) == 0)score++;//cheats(bonus points***************)
  if (cb == 0 || cb2 == 0)//
 {
if (cb==0)
 {
  dly(td);
  lives2=lives;
  lives = Crash (R,rb,lives);
  Clean(cb,rb);
  cb=15;
  rb = MoveBlock(rb);

if (lives2!=lives)score=score;
else score++;
 }
if(cb2==0)
 {
  dly(td);
  lives2=lives;
  lives = Crash (R,rb2,lives);
  Clean(cb2,rb2);
       cb2=15;
  rb2 = MoveBlock(rb2);

if (lives2!=lives)score=score;
else score++;
    }
set_cursor(0,R);
         lcd_putchar(car);
}
 }
lcd_clear();
while(i<3)//at the end of the game the lights blink 3 times
{
LED=255;
dly(10000);
LED=0;
dly(10000);
i++;
}
LED=255;
dly(20000);
LED=255;
dly(200);
set_cursor(3,0);
lcd_print("Game Over");
set_cursor(0,1);
lcd_print("score:");
sprintf(str,"%d",score);
lcd_print(str);
dly(200000);
lcd_clear();
set_cursor(0,0);
lcd_print("try again press->reset");
dly(1000000000);
}

