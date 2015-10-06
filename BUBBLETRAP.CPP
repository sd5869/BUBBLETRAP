#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>
#include<time.h>

class point
{
public :
int x,y;
};
class ball:protected point
{
   int len; int life ;int scr;int di;int st;int flag;
   public:
   //constructor
   ball()
   {
    st=5;x=getmaxx()/2;y=getmaxy()/2;life=5;scr=0;len=50;di=53;flag=0;
   }
   //destructor
  ~ball()
   {
    st=0;x=0;y=0;life=0;scr=0;len=0;di=0;flag=0;
   }
   void in()
   {
	char a = getche();
	int c=a;
	if (c>=49&&c<=57||c==27)
	   di=c;
   }
  void cwall(int&x,int&y,int len);
  void con();void exp();void ptso();
  void pts();void lif();void score();
  void bon();void red();void move();
  void init();void fhandle(char* s);
  int  getlife(){return life;}
}b;
			//intial position
void ball::init()
{
	if(flag==0)
	   {
	    x=getmaxx()/2;y=getmaxy()/2;circle(x,y,len);flag=1;
	   }
}
		      //collision
void ball::cwall(int& x,int& y,int len)
{   int mx=getmaxx();
    int my=getmaxy();
    if (x-len<=0)
	 {circle(mx,y,len);x=mx-len;}
       else if(y-len<=0)
	 {circle(x,my,len);y=my-len;}
       else if(x+len>=mx)
	 {circle(0,y,len);x=0+len;}
       else if(y+len>=my)
	 {circle(x,0,len);y=0+len;}
       else
	 circle(x,y,len);

}
		      //file handle
void ball::fhandle(char* s)
{       cleardevice();
	char a[25];
	cout<<endl<<"ENTER YOUR NAME: ";
	gets(a);
	strcat(a,strcat(" ",s));
	cout<<"OUR TOP SCORERS:\n";
	fstream f("score.dat",ios::app|ios::in);
	f.write(a,25);
	f.seekp(0);f.seekg(0);
	f.read(a,25);
	while(f)
	{ cout<<a;
	  f.read(a,25);
	  cout<<endl;
	}
}
		//scr--
void ball::red()
{
	int mx,my,p5,p6;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(10);
	if (!(p5-5<=0||p6-5<=0||p5+5>=mx||p6+5>=my))
	       circle(p5,p6,5);
	if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
	       scr-=10;
}
		      //bonus
void ball::bon()
{
	int mx,my,p5,p6;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval+mx/2);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(1);
	if (!(p5-5<=0||p6-5<=0||p5+5>=mx||p6+5>=my))
	       circle(p5,p6,5);
	if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
	       scr+=10;
}
		      //life++
void ball::lif()
{     	int mx,my,p5,p6;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval+my/2);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(5);
	if (!(p5-5<=0||p6-5<=0||p5+5>=mx||p6+5>=my))
	{
	    circle(p5,p6,5);
	}
	if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
	    life++;
}
			//contraction
void ball::con()
{            int mx,my,p5,p6; int seedval;
	time_t t1;seedval=(unsigned)time(&t1);srand(seedval+mx);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(6);
	if (!(p5-len<=0||p6-len<=0||p5+len>=mx||p6+len>=my))
			circle(p5,p6,5);
	if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
	    {
	       if(len<=25)
	       len=25;
	       else
	       len--;
	    }
}
		      //expansion
void ball::exp()
{
	      int mx,my,p5,p6;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval+my);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(14);
	if (!(p5-len<=0||p6-len<=0||p5+len>=mx||p6+len>=my))
			circle(p5,p6,5);
	if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
	     { if(len>=150)
		len=100;
		else
		len++;
	     }
}
		  //help
void help()
{
	cleardevice();
	setcolor(9);
	settextstyle(2,0,6);
	outtextxy(0,0,"AIM: Capture The GREEN BUBBLE And Stay Away From RED BUBBLE.");
	setcolor(3);
	rectangle(0,200,260,370);
	setcolor(2);
	outtextxy(100,210,"POWER UPS");
	setcolor(14);
	circle(10,333,5);
	outtextxy(17,330,":It INCREASES SIZE Of Bubble");
	setcolor(6);
	circle(10,353,5);
	outtextxy(17,350,":It DECREASES SIZE Of Bubble");
	setcolor(1);
	circle(10,310,5);
	outtextxy(17,310,":It INCREASES SCORE By 10");
	setcolor(5);
	circle(10,233,5);
	outtextxy(17,230,":It INCREASES LIFE By 1");
	setcolor(4);
	circle(10,253,5);
	outtextxy(17,250,":It DECREASES LIFE By 1");
	setcolor(2);
	circle(10,273,5);
	outtextxy(17,270,":It INCREASES SCORE By 1");
	setcolor(10);
	circle(10,293,5);
	outtextxy(17,290,":It DECREASES SCORE By 10");
	setcolor(3);
	rectangle(getmaxx()/2+100,200,580,420);
	settextstyle(7,0,1);
	setcolor(12);
	outtextxy(getmaxx()/2+150,220,"CONTROLS");
	outtextxy(getmaxx()/2+110,240,"1:LEFT Down");
	outtextxy(getmaxx()/2+110,260,"2:Down");
	outtextxy(getmaxx()/2+110,280,"3:RIGHT Down");
	outtextxy(getmaxx()/2+110,300,"4:LEFT");
	outtextxy(getmaxx()/2+110,320,"5:STOP");
	outtextxy(getmaxx()/2+110,340,"6:RIGHT");
	outtextxy(getmaxx()/2+110,360,"7:LEFT UP");
	outtextxy(getmaxx()/2+110,380,"8:UP");
	outtextxy(getmaxx()/2+110,400,"9:RIGHT UP");
	getch();
}
		      //cover
