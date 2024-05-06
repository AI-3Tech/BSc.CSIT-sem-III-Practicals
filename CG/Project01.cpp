#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int width, height;

void rain(int xx, int yy, int midy)
{
        int i;
        for(i=0; i<50; i++)
        {
                settextstyle(0, HORIZ_DIR, 2);
                outtextxy(rand() % width, rand() % midy, (char*)"/");
        }
}

void Image1(int xx, int yy, int radius, int midy)
{
        circle(xx, yy, radius);

        line(xx, yy + radius, xx, yy + radius + 50);

        /* leg design */

        line(xx, yy + radius + 50, xx - 10, midy);

        line(xx, yy + radius + 50, xx + 10, midy - 30);

        line(xx + 10, midy - 30, xx + 10, midy);



        /* hand motion */

        line(xx, yy + radius + 10, xx - 15, yy + radius + 30);

        line(xx - 15, yy + radius + 30, xx + 15, yy + radius + 40);

        if(xx >= 100)
        {
                rain(xx, yy, midy);
                xx = xx + 30;
                delay(70);
        }
        //else
        //{
                xx += 10;
                delay(130);
        //}
        cleardevice();
}

void Image2(int xx, int yy, int radius, int midy)
{
         /* forwarding the position of stick man */

                setlinestyle(SOLID_LINE, 1, 3);

                line(0, midy, getmaxx(), midy);

                circle(xx, yy, radius);

                line(xx, yy + radius, xx, yy + radius + 50);



                /* leg design */

                line(xx, yy + radius + 50, xx - 15, midy);

                line(xx, yy + radius + 50, xx + 10, midy - 30);

                line(xx + 10, midy - 30, xx + 10, midy);



                /* hand motion */

                line(xx, yy + radius + 5, xx - 10, yy + radius + 20);

                line(xx - 10, yy + radius + 20, xx - 10, yy + radius + 45);

                line(xx, yy + radius + 5, xx + 5, yy + radius + 25);

                line(xx + 5, yy + radius + 25, xx + 15, yy + radius + 45);

        if(xx >= 100)
        {
                rain(xx, yy, midy);
                xx = xx + 30;
                delay(70);
        }
        //else
        //{
                xx += 10;
                delay(130);
        //}
        cleardevice();
}

void Image3(int xx, int yy, int radius, int midy)
{
        setlinestyle(SOLID_LINE, 1, 3);

        line(0, midy, getmaxx(), midy);

                circle(xx, yy, radius);

                line(xx, yy + radius, xx, yy + radius + 50);



                /* leg design */

                line(xx, yy + radius + 50, xx - 20, midy);

                line(xx, yy + radius + 50, xx + 20, midy);



                /* hand motion */

                line(xx, yy + radius + 5, xx - 20, yy + radius + 20);

                line(xx - 20, yy + radius + 20, xx - 20, yy + radius + 30);

                line(xx, yy + radius + 5, xx + 20, yy + radius + 25);

                line(xx + 20, yy + radius + 25, xx + 30, yy + radius + 30);

        if(xx >= 100)
        {
                rain(xx, yy, midy);
                xx = xx + 30;
                delay(70);
        }
        //else
        //{
                xx += 10;
                delay(130);
        //}
        cleardevice();
}

void Image4(int xx, int yy, int radius, int midy)
{


                setlinestyle(SOLID_LINE, 1, 3);

                line(0, midy, getmaxx(), midy);

                circle(xx, yy, radius);

                line(xx, yy + radius, xx, yy + radius + 50);



                /* leg design */

                line(xx, yy + radius + 50, xx - 8, midy - 30);

                line(xx - 8, midy - 30, xx - 25, midy);

                line(xx, yy + radius + 50, xx + 10, midy - 30);

                line(xx + 10, midy - 30, xx + 12, midy);



                /* hand motion */

                line(xx, yy + radius + 5, xx - 10, yy + radius + 10);

                line(xx- 10, yy + radius + 10, xx - 10, yy + radius + 30);

                line(xx, yy + radius + 5, xx + 15, yy + radius + 20);

                line(xx + 15, yy + radius + 20, xx + 30, yy + radius + 20);

        if(xx >= 100)
        {
                rain(xx, yy, midy);
                xx = xx + 30;
                delay(70);
        }
        //else
        //{
                xx += 10;
                delay(130);
        //}
        cleardevice();
}

void Image5(int xx, int yy, int radius, int midy)
{
                setlinestyle(SOLID_LINE, 1, 3);
                line(0, midy, getmaxx(), midy);

                circle(xx, yy, radius);

                line(xx, yy + radius, xx, yy + radius + 50);



                /* leg design */

                line(xx, yy + radius + 50, xx + 3, midy);

                line(xx, yy + radius + 50, xx + 8, midy - 30);

                line(xx + 8, midy - 30, xx - 20, midy);



                /* hand motion */

                line(xx, yy + radius + 5, xx - 15, yy + radius + 10);

                line(xx - 15, yy + radius + 10, xx - 8, yy + radius + 25);

                line(xx, yy + radius + 5, xx + 15, yy + radius + 20);

                line(xx + 15, yy + radius + 20, xx + 30, yy + radius + 20);
        
        if(xx >= 100)
        {
                rain(xx, yy, midy);
                xx = xx + 30;
                delay(70);
        }

        xx += 10;
        delay(130);        
        if(xx < (getmaxx() - 35))
                cleardevice();
}

int main()
{
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width,height,(char*)"Project01");
	int xx, yy, midy, radius = 10, i;

	xx = 50;

        midy = getmaxy() / 2 + 200;

        yy = midy - 100;

        /*

         * used 5 stick man (still/image)

         * position to get walking animation

         */

        while (xx < getmaxx() - 25) {

                setlinestyle(SOLID_LINE, 1, 3);

                /* road for stick man */

                line(0, midy, getmaxx(), midy);

                /* image 1  - first position of stick man */
                Image1(xx, yy, radius, midy);

                /* image 2 - second position of stick man */
                Image2(xx, yy, radius, midy); 

                /* image 3 */
                Image3(xx, yy, radius, midy);

                /* image 4 */
                Image4(xx, yy, radius, midy);

                /* image 5 */
                Image5(xx, yy, radius, midy);
                
	        if(xx > 100)
                        xx = xx + 30;
                else
                        xx = xx + 10;       
        }

	getch();
	return 0;
}