/*int text_width=textwidth((char*)"Loading...");
	int text_height=textheight((char*)"Loading...");
	int x=width/2-text_width/2;
	int y=height/2-text_height/2-20;
	int n=1, ;;
	int page=0;
	while(n<=101)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
	
	 outtextxy(x,y,(char*)"Loading...");
	 rectangle(width/2-101,height/2-2,width/2+102,height/2+20+2);
	 stringstream s;
	 s<<n<<'%';
	 char ch[5];
	 s>>ch;
	 outtextxy(width/2-20,height/2+30,ch);
	 for(int i=1;i<=n*2;i++)
	 {
	 	line(width/2-100+i,height/2,width/2-100+i,height/2+20);
	 }
	 n++;
	page=1-page;
	delay(10);
	
	}*/