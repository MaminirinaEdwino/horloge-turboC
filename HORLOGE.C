#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void horloge();

int main()
{
	horloge();
	getch();
	return 0;
}

void horloge(){
	int angle ;
	union REGS horloge;
	//union REGS ecran, sortie;
	
	//union REGS mode_graphique, sortie2, mode_texte, sortie3;
	union REGS date;
	int heure;
	int minute;
	int seconde;
	char str_s[10], str_m[10], str_h[10];

	int i = 0;
	int j = 0;
	int gd = DETECT, gm;
	int long_h_x = 100, long_h_y  = 100;
	int long_m_x = 87.5, long_m_y = 87.5; 
	int long_s_x = 75, long_s_y = 75;
	int jour, date_jour, mois, anne;
	char str_j[20], str_d[20], str_mois[20], str_a[20];
	horloge.h.ah =0x2c;
	date.h.ah = 0x2a;
	/*ecran.h.ah =0x06;
	ecran.h.al = 0;
	ecran.h.dh = 24;
	ecran.h.dl = 79;
	ecran.h.bh = 7;
	ecran.x.cx = 0;*/
	//mode_graphique.h.al = 0x03;
	//mode_graphique.h.ah = 0x00;
	//mode_texte.h.al = 0x13;
	//mode_texte.h.ah = 0x00;

	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	//cadre
	//int86(0x21, &date, &date);
	/*jour = date.h.al;
	anne = date.x.cx;
	mois = date.h.dh;
	date_jour = date.h.dl;*/
	//printf("%d %d %d %d\n", date_jour, jour, mois, anne);

	//int86(0x10, &mode_graphique, &sortie2);
	while(1){
		//int86(0x10, &ecran, &sortie);
		
		int86(0x21, &horloge, &horloge);
		int86(0x21, &date, &date);
		jour = date.h.al;
		anne = date.x.cx;
		mois = date.h.dh;
		date_jour = date.h.dl;
		
		heure = horloge.h.ch;
		minute = horloge.h.cl;
		seconde = horloge.h.dh;
	
		angle = (seconde*6)-90;
		long_s_x = 150+(85*cos(angle*(3.14/180)));
		long_s_y = 150+(85*sin(angle*(3.14/180)));
		angle = (minute*6)-90;
		long_m_x = 150+(65*cos(angle*(3.14/180)));
		long_m_y = 150+(65*sin(angle*(3.14/180)));
		/*angle = (heure*15)-180;
		long_h_x = 150+(50*cos(-angle*(3.14/180)));
		long_h_y = 150+(50*sin(-angle*(3.14/180)));*/
		//minute
		//heure
		if (heure == 0)
		{
			long_h_x = 150;
			long_h_y = 100;
		}
		if (heure == 1 || heure == 13)
		{
			long_h_x = 175;
			long_h_y = 105;
		}
		if (heure == 2 || heure == 14)
		{
			long_h_x = 140;
			long_h_y = 125;
		}
		if (heure == 3 || heure == 15)
		{
			long_h_x = 200;
			long_h_y = 150;
		}
		if (heure == 4 || heure == 16)
		{
			long_h_x = 190;
			long_h_y = 175;
		}
		if (heure == 5 || heure == 17)
		{
			long_h_x = 175;
			long_h_y = 190;
		}
		if (heure == 6 || heure == 18)
		{
			long_h_x = 150;
			long_h_y = 200;
		}
		if (heure == 7 || heure == 19)
		{
			long_h_x = 125;
			long_h_y = 190;
		}
		if (heure == 8 || heure == 20)
		{
			long_h_x = 105;
			long_h_y = 175;
		}
		if (heure == 9 || heure == 21)
		{
			long_h_x = 100;
			long_h_y = 150;
		}
		if (heure == 10 || heure == 22)
		{
			long_h_x = 65;
			long_h_y = 125;
		}
		if (heure == 11 || heure == 23)
		{
			long_h_x = 125;
			long_h_y = 105;
		}
		
		
		cleardevice();
		line(50,50,250, 50);
		line(50,50,50,250);
		line(50,250,250,250);
		line(250,50,250,250);

		line(30,30,270, 30);
		line(30,30,30,270);
		line(30,270,270,270);
		line(270,30,270,270);		
		//12h
		line(150,48,150,52);
		outtextxy(147, 40, "12");
		//11h
		line(100,48,100,52);
		outtextxy(98, 40, "11");
		//1h
		line(200,48,200,52);
		outtextxy(200, 40, "1");
		//6h
		line(150,248,150,252);
		outtextxy(150, 253, "6");
		//7h
		line(100,248,100,252);
		outtextxy(100, 253, "7");
		//5h
		line(200,248,200,252);
		outtextxy(200, 253, "5");
		//10h
		line(48,100,52,100);
		outtextxy(38, 100, "10");
		//9h
		line(48,150,52,150);
		outtextxy(39, 147, "9");
		//8h
		line(48,200,52,200);
		outtextxy(38, 197, "8");

		//2h
		line(248,100,252,100);
		outtextxy(255, 100, "2");
		//3h
		line(248,150,252,150);
		outtextxy(255, 147, "3");

		//4h
		line(248,200,252,200);
		outtextxy(255, 197, "4");
		itoa(seconde, str_s, 10);
		itoa(minute, str_m, 10);
		itoa(heure, str_h, 10);
		outtextxy(198, 200,  str_s);
		outtextxy(148, 200, str_m);
		outtextxy(98, 200, str_h);
		if (jour == 0){
			outtextxy(65, 215, "Dimanche");
		}
		if (jour == 1)
		{
			outtextxy(65, 215, "Lundi");
		}
		if (jour == 2)
		{
			outtextxy(65, 215, "Mardi");
		}
		if (jour == 3)
		{
			outtextxy(65, 215, "Mercredi");
		}
		if (jour == 4)
		{
			outtextxy(65, 215, "Jeudi");
		}
		if (jour == 5)
		{
			outtextxy(65, 215, "Vendredi");
		}
		if (jour == 6)
		{
			outtextxy(65, 215, "Samedi");
		}

		if (mois == 1)
		{
			outtextxy(170, 215, "Janvier");
		}
		if (mois == 2)
		{
			outtextxy(170, 215, "Fevrier");
		}
		if (mois == 3)
		{
			outtextxy(170, 215, "Mars");
		}
		if (mois == 4)
		{
			outtextxy(170, 215, "Avril");
		}
		if (mois == 5)
		{
			outtextxy(170, 215, "Mais");
		}
		if (mois == 6)
		{
			outtextxy(170, 215, "Juin");
		}
		if (mois == 7)
		{
			outtextxy(170, 215, "Juillet");
		}
		if (mois == 8)
		{
			outtextxy(170, 215, "Aout");
		}
		if (mois == 9)
		{
			outtextxy(170, 215, "Septembre");
		}
		if (mois == 10)
		{
			outtextxy(170, 215, "Octobre");
		}
		if (mois == 11)
		{
			outtextxy(170, 215, "Novembre");
		}
		if (mois == 12)
		{
			outtextxy(170, 215, "Decembre");
		}
		itoa(date_jour, str_d, 10);
		itoa(anne, str_a, 10);
		outtextxy(144, 215, str_d);
		outtextxy(134, 225, str_a);
		line(150,150,long_s_x, long_s_y);
		line(150,150,long_m_x, long_m_y );
		line(150,150,long_h_x, long_h_y);
		//seconde
		line(300, 100, 300,200);
		line(350, 100, 350, 200);
		line(300, 100, 350,100);
		line(300, 200, 350,200);

		for (j = 0; j < i; ++j)
		{
			line(300, 100+j, 350, 100+j);
		}
		i++;
		if (i==100)
		{
			i=0;
		}
		delay(1000);
		
		
	}
}
