#include<gl/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#include <time.h>
#include <cstdlib>
#include<sstream>

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std ; 

float cx , cy;
char buffer[10];

float ex , ey ; 
float ebx , eby ;
string ebd ;

string dirE  ;

int score = 0 ; 


int isShoted[5] = {0,0,0,0,0};
int bx[5] = {-20,-20,-20,-20,-20} ;
int by[5] = {-20,-20,-20,-20,-20} ;

int index=0 ;


string dir[5]={"","","","",""};

void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (int i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}

bool isBlocked(float x , float y )
{
	if(x<0||y<0||x>600||y>600)
	{
		return false ;
	}
	
	//n shape in the bottom
	else if(x>225&&x<=300&&y>=0&&y<50)
	{
		return false ; 
	}
	else if(x>225&&x<375&&y>=50&&y<75)
	{
		return false ; 
	}
	else if(x>275&&x<375&&y>=0&&y<50)
	{
		return false ; 
	}
	//4 column in bottom
	else if(x>0&&x<100&&y<225&&y>0)
	{
		return false ; 
	}
	else if(x>100&&x<200&&y<225&&y>0)
	{
		return false ; 
	}
	else if(x>400&&x<500&&y<225&&y>0)
	{
		return false ; 
	}
	else if(x>500&&x<600&&y<225&&y>0)
	{
		return false ; 
	}
	
	
	//4 column in top
		else if(x>0&&x<100&&y<600&&y>325)
	{
		return false ; 
	}
	else if(x>100&&x<200&&y<600&&y>325)
	{
		return false ; 
	}
	else if(x >400&&x<500&&y<600&&y>325)
	{
		return false ; 
	}
	else if(x>500&&x<600&&y<600&&y>325)
	{
		return false ; 
	}
	
	
	//(-) on the leftmost
	
	else if(x>=0&&x<50&&y<300&&y>225)
	{
		return false ; 
	}
	
	//(-) on the rightmost
	else if(x>550&&x<=600&&y<300&&y>225)
	{
		return false ; 
	}
	
	//(-) on left 
	
	else if(x>50&&x<200&&y<325&&y>225)
	{
		return false ; 
	}
	
	//(-) on the right 
	
	else if(x>400&&x<550&&y<325&&y>225)
	{
		return false ; 
	}
	
	//dot in the left middle
	
	else if(x>200&&x<300&&y<375&&y>275)
	{
		return false ; 
	}	 
	//dot in the right middle
	else if(x>300&&x<400&&y<375&&y>275)
	{
		return false ; 
	}
	
	// the H 
	
	else if(x>200&&x<300&&y<275&&y>75)
	{
		return false ; 
	}
	
	else if(x>300&&x<400&&y<275&&y>75)
	{
		return false ; 
	}
	
	else if(x>250&&x<350&&y<250&&y>150)
	{
		return false ; 
	}	 
	//
	
	return true ; 
}

bool bulletwallcrash(float x, float y)
{
	
	if (x < 0 || y < 0 || x>650 || y>650)
	{
		return false;
	}

	//1-first shape in the bottom
	else if (x > 50 && x <= 100 && y >= 50 && y < 225)
	{
		return false;
	}
	//2-first shape in the top
	else if (x > 50 && x < 100 && y >= 375 && y < 600)
	{
		return false;
	}
	//3-second shape in the bottom
	else if (x > 150 && x < 200 && y >= 50 && y < 225)
	{
		return false;
	}
	//4-second shape in the top
	else if (x > 150 && x < 200 && y > 375 && y<600)
	{
		return false;
	}
	//5-third shape in the bottom
	else if (x > 450 && x < 500 && y > 50 && y<225)
	{
		return false;
	}
	//6-third shape in the top
	else if (x > 450 && x < 500 && y > 375 && y<600)
	{
		return false;
	}
	//7-forth shape in the bottom
	else if (x > 550 && x < 600 && y > 50 && y<225)
	{
		return false;
	}


	//8-forth shape in the top
	else if (x > 550 && x < 600 && y >375 && y<600)
	{
		return false;
	}

	//shape in middle bottom(9-10-11)
	//9
	else if (x > 275 && x < 300 && y > 0 && y<75)
	{
		return false;
	}
	//10
	else if (x > 300 && x < 350 && y > 50 && y<75)
	{
		return false;
	}
	//11
	else if (x > 350 && x < 375 && y >0 && y<75)
	{
		return false;
	}


	//12-first shape in middle

	else if (x >= 0 && x < 50 && y < 300 && y>225)
	{
		return false;
	}

	//13-second shape in middle
	else if (x > 100 && x <= 200 && y > 275 && y<325)
	{
		return false;
	}

	//14-third shape in middle

	else if (x > 250 && x < 300 && y > 325 && y<375)
	{
		return false;
	}

	//15-forth shape in middle 

	else if (x > 350 && x < 400 && y > 325 && y<375)
	{
		return false;
	}

	//16-fifth shape in middle 

	else if (x > 450 && x < 550 && y > 275 && y<325)
	{
		return false;
	}


	//17-sixth shape in middle 
	else if (x > 600 && x < 650 && y > 275 && y<300)
	{
		return false;
	}
	//18
	
	else if (x > 240 && x < 300 && y > 125 && y<275)
	{
		return false;
	}

    //19-second shape in H (-)
	else if (x > 300 && x < 350 && y > 200 && y<250)
	{
		return false;
	}

    //20-third shape in H (|)
	else if (x > 350 && x < 400 && y > 125 && y<275)
	{
		return false;
	}

	return true;
}

