//REVERSI GAME
//HARITA 11BCE021
//CHAITANYA 11BCE012

//colour map//
//red 4//blue 3// green 2// white 15// black 0

#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include "mouse.h"
#include <dos.h>

/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

int player=1;//default player

char p1[80], p2[80], str1[80], str2[80];

char *player1="Player 1: ",*player2="Player 2: ";

int max=8;

/* Chip 1 - Red; Chip 2 - Blue */
int chip1=0,chip2=0;

int colour;//store colour of chip

//from where the board starts//
int o_x=649/2-(max/2*50), o_y=479/2-(50*max/2);

int i, j, c;//loop variables//

int x=639, y=479;//the clicked position//

//to draw the board
void drawboard(int o_x, int o_y, int max);

//to identify the square
void identifysquare(int x,int y);

//to draw chip
void drawchip(int x,int y);

//switch between two players
int selectplayer(int player);

//to change color of chip//
void changechip(int x,int y,int colour);

void findsquare(int x,int y);

void chipcount();

int main(void)
{

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* initialise the mouse */

   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);

   settextjustify(CENTER_TEXT,CENTER_TEXT);

   outtextxy(getmaxx()/2,getmaxy()/2,"WELCOME TO THE REVERSI GAME");

   delay(1000);

   cleardevice();

   cout<<"Enter name of PLAYER 1: ";
   gets(p1);

   strcpy(str1,player1);
   strcat(str1,p1);

   cout<<"Enter name of PLAYER 2: ";
   gets(p2);

   strcpy(str2,player2);
   strcat(str2,p2);

   cleardevice();

   settextstyle(SANS_SERIF_FONT,0,1);

   settextjustify(LEFT_TEXT,TOP_TEXT);
   outtextxy(1,1,str1);
   settextjustify(RIGHT_TEXT,TOP_TEXT);
   outtextxy(getmaxx(),1,str2);

   showmouse();
   setposition(x,y);
   setcolor(0);


   drawboard(o_x,o_y,max);

   int count=0;
   while(count!=max/2)
   {
	getposition(&x,&y);
	identifysquare(x,y);
	drawchip(x,y);
	player=selectplayer(player);
	count++;
   }
   chipcount();
   while(chip1!=0||chip2!=0)
   {
	getposition(&x,&y);
	colour=getpixel(x,y);
	changechip(x,y,colour);
	chipcount();
   }

   cout<<"Chip 1: "<<chip1<<endl<<"Chip 2: "<<chip2;

   /* clean up */
   getch();
   closegraph();
   return 0;
}


//function definitions........

   void drawboard(int o_x, int o_y, int max)
   {
	for (i=0; i<max; i++)
	{
		for(j=0; j<max; j++)
		{
			if((i+j)%2==0)
			{
			setcolor(0);
			setfillstyle(1, 2);
			}

			else
			{
			setcolor(0);
			setfillstyle(1,	15);
			}

			bar3d(o_x+(j*50), o_y+(i*50),
			      o_x+(j*50)+50, o_y+(i*50)+50,
			      0, 0);

		}
	}

	setfillstyle(1,3);
	setcolor(2);
	fillellipse(o_x+25+50*((max/2)-1),o_y+25+50*((max/2)-1),20,20);
	fillellipse(o_x+25+50*(max/2),o_y+25+50*(max/2),20,20);

	setfillstyle(1,4);
	setcolor(15);
	fillellipse(o_x+25+50*(max/2),o_y+25+50*((max/2)-1),20,20);
	fillellipse(o_x+25+50*((max/2)-1),o_y+25+50*(max/2),20,20);
   }

   int selectplayer(int player)
   {
	player++;
	if(player==1)
	{
		player=1;
	}
	else
	{
		player=0;
	}
	return(player);
   }

   void findsquare(int x,int y)
   {
	int k=0;
	int l=0;

	for(i=0;i<max;i++)
	{
		if( y > ((o_y)+i*50) && y < ((o_y+50)+i*50) )
		{
		k=i;
		}
	}

	for(i=0;i<max;i++)
	{
		if( x > ((o_x)+i*50) && x < ((o_x+50)+i*50) )
		{
		l=i;
		}
	}

	c=abs(k-l);
   }


   void identifysquare(int x,int y)
   {
   int k=0;

   for(i=0;i<max;i++)
   {
	if( y > ((o_y)+i*50) && y < ((o_y+50)+i*50) )
	{
		k=(i*max);
	}
   }

   for(i=0;i<max;i++)
   {
	if( x > ((o_x)+i*50) && x < ((o_x+50)+i*50) )
	{
		k=k+(i+1);
	}
   }

   cout<<"Square Clicked is "<<k<<endl;

   }


   void drawchip(int x,int y)
   {

	if(player==1)
	{
		setfillstyle(1,4);
		setcolor(4);
	}
	else
	{
		setfillstyle(1,3);
		setcolor(3);
	}

	int k=0;
	int l=0;

	for(i=0;i<max;i++)
	{
		if( y > ((o_y)+i*50) && y < ((o_y+50)+i*50) )
		{
		k=i;
		}
	}

	for(i=0;i<max;i++)
	{
		if( x > ((o_x)+i*50) && x < ((o_x+50)+i*50) )
		{
		l=i;
		}
	}

	//cout<<k<<" "<<l<<"|";

	fillellipse(o_x+25+50*l,o_y+25+50*k,20,20);

   }

   void changechip(int x,int y,int colour)
   {

	findsquare(x,y);

	int k;
	k=(x-o_x)/50;
	int l;
	l=(y-o_y)/50;



	if(colour==3)

	{
		if(c%2==0)
		{
		setcolor(2);
		}
		else
		{
		setcolor(15);
		}

		for(i=20;i>0;i--)
		{

		setfillstyle(1,3);
		fillellipse(o_x+25+50*k,o_y+25+50*l,20,i);
		delay(10);

		}

		for(i=0;i<20;i++)
		{
		setfillstyle(1,4);
		fillellipse(o_x+25+50*k,o_y+25+50*l,20,i);
		delay(10);
		}
	}

	if(colour==4)

	{
		if(c%2==0)
		{
		setcolor(2);
		}
		else
		{
		setcolor(15);
		}

		for(i=20;i>0;i--)
		{

		setfillstyle(1,4);
		fillellipse(o_x+25+50*k,o_y+25+50*l,20,i);
		delay(10);

		}

		for(i=0;i<20;i++)
		{
		setfillstyle(1,3);
		fillellipse(o_x+25+50*k,o_y+25+50*l,20,i);
		delay(10);
		}
	}

   }

   void chipcount()
   {
	int colour;
	char msg1[10];
	char msg2[10];

	for (i=0; i<max; i++)
	{
		for(j=0; j<max; j++)
		{
			colour=getpixel(o_x+25+50*j,o_y+25+50*i);
			if(colour==3)
			{
				chip1++;
			}

			if(colour==4)
			{
				chip2++;
			}
		}
	}
   }