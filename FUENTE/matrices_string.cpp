#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
//DATOS DE ENTRADA DE FORMA FLOAT
float entrada(){
	float a;
	cin>>a;
	return a;
}
//DATOS DE ENTRADA DE NUESTRO STRING
string entrada_texto(){
	string a;
	cout<<"Entrar la oracion:";
	cin>>a;
	return a;
}
//RECOLECTAMSO NUESTROS DATOS DE CADA POSICION DE LA MATRIZ
void datos(float a[][3],int len){
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
			cout<<"Entrar los datos de la matriz:";
			a[i][j]=entrada();
			cout<<"\n";
		}
	}
}
//FUNCION QUE IMPRIMI LA MATRIZ
void imprimir(float a[][3],int len){
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
			cout<<"  "<<a[i][j]<<"  ";
		}
	cout<<"\n";	
	}
}
//FUNCION QUE HAYA EL MNIMO
float min(float a[][3],int len){
	float mini=a[0][0];
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
			if (a[i][j]<mini){
				mini=a[i][j];
			}
		}
	}
	return mini;
}	
//FUNCION QUE HALLA EL MAXIMO	
float maxi(float a[][3],int len){
	float maxi=a[0][0];
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
			if (a[i][j]>maxi){
				maxi=a[i][j];
			}
		}
	}
	return maxi;
}	
//FUNCION QUE HALLA EL PROMEDIO
float promedio(float a[][3],int len){
	float prom=0.0;
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
			prom=prom+a[i][j];
			}
		}
	
	prom=(prom/9);
	return prom;
}	
//FUNCION QUE OREDENA LOS DATOS DE MI MATRIZ DE MAYOR A MENOR
void ordenar(float a[][3],int len){
	float ultimo[9]={};
	float temp=0;
	int k=0;
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
				ultimo[k]=a[i][j];
				k++;
			}
		}
	for (int i=0;i<9;i++){
		for (int j=0;j<9-i;j++){
				if (ultimo[j]>ultimo[j+1]){
					temp=ultimo[j];
					ultimo[j]=ultimo[j+1];
					ultimo[j+1]=temp;
					}
			}
		}
	k=0;	
	for (int i=0;i<len;i++){
		for (int j=0;j<len;j++){
				a[i][j]=ultimo[k];
				k++;
			}	
		}	
}
//FUCION QUE PERMITE CORREGIR LOS ERRORES DE MI STRING ORACION Y OS IMPRIME DE ACUERDO A LA RESTRICCIONES
//ESTA ES LA FORMA SIN LIBRERIAS IMPORTADAS
void verificar_oracion(string a){
	int len=a.size();
	for (int i=0;i<len;i++){
		if ((int)a[i]>=97 and (int)a[i]<=122){
			cout<<a[i];
			}
		if ((int)a[i]>=65 and (int)a[i]<=90){
			cout<<" "<<a[i];
			}
		}
	}
//FUCION QUE PERMITE CORREGIR LOS ERRORES DE MI STRING ORACION Y OS IMPRIME DE ACUERDO A LA RESTRICCIONES	
//ESTA  ES LA FORMA CON LIBRERIAS IMPORTADAS
void verificar_oracion_2(string a){
	int len=a.size();
	int caracter=0;
	for (int i=0;i<len;i++){
		caracter=a[i];
		if (isalpha(a[i])){
			if ((isupper(a[i]))){
				cout<<" "<<a[i];
			}else{
				cout<<a[i];
				}
		}
	}
}	
int main() {
	float entrada[3][3]={};//DECLARACION DE MATRIZ
	float a1[4]={};//GUARDA LOS DATOS DE MINIMO,MAXIMO,PROMEDIO Y MEDIANA
	const int len=3;//TAMAÑAO DE LA MATRIZ
	string oracion=entrada_texto();//PEDIMOS EL TETO
	datos(entrada,len);//PEDIMOS LOS NUMEROS QUE TENDAR LA MATRIZ
	cout<<"Matriz inicial\n";
	imprimir(entrada,len);//IMPRESION DE LA MATRIZ ENTRANTE
	a1[0]=min(entrada,len);//HALLAMOS EL MINIMO
	cout<<"minimo::"<<a1[0]<<"\n";
	a1[1]=maxi(entrada,len);//HALLAMS EL MAXIMO
	cout<<"maximo::"<<a1[1]<<"\n";
	a1[2]=promedio(entrada,len);//HALLAMOS EL PROMEDIO
	cout<<"promedio::"<<a1[2]<<"\n";
	a1[3]=entrada[1][1];//HALLAMOS LA MEDIANA
	cout<<"mediana::"<<a1[3]<<"\n";
	ordenar(entrada,len);//ORDENAMOS LA MATRIZ DE MENOR A MAYOR
	cout<<"Matriz ordenada::\n";
	imprimir(entrada,len);//IMPRIMIMOS LA MATRIZ ORDENADA CON LA FUNCION ANTERIOR
	cout<<"Oracion corregida::\n";
	verificar_oracion(oracion);//VERIFICAMOS Y IMPIMOS LA ORACIN CON LA RESTRICCIONES DICHAS
	cout<<"\n";
	cout<<"Oracion corregida con funciones de libreria\n";
	verificar_oracion_2(oracion);//VERIFICAMOS Y IMPIMOS LA ORACIN CON LA RESTRICCIONES DICHAS
	cout<<"\n";
	return 0;
}
