#include "iGraphics.h"
#include "bitmap_loader.h"
#include "stdlib.h"
#include "string.h"


int b,c,d,e,f;
int b1;
int game =-2;
int kpdx=395,kpdy=10;
int BulletCount=0;
int point =0;
int healthX=150;
bool keyPlane=true;
int gameOver;
char score[20];
int bMode=0;


int healthTimer=0;
bool exLife=false,bPower=false;
int exLifeX=200,exLifeY=800,bPowerX=300,bPowerY=800;



//char enemyArr[26][30]={"images//enemy21.bmp","images//enemy22.bmp","images//enemy23.bmp","images//enemy24.bmp","images//enemy25.bmp","images//enemy26.bmp","images//enemy27.bmp","images//enemy28.bmp","images//enemy29.bmp","images//enemy30.bmp","images//enemy31.bmp","images//enemy32.bmp","images//enemy33.bmp","images//enemy34.bmp","images//enemy35.bmp","images//enemy36.bmp","images//enemy37.bmp","images//enemy38.bmp","images//enemy39.bmp","images//enemy40.bmp","images//enemy41.bmp","images//enemy42.bmp","images//enemy43.bmp","images//enemy44.bmp","images//enemy45.bmp","images//enemy46.bmp"};

/*
 function iDraw() is called again and again by the system.

 */

struct buttoncordinate{
	int x;
	int y;
}bcordinate[4];

struct Bullet{
	int x,y;
	bool  show;

}bullet[100000],bullet1[100000],bullet2[100000];

char button[10][15]={"play.bmp", "score.bmp","ins.bmp","about.bmp"};
char play[25]={"play1.bmp"};
char s[25]= {"score1.bmp"};


void bulletShow()//showing the bullet of key aircraft
{
	for(int i = 0; i < BulletCount ; i++)
		{
			if(bullet[i].show== true )
				{
					iShowBMP2(bullet[i].x,bullet[i].y,"Bullet.bmp",0);
				}	
		}	
}

void bulletShow1()//showing the bullet of key aircraft
{
	for(int i = 0; i < BulletCount ; i++)
		{
			if(bullet1[i].show== true )
				{
					iShowBMP2(bullet1[i].x,bullet1[i].y,"Bullet.bmp",0);
				}	
		}	
}

void bulletShow2()//showing the bullet of key aircraft
{
	for(int i = 0; i < BulletCount ; i++)
		{
			if(bullet2[i].show== true )
				{
					iShowBMP2(bullet2[i].x,bullet2[i].y,"Bullet.bmp",0);
				}	
		}	
}


int enemyX = 200,enemyY = 600,enemy_Speed = 1,enemybullet_Speed = 4;


struct Enemy{
	int x,y;
	bool active;

}enemy[5],enemyBullet[5],enemyBullet2[5];

void Enemy()
{

	for (int i = 0,y1=100 ; i < 5 ; i++,y1+=100)
	{
		enemy[i].y -= enemy_Speed;
		if(enemy[i].y<0 )
		{	
			enemy[i].y =enemyY + y1;
			enemy[i].x = (enemyX-100)+ rand() % 1500;
			enemy[i].active = true;
		}
	}
}

void EnemyBullet()
{

	for (int i = 0; i < 5 ; i++)
	{
		enemyBullet[i].y -= enemybullet_Speed;
		if(enemy[i].y == 750 )
		{	
			enemyBullet[i].y = 750;
			
			enemyBullet[i].active = true;
		}

	}

	for (int i = 0; i < 5 ; i++)
	{
		enemyBullet2[i].y -= enemybullet_Speed;
		if(enemy[i].y == 500 )
		{	
			enemyBullet2[i].y = 500;
			
			enemyBullet2[i].active = true;
		}

	}
}

void showEnemy()
{
	for (int i = 0 ; i < 5 ; i++)
		{
			if (enemy[i].active)
				{
					iShowBMP2(enemy[i].x,enemy[i].y,"enemy1.bmp",0);
				}
			if (enemyBullet[i].active)
				{
					iShowBMP2(enemy[i].x,enemyBullet[i].y,"Bullet.bmp",0);
				}
			if (enemyBullet2[i].active)
				{
					iShowBMP2(enemy[i].x,enemyBullet2[i].y,"Bullet.bmp",0);
				}
			
		}
}
/*

*/

