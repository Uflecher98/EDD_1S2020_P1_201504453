
#include<iostream>
#include<stdlib.h>
#include<string>
#include<ncurses.h>
#include<string.h>
using namespace std;

//=======================================LISTA DOBLEMENTE ENLAZADA===================================================
   class Nodo_LD{
    private:
    char car;
    int id;
    Nodo_LD *anterior;
    Nodo_LD *siguiente;
    friend class ListaDoble;
    };

class ListaDoble{

  public:
   
   ListaDoble(){
     primero = NULL;
     ultimo = NULL;
     
     
   }
 
   
   void Insertar(int  referencia, char c, int i){
       Nodo_LD *nuevo = new Nodo_LD();
       nuevo->car = c;
       nuevo->id = i;

      Nodo_LD *actual = new Nodo_LD();
       actual = primero;
       bool enc = false;

       Nodo_LD *n = new Nodo_LD();

            while(actual != NULL && enc != true){

            if(actual->id ==  referencia){ //Encontró el nodo 
                n = actual;
                enc= true;
            }
           
              actual = actual -> siguiente;
           }
     
       if (primero == NULL){ //Vacío
              
           primero = nuevo;
           primero->siguiente = NULL;
           primero->anterior = NULL;
           ultimo = primero;
       }else if(n==primero){ //Al frente 
           
           ultimo ->siguiente = nuevo;
           nuevo -> siguiente = NULL;
           nuevo->anterior = ultimo;
           ultimo = nuevo;
       } else { //insertar después de 

           n->siguiente->anterior = nuevo;
           nuevo->siguiente = n->siguiente;
           n->siguiente = nuevo;
           nuevo->anterior = n;
       }
   }

   void InsercionSimple(char c, int i){

     
       Nodo_LD *nuevo = new Nodo_LD();
       nuevo->car = c;
       nuevo->id = i;
       if (primero == NULL){
             
           primero = nuevo;
           primero->siguiente = NULL;
           primero->anterior = NULL;
           ultimo = primero;
       }else {
           ultimo ->siguiente = nuevo;
           nuevo -> siguiente = NULL;
           nuevo->anterior = ultimo;
           ultimo = nuevo;
       } 
   }
   void Eliminar(int id){
       Nodo_LD *actual = new Nodo_LD();
       actual = primero;
       Nodo_LD *anterior = new Nodo_LD();
       anterior = NULL;
       bool enc = false;
       
       if(primero != NULL){
           while(actual != NULL && enc != true){

               if (actual->id == id) {
               
                   if (actual == primero){
                       primero = primero->siguiente ;
                       primero->anterior = NULL;
                   } else if(actual == ultimo){
                       anterior->siguiente = NULL;
                       ultimo = anterior;
                   } else{
                       anterior->siguiente = actual ->siguiente;
                       actual->siguiente->anterior = anterior;
                   }

                   enc = true;
               }
              anterior = actual;
              actual = actual -> siguiente;
           }
        if (!enc){
            cout<<"Nodo no encontrado ";
        }

       } else {
           cout<<"Lista vacía";
       }
   }

   void Modificar(int n, int id, char c){
        Nodo_LD *actual = new Nodo_LD();
       actual = primero;
       bool enc = false;
       
       if(primero != NULL){
           while(actual != NULL && enc != true){

            if(actual->id == n){
                actual->id = id;
                actual->car = c;
                enc= true;
            }
           
              actual = actual -> siguiente;
           }
        if (!enc){
            cout<<"Nodo no encontrado ";
        }

       } else {
           cout<<"Lista vacía";
       }
   }



   void Mostrar(){
       Nodo_LD *aux = new Nodo_LD();
       aux = primero;
  
       if (primero!= NULL){
         while (aux!= NULL){
            cout<<"["<<aux->id<<", "<<aux->car<<"] <--->";
            aux= aux->siguiente;
         }
       } else {
           cout<<"La lista está vacía";
       }
   }

   void Pantalla(int id){
       Nodo_LD *aux = new Nodo_LD();
       aux = primero;
  
       if (primero!= NULL){
         while (aux!= NULL){
            
            if (aux->id == id){
                printw("%c", aux->car);
            }
            
            aux= aux->siguiente;
         }
       } else {
           cout<<"La lista está vacía";
       }
   }
   
private:
 Nodo_LD *primero;
 Nodo_LD *ultimo;
};


//================================================ PILA ============================================================

struct Nodo{
    char p_buscar;
    char p_reemp;
    bool estado;
    char palabra;
    int posicion;

    Nodo *siguiente;
} ;

