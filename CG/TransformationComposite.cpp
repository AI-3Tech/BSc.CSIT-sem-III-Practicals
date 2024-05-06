#include<stdio.h> 
#include <graphics.h> 
 
void multiply(int a[3][3],int b[3][3],int c[3][3],int r,int co){
	int k,i,j;  
	for(i=0;i<r;i++)    
	{    
		for(j=0;j<co;j++)    
		{    
			c[i][j]=0;    
			for(k=0;k<co;k++)    
			{    
				c[i][j]+=a[i][k]*b[k][j];    
			}    
		}    
	} 
}

int main()
{  
	int a[3][3],b[3][3],c[3][3],i,j,k;  
	printf("Enter the elements in the coordinates matrix=\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements in the composite matrix=\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}

	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	line(a[0][0],a[1][0],a[0][1],a[1][1]);
	outtextxy(a[0][0],a[1][0]-10,(char*)"original line");
	multiply(b,a,c,3,3);
	
	line(c[0][0],c[1][0],c[0][1],c[1][1]);
	outtextxy(c[0][0],c[1][0]-10,(char*)"Scaled line");
	getch();
	closegraph();
	return 0;  
}  