void killEnemy()
{
	for (int i = 0; i < BulletCount ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && bullet[i].show == true)
						{
							if (bullet[i].x+12 >= enemy[j].x && bullet[i].x+12 <= enemy[j].x +66)
								{
									if (bullet[i].y+21 >= enemy[j].y && bullet[i].y+21 <= enemy[j].y + 97)
											{
												enemy[j].active = false;
												bullet[i].show = false;
												
													point+=5;
													itoa(point,score,10);
												
												
											}
								}
						}
				}
		}

	for (int i = 0; i < BulletCount ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && bullet1[i].show == true)
						{
							if (bullet1[i].x+12 >= enemy[j].x && bullet1[i].x+12 <= enemy[j].x +66)
								{
									if (bullet1[i].y+21 >= enemy[j].y && bullet1[i].y+21 <= enemy[j].y + 97)
											{
												enemy[j].active = false;
												bullet1[i].show = false;
												
													point+=5;
													itoa(point,score,10);
												
												
											}
								}
						}
				}
		}


	for (int i = 0; i < BulletCount ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && bullet2[i].show == true)
						{
							if (bullet2[i].x+12 >= enemy[j].x && bullet2[i].x+12 <= enemy[j].x +66)
								{
									if (bullet2[i].y+21 >= enemy[j].y && bullet2[i].y+21 <= enemy[j].y + 97)
											{
												enemy[j].active = false;
												bullet2[i].show = false;
												
													point+=5;
													itoa(point,score,10);
												
												
											}
								}
						}
				}
		}
	
}
void colWithEnemy()
{
	for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && keyPlane == true)

						{
							if ((kpdx+90 >= enemy[j].x && kpdx <= enemy[j].x)||(kpdx+90 >= enemy[j].x+66 && kpdx <= enemy[j].x+66))
							{
								if (kpdy+147>= enemy[j].y && kpdy<=enemy[j].y)
								{
									
									enemy[j].active = false;
									healthX-=10;
									
								}
							}
					}
	}

}


void healthIncrease()
{
	int e1=800;

	if(healthTimer%450==0)
		exLife=true;
	if(exLife==true)
	{
		iShowBMP2(exLifeX,exLifeY,"Health.bmp",0);
	}


	if( exLife==true && keyPlane==true)

						{
							if ((kpdx+90 >= exLifeX && kpdx <= exLifeX)||(kpdx+90 >= exLifeX+30 && kpdx <= exLifeX+30))
							{
								if (kpdy+147>= exLifeY && kpdy<=exLifeY)
								{
									healthX=150;
									exLife = false;
									exLifeY=e1;
									exLifeX=(exLifeX+100)+ rand() % 1400;
									
									
								}
							}
					}

	
	if(exLifeY<0){
		exLife=false;
		exLifeY=e1;
		exLifeX=(exLifeX+100)+ rand() % 1400;
	}



}




void bullet2x()
{
	int e1=800;

	if(healthTimer%500==0)
		bPower=true;
	if(bPower==true)
	{
		iShowBMP2(bPowerX,bPowerY,"pBullet.bmp",0);
	}


	if( bPower==true && keyPlane==true)

						{
							if ((kpdx+90 >= bPowerX && kpdx <= bPowerX)||(kpdx+90 >= bPowerX+12 && kpdx <= bPowerX+12))
							{
								if (kpdy+147>= bPowerY && kpdy<=bPowerY)
								{
									bMode=1;
									bPower = false;
									bPowerY=e1;
									bPowerX=(bPowerX+100)+ rand() % 1400;
									
									
								}
							}
					}

	
	if(bPowerY<0){
		bPower=false;
		bPowerY=e1;
		bPowerX=(bPowerX+100)+ rand() % 1400;
	}



}




