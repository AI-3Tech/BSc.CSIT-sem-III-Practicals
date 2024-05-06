#include<stdio.h>
#include<conio.h>
#include<graphics.h>

  void drawcircle(int x0, int y0, int radius)
	  {     
	        int x = 0, y = radius, p = 1 - radius;   
		   
		    while (x < y)    
			{  
			    putpixel(x0 + x, y0 + y, WHITE); 
                delay(20);
                putpixel(x0 - x, y0 + y, WHITE);  
			    delay(20);
                putpixel(x0 + x, y0 - y, WHITE);
				delay(20);
                putpixel(x0 - x, y0 - y, WHITE);  
			    delay(20);
                putpixel(x0 + y, y0 + x, WHITE);  
                delay(20);
                putpixel(x0 - y, y0 + x, WHITE);
                delay(20);
                putpixel(x0 + y, y0 - x, WHITE);  
			    delay(20);
                putpixel(x0 - y, y0 - x, WHITE);  
			    delay(20); 

                x++;
			    if (p < 0)  
			      {            
			        p += (2*x + 1);  
				  }   
			    if (p >= 0)  
			      {    
			        y -= 1;   
			        p += (1 -2*y); 
				  }     
		   	} 
	}   

	int main() 
	{  
	int gdriver=DETECT, gmode, x, y, r;  
	initgraph(&gdriver, &gmode, (char*)"");    

	printf("Enter radius of circle: ");  
	scanf("%d", &r);    
	printf("Enter co-ordinates of center(x and y): "); 
    scanf("%d%d", &x, &y);  
    drawcircle(x, y, r);  
	getch();  
	return 0; 
}