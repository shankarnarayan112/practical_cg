#include<graphics.h> #include<stdlib.h> #include<conio.h> #include<math.h>

int *x1,*y1,*x2,*y2,*x,*y,*ymax,*ymin,i,j,nin,nout,*pintersect; float *dx,*xa;



int sign(long int a)
{
if (a<0) return(-1);
else if (a==0) return(0); else return(1);
}


void clip_polygon(void)
{
int s1,s2,f1,f2,spcross,svisible;
int visible(int a,int b,int c,int d,int e,int f); void output(int a,int b,int *c,int *d,int *e);
int cross(int a,int b,int c,int d,int e,int f,int g,int h);
int *intersect(int a,int b,int c,int d,int e,int f,int g,int h); pintersect=(int *)malloc(sizeof(int)*2);
for (i=1;i<=4;i++)
{
 

nout=0;
for (j=0;j<nin;j++)
*(x2+j)=*(y2+j)=0; for (j=1;j<=nin;j++)
{
if (j!=1) {} else
{
f1=*(x1+j-1);
f2=*(y1+j-1);
s1=*(x1+j-1);
s2=*(y1+j-1);
svisible=visible(s1,s2,*(x+i-1),*(y+i-1),*(x+i),*(y+i)); if (svisible>=0) output(s1,s2,&nout,x2,y2);
continue;

}
spcross=cross(s1,s2,*(x1+j-1),*(y1+j-1),*(x+i-1),*(y+i-1),*(x+i),*(y+i)); if (!spcross) {}
else
{

pintersect=intersect(s1,s2,*(x1+j-1),*(y1+j-1),*(x+i-1),*(y+i-
1),*(x+i),*(y+i));

output(*pintersect,*(pintersect+1),&nout,x2,y2);

}
s1=*(x1+j-1);
s2=*(y1+j-1);
svisible=visible(s1,s2,*(x+i-1),*(y+i-1),*(x+i),*(y+i)); if (svisible>=0) output(s1,s2,&nout,x2,y2);
}
if (!nout) continue;
spcross=cross(s1,s2,f1,f2,*(x+i-1),*(y+i-1),*(x+i),*(y+i));
 

if (!spcross) {} else
{
pintersect=intersect(s1,s2,f1,f2,*(x+i-1),*(y+i-1),*(x+i),*(y+i)); output(*pintersect,*(pintersect+1),&nout,x2,y2);
}
for (j=0;j<nout;j++)
{
*(x1+j)=*(x2+j);
*(y1+j)=*(y2+j);
}
nin=nout;
}
*(x2+nout)=*x2;
*(y2+nout)=*y2;

}


int cross(int s1,int s2,int p1,int p2,int wx1,int wy1,int wx2,int wy2)
{
int pvisible1,pvisible2;
int visible(int a,int b,int c,int d,int e,int f); pvisible1=visible(s1,s2,wx1,wy1,wx2,wy2); pvisible2=visible(p1,p2,wx1,wy1,wx2,wy2); if (pvisible1==-pvisible2)
return 1;
else return 0;
}


int visible(int sx1,int sx2,int px1,int py1,int px2,int py2)
{
long int temp1,temp2,temp3;
 

int pvisible;
temp1=(long)(sx1-px1)*(long)(py2-py1); temp2=(long)(sx2-py1)*(long)(px2-px1); temp3=temp2-temp1; pvisible=sign(temp3);
return (pvisible);

}


int *intersect(int px1,int py1,int px2,int py2,int wx1,int wy1,int wx2,int wy2)
{
float parameter[2][1],coeff[2][2],temp1,temp2; int right[2][1];
coeff[0][0]=px2-px1; coeff[0][1]=wx1-wx2; coeff[1][0]=py2-py1; coeff[1][1]=wy1-wy2; right[0][0]=wx1-px1; right[1][0]=wy1-py1;
temp1=(coeff[0][0]*coeff[1][1])-(coeff[0][1]*coeff[1][0]); temp2=coeff[0][0];
coeff[0][0]=(coeff[1][1])/temp1; coeff[1][1]=temp2/temp1; coeff[0][1]=-(coeff[0][1])/temp1;
coeff[1][0]=-(coeff[1][0])/temp1; parameter[0][0]=(coeff[0][0]*right[0][0])+(coeff[0][1]*right[1][0]);
parameter[1][0]=(coeff[1][0]*right[0][0])+(coeff[1][1]*right[1][0]);
*pintersect=px1+(px2-px1)*parameter[0][0];
*(pintersect+1)=py1+(py2-py1)*parameter[0][0]; return(pintersect);
}
 

void output(int vertex1,int vertex2,int *n,int *x2,int *y2)
{
(*n)++;
*(x2+(*n)-1)=vertex1;
*(y2+(*n)-1)=vertex2;
}


void include(int *end_edge,int final_edge,int scan)
{
while((*end_edge<=final_edge)&&(*(ymax+*end_edge)>=scan)) (*end_edge)++;
}


void fillscan(int end_edge,int start_edge,int scan)
{
int nx,j,k;
nx=(end_edge-start_edge)/2; j=start_edge;
for (k=1;k<=nx;k++)
{
line(*(xa+j),scan,*(xa+j+1),scan); j+=2;
}
}


void update_xvalues(int last_edge,int *start_edge,int scan)
{
int k1,k2; k2=last_edge;
for (k1=last_edge;k1>=*start_edge;k1--)
{
 

if (*(ymin+k1)<scan)
{
*(xa+k2)=*(xa+k1)+*(dx+k1); if (k1!=k2)
{
*(ymin+k2)=*(ymin+k1);
*(dx+k2)=*(dx+k1);
}
k2--;
}
}
*start_edge=k2+1;

}


