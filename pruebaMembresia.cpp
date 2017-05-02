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
typedef enum{Q=81,E=69,T=84,F=70}generadores;
typedef enum{q=113,e=101,s=115,p=112,l=108,r=114,n=110,x=120}terminales;
	
typedef vector<rule>gramatica;
typedef set<int> conjunto;
typedef map<int,conjunto>row;
typedef map<int,conjunto>table;

gramatica lista;
 
	rule crearProduccion(int x, int y, int z){
		rule r;
		r.header=x;
		r.former=y;
		r.latter=z;
		return r;
	}
	
	void crearGramatica(){
		lista.push_back(crearProduccion(Q,q ,e));
		lista.push_back(crearProduccion(E,r ,n));
		lista.push_back(crearProduccion(T, Q,x));
		lista.push_back(crearProduccion(F,q ,s));
		lista.push_back(crearProduccion(F,l,n));
		
		}
	
	
	/*bool cyk(gramatica &g,string &w){
		
		
		
		}*/
		
	void imprimirGramatica(gramatica &g){
		
			 gramatica::iterator i; 
			for ( i = g.begin(); i != g.end(); i++){
			cout<<static_cast<char>(i->header)<<"->  "<<static_cast<char>(i->former)<<"  "<<static_cast<char>(i->latter)<<endl;
			//printf("%c -> %c %c \n",i->header,i->former, i->latter);
		}
		}	

int main(){
    
    string cadena; 
    crearGramatica();
    cout<<static_cast<char>(69);
    cout<<"ingrese una cadena: ";
    cin>>cadena;
    cout<<endl;
    imprimirGramatica(lista);
    
     

    system("PAUSE");
    return 0;
}
