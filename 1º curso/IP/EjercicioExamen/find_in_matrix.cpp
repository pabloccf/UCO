#include <iostream> 
using namespace std;

/** 
*
* Cree la funcion que busca el numero de veces que aparece el valor indicado en la matriz pasada
* 
* Nombre Funcion: find_in_matrix
* Parametros:
*   - matrix de flotantes de 6x6
*   - valor flotante a buscar
* Retorno: numero de veces que aparece el valor indicado.
*/
int find_in_matrix(float m[6][6],float val){
	int count=0;
	for(int i=0;i<6;i++){
		for(int j=0;i<6;i++){
			if(m[j][i]==val){
				count++;
			}
		}
	}	
	return count;
}
//No toque nada a partir de aqui
bool test_find_in_matrix();
int main(){
		if( test_find_in_matrix()) cout<<"Correcto"<<endl;
		else cout<<"Error"<<endl;
}
 


bool test_find_in_matrix(){
    cerr<<"testing..."<<__func__<<": ";
    float m[6][6]={ {1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,3,3,3,3},{4,4,4,4,4,4},{5,5,5,5,5,5},{-1,6,6,6,6,6}};
    if (find_in_matrix(m,3)!=6)return false;
    if (find_in_matrix(m,-1)!=1)return false;

    return true;
}