void keyboarddown(unsigned char key , int x , int y ){

	if ( key == 'a' || key == 'A') // horizontal [-]
	{
		if(isBlocked(cx -5.0, cy )==true)
		{
			cx -= 5;
		}
		
		dir[index] = "left";
			
	}
		
	else if ( key == 'd' || key == 'D') // horizontal [-]
	{
		if(isBlocked(cx + 5.0 , cy)==true)
		{
			cx += 5;
		}
		
	dir[index] = "right";
		
	}
	else if ( key == 'w' || key == 'W') // vertical [|]
	{
		if(isBlocked(cx,cy + 5.0)==true)
		{
			cy += 5;
		}
		dir[index] = "up";
		
	}
	else if ( key == 's' || key == 'S') // vertical [|]
	{
		if(isBlocked(cx,cy - 5.0)==true)
		{
			cy -= 5.0;
		}
		
	dir[index] = "down";
		
	}
	else if ( key == ' ') // vertical [|]
	{	
		isShoted[index] = 1 ;
		
		
		bx[index] = cx+25 ; 
		by[index] = cy+25 ;
		
			
		index += 1 ;
		if(index>=5)
		{
			index = 0 ;
			

		}
	}
		
	else if( key == 27) // exit game when press esc 
		exit(0);
	
}

void drawBullet()
{	

	for(int i = 0 ; i < 5 ; i ++)
	{
		if(isShoted[i]==1)
		{
			glColor3f(0,0,1);
			glEnable(GL_POINT_SMOOTH);
			glPointSize(15);
			glBegin(GL_POINTS);	
			glVertex2f(bx[i],by[i]);
			glEnd();	
		}
	}
}

