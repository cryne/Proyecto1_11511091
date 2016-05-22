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
int juego(Carta**,int*,int*,int*,int,int,int);
int resultados(Carta**,int*,int*,int);
Carta** barajas(const int,const int);
void imprime_carta(Carta,int);
void mostrar_manos();
int main(int argc, char const *argv[])
{
	initscr();
	noecho();
	raw();
	start_color();
	srand(time(NULL));
	int enter,b,c,s,z,saldo_guardado=500;
	Carta** baraja=barajas(4,13);
	printw("presione cualquier tecla que no sea ESC para iniciar el programa");
	while(((z=getch())!=27)){
		limpiar();	
		getmaxyx(stdscr,s,c);
		mvprintw(s/2,(c/2)-15,"------------------------------");
		mvprintw((s/2)+1,(c/2)-15,"|      Nuevo juego(enter)    |");
		mvprintw((s/2)+2,(c/2)-15,"| Continuar saldo anterior(b)|");
		mvprintw((s/2)+3,(c/2)-15,"|          Salir(esc)        |");
		mvprintw((s/2)+4,(c/2)-15,"------------------------------");	
		if((enter=getch())==10){
			limpiar();
			int dinero=500;
			int control_eleccion=0; 
			int* ies=new int[5];
			int*jotas=new int[5];
			int* opciones_carta=new int[5];
			int control_rondas=1;
			for (int i = 0; i < 5; ++i)
			{
				opciones_carta[i]=0;
			}
			saldo_guardado=juego(baraja,ies,jotas,opciones_carta,control_eleccion,dinero,control_rondas);
			delete[] ies;
			delete[] jotas;
			delete[] opciones_carta;
			refresh();
		}else if((b=getch())==98){
			limpiar();
			int control_eleccion=0; 
			int* ies=new int[5];
			int*jotas=new int[5];
			int* opciones_carta=new int[5];
			int control_rondas=1;
			for (int i = 0; i < 5; ++i)
			{
				opciones_carta[i]=0;
			}
			saldo_guardado=juego(baraja,ies,jotas,opciones_carta,control_eleccion,saldo_guardado,control_rondas);
			delete[] ies;
			delete[] jotas;
			delete[] opciones_carta;
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
	for (int i = 0; i <z ; ++i)
	{
		for (int j = y; j < x; ++j)
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
	while(apuesta>dinero||apuesta==0){
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
void mostrar_manos(){
	mvprintw(14,48,"---Manos Especiales---");
	mvprintw(15,48,"|*Par de Jacks     x1|");
	mvprintw(16,48,"|*Dos Pares        x2|");
	mvprintw(17,48,"|*Trio             x3|");
	mvprintw(18,48,"|*Escalera 4       x4|");
	mvprintw(19,48,"|*Mismo manjar     x5|");
	mvprintw(20,48,"|*Full house       x9|");
	mvprintw(21,48,"|*Cuatro iguales  x25|");
	mvprintw(22,48,"|*Escalera simple x50|");
	mvprintw(23,48,"|*Escalera       x100|");
	mvprintw(24,48,"|*Escalera Real  x250|");
	mvprintw(25,48,"----------------------");
}
int resultados(Carta** baraja,int* ies,int* jotas,int apuesta){
	int numeros[5];
	string tipo[5];
	for (int i = 0; i < 5; ++i)
	{
		if(baraja[ies[i]][jotas[i]].getNumero()=="A"){
			numeros[i]=1;		
		}else if(baraja[ies[i]][jotas[i]].getNumero()=="J"){
			numeros[i]=11;
		}else if(baraja[ies[i]][jotas[i]].getNumero()=="Q"){
			numeros[i]=12;
		}else if(baraja[ies[i]][jotas[i]].getNumero()=="K"){
			numeros[i]=13;
		}else{
			numeros[i]=atoi(baraja[ies[i]][jotas[i]].getNumero().c_str());
		}
		tipo[i]=baraja[ies[i]][jotas[i]].getTipo().c_str();
	}
	int temporal;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j){
			if (numeros[j]>numeros[j+1])
			{
				temporal=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=temporal;
			}
		}	
	}
	if (numeros[0]==1&&numeros[1]==10&&numeros[2]==11&&numeros[3]==12&&numeros[4]==13&&tipo[0]==tipo[1]&&tipo[1]==tipo[2]&&tipo[2]==tipo[3]&&tipo[3]==tipo[4])
	{
		mvprintw(11,0,"Escalera Real,Ganancia:%d",apuesta*250);
		return apuesta*250;
	}else if (numeros[0]+1==numeros[1]&&numeros[1]+1==numeros[2]&&numeros[2]+1==numeros[3]&&numeros[3]+1==numeros[4]&&tipo[0]==tipo[1]&&tipo[1]==tipo[2]&&tipo[2]==tipo[3]&&tipo[3]==tipo[4])
	{
		mvprintw(11,0,"Escalera,Ganancia:%d",apuesta*100);
		return apuesta*100;
	}else if (numeros[0]+1==numeros[1]&&numeros[1]+1==numeros[2]&&numeros[2]+1==numeros[3]&&numeros[3]+1==numeros[4])
	{
		mvprintw(11,0,"Escalera simple,Ganancia:%d",apuesta*50);
		return apuesta*50;
	}else if (numeros[0]==numeros[1]&&numeros[0]==numeros[2]&&numeros[0]==numeros[3]||numeros[1]==numeros[2]&&numeros[1]==numeros[3]&&numeros[1]==numeros[4])
	{
		mvprintw(11,0,"4 iguales,Ganancia:%d",apuesta*25);
		return apuesta*25;
	}else if (numeros[0]==numeros[1]&&numeros[1]==numeros[2]&&numeros[3]==11&&numeros[3]==numeros[4]||numeros[2]==numeros[3]&&numeros[3]==numeros[4]&&numeros[0]==11&&numeros[0]==numeros[1])
	{
		mvprintw(11,0,"full house,Ganancia:%d",apuesta*9);
		return apuesta*9;
	}
	else if (numeros[0]==numeros[1]&&numeros[1]==numeros[2]&&numeros[3]==12&&numeros[3]==numeros[4]||numeros[2]==numeros[3]&&numeros[3]==numeros[4]&&numeros[0]==12&&numeros[0]==numeros[1])
	{
		mvprintw(11,0,"full house,Ganancia:%d",apuesta*9);
		return apuesta*9;
	}
	else if (numeros[0]==numeros[1]&&numeros[1]==numeros[2]&&numeros[3]==13&&numeros[3]==numeros[4]||numeros[2]==numeros[3]&&numeros[3]==numeros[4]&&numeros[0]==13&&numeros[0]==numeros[1])
	{
		mvprintw(11,0,"full house,Ganancia:%d",apuesta*9);
		return apuesta*9;
	}
	else if (numeros[0]==numeros[1]&&numeros[1]==numeros[2]&&numeros[3]==1&&numeros[3]==numeros[4]||numeros[2]==numeros[3]&&numeros[3]==numeros[4]&&numeros[0]==1&&numeros[0]==numeros[1])
	{
		mvprintw(11,0,"full house,Ganancia:%d",apuesta*9);
		return apuesta*9;
	}else if (tipo[0]==tipo[1]&&tipo[1]==tipo[2]&&tipo[2]==tipo[3]&&tipo[3]==tipo[4])
	{
		mvprintw(11,0,"mismo Manjar,Ganancia:%d",apuesta*5);
		return apuesta*5;
	}else if (numeros[0]+1==numeros[1]&&numeros[1]+1==numeros[2]&&numeros[2]+1==numeros[3]||numeros[1]+1==numeros[2]&&numeros[2]+1==numeros[3]&&numeros[3]+1==numeros[4]||numeros[0]+1==numeros[1]&&numeros[1]==numeros[2]&&numeros[2]+1==numeros[3]&&numeros[3]+1==numeros[4]||numeros[0]+1==numeros[1]&&numeros[1]+1==numeros[2]&&numeros[2]==numeros[3]&&numeros[3]+1==numeros[4])
	{
		mvprintw(11,0,"Escalera de 4,Ganancia:%d",apuesta*4);
		return apuesta*4;
	}else if(numeros[0]==numeros[1]&&numeros[1]==numeros[2]||numeros[1]==numeros[2]&&numeros[2]==numeros[3]||numeros[2]==numeros[3]&&numeros[3]==numeros[4]){
		mvprintw(11,0,"Trio,Ganancia:%d",apuesta*3);
		return apuesta*3;
	}else if (numeros[0]==1&&numeros[0]==numeros[1]&&numeros[2]==11&&numeros[2]==numeros[3]||numeros[0]==1&&numeros[0]==numeros[1]&&numeros[3]==11&&numeros[3]==numeros[4]||numeros[1]==1&&numeros[1]==numeros[2]&&numeros[3]==11&&numeros[3]==numeros[4])
	{
		mvprintw(11,0,"Dos pares,Ganancia:%d",apuesta*2);
		return apuesta*2;
	}else if (numeros[0]==11&&numeros[0]==numeros[1]&&numeros[2]==12&&numeros[2]==numeros[3]||numeros[0]==11&&numeros[0]==numeros[1]&&numeros[3]==12&&numeros[3]==numeros[4]||numeros[1]==11&&numeros[1]==numeros[2]&&numeros[3]==12&&numeros[3]==numeros[4])
	{
		mvprintw(11,0,"Dos pares,Ganancia:%d",apuesta*2);
		return apuesta*2;
	}else if (numeros[0]==12&&numeros[0]==numeros[1]&&numeros[2]==13&&numeros[2]==numeros[3]||numeros[0]==12&&numeros[0]==numeros[1]&&numeros[3]==13&&numeros[3]==numeros[4]||numeros[1]==12&&numeros[1]==numeros[2]&&numeros[3]==13&&numeros[3]==numeros[4])
	{
		mvprintw(11,0,"Dos pares,Ganancia:%d",apuesta*2);
		return apuesta*2;
	}else if(numeros[0]==11&&numeros[0]==numeros[1]||numeros[1]==11&&numeros[1]==numeros[2]||numeros[2]==11&&numeros[2]==numeros[3]||numeros[3]==11&&numeros[3]==numeros[4]){
		mvprintw(11,0,"Par de jacks,no pierdes nada");
		return apuesta;
	}
	else if(numeros[0]==12&&numeros[0]==numeros[1]||numeros[1]==12&&numeros[1]==numeros[2]||numeros[2]==12&&numeros[2]==numeros[3]||numeros[3]==12&&numeros[3]==numeros[4]){
		mvprintw(11,0,"Par de jacks,no pierdes nada");
		return apuesta;
	}
	else if(numeros[0]==13&&numeros[0]==numeros[1]||numeros[1]==13&&numeros[1]==numeros[2]||numeros[2]==13&&numeros[2]==numeros[3]||numeros[3]==13&&numeros[3]==numeros[4]){
		mvprintw(11,0,"Par de jacks,no pierdes nada");
		return apuesta;
	}
	else if(numeros[0]==1&&numeros[0]==numeros[1]||numeros[1]==1&&numeros[1]==numeros[2]||numeros[2]==1&&numeros[2]==numeros[3]||numeros[3]==1&&numeros[3]==numeros[4]){
		mvprintw(11,0,"Par de jacks,no pierdes nada");
		return apuesta;
	}else{
		mvprintw(11,0,"Derrota,pierdes lo que apostaste");
		return 0;
	}
}	
void guardar(){

}
int juego(Carta** baraja,int*ies,int*jotas,int*opciones_carta,int control_eleccion,int dinero,int control_rondas){
	int control=-1;
	while(control!=0){
		limpiar();
		control=-1;
		int apuesta;
		if(control_rondas==1){
			apuesta=apuestas(dinero);
			dinero=dinero-apuesta;
		}
		limpiar();	
		/*ies[0]=0;
		jotas[0]=0;
		ies[1]=1;
		jotas[1]=0;
		ies[2]=0;
		jotas[2]=3;
		ies[3]=1;
		jotas[3]=3;
		ies[4]=2;
		jotas[4]=3;*/
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
							int compara_i=ies[i],compara_j=jotas[i];
							if(compara_i==random_tipo&&compara_j==random_numero){
								revision=1;
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
							int compara_i=ies[i],compara_j=jotas[i];
							if(compara_i==random_tipo&&compara_j==random_numero){
								revision=1;
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
							int compara_i=ies[i],compara_j=jotas[i];
							if(compara_i==random_tipo&&compara_j==random_numero){
								revision=1;
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
							int compara_i=ies[i],compara_j=jotas[i];
							if(compara_i==random_tipo&&compara_j==random_numero){
								revision=1;
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
							int compara_i=ies[i],compara_j=jotas[i];
							if(compara_i==random_tipo&&compara_j==random_numero){
								revision=1;
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
		for (int i = 0; i < 5; ++i)
		{	
			imprime_carta(baraja[ies[i]][jotas[i]],i);
		}
		mvprintw(10,0,"Saldo no apostado:%d apuesta actual:%d",dinero,apuesta);	
		int bonus=1;
		if(control_rondas==2){
			control_rondas=1;
			bonus=resultados(baraja,ies,jotas,apuesta);
			for (int i = 0; i < 5; ++i)
			{
				opciones_carta[i]=0;
			}
			dinero=dinero+bonus;
		}else{
			control_rondas=2;
		}
		if (control_rondas+1==3){
			for (int i = 0; i < 5; ++i)
			{
				int descision=-1;   				
				while(descision!=0&&descision!=1){
					if(opciones_carta[i]==0){
						mvprintw(12,0,"-si ingresa presiona alguna tecla diferente a las opciones se le volvera a pedir-\nDesea quedarse con la carta numero %d?\n1-si\n0-no",i+1);
						mostrar_manos();
						if((descision=getch())==48){
							descision=0;
						}else if(descision==49){
							descision=1;
						}
					}else{
						descision=1; 
					}
				}   				
				opciones_carta[i]=descision;
			}		
		}
		limpiar_y(12);
		if (dinero+bonus!=0)
		{
			while(control!=0&&control!=1){
				limpiar_y(12);
				mvprintw(12,0,"-si ingresa presiona alguna tecla diferente a las opciones se le volvera a pedir-\nDesea continuar el juego, guardarlo o terminarlo?\n1-continuar\n2-terminar\n0-guardar");
				mostrar_manos();
				control=getch();
				if(control==48){
					limpiar_y(12);
					mvprintw(12,0,"si le da a la opcion podra continuar esta partida (presione cualquier tecla para volver al menu principal)");
					return dinero;
					control=0;
				}else if(control==49){
					control=1;
				}else if (control==50){
					control=0;
					limpiar_y(12);
					mvprintw(12,0,"El juego termino(presione cualquier tecla para volver al menu principal)");
				}
			}		
		}else{
			limpiar_y(12);
			mvprintw(12,0,"Ya no dispone de saldo para continuar,Gracias por jugar(presione cualquier tecla para volver al menu principal)");
			control=0;
		}				
		control_eleccion=1;
	}
	return 500;
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
void imprime_carta(Carta carta,int i){
	if(carta.getTipo()=="T"){
		mvprintw(0,16*i,"*-----------*");
		mvprintw(1,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(2,16*i,"|    (*)    |");
		mvprintw(3,16*i,"|  (*)*(*)  |");
		mvprintw(4,16*i,"|     |     |");
		mvprintw(5,16*i,"|    ***    |");
		mvprintw(6,16*i,"|           |");
		mvprintw(7,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(8,16*i,"*-----------*");
	}else if (carta.getTipo()=="P"){
		mvprintw(0,16*i,"*-----------*");
		mvprintw(1,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(2,16*i,"|     ^     |");
		mvprintw(3,16*i,"|    ***    |");
		mvprintw(4,16*i,"|   **|**   |");
		mvprintw(5,16*i,"|    ***    |");
		mvprintw(6,16*i,"|           |");
		mvprintw(7,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(8,16*i,"*-----------*");
	}else if (carta.getTipo()=="D"){
		mvprintw(0,16*i,"*-----------*");
		mvprintw(1,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(2,16*i,"|     ^     |");
		mvprintw(3,16*i,"|    ***    |");
		mvprintw(4,16*i,"|   *****   |");
		mvprintw(5,16*i,"|    ***    |");
		mvprintw(6,16*i,"|     *     |");
		mvprintw(7,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(8,16*i,"*-----------*");
	}else{
		mvprintw(0,16*i,"*-----------*");
		mvprintw(1,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(2,16*i,"|           |");
		mvprintw(3,16*i,"|    ^ ^    |");
		mvprintw(4,16*i,"|   *****   |");
		mvprintw(5,16*i,"|    ***    |");
		mvprintw(6,16*i,"|     *     |");
		mvprintw(7,16*i,"%s          %s",carta.getNumero().c_str(),carta.getNumero().c_str());
		mvprintw(8,16*i,"*-----------*");
	}
	
}
