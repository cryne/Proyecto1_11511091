#include "carta.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using std::cin;
using std::ostringstream;
using std::string;
using std::atoi;
void limpiar();
void limpiar_y(int);
void guardar();
int apuestas(int);
void juego(Carta**,int*,int*,int*,int,int);
int resultados(Carta**,int*,int*,int);
Carta** barajas(const int,const int);
int main(int argc, char const *argv[])
{
	initscr();
	noecho();
	raw();
	start_color();
	srand(time(NULL));
	int enter,b,c,s,z;
	Carta** baraja=barajas(4,13);
	printw("presione cualquier tecla que no sea ESC para iniciar el programa");
	while(((z=getch())!=27)){
	    limpiar();	
		getmaxyx(stdscr,s,c);
		mvprintw(s/2,(c/2)-15,"------------------------------");
    	mvprintw((s/2)+1,(c/2)-15,"|      Nuevo juego(enter)    |");
    	mvprintw((s/2)+2,(c/2)-15,"|       Ultima partida(b)    |");
    	mvprintw((s/2)+3,(c/2)-15,"|          Salir(esc)        |");
    	mvprintw((s/2)+4,(c/2)-15,"------------------------------");	
    	if((enter=getch())==10){
    		limpiar();
    		int dinero=500;
    		int control_eleccion=0; 
    		int* ies=new int[5];
    		int*jotas=new int[5];
    		int* opciones_carta=new int[5];
    		for (int i = 0; i < 5; ++i)
    		{
    			opciones_carta[i]=0;
    		}
    		juego(baraja,ies,jotas,opciones_carta,control_eleccion,dinero);
    		delete[] ies;
    		delete[] jotas;
    		delete[] opciones_carta;
    		refresh();
    	}else if((b=getch())==98){
    		move(s/2,(c/2)-15);
    		printw("b");
    		refresh();
    	}else{
    		move(s/2,(c/2)-15);
    		printw("hola inti");
    		refresh();
    	}   	
	}
	endwin();
	for (int i = 0; i <4; ++i)
	{
		delete[] baraja[i];
	}
	delete[] baraja;
	return 0;
}
void limpiar(){
 	int x,y;
	getmaxyx(stdscr,x,y);
	for (int i = 0; i <y ; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			mvprintw(j,i," ");
		}
	}
	move(0,0);
}
void limpiar_y(int y){
 	int x,z;
	getmaxyx(stdscr,x,z);
	for (int i = 0; i <x ; ++i)
	{
		for (int j = y; j < z; ++j)
		{
			mvprintw(j,i," ");
		}
	}
	move(y,0);
}
int apuestas(int dinero){
	int apuesta=dinero+1;	
	string dato="";
	char valor;
	int control;
	mvprintw(12,0,"De su saldo actual de %d cuanto desea apostar?",dinero);
	while(apuesta>dinero&&apuesta!=0){
		while((control=getch())!=10){
			limpiar();
			mvprintw(12,0,"De su saldo actual de %d cuanto desea apostar?",dinero);
			if(control>47&&control<58){
				valor=control;
				dato.push_back(valor);
				mvprintw(13,0,"%s",dato.c_str());
			}else{
				mvprintw(13,0,"%s",dato.c_str());
			}
			apuesta=atoi(dato.c_str());
		}
		dato.clear();
	}	
	return apuesta;
}
int resultados(Carta** baraja,int* ies,int* jotas,int apuesta){
	int numeros[5]
	for (int i = 0; i < 5; ++i)
	{
		if(baraja[ies[i]][jotas[i]]=)
	}
}
void guardar(){

}
void juego(Carta** baraja,int*ies,int*jotas,int*opciones_carta,int control_eleccion,int dinero){
	int control=-1;
	int control_rondas=1;
	while(control!=0){
		limpiar();
		control=-1;
		int apuesta;
		if(control_rondas==1);
			apuesta=apuestas(dinero);
	    }
		limpiar();	
		for (int i = 0; i < 5; ++i)
		{	
			if(i==0&&opciones_carta[i]==0){
				if(control_eleccion==1){
					int revision=1;
					int random_tipo=0;
					int random_numero=0;
					while(revision==1){
						random_tipo=rand()%4;
						random_numero=rand()%13;
						revision=0;
						for (int i = 0; i < 5; ++i)
						{
							if(opciones_carta[i]==1){
								int compara_i=ies[i],compara_j=jotas[i];
								if(compara_i==random_tipo&&compara_j==random_numero){
									revision=1;
								}
							}
						}
					}
					ies[i]=random_tipo;
					jotas[i]=random_numero;
				}else{
					ies[i]=rand()%4;
					jotas[i]=rand()%13;
				}
			}
			if(i==1&&opciones_carta[i]==0){
				if(control_eleccion==1){
					int revision=1;
					int random_tipo=0;
					int random_numero=0;
					while(revision==1){
						random_tipo=rand()%4;
						random_numero=rand()%13;
						revision=0;
						for (int i = 0; i < 5; ++i)
						{
							if(opciones_carta[i]==1){
								int compara_i=ies[i],compara_j=jotas[i];
								if(compara_i==random_tipo&&compara_j==random_numero){
									revision=1;
								}
							}
						}
					}
					ies[i]=random_tipo;
					jotas[i]=random_numero;
				}else{
					ies[i]=rand()%4;
					jotas[i]=rand()%13;
				}
			}
			if(i==2&&opciones_carta[i]==0){
				if(control_eleccion==1){
					int revision=1;
					int random_tipo=0;
					int random_numero=0;
					while(revision==1){
						random_tipo=rand()%4;
						random_numero=rand()%13;
						revision=0;
						for (int i = 0; i < 5; ++i)
						{
							if(opciones_carta[i]==1){
								int compara_i=ies[i],compara_j=jotas[i];
								if(compara_i==random_tipo&&compara_j==random_numero){
									revision=1;
								}
							}
						}
					}
					ies[i]=random_tipo;
					jotas[i]=random_numero;
				}else{
					ies[i]=rand()%4;
					jotas[i]=rand()%13;
				}
			}
			if(i==3&&opciones_carta[i]==0){
				if(control_eleccion==1){
					int revision=1;
					int random_tipo=0;
					int random_numero=0;
					while(revision==1){
						random_tipo=rand()%4;
						random_numero=rand()%13;
						revision=0;
						for (int i = 0; i < 5; ++i)
						{
							if(opciones_carta[i]==1){
								int compara_i=ies[i],compara_j=jotas[i];
								if(compara_i==random_tipo&&compara_j==random_numero){
									revision=1;
								}
							}
						}
					}
					ies[i]=random_tipo;
					jotas[i]=random_numero;
				}else{
					ies[i]=rand()%4;
					jotas[i]=rand()%13;
				}
			}
			if(i==4&&opciones_carta[i]==0){
				if(control_eleccion==1){
					int revision=1;
					int random_tipo=0;
					int random_numero=0;
					while(revision==1){
						random_tipo=rand()%4;
						random_numero=rand()%13;
						revision=0;
						for (int i = 0; i < 5; ++i)
						{
							if(opciones_carta[i]==1){
								int compara_i=ies[i],compara_j=jotas[i];
								if(compara_i==random_tipo&&compara_j==random_numero){
									revision=1;
								}
							}
						}
					}
					ies[i]=random_tipo;
					jotas[i]=random_numero;
				}else{
					ies[i]=rand()%4;
					jotas[i]=rand()%13;
				}
			}  					
		}
		printw("*-----------*");
		mvprintw(1,0,"%s          %s",baraja[ies[0]][jotas[0]].getNumero().c_str(),baraja[ies[0]][jotas[0]].getNumero().c_str());
		mvprintw(2,0,"|           |");
		mvprintw(3,0,"|           |");
		mvprintw(4,0,"|     %s     |",baraja[ies[0]][jotas[0]].getTipo().c_str());
		mvprintw(5,0,"|           |");
		mvprintw(6,0,"|           |");
		mvprintw(7,0,"%s          %s",baraja[ies[0]][jotas[0]].getNumero().c_str(),baraja[ies[0]][jotas[0]].getNumero().c_str());
		mvprintw(8,0,"*-----------*");

		mvprintw(0,16,"*-----------*");
		mvprintw(1,16,"%s          %s",baraja[ies[1]][jotas[1]].getNumero().c_str(),baraja[ies[1]][jotas[1]].getNumero().c_str());
		mvprintw(2,16,"|           |");
		mvprintw(3,16,"|           |");
		mvprintw(4,16,"|     %s     |",baraja[ies[1]][jotas[1]].getTipo().c_str());
		mvprintw(5,16,"|           |");
		mvprintw(6,16,"|           |");
		mvprintw(7,16,"%s          %s",baraja[ies[1]][jotas[1]].getNumero().c_str(),baraja[ies[1]][jotas[1]].getNumero().c_str());
		mvprintw(8,16,"*-----------*");

		mvprintw(0,32,"*-----------*");
		mvprintw(1,32,"%s          %s",baraja[ies[2]][jotas[2]].getNumero().c_str(),baraja[ies[2]][jotas[2]].getNumero().c_str());
		mvprintw(2,32,"|           |");
		mvprintw(3,32,"|           |");
		mvprintw(4,32,"|     %s     |",baraja[ies[2]][jotas[2]].getTipo().c_str());
		mvprintw(5,32,"|           |");
		mvprintw(6,32,"|           |");
		mvprintw(7,32,"%s          %s",baraja[ies[2]][jotas[2]].getNumero().c_str(),baraja[ies[2]][jotas[2]].getNumero().c_str());
		mvprintw(8,32,"*-----------*");

		mvprintw(0,48,"*-----------*");
		mvprintw(1,48,"%s          %s",baraja[ies[3]][jotas[3]].getNumero().c_str(),baraja[ies[3]][jotas[3]].getNumero().c_str());
		mvprintw(2,48,"|           |");
		mvprintw(3,48,"|           |");
		mvprintw(4,48,"|     %s     |",baraja[ies[3]][jotas[3]].getTipo().c_str());
		mvprintw(5,48,"|           |");
		mvprintw(6,48,"|           |");
		mvprintw(7,48,"%s          %s",baraja[ies[3]][jotas[3]].getNumero().c_str(),baraja[ies[3]][jotas[3]].getNumero().c_str());
		mvprintw(8,48,"*-----------*");

		mvprintw(0,64,"*-----------*");
		mvprintw(1,64,"%s          %s",baraja[ies[4]][jotas[4]].getNumero().c_str(),baraja[ies[4]][jotas[4]].getNumero().c_str());
		mvprintw(2,64,"|           |");
		mvprintw(3,64,"|           |");
		mvprintw(4,64,"|     %s     |",baraja[ies[4]][jotas[4]].getTipo().c_str());
		mvprintw(5,64,"|           |");
		mvprintw(6,64,"|           |");
		mvprintw(7,64,"%s          %s",baraja[ies[4]][jotas[4]].getNumero().c_str(),baraja[ies[4]][jotas[4]].getNumero().c_str());
		mvprintw(8,64,"*-----------*");
		mvprintw(10,0,"Saldo no apostado:%d apuesta actual:%d",dinero,apuesta);		
		for (int i = 0; i < 5; ++i)
		{
			int descision=-1;   				
			while(descision!=0&&descision!=1){
				if(opciones_carta[i]==0){
					mvprintw(12,0,"-si ingresa presiona alguna tecla diferente a las opciones se le volvera a pedir-\nDesea quedarse con la carta numero %d?\n1-si\n0-no",i+1);
					if((descision=getch())==48){
						descision=0;
					}else if(descision==49){
						descision=1;
					}
				}else{
					descision=1; 
				}
				limpiar_y(10);
			}   				
			opciones_carta[i]=descision;
		}
		if(control_rondas==2){
			control_rondas=1;

		}
		while(control!=0&&control!=1){
			mvprintw(12,0,"-si ingresa presiona alguna tecla diferente a las opciones se le volvera a pedir-\nDesea continuar el juego, guardarlo o terminarlo?\n1-continuar\n2-terminar\n0-guardar");
			control=getch();
			if(control==48){
				guardar();
				control=0;
			}else if(control==49){
				control=1;
			}else if (control==50){
				control=0;
			}
			limpiar_y(12);
		}
		limpiar();
		control_rondas+=1;
		control_eleccion=1;
	}
}
Carta** barajas(const int tipo,const int numero){
	Carta** baraja=new Carta*[tipo];
	for (int i = 0; i <tipo; ++i)
	{
		baraja[i]=new Carta[numero];
		if(i==0){
			for (int j = 0; j <numero; ++j)
			{
				if(j+1==1){
					baraja[i][j]=Carta("A","T");
				}else if(j+1==11){
					baraja[i][j]=Carta("J","T");
				}else if(j+1==12){
					baraja[i][j]=Carta("Q","T");
				}else if(j+1==13){
					baraja[i][j]=Carta("K","T");
				}else{
					baraja[i][j]=Carta(static_cast<ostringstream*>(&(ostringstream()<<(j+1)))->str(),"T");
				}				
			}
		}
		if (i==1)
		{
			for (int j = 0; j <numero; ++j)
			{
				if(j+1==1){
					baraja[i][j]=Carta("A","C");
				}else if(j+1==11){
					baraja[i][j]=Carta("J","C");
				}else if(j+1==12){
					baraja[i][j]=Carta("Q","C");
				}else if(j+1==13){
					baraja[i][j]=Carta("K","C");
				}else{
					baraja[i][j]=Carta(static_cast<ostringstream*>(&(ostringstream()<<(j+1)))->str(),"C");
				}				
			}
		}
		if (i==2)
		{
			for (int j = 0; j <numero; ++j)
			{
				if(j+1==1){
					baraja[i][j]=Carta("A","D");
				}else if(j+1==11){
					baraja[i][j]=Carta("J","D");
				}else if(j+1==12){
					baraja[i][j]=Carta("Q","D");
				}else if(j+1==13){
					baraja[i][j]=Carta("K","D");
				}else{
					baraja[i][j]=Carta(static_cast<ostringstream*>(&(ostringstream()<<(j+1)))->str(),"D");
				}				
			}
		}
		if (i==3 )
		{
			for (int j = 0; j <numero; ++j)
			{
				if(j+1==1){
					baraja[i][j]=Carta("A","P");
				}else if(j+1==11){
					baraja[i][j]=Carta("J","P");
				}else if(j+1==12){
					baraja[i][j]=Carta("Q","P");
				}else if(j+1==13){
					baraja[i][j]=Carta("K","P");
				}else{
					baraja[i][j]=Carta(static_cast<ostringstream*>(&(ostringstream()<<(j+1)))->str(),"P");
				}				
			}
		}
	}
	return baraja;
}