void xsort(int start_edge,int last_edge)
{
int k,l; float t;
for (k=start_edge;k<=last_edge;k++)
{
l=k;
while((l>start_edge)&&(*(xa+l)<*(xa+l-1)))
{
t=*(ymin+l);
*(ymin+l)=*(ymin+l-1);
*(ymin+l-1)=t; t=*(xa+l);
*(xa+l)=*(xa+l-1);
*(xa+l-1)=t; t=*(dx+l);
*(dx+l)=*(dx+l-1);
 

*(dx+l-1)=t;
l--;

}

}

}


void poly_insert(int j,int xc1,int yc1,int xc2,int yc2)
{
int j1,ym; j1=j;
if (yc1>yc2) ym=yc1; else ym=yc2;
while((j1!=0)&&(*(ymax+j1-1)<ym))
{
*(ymax+j1)=*(ymax+j1-1);
*(ymin+j1)=*(ymin+j1-1);
*(xa+j1)=*(xa+j1-1);
*(dx+j1)=*(dx+j1-1); j1--;
}
*(ymax+j1)=ym;
*(dx+j1)=-(float)(xc2-xc1)/(yc2-yc1); if (yc1>yc2)
{
*(ymin+j1)=yc2;
*(xa+j1)=xc1;
}
else
{
*(ymin+j1)=yc1;
*(xa+j1)=xc2;
 

}

}


void getpoint(int i,int *xtemp,int *ytemp)
{
*xtemp=*(x2+i);
*ytemp=*(y2+i);
}


void loadpolygon(int i,int *edges)
{
int xc1,xc2,yc1,yc2,i1,k; getpoint(i,&xc1,&yc1); i1=i+1;
*edges=0; for(k=1;k<=nin;k++)
{
getpoint(i1,&xc2,&yc2); if (yc1==yc2)
xc1=xc2; else
{
poly_insert(*edges,xc1,yc1,xc2,yc2); (*edges)++;
yc1=yc2; xc1=xc2;
} i1++;
}
(*edges)--;
}
 



void fillpolygon(int index)
{
int edges,scan,start_edge,end_edge; loadpolygon(index,&edges);
if (edges<1) return; scan=*ymax; start_edge=0; end_edge=0;
include(&end_edge,edges,scan); while(end_edge!=start_edge)
{
xsort(start_edge,end_edge-1); fillscan(end_edge,start_edge,scan); scan--;
update_xvalues(end_edge-1,&start_edge,scan); include(&end_edge,edges,scan);
}
}


void main()
{
int gd=DETECT,gm;
int gdriver = DETECT,gmode,errorcode; clrscr();
/* //Request autodetection
int gdriver = DETECT,gmode,errorcode;
//int xmax,ymax,x1,y1,x2,y2,l;
//Initialize graphics and local variables initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
//Read result of initialization
 

errorcode=graphresult(); if(errorcode!=grOk) //Error occured
{
printf("Graphics error : %s\n",grapherrormsg(errorcode)); printf("Press any key to halt.");
getch();
exit(1);
}*/


x=(int *)malloc(sizeof(int)*5); y=(int *)malloc(sizeof(int)*5);
printf("Enter number of sides in polygon : "); scanf("%d",&nin);
x1=(int *)malloc(sizeof(int)*2*nin); y1=(int *)malloc(sizeof(int)*2*nin); x2=(int *)malloc(sizeof(int)*2*nin); y2=(int *)malloc(sizeof(int)*2*nin); ymax=(int *)malloc(sizeof(int)*2*nin); ymin=(int *)malloc(sizeof(int)*2*nin); xa=(float *)malloc(sizeof(float)*2*nin); dx=(float *)malloc(sizeof(float)*2*nin);
printf("Enter the coordinates of the polygon vertices (x y) :\n"); for (i=0;i<nin;i++)
{
printf("%d",(i+1));
printf(":"); scanf("%d%d",&*(x1+i),&*(y1+i));
}
*(x1+nin)=*x1;
*(y1+nin)=*y1;
printf("\n\nEnter the coordinates of the window vertices :\n");
 

for (i=0;i<4;i++)
{
printf("%d",(i+1));
printf(":"); scanf("%d%d",&*(x+i),&*(y+i));
}
*(x+4)=*x;
*(y+4)=*y;
// registerbgidriver(EGAVGA_driver); initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI"); errorcode = graphresult();
// initgraph(&gd,&gm,""); printf("Before clipping"); outtextxy(*x1+10,*y1-10,"Polygon");
outtextxy(*(x+1)+10,*(y+1)-10,"Clipping Window"); for (i=0;i<4;i++)
line(*(x+i),*(y+i),*(x+i+1),*(y+i+1)); for (i=0;i<nin;i++)
line(*(x1+i),*(y1+i),*(x1+i+1),*(y1+i+1));
getch(); clearviewport(); printf("After clipping");
//rectangle(200,200,400,400); for (i=0;i<4;i++)
line(*(x+i),*(y+i),*(x+i+1),*(y+i+1)); clip_polygon();
for (i=0;i<nin;i++)
{
if(*(y2+i)<*(y2+i+1))
{
*(ymax+i)=*(y2+i+1);
 

*(ymin+i)=*(y2+i);
*(xa+i)=*(x2+i+1);

}
else
{

*(ymax+i)=*(y2+i);
*(ymin+i)=*(y2+i+1);
*(xa+i)=*(x2+i);

}
*(dx+i)=*(y2+i)-*(y2+i+1); if (*(dx+i))
*(dx+i)=(float)(*(x2+i)-*(x2+i+1))/(*(dx+i));
line(*(x2+i),*(y2+i),*(x2+i+1),*(y2+i+1));
}
fillpolygon(0); getch(); closegraph();
}
 