void cover ()
{setcolor(9);
settextstyle(7,0,8);
outtextxy(((getmaxx()/2)-(textwidth("BUBBLE TRAP")/2)),((getmaxy()/2)-textheight("BUBBLE TRAP")),"BUBBLE TRAP");
settextstyle(7,0,2);
outtextxy(((getmaxx()/2)-(textwidth("PRESS ANY KEY TO START")/2)),((getmaxy()/2)-textheight("PRESS ANY KEY TO START")+50),"PRESS ANY KEY TO START");
outtextxy(((getmaxx()/2)-(textwidth("PRESS H FOR HELP")/2)),((getmaxy()/2)-textheight("PRESS H FOR HELP")+100),"PRESS H FOR HELP");
char a ;
a=getche();
if (a=='h' || a=='H')
help();
getch();
}
		      //score
void ball:: score()
{
	scr/=40;
	char* nm = itoa(scr,nm,10);
	settextstyle(7,0,2);
	char x[30]= "YOUR SCORE IS:";
	char* a = strcat(x,nm);
	cleardevice();
	outtextxy(((getmaxx()/2)-(textwidth(a)/2)),((getmaxy()/2)-textheight(a)),a);
	outtextxy(((getmaxx()/2)-(textwidth(a)/2)-100),((getmaxy()/2)-textheight(a)-100),"TO SAVE YOUR SCORE PRESS S");
	char y =getche();
	if (y=='s' || y=='S')
	b.fhandle(nm);
	getch();
	exit(0);
}
		      //points
void ball:: pts()
{
	int mx,my,p5,p6;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval-mx);
	mx=getmaxx();
	my=getmaxy();
	p5=(rand()%mx)+len;
	p6=random(rand()%my)+len;
	setcolor(2);
		if (!(p5-5<=0||p6-5<=0||p5+5>=mx||p6+5>=my))
		circle(p5,p6,5);
		if(p5>=(x-len) && p5<=(x+len) && p6>=(y-len) && p6<=(y+len))
		scr++;
}
		      //points out
void ball:: ptso()
{
	int mx,my,p3,p4;unsigned int seedval;
	time_t t;seedval=(unsigned)time(&t);srand(seedval-my);
	mx=getmaxx();
	my=getmaxy();
	p3=(rand()%mx)+len;
	p4=random(rand()%my)+len;
	setcolor(4);
	setaspectratio(1,1);
	for(int i=0;i<10;i++)
       {
		if (!(p3-5<=0||p4-5<=0||p3+5>=mx||p4+5>=my))
		circle(p3,p4,5);
       }
	 if(p3>=(x-len) && p3<=(x+len) && p4>=(y-len) && p4<=(y+len))
	 life--;

}
void main()
{       /* initialize graphics and local variables */
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
				/* real code */
	cover();
	while(b.getlife()!=0)
		{
		    if(!kbhit())
				{
				  b.red();b.con();b.init();
				  b.exp();b.ptso();b.pts();
				  b.lif();b.bon();delay(10);
				  cleardevice();setcolor(15);
				  b.move();
				}
			else
			      b.in();

		}

	b.score();
	getch();
	closegraph();

}
void ball::move()
{
     switch (di)
	{
	  case 49:
	  x-=st;y+=st;cwall(x,y,len);break;
	  case 50:
	  y+=st;cwall(x,y,len);break;
	  case 51:
	  x+=st;y+=st;cwall(x,y,len);break;
	  case 52:
	  x-=st;cwall(x,y,len);break;
	  case 53:
	  circle(x,y,len);break;
	  case 54:
	  x+=st;cwall(x,y,len);break;
	  case 55:
	  y-=st;x-=st;cwall(x,y,len);break;
	  case 56:
	  y-=st;cwall(x,y,len);break;
	  case 57:
	  x+=st;y-=st;cwall(x,y,len);break;
	  case 27:
	  b.score();
	  default:
	  break;
	}
}
