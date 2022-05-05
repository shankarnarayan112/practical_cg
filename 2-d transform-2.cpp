#include<stdio.h> #include<graphics.h> #include<math.h> #define pi (22/7) #define sz 3
double x[3][3],res[3][3],tm[3][3]; int t2[3][2];

void prod(double a[sz][sz],double b[sz][sz],double c[sz][sz],int r1,int c1,int c2)
{	int i,j,k; for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
for(k=0;k<c1;k++)
{
c[i][j] += a[i][k]*b[k][j];
}
}
}
}
void drawtriangle(int t[3][2])
{	int i;
for(i=0;i<3;i++)
{
line(t[i][0]+100,100-t[i][1],t[(i+1)%3][0]+100,100-t[(i+1)%3][1]);
} line(0,100,400,100); line(100,0,100,400);
 

}
void translation(int t1[3][2])
{
int i,j,val; for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
x[i][j] = t1[i][j]; t2[i][j] = 0;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else

tm[i][j] = 0;

}
x[i][j] = 1;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;

}
printf("\n Shift in x-axis : "); scanf("%d",&val);
tm[2][0] = val;
printf("\n Shift in y-axis : "); scanf("%d",&val);
tm[2][1] = val; prod(x,tm,res,3,3,3); for(i=0;i<3;i++)
 

{

for(j=0;j<2;j++)
{
t2[i][j] = (int)res[i][j];
}

}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr();
outtextxy(10,10,"\n Triangle after transformation "); drawtriangle(t2);
outtextxy(10,405,"Press any key to continue..."); getch();
}
void rotation(int t1[3][2])
{
int i,j,ang;
double sinx[] = {0,0.5,0.7,0.8,1,0,-1,0};
double cosx[] = {1,0.8,0.7,0.5,0,-1,0,1};
for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
x[i][j] = t1[i][j]; t2[i][j] = 0;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;
 

}
x[i][j] = 1;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;

}
printf("\n Choose the angle of rotation : ");
printf("\n\t 1. 0 degree\n\t 2. 30 degree\n\t 3. 45 degree\n\t 4. 60 degree\n\t 5. 90 degree");
printf("\n\t 6. 180 degree\n\t 7. 270 degree\n\t 8. 360 degree\n Enter your choice : "); scanf("%d",&ang);
if(ang > 0 && ang < 9)
{
tm[0][0] = tm[1][1] = cosx[ang-1];
tm[0][1] = tm[1][0] = sinx[ang-1];
}
else
{
tm[0][0] = tm[1][1] = cosx[0];
tm[0][1] = tm[1][0] = sinx[0];
}
tm[1][0] *= (-1);
prod(x,tm,res,3,3,3); for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
t2[i][j] = (int)res[i][j];
}
 

}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr();
outtextxy(10,10,"\n Triangle after transformation "); drawtriangle(t2);
outtextxy(10,405,"Press any key to continue..."); getch();
}
void scaling(int t1[3][2])
{
int i,j; for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
x[i][j] = t1[i][j]; t2[i][j] = 0;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;
}
x[i][j] = 1;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;
 

}
printf("\n Enter the Scaling value : "); scanf("%lf",&tm[0][0]);
tm[1][1] = tm[0][0];
prod(x,tm,res,3,3,3); for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
t2[i][j] = (int)res[i][j];
}
}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr();
outtextxy(10,10,"\n Triangle after transformation "); drawtriangle(t2);
outtextxy(10,405,"Press any key to continue..."); getch();
}
void reflection(int t1[3][2])
{
int i,j,ch; for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
x[i][j] = t1[i][j]; t2[i][j] = 0;
res[i][j] = 0;
 

if(i == j)

tm[i][j] = 1;

else

tm[i][j] = 0;

}
x[i][j] = 1;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;

}
printf("\n Type of Reflection : ");

printf("\n\t 1. Along x-axis ; y = 0\n\t 2. Along y-axis ; x = 0\n\t 3. Along y = x\n\t 4. Along y =
-x ");

printf("\n Enter your choice : "); scanf("%d",&ch);
if(ch > 0 && ch < 4)
{	if(ch < 3)
{
tm[0][1] = tm[1][0] = 0;
if(ch == 1)
tm[1][1] = -1;
else
tm[0][0] = -1;
}
else
{
tm[0][0] = tm[1][1] = 0;
if(ch == 3)
tm[0][1] = tm[1][0] = 1;
 

else

tm[0][1] = tm[1][0] = -1;

}

}
else // taking the case of reflection along y = 0
{
tm[0][1] = tm[1][0] = 0; tm[1][1] = -1;
}
prod(x,tm,res,3,3,3); for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
t2[i][j] = (int)res[i][j];
}
}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr();
outtextxy(10,10,"\n Triangle after transformation "); drawtriangle(t2);
outtextxy(10,405,"Press any key to continue..."); getch();
}
void distortion(int t1[3][2])
{
int i,j; for(i=0;i<3;i++)
{
 

for(j=0;j<2;j++)
{
x[i][j] = t1[i][j]; t2[i][j] = 0;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;
}
x[i][j] = 1;
res[i][j] = 0; if(i == j)
tm[i][j] = 1;
else
tm[i][j] = 0;

}
printf("\n Enter the Scaling value for x-axis : "); scanf("%lf",&tm[0][0]);
printf("\n Enter the Scaling value for y-axis : "); scanf("%lf",&tm[1][1]);
prod(x,tm,res,3,3,3); for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
t2[i][j] = (int)res[i][j];
}
}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue...");
 

getch();
clrscr();
outtextxy(10,10,"\n Triangle after transformation "); drawtriangle(t2);
outtextxy(10,405,"Press any key to continue..."); getch();
}
void main()
{
int gd = DETECT,gm,i,ch; int t1[3][2];
initgraph(&gd,&gm,"C:\\TURBOC3\\bgi"); clrscr();
for(i=0;i<3;i++)
{
printf("\n Enter the value of x%d : ",i+1); scanf("%d",&t1[i][0]);
printf("\n Enter the value of y%d : ",i+1); scanf("%d",&t1[i][1]);
}
settextstyle(2,0,5);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr();
outtextxy(10,10,"Triangle before transformation "); drawtriangle(t1);
outtextxy(10,405,"Press any key to continue..."); getch();
clrscr(); do
{
 

printf("\n 1.Translation\n 2.Rotation\n 3.Scaling\n 4.Reflection\n 5.Distortion\n Enter your choice : ");
scanf("%d",&ch); switch(ch)
{
case 1:
translation(t1); break;
case 2:
rotation(t1); break;
case 3:
scaling(t1); break;
case 4:
reflection(t1); break;
case 5:
distortion(t1); break;
default:
printf("\n Invalid Choice !");
}
clrscr();
printf("\n Do you want to choose again? (1/0) : "); scanf("%d",&ch);
}while(ch == 1); getch(); closegraph(); restorecrtmode();
}
 
