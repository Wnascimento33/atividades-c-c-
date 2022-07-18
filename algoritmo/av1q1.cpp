#include <iostream>
using namespace std;

//av1- Introdução a Programação Estruturada em C++.
//aluno: Wellington Antonio do Nascimento.
//1ª- A,B,C
 
int main(){
	
	float n1, n2;
	char crt;
	
	cout << "digite dois numeros:\n";
	cout << "1º:";
	cin >> n1;
	cout << "2º:";
	cin >> n2;
	
	cout << "QUAL OPERAÇÃO DESEJA FAZER:\n";
	cout << "[+] - Adicão\n";
	cout << "[-] - Subtracão\n";
	cout << "[*] - Multiplicacão\n";
	cout << "[/] - Divisão.\n";
	cin >> crt;
	
	switch(crt){
		
		case'+':
			cout << "A soma de "<< n1 <<" + "<< n2 << " = " << n1 + n2;
			break;
		case'-':
			cout <<  "A Subtracão de "<< n1 <<" - "<< n2 << " = " << n1 - n2;
			break;
		case'*':
			cout <<  "A Multiplicacão de "<< n1 <<" * "<< n2 << " = " << n1 * n2;
			break;
		case'/':
			if (n2 != 0 ){
				cout <<  "A Divisão de "<< n1 <<" / "<< n2 << " = " << n1 / n2;
			}
			else{
				cout << "O número não é divisivel por zero";
			} 
			break;
		default:
			cout << " ERRO! ESCOLHA UM OPERADOR VALIDO.";
			
	}
	
}
