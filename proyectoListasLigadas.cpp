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
<<<<<<< HEAD
					fflush(stdin);
					cout<<"Titulo: ";
					getline (cin, tituloAux);
					fflush(stdin);
					cout<<"Cantante: ";
					getline (cin, cantanteAux);
					fflush(stdin);
					cout<<"Duracion: ";
					cin >> duracionAux;
					cout << endl << endl;
					break;
				case 2:
					fflush(stdin);
					cout<<"Cantante: ";
					getline (cin, cantanteAux);
					fflush(stdin);
					cout<<"Titulo: ";
					getline (cin, tituloAux);
					fflush(stdin);
					cout<<"Duracion: ";
					cin >> duracionAux;
					cout << endl << endl;
					break;
				case 3:
					fflush(stdin);
					cout<<"Duracion: ";
					cin>>duracionAux;
					fflush(stdin);
					cout<<"Titulo: ";
					getline (cin, tituloAux);
					fflush(stdin);
					cout<<"Cantante: ";
					getline (cin, cantanteAux);
					fflush(stdin);
					cout << endl << endl;
					break;
			}
			system("cls");
=======
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
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
				return;
=======
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
								ant-> setSig(p);
=======
								ant->setSig(p);
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
								//p->setSig(aux->getSig());
								//aux->setSig(p);
								//return;
								}
							}
							if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
=======
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
								}
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
								//p->setSig(aux->getSig());
								//aux->setSig(p);
								//return;
						    	}
							}
							if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
=======
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
<<<<<<< HEAD
=======
							}
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
								//p->setSig(aux->getSig());
								//aux->setSig(p);
								//return;
								}
							}
							if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
=======
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
<<<<<<< HEAD
=======
							}
>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98
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
<<<<<<< HEAD
				cout<<"Error, La lista de reproduccion esta vacia"<<endl;
				return;
			}
			Cancion* p = cabeza;
			switch(prioridad){
				case 1:
					while(p != NULL){
						cout << p->getTitulo()<<endl;
						cout << p->getCantante()<<endl;
						cout << p->getDuracion()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
					}
					break;
				case 2:
					while(p != NULL){
						cout << p->getCantante()<<endl;
						cout << p->getTitulo()<<endl;
						cout << p->getDuracion()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
					}
					break;
				case 3:
					while(p != NULL){
						cout << p->getDuracion()<<endl;
						cout << p->getTitulo()<<endl;
						cout << p->getCantante()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
					}
					break;
			}
		}
		
		void eliminarCancionTitulo(string tit){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getTitulo() == tit)){
					cabeza = p->getSig();
					delete p;
					return;
				}else if(p->getTitulo() == tit){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
		}
		
		void eliminarCancionCantante(string can){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getCantante() == can)){
					cabeza = p->getSig();
					delete p;
					return;
				}else if(p->getCantante() == can){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
		}
		
		void eliminarCancionDuracion(int dur){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getDuracion() == dur)){
					cabeza = p->getSig();
					delete p;
					return;
				}else if(p->getDuracion() == dur){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
		}
		
};

void menu(ListaReproduccion* li){
	int opc = 1;
	while(opc>0 && opc<7){
		cout << "1. Insertar cancion."<<'\n'<<"2. Mostrar lista."<<'\n'<<"3. Eliminar cancion por titulo."<<'\n'<<"4. Eliminar cancion por cantante."<<'\n'<<"5. Eliminar cancion por duracion."<<'\n'<<"6. Salir"<<endl;	
		cin >> opc;
		switch(opc){
			case 1:
				li->pedirDatos();
				li->insertar();
				break;
			case 2:
				li->mostrar();
				break;
			case 3:
				li->eliminarCancionTitulo("or nah");
				break;
			case 4: 
				li->eliminarCancionCantante("peso pluma");
				break;
			case 5: 
				li->eliminarCancionDuracion(241);
				break;
			case 6:
				opc = 0;
				break;
		}
	}	
}
=======
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

>>>>>>> 84cdace687cf71bd64002cd9d002943a05adec98

int jerarquiaInsert(){
	int opc;
	do{
		cout << "Como quieres meter lo datos de las canciones: "<<endl;
		cout << "1. Por titulo."<<'\n'<<"2. Por cantante."<<'\n'<<"3. Por duracion."<<endl;
		cin >> opc;
	}while(opc<1 || opc>3);
	return opc;
}

void cancionesIniciales(ListaReproduccion* li){
	cout << "Con cuantas canciones quieres comenzar: "<<endl;
	int cant;
	cin >> cant;
	int j = 1;
	for(int i = 0 ; i < cant ; i++){
		cout <<"<---"<< " Cancion "<<j<<" --->"<<endl;
		li->pedirDatos();
		li->insertar();
		j = j+1;
	}
}

int main(){
	int prio = jerarquiaInsert();
	ListaReproduccion* li = new ListaReproduccion(prio);
	cancionesIniciales(li);
	menu(li);
	
	
	return 0;
}
