#include <iostream>
using namespace std;

//av1- Introdu��o a Programa��o Estruturada em C++.
//aluno: Wellington Antonio do Nascimento.
//1�- A,B,C
 
int main(){
	
	float n1, n2;
	char crt;
	
	cout << "digite dois numeros:\n";
	cout << "1�:";
	cin >> n1;
	cout << "2�:";
	cin >> n2;
	
	cout << "QUAL OPERA��O DESEJA FAZER:\n";
	cout << "[+] - Adic�o\n";
	cout << "[-] - Subtrac�o\n";
	cout << "[*] - Multiplicac�o\n";
	cout << "[/] - Divis�o.\n";
	cin >> crt;
	
	switch(crt){
		
		case'+':
			cout << "A soma de "<< n1 <<" + "<< n2 << " = " << n1 + n2;
			break;
		case'-':
			cout <<  "A Subtrac�o de "<< n1 <<" - "<< n2 << " = " << n1 - n2;
			break;
		case'*':
			cout <<  "A Multiplicac�o de "<< n1 <<" * "<< n2 << " = " << n1 * n2;
			break;
		case'/':
			if (n2 != 0 ){
				cout <<  "A Divis�o de "<< n1 <<" / "<< n2 << " = " << n1 / n2;
			}
			else{
				cout << "O n�mero n�o � divisivel por zero";
			} 
			break;
		default:
			cout << " ERRO! ESCOLHA UM OPERADOR VALIDO.";
			
	}
	
}