void iDraw()
{
	//place your drawing codes here
	iClear();
	if(game==-2)
	{	
	iShowImage(0,0,1500,800,c);

	iSetColor(255,0,0);
	iText( 750,150,"press p for menu", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	if(game==-1)
	{
	iShowImage(0,0,1500,800,b);
	iSetColor(255,255,255);
	iText(800,800,"Press 'Q' for quit",GLUT_BITMAP_TIMES_ROMAN_24);

	for(int i=0;i<4;i++)
	 {
		iShowBMP2(bcordinate[i].x, bcordinate[i].y,  button[i], 0);
	 }
	}


	else if(game == 0)
	{
		iShowImage(0,0,1500,800,b1);
		if(keyPlane==true){
	iShowBMP2(kpdx,kpdy,"keyPlane11.bmp",0);
		}
	if(kpdx<0)
		kpdx=0;
	if(kpdx>1414)
		kpdx=1414;
	if(kpdy<0)
		kpdy=0;
	if(kpdy>720)
		kpdy=720;
	iSetColor(255,255,255);
	iRectangle(10,770,150,20);
	iSetColor(0,0,255);
	iFilledRectangle(10,770,healthX,20);
	bullet2x();
	if(bMode==0){
	bulletShow();
	}
	if(bMode==1){
	bulletShow1();
	bulletShow2();
	}

	
	showEnemy();
	Enemy();
	EnemyBullet();
	killEnemy();
	colWithEnemy();
	healthIncrease();
	
	iSetColor(0, 136, 21);
	iText(1400,760,score,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1320,760,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
	if(healthX<=0)

			{
				iShowImage(0,0,1500,800,gameOver);
				keyPlane=false;							
			}
		
	}



	else if(game == 1)
	{
		iShowBMP(0,0, s);
		iShowBMP2(10,20, "back BMP.bmp",0);
	}
	else if(game == 2)
	{ 
		iShowBMP(0,0, "ins001 BMP.bmp");
		iShowBMP2(10,20, "back BMP.bmp",0);
	}
	else if (game == 3)
	{
		iShowBMP(0,0, "about BMP.bmp");
		iShowBMP2(10,20, "back BMP.bmp",0);
	}
	


	
}

void iPassiveMouse(int x, int y)
{
	
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		//x += 10;
		//y += 10;
		for(int i=0; i<4; i++)
		{
		  if( mx >= bcordinate[i].x && mx <=bcordinate[i].x + 350 && my >= bcordinate[i].y && my <=bcordinate[i].y +140)
			game = i ;
		  
		}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//x -= 10;
		//y -= 10;
		 
			 if( mx >= 10 && mx<= 360 && my>=20 && my<=170)
			  game=-1;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if  (key == 'p')
	{
		game=-1;
	}
	if  (key == 'q')
	{
		if(game == -1)
		{
			exit(0);
		}
	}
	
	if (key == 'a')///for shooting 
	{
			if(BulletCount<100)
			BulletCount++;
		else if(BulletCount==100)
			BulletCount=0;

		bullet[BulletCount-1].show=true;
		bullet[BulletCount-1].x=kpdx+39;
		bullet[BulletCount-1].y=kpdy+147;

		bullet1[BulletCount-1].show=true;
		bullet1[BulletCount-1].x=kpdx;
		bullet1[BulletCount-1].y=kpdy+30;

		bullet2[BulletCount-1].show=true;
		bullet2[BulletCount-1].x=kpdx+78;
		bullet2[BulletCount-1].y=kpdy+30;
	}
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	
		if (key == GLUT_KEY_RIGHT)
	{
			
		kpdx+=20;	
	}
	if (key == GLUT_KEY_LEFT)
	{
		kpdx-=20;
	}
	if (key == GLUT_KEY_UP)
	{
		kpdy+=20;
	}
	if (key == GLUT_KEY_DOWN)
	{
		 kpdy-=20;
	}
	
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	
	//place your codes for other keys here
}
void BulletShoot()
{
	for(int i = 0 ; i < BulletCount ; i++)
	{
		
		if(bullet[i].show)
			bullet[i].y += 20;

		if(bullet[i].y > 800)
			bullet[i].show = false;

	}
	for(int i = 0 ; i < BulletCount ; i++)
	{
		
		if(bullet1[i].show)
			bullet1[i].y += 20;

		if(bullet1[i].y > 800)
			bullet1[i].show = false;

	}

	for(int i = 0 ; i < BulletCount ; i++)
	{
		
		if(bullet2[i].show)
			bullet2[i].y += 20;

		if(bullet2[i].y > 800)
			bullet2[i].show = false;

	}
	healthTimer++;

	if(exLife)
		exLifeY-=10;

	if(bPower)
		bPowerY-=10;

}




int main()
{
	//place your own initialization codes here.
	iSetTimer(100,BulletShoot);


	int sum=150;
	for(int i=3;i>=0;i--)
	{
		bcordinate[i].x=50;
		bcordinate[i].y=  sum;
		sum+= 150;
	}
	iInitialize(1500,800,"Sky Attack");

	c=iLoadImage("startPage.jpg");
	b=iLoadImage("MENU.jpg");
	b1=iLoadImage("bg01.jpg");
	gameOver=iLoadImage("gameOver.png");
	
	iStart(); // it will start drawing
	

	return 0;
}

