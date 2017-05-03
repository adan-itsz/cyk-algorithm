#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include<vector>
#include<string>
using namespace std;

typedef struct{
	int header;
	int former;
	int latter;
	}rule;
	

typedef enum{Q=81,E=69,T=84,F=70,A1=200,A2,A3,A4,A5,A6,A7,A8,A9,A11,A12,A13,A14}generadores;
typedef enum{q=113,e=101,s=115,p=112,l=108,r=114,n=110,x=120}terminales;
	
typedef vector<rule>gramatica;
typedef set<int> conjunto;
typedef map<int,conjunto>row;
typedef map<int,row>table;

gramatica lista;
table N;

rule crearProduccion(int x, int y, int z);
void crearGramatica();
bool esMiembro(conjunto &c, int w);
void agregarAConjunto(conjunto &final, conjunto &uno, conjunto &dos);
void hacerConjuntos(conjunto &c,int a,int b);

bool cyk(gramatica &g,string &w);
void imprimirGramatica(gramatica &g);
 
	rule crearProduccion(int x, int y, int z){
		rule r;
		r.header=x;
		r.former=y;
		r.latter=z;
		return r;
	}
	
	void crearGramatica(){
		
		lista.push_back(crearProduccion(A1, l ,0));
		lista.push_back(crearProduccion(A2, q, 0));
		lista.push_back(crearProduccion(A3, n, 0));
		lista.push_back(crearProduccion(A4, r, 0));
		lista.push_back(crearProduccion(A5, p, 0));
		lista.push_back(crearProduccion(A6, s, 0));
		lista.push_back(crearProduccion(A7, A2, A8));
		lista.push_back(crearProduccion(A8, Q, A9));
		lista.push_back(crearProduccion(A9,E,Q));
		lista.push_back(crearProduccion(Q,E,A7));
		lista.push_back(crearProduccion(Q,A3,E));
		lista.push_back(crearProduccion(Q,A1,A11));
		lista.push_back(crearProduccion(A11,Q,A4));
		lista.push_back(crearProduccion(Q,x,0));
		lista.push_back(crearProduccion(Q,T,A12));
		lista.push_back(crearProduccion(A12,A5,F));
		lista.push_back(crearProduccion(Q,E,A13));
		lista.push_back(crearProduccion(A13,A6,T));
		lista.push_back(crearProduccion(E,E,A13));
		lista.push_back(crearProduccion(E,A1,A11));
		lista.push_back(crearProduccion(E,A3,E));
		lista.push_back(crearProduccion(E,x,0));
		lista.push_back(crearProduccion(E,T,A12));
		lista.push_back(crearProduccion(T,T,A12));
		lista.push_back(crearProduccion(T,A1,A11));
		lista.push_back(crearProduccion(T,A3,E));
		lista.push_back(crearProduccion(T,x,0));
		lista.push_back(crearProduccion(F,A10,A11));
		lista.push_back(crearProduccion(F,A3,E));
		lista.push_back(crearProduccion(F,x,0));
		
		
		}
		
	bool esMiembro(conjunto &c, int w){
			return c.find(w)!= c.end();
	}
			
	void agregarAConjunto(conjunto &final, conjunto &uno, conjunto &dos){
		conjunto::iterator it;
		conjunto::iterator it2;
			for(it=uno.begin();it != uno.end();it++){
				for(it2=dos.begin();it2 !=dos.end();it2++){
						hacerConjuntos(final,*it,*it2);
					}
				}
		}		
		
	void hacerConjuntos(conjunto &c,int a,int b){
		
		gramatica::iterator i; 
			for ( i = lista.begin(); i != lista.end(); i++){
				if(i->former==a && i->latter==b){
					c.insert(i->header);
					}
				}
		}
			
		
	void hacerConjuntos(conjunto &c,int w){
		
		gramatica::iterator i; 
			for ( i = lista.begin(); i != lista.end(); i++){
				if(i->former==w || i->latter==w){ 
					c.insert(i->header);
					}
				}
		}
	
	
	
	bool cyk(gramatica &g,string &w){
		int n=w.length();
		for(int i=0;i<=n;i++)
			hacerConjuntos(N[i][1],w[i-1]);
		for(int j=2;j<=n;j++){
			for(int i=1;i<=n-j+1;i++){
				for(int k=1;k<=j-1;k++){
					
					agregarAConjunto(N[i][j],N[i][k],N[i+k][j-k]);
					
					}
				}
			
			}	
			
		return esMiembro(N[1][n],Q);
		}
		
	void imprimirGramatica(gramatica &g){
		
			 gramatica::iterator i; 
			for ( i = g.begin(); i != g.end(); i++){
			cout<<static_cast<char>(i->header)<<"->  "<<static_cast<char>(i->former)<<"  "<<static_cast<char>(i->latter)<<endl;
		}
		}	

int main(){
    
    bool valor;
    string cadena; 
    crearGramatica();
    cout<<"ingrese una cadena: ";
    cin>>cadena;
    cout<<endl;
    imprimirGramatica(lista);
    valor=cyk(lista,cadena);
     if(valor)
     cout<< "la cadena "<< cadena<< " esta en el lenguaje de la gramatica"<<endl;
     else
     cout<< "la cadena "<< cadena<< " no esta en el lenguaje de la gramatica"<<endl;

    system("PAUSE");
    return 0;
}