void draw(int row, int column)
{
	
	glColor3f(0.23, 0.23, 0.24);
	glBegin(GL_POLYGON);
	glVertex2f((column-1)*25,(row-1)*25);
	glVertex2f(column*25,(row-1)*25);
	glVertex2f(column*25,row*25);
	glVertex2f((column-1)*25,row*25);
	glEnd();
	
}
void init()
{
	ex =  325 ; 
	ey = 450 ; 
	dirE= "left" ;
	
	ebx = ex ; 
	eby = ey ; 
	ebd= dirE ;
	glMatrixMode(GL_PROJECTION);
	glViewport(0,650,0,650);
	glLoadIdentity();
	gluOrtho2D(0, 650, 0, 650);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{

	glClearColor(0.69, 0.70, 0.72,0);
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1 ,1, 1);
	
	
	//drawText("Score:", 300, 600);
   /* itoa (score, buffer, 10);*/
    glColor3f(1,1,1);
    drawText(buffer, 375,600);
	
	draw(1,12);
	draw(1,15);
	draw(2,12);
	draw(2,15);
	draw(3,3);
	draw(3,4);
	draw(3,7);
	draw(3,8);
	
	
	draw(3,12);
	draw(3,13);
	draw(3,14);
	draw(3,15);
	draw(3,19);
	draw(3,20);
	draw(3,23);
	draw(3,24);
	draw(4, 3);
	draw(4, 4);
	draw(4, 7);
	draw(4, 8);
	draw(4, 19);
	draw(4, 20);
	draw(4, 23);
	draw(4, 24);

	draw(5, 3);
	draw(5, 4);
	draw(5, 7);
	draw(5, 8);
	draw(5, 19);
	draw(5, 20);
	draw(5, 23);
	draw(5, 24);

	draw(6, 3);
	draw(6, 4);
	draw(6, 7);
	draw(6, 8);
	draw(6, 11);
	draw(6, 12);
	draw(6, 15);
	draw(6, 16);
	draw(6, 19);
	draw(6, 20);
	draw(6, 23);
	draw(6, 24);

	draw(7, 3);
	draw(7, 4);
	draw(7, 7);
	draw(7, 8);
	draw(7, 11);
	draw(7, 12);
	draw(7, 15);
	draw(7, 16);
	draw(7, 19);
	draw(7, 20);
	draw(7, 23);
	draw(7, 24);

	draw(8, 3);
	draw(8, 4);
	draw(8, 7);
	draw(8, 8);
	draw(8, 11);
	draw(8, 12);
	draw(8, 15);
	draw(8, 16);
	draw(8, 19);
	draw(8, 20);
	draw(8, 23);
	draw(8, 24);

	draw(9, 3);
	draw(9, 4);
	draw(9, 7);
	draw(9, 8);
	draw(9, 11);
	draw(9, 12);
	draw(9, 13);
	draw(9, 14);
	draw(9, 15);
	draw(9, 16);
	draw(9, 19);
	draw(9, 20);
	draw(9, 23);
	draw(9, 24);

	draw(10, 11);
	draw(10, 12);
	draw(10, 13);
	draw(10, 14);
	draw(10, 15);
	draw(10, 16);

	draw(11, 11);
	draw(11, 12);
	draw(11, 15);
	draw(11, 16);

	draw(12, 1);
	draw(12, 2);
	draw(12, 5);
	draw(12, 6);
	draw(12, 7);
	draw(12, 8);
	draw(12, 19);
	draw(12, 20);
	draw(12, 21);
	draw(12, 22);
	draw(12, 25);
	draw(12, 26);

	draw(13, 5);
	draw(13, 6);
	draw(13, 7);
	draw(13, 8);
	draw(13, 19);
	draw(13, 20);
	draw(13, 21);
	draw(13, 22);

	draw(14, 11);
	draw(14, 12);
	draw(14, 15);
	draw(14, 16);

	draw(15, 11);
	draw(15, 12);
	draw(15, 15);
	draw(15, 16);

	draw(16, 3);
	draw(16, 4);
	draw(16, 7);
	draw(16, 8);
	draw(16, 19);
	draw(16, 20);
	draw(16, 23);
	draw(16, 24);

	draw(17, 3);
	draw(17, 4);
	draw(17, 7);
	draw(17, 8);
	draw(17, 19);
	draw(17, 20);
	draw(17, 23);
	draw(17, 24);

	draw(18, 3);
	draw(18, 4);
	draw(18, 7);
	draw(18, 8);
	draw(18, 19);
	draw(18, 20);
	draw(18, 23);
	draw(18, 24);


	draw(19, 3);
	draw(19, 4);
	draw(19, 7);
	draw(19, 8);
	draw(19, 19);
	draw(19, 20);
	draw(19, 23);
	draw(19, 24);

	draw(20, 3);
	draw(20, 4);
	draw(20, 7);
	draw(20, 8);
	draw(20, 19);
	draw(20, 20);
	draw(20, 23);
	draw(20, 24);

	draw(21, 3);
	draw(21, 4);
	draw(21, 7);
	draw(21, 8);
	draw(21, 19);
	draw(21, 20);
	draw(21, 23);
	draw(21, 24);

	draw(22, 3);
	draw(22, 4);
	draw(22, 7);
	draw(22, 8);
	draw(22, 19);
	draw(22, 20);
	draw(22, 23);
	draw(22, 24);


	draw(23, 3);
	draw(23, 4);
	draw(23, 7);
	draw(23, 8);
	draw(23, 19);
	draw(23, 20);
	draw(23, 23);
	draw(23, 24);

	draw(24, 3);
	draw(24, 4);
	draw(24, 7);
	draw(24, 8);
	draw(24, 19);
	draw(24, 20);
	draw(24, 23);
	draw(24, 24);
	
	glColor3f(0,0,1);
	

	drawBullet();
	
	
	glColor3f(1,0,0);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(15);
	glBegin(GL_POINTS);	
	glVertex2f(ebx+25,eby+25);
	glEnd();
			
	//Player 1	
	glColor3f(0,0,1);

	glBegin(GL_POLYGON);
	glVertex2f(cx, cy);
	glVertex2f(cx + 50, cy);
	glVertex2f(cx + 50, cy + 50);
	glVertex2f(cx, cy + 50);

	
	
	glEnd();
	
	
		//Enmy Player
		glColor3f(1,0,0);
		glBegin(GL_POLYGON);
		glVertex2f(ex,ey);
		glVertex2f(ex+50,ey);
		glVertex2f(ex+50,ey+50);
		glVertex2f(ex,ey+50);
		glEnd();		


	
	glutSwapBuffers();


}


