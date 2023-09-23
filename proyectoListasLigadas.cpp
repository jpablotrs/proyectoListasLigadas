#include <iostream>
#include <string>
using namespace std;

class Cancion{
	private:
		string titulo;
		string cantante;
		int duracion;
		Cancion* sig;
	public:
		cancion(){
			titulo = "";
			cantante = "";
			duracion = 0;
			sig = NULL;
		}
		cancion(string tit, string can, int dur, Cancion* s){
			titulo = tit;
			cantante = can;
			duracion = dur;
			sig = s;
		}
		void setTitulo(string tit){
			titulo = tit;
		}
		void setCantante(string can){
			cantante = can;
		}
		void setDuracion(int dur){
			duracion = dur;
		}
		void setSig(Cancion* s){
			sig = s;
		}
		string getTitulo(){
			return titulo;
		}
		string getCantante(){
			return cantante;
		}
		int getDuracion(){
			return duracion;
		}
		Cancion* getSig(){
			return sig;
		}	
};

class ListaReproduccion{
	private:
		Cancion* cabeza;
		int prioridad;
		//tres variables auxiliares para pedir los daos
		string tituloAux;
		string cantanteAux;
		int duracionAux;
	public:
		ListaReproduccion(int prio){
			cabeza = NULL;
			prioridad = prio;
		}
		
		~ListaReproduccion(){
			Cancion* p = cabeza;
			while(p != NULL){
				cabeza = p->getSig();
				delete p;
				p = cabeza;
			}
		}
		
		//metodo para pedir datos de acuerdo a la prioridad
		void pedirDatos(){
			switch(prioridad){
				case 1:
					cout<<"Titulo: ";
					cin>>tituloAux;
					cout<<"Cantante: ";
					cin>>cantanteAux;
					cout<<"Duracion: ";
					cin>>duracionAux;
					break;
				case 2:
					cout<<"Cantante: ";
					cin>>cantanteAux;
					cout<<"Titulo: ";
					cin>>tituloAux;
					cout<<"Duracion: ";
					cin>>duracionAux;
					break;
				case 3:
					cout<<"Duracion: ";
					cin>>duracionAux;
					cout<<"Titulo: ";
					cin>>tituloAux;
					cout<<"Cantante: ";
					cin>>cantanteAux;
					break;
			}
		}
		
		void insertar(){
			Cancion *p = new Cancion();
			p->setTitulo(tituloAux);
			p->setCantante(cantanteAux);
			p->setDuracion(duracionAux);
			//Insertar cuando la lista esta vacia
			
			if(estaVacia()){
				p->setSig(NULL);
				cabeza = p;
			}
			
			//recorrer la lista para ver donde meter el dato de acuerdo a la prioridad
			Cancion* aux;
			Cancion* ant;
			ant = NULL;
			aux = cabeza;
			while(aux!=NULL){
				switch(prioridad){
					case 1:
							if(p->getTitulo().compare(aux->getTitulo()) < 0){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getTitulo() == aux->getTitulo()){
								//SE REVISAN LOS DEMAS PARAMETROS
								if(p->getCantante().compare(aux->getCantante()) < 0){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								if(p->getCantante() == aux->getCantante()){
								//SE REVISA el ultimo parametro
								if(p->getDuracion() <= aux->getDuracion()){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								//se inserta despues del aux
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
								}
							}
							break;
					case 2:
							if(p->getCantante().compare(aux->getCantante()) < 0){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getCantante() == aux->getCantante()){
								//SE REVISAN LOS DEMAS PARAMETROS
								if(p->getTitulo().compare(aux->getTitulo()) < 0){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								if(p->getTitulo() == aux->getTitulo()){
								//SE REVISA el ultimo parametro
								if(p->getDuracion() <= aux->getDuracion()){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								//se inserta despues del aux
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
							}
							break;
					case 3:
							if(p->getDuracion() < aux->getDuracion()){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getDuracion() == aux->getDuracion()){
								//SE REVISAN LOS DEMAS PARAMETROS
								if(p->getTitulo().compare(aux->getTitulo()) < 0){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								if(p->getTitulo() == aux->getTitulo()){
								//SE REVISA el ultimo parametro
								if(p->getCantante().compare(aux->getCantante()) < 0){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								//se inserta despues del aux
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
							}
							break;
				}
				ant = aux;
				aux = aux->getSig();
			}
		}
		
		int estaVacia(){
			if(cabeza == NULL)
				return 1;
			else
			
				return 0;
		}

		
		void mostrar(){
			if(estaVacia()){
				cout<<"Error, La lista de reproducción esta vacia";
				return;
			}
			Cancion* p = cabeza;
			while(p != NULL){
				//SE DEBEN IMPRIMIR CON UN SWITCH PARA LA Jerarquia
				
				
				p = p->getSig();
			}
		}
		
};



int main(){
	cout << "Hola mundo";
	
	return 0;
}
