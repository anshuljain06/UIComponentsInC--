#include"DLL.cpp"
#include"myfunc.cpp"
#include<string.h>
class String
{
char item[81];
public:
String(char *item)
{
strcpy(this->item,item);
}
char * getItem()
{
return item;
}
};
DLL<String *> list;
void loadData()
{
list.add(new String("ONE"));
list.add(new String("TWO"));
list.add(new String("THREE"));
list.add(new String("FOUR"));
list.add(new String("FIVE"));
list.add(new String("SIX"));
list.add(new String("SEVEN"));
list.add(new String("EIGHT"));
list.add(new String("NINE"));
list.add(new String("TEN"));
list.add(new String("ELEVEN"));
list.add(new String("TWELVE"));
list.add(new String("THIRTEEN"));
list.add(new String("FOURTEEN"));
list.add(new String("FIFTEEN"));
list.add(new String("SIXTEEN"));
list.add(new String("SEVENTEEN"));
list.add(new String("EIGHTEEN"));
list.add(new String("NINTEEN"));
list.add(new String("TWENTY"));
}
/*void main()
{
loadData();
drawBox(1,1,24,16);
gotoxy(2,2);
cprintf("Size of DLL %d",list.getSize());
int x;
x=0;
gotoxy(2,3);
cprintf("--------------");
while(x<list.getSize())
{
gotoxy(2,4+x);
cprintf("%s",list.get(x)->getItem());
x++;
}
getch();
}*/
void main()
{
loadData();
int viewSize=10;
int startFrom=0;
int endAt=viewSize+startFrom-1;
int contentSize=list.getSize();
int ch;
int e;
int i;
i=0;
String *t;
while(1)
{
clrscr();
e=0;
while(e<viewSize)
{
t=list.get(startFrom+e);
gotoxy(2,2+e);
if(e==i)
{
textbackground(WHITE);
textcolor(BLACK);
}
cprintf("%s",t->getItem());
if(strlen(t->getItem())<10)
{
int ll;
ll=strlen(t->getItem());
while(ll<10)
{
cprintf(" ");
ll++;
}
}
textbackground(BLACK);
textcolor(WHITE);
e++;
}
int j=1;
while(j<11)
{
gotoxy(13,j+1);
textbackground(WHITE);
cprintf(" ");
j++;
}
int jo=(startFrom+i)/2;
if((startFrom+i)==1)
{
gotoxy(13,jo+3);
}
else if((startFrom+i)==(list.getSize()-2))
{
gotoxy(13,jo+1);
}
else
{
gotoxy(13,jo+2);
}
printf("%c",4);
textbackground(BLACK);
drawBox(1,1,12,14);
gotoxy(2,2+i);
ch=getch();
if(ch==27)
{
break;
}
if(ch==0)
{
ch=getch();
if(ch==80)
{
if(i<9)
{
i++;
}
else if(endAt<contentSize-1)
{
startFrom++;
endAt++;
}
else if(endAt==(list.getSize()-1))
{
i=0;
startFrom=0;
endAt=startFrom+viewSize-1;
}
}
if(ch==72)
{
if(i>0)
{
i--;
}
else if(startFrom>0)
{
startFrom--;
endAt--;
}
else if(startFrom==0)
{
endAt=(list.getSize()-1);
startFrom=endAt-viewSize+1;
i=9;
}
}
if(ch==73)
{
i=i-5;
if(i<=0)
{
startFrom=startFrom+i;
endAt=startFrom+viewSize-1;
i=0;
if(startFrom<=0)
{
startFrom=0;
endAt=startFrom+viewSize-1;
}
}
}
if(ch==81)
{
i=i+5;
if(i>=(viewSize-1))
{
endAt=endAt+5-((viewSize-1)-(i-5));
startFrom=endAt-(viewSize-1);
i=(viewSize-1);
if(endAt>=(list.getSize()-1))
{
endAt=(list.getSize()-1);
startFrom=endAt-viewSize+1;
}
}
}
}
}
clrscr();
}