void push(Nodo *&, char, char, bool, char, int);
void pop(Nodo *&, int &);

void push(Nodo *&pila, char buscar, char reemplazar, bool estado, char palabra, int pos){
    Nodo *nuevo = new Nodo();
    nuevo->p_buscar = buscar;
    nuevo->p_reemp = reemplazar;
    nuevo->estado= estado;
    nuevo->palabra = palabra;
    nuevo->posicion= pos;
      
    nuevo->siguiente = pila;
    pila = nuevo;

}

void pop(Nodo *&pila, int &n){
  Nodo *aux = pila;
  n= aux->posicion;
  pila = aux->siguiente;
  delete aux;

}


//=======================================LISTA SIMPLE ORDENADA ============================================================

struct NodoSimple{
int id;
char palabra;
NodoSimple *siguiente;
};

void InsertarSimple(NodoSimple *&, int, string);
void MostrarSimple(NodoSimple *);
void BuscarSimple(NodoSimple *, int);
void EliminarSimple(NodoSimple *&, int);




void InsertarSimple(NodoSimple *&lista, int n, char nombre){
    NodoSimple *nuevo = new NodoSimple();
    nuevo->id = n;
    nuevo ->palabra = nombre;
    NodoSimple *a1 = lista;
    NodoSimple *a2;

    while ((a1 != NULL) && (a1->id < n)){
        a2 =  a1;
        a1 = a1->siguiente;
    }

    if (lista== a1){
        lista = nuevo;
    }
    else {
        a2->siguiente=nuevo;
    }

       nuevo -> siguiente = a1;
}


void MostrarSimple(NodoSimple *lista){
    NodoSimple *actual = new NodoSimple();
    actual = lista;
    while(actual != NULL){
        cout<<actual->id<<", "<<actual->palabra<<" --->";
        actual = actual->siguiente;
    }
}

void BuscarSimple(NodoSimple *lista, int n){
    bool x = false;

    NodoSimple *actual = new NodoSimple();
    actual = lista;

    while((actual != NULL) && (actual->id <= n)){
        if (actual -> id == n){
            x= true;
            cout<<"El nombre es: "<<actual->palabra;
        }
        actual = actual ->siguiente;
    }

    if (x==true){
        cout<<"Elemento "<<n<<" Se encontró";

    } else {
        cout<<"Elemento no Se encontró";
    }
}

void EliminarSimple(NodoSimple *&lista, int n){
    if (lista != NULL ){
        NodoSimple *aux1;
        NodoSimple *ante = NULL;
        aux1 = lista;
        
        while ((aux1 !=NULL)&&(aux1->id != n)){
            ante = aux1;
            aux1 = aux1->siguiente;
        }

        if (aux1 == NULL){
            cout<<"El elemento no existe";

        }else if (ante == NULL){
            lista = lista -> siguiente;
            delete aux1;

        } else {
            ante ->siguiente= aux1->siguiente;
            delete aux1;
        }
    }
}





//==========================================LISTA  CIRCULAR ===============================================================

struct NodoCircular{
int id;
char nombre;
char ruta;
NodoCircular *siguiente;
};

NodoCircular *primero = NULL;
NodoCircular *ultimo = NULL;

void InsertarRecientes(NodoCircular *&, int, char, char);
void MostrarRecientes(NodoCircular *);
void BuscarReciente(NodoCircular *, int);
void ElminarReciente(NodoCircular *&, int);

  
void InsertarRecientes(NodoCircular *&primero, int n, char nombre, char ruta){
    NodoCircular *nuevo = new NodoCircular();
    nuevo->id = n;
    nuevo->nombre = nombre;
    nuevo->ruta = ruta;
    NodoCircular *a2;

if (primero == NULL){
    primero = nuevo;
    primero->siguiente = primero;
    ultimo = primero;
} else {
    ultimo->siguiente = nuevo;
    nuevo ->siguiente = primero;
    ultimo = nuevo;
}
}


void MostrarRecientes(NodoCircular *primero){
    NodoCircular *actual = new NodoCircular();
    actual = primero;

    if (primero != NULL){
        do {
        cout<<actual->id<<", "<<actual->nombre<<" --->";
        actual = actual->siguiente;}
    
      while(actual != primero);
        cout<<actual->id;
    } else {
     cout<<"VACIO";
    }
   

}