void timer(int value)
{ 
    display();
    glutTimerFunc(1000/25,timer,0); 
    
    
    
	if(cx+50>=ebx&&cx<=ebx&&cy+50>eby&&cy<=eby)
	{
		exit(0);
	}
	
	
	if(cx+50>=ex&&cx<=ex+50&&cy+50>ey&&cy<=ey+50)
	{
		cx = 0 ; 
		cy = 0 ; 
		
		ex =  325 ; 
		ey = 450 ; 
			
		++score ; 
	}
	
	
    for(int i = 0 ; i<5 ; i++)
    {
    	if(ex+50>=bx[i]&&ex<=bx[i]&&ey+50>=by[i]&&ey<=by[i])
    	{
    		isShoted[i]= 0 ; 
    		
			ex =  325 ; 
			ey = 450 ; 
			
			++score ; 
			
			
			for(int j = 0 ; j<= 5 ;j++)
			{
				isShoted[j]= 0 ; 
			
				bx[j]=-20 ; 
				by[j]=-20 ; 
			}
		}
		
    	
		if(isShoted[i]==1)
		{
			
			if(bulletwallcrash(bx[i],by[i])==false)
			{
				isShoted[i]=0;
			}
			
		    if(dir[i]=="left")
		    {
		    	bx[i] -= 10 ; 
		    	
			}
			else if (dir[i]=="right") 
			{
				bx[i]+=10 ;
			}
			else if(dir[i]=="up")
			{
				by[i]+=10 ;
			}
			
			else if (dir[i]=="down")
			{
				by[i] -= 10 ;
				
			}
			else if(dir[i]=="")
			{
				if(i-1==-1)
				{
					isShoted[i]=0;
				}
				else 
				{
					dir[i]=dir[i-1];
				}
			}
		}
	}
	
	string direction[4] ={"left","right","up","down"};
	srand(time(0));
	
	if(dirE=="left")
	{	
		if(isBlocked(ex-2.5,ey)==true)
		{
			ex-=2.5 ;
		}
		else	
		{				
			dirE=direction[rand() % 4];
		}
		
	}
	 if (dirE=="down")
	{
		
		if(isBlocked(ex,ey-2.5)==true)
		{
			ey-= 2.5 ;
		}
		else
		{
			dirE=direction[rand() % 3];
		}
		
	}
	if (dirE=="right")
	{
		if(isBlocked(ex+2.5,ey)==true)
		{
			ex += 2.5 ;
		}
		else
		{
			dirE=direction[rand() % 4];
		}
	}
	if (dirE=="up")
	{
		if(isBlocked(ex,ey+2.5)==true)
		{
			ey+= 2.5 ;
		}
		else 
		{
			dirE=direction[rand() % 4];
		}
		
	}
	
	//
		if(ebd=="left")
		{	
		if(isBlocked(ebx-5,eby)==true)
		{
			ebx-=5 ;
		}
		else	
		{				
			ebx =ex ;
			eby = ey;
			
			ebd =dirE ;
		}
		
	}
	 if (ebd=="down")
	{
		
		if(isBlocked(ebx,eby-5)==true)
		{
			eby-= 5 ;
		}
		else
		{
			ebx =ex ;
			eby = ey;
			
			ebd =dirE ;
		}
		
	}
	if (ebd=="right")
	{
		if(isBlocked(ebx+2.5,eby)==true)
		{
			ebx += 5 ;
		}
		else
		{
			ebx =ex ;
			eby = ey;
			
			ebd =dirE ;
		}
	}
	if (ebd=="up")
	{
		if(isBlocked(ebx,eby+5)==true)
		{
			eby+= 5 ;
		}
		else 
		{
			ebx =ex ;
			eby = ey;
			
			ebd =dirE ;
		}
		
	}
}

int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,0);
    glutInitWindowSize(650,650);
    glutCreateWindow("TANK 90");
    init();
    glutDisplayFunc(display);
	glutKeyboardFunc(keyboarddown);

    glutTimerFunc(0,timer,0);

    glutMainLoop();
}
