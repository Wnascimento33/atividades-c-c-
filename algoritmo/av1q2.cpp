#include <iostream>
#include <string>
using namespace std;

//av1- Introdução a Programação Estruturada em C++.
//aluno: Wellington Antonio do Nascimento.
//2ª- A,B,C
 
int main(){
	
	float peso, alt, imc;
	int idade;
	string nome; 
	char sexo;
	
	cout << "Digite seu nome:";
	cin >> nome;
	cout << "\nDigite sua idade:";
	cin >> idade;
	cout << "\nDigite seu peso:";
	cin >> peso;
	cout << "\nDigite sua altura:";
	cin >> alt;
	
	cout << "Sexo:\n";
	cout << "[M] - Homem\n";
	cout << "[F] - Mulher\n";
	cin >> sexo;
	
	if (idade < 18)
	{
		cout << nome <<", não há calculo de IMC para menores de 18 anos.";
	}
	switch(sexo)
	{
		case'M':
		case'm':
			imc = peso / (alt * alt);
			if(imc >= 40){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificado como Obesidade mórbida.";
			} 
			else if(imc >= 30 && imc < 40){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificado como Obesidade moderada.";
			}
			else if(imc >= 25 && imc < 30){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificado como Obesidade leve.";
			}
			else if(imc >= 20 && imc < 24){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificado como Normal.";
			}
			else if(imc < 20){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificado como Abaixo do normal.";
			}
			break;
		case'F':
		case'f':
			imc = peso / (alt * alt);
			if(imc >= 39){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificada como Obesidade mórbida.";
			} 
			else if(imc >= 29 && imc < 39){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificada como Obesidade moderada.";
			}
			else if(imc >= 24 && imc < 29){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificada como Obesidade leve.";
			}
			else if(imc >= 19 && imc < 24){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificada como Normal.";
			}
			else if(imc < 19){
				cout <<nome<< ", seu IMC é igual a "<<imc<< " e é classificada como Abaixo do normal.";
			}
			break;
		default:
			cout << "opcao invalida!";
				
	}
	return 0;
	
	
}