void BuscarReciente(NodoCircular *lista, int n){
    bool x = false;

    NodoCircular *actual = new NodoCircular();
    actual = lista;

    while((actual != NULL) && (actual->id <= n)){
        if (actual -> id == n){
            x= true;
            cout<<"El nombre es: "<<actual->nombre;
        }
        actual = actual ->siguiente;
    }

    if (x==true){
        cout<<"Elemento "<<n<<" Se encontró";

    } else {
        cout<<"Elemento no Se encontró";
    }
}

void EliminarReciente(NodoCircular *&lista, int n){
    if (lista != NULL ){
        NodoCircular *aux1;
        NodoCircular *ante = NULL;
        aux1 = lista;
        
        while ((aux1 !=NULL)&&(aux1->id != n)){
            ante = aux1;
            aux1 = aux1->siguiente;
        }

        if (aux1 == NULL){
            cout<<"El elemento no existe";

        }else if (ante == NULL){
            lista = lista -> siguiente;
            delete aux1;

        } else {
            ante ->siguiente= aux1->siguiente;
            delete aux1;
        }
    }
}

//=========================================================================================================================

void ImprimirHead(){
    clear();
    move(2,2);
    printw("UNIVERSIDAD DE SAN CARLOS DE GUATEMALA");
    move(3,2);
    printw("FACULTAD DE INGENIERIA");
    move(4,2);
    printw("ESTRUCTURAS DE DATOS");
    move(5,2);
    printw("PRACTICA 1");
    move(6,2);
    printw("ULYSSES ORLANDO FLECHER GONZALEZ");
    move(7,2);
    printw("201504453");
    
    move(9,3);
    printw("MENU");
    move(10,3);
    printw("1. Crear Archivo");
    move(11,3);
    printw("2. Abrir Archivo");
    move(12,3);
    printw("3. Archivos Recientes");
    move(13,3);
    printw("4. Salir");

    move(11,30);
    printw("Opcion? ");
}


int key;
ListaDoble Principal;

void BuscarYReemplazar(int id_buscada){
    string funcionbr;
    char t[256];
    echo();
        move (2,0);
        printw ("Buscar y reemplazar: ");
        scanw("%s", t);
        
   
    funcionbr = (string)t;
    int n = funcionbr.length(); 
    char cadena[n + 1]; 
    strcpy(cadena, funcionbr.c_str()); 
    move(10,40);

        int x =0;
        int c1 =0;
      

    for (int i = 0; i < n; i++) {
        c1++;
     while(x!=1){
         
         if(cadena[i]==';'){
             char busc[c1-1];
              printw("tamaño 1: %i", sizeof(busc));
             x=1;
             c1=0;
         }
        
     }
   
    
     
     printw("%c", cadena[i]);
    }
      char reemp[c1];
         printw("tamaño 2: %i", sizeof(reemp));
    
    printw("\n");

        char *palabra[1];
    palabra[0] = strtok(cadena, ";"); //busc
    printf ("test 1: %s\n",palabra[0]); 
    palabra[1] = strtok (NULL, ""); //reemp
    printf ("test 2: %s\n",palabra[1]); 

    
    
   
    
         
    noecho();
       
}

void menu(){
    
    key = getch();
    int i = 4;
    int id = -1;

    switch (key)
    {
    case 49: //Crear archivo
        clear();
        move(0,0);
        printw("    ^w (Buscar y reemplazar)      ^c (Reportes)       ^s (Guardar)");
        move(4,2);
    
        do {
            key = getch();

            switch (key)
            {
            case 23:      //BUSCAR Y REEMPLAZAR 
                BuscarYReemplazar(id);

                break;
            case 10:      //ENTER 
                i++;                            
                move(i,2);
                //Principal.InsercionSimple(' ', id);
                Principal.Insertar(0, '\n', id);
                break;
            case 19:   //GUARDAR ARCHIVO 
                 
                 break;
            case 3: //GENERAR REPORTES

                break;
            case 127: //BACKSPACE


                break;
            default:
                      
                 id++;
                 //Principal.InsercionSimple((char)key, id);
                 Principal.Insertar(0, (char)key, id );
                 Principal.Pantalla(id);

                break;
            }
        } while (key != 27);

        refresh();
        clear();
        refresh();
        ImprimirHead();
        menu();


        break;
    
    case 50: //Abrir archivo 
        
    break;

    case 51: //Archivos recientes 

    break;

    case 52: //SALIR
            
        
            
    break;

    default:

        break;
    }
   
}

int main(){
  Nodo *pila = NULL;
  NodoSimple *lista = NULL;

  
   
   
  
    initscr();
    noecho();
    raw();
    keypad(stdscr, true);
    ImprimirHead();
 
    menu();
    
    
   
    endwin();

    Principal.Mostrar();
    

  return 0;
}

