#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <locale.h>

using namespace std;


struct Log {
	
	int id; // valor chave
	char data[8]; // xx/xx/xx
	char hora[5]; // xx:xx
	int tipo; // 0 para perda de v�deo e 1 para detec��o de movimento
	
}; // 24 bytes 


const string NOMEARQUIVO = "log.dat";


// fun��o para capturar os dados da struct
Log capturaDados(){
	
	// struct
	Log evento;
		
	system("cls");
	cout << endl << "\t" << ">>>> Captura dados <<<<" << "\t" << endl;
	cout << endl;
	
	cout << "Informe a ID: ";
	cin >> evento.id;	
		
	cout << endl << endl << "[0] = Perda de v�deo || [1] Detec��o de movimento" << endl;
	cout << "Informe o tipo de evento: ";
	cin >> evento.tipo;	
	
	cout << endl << endl << "Exemplo de data: XX/XX/XX" << endl;
	cout << "Insira a data: ";
	cin.ignore();
	gets(evento.data);	
		
	cout << endl << endl << "Exemplo de hora: XX:XX" << endl;
	cout << "Insira a data: ";
	cin.ignore();
	gets(evento.hora);
	
	return evento;
	
} 

int escreveDados(Log evento){
	
	ofstream file;
	
	// abre o arquivo log.dat para saida de dados, do tipo bin�rio e para inser��o ao final
	file.open(NOMEARQUIVO.c_str(), ios::out | ios::binary | ios::app);
	
	// se arquivo estiver aberto, escreve os dados da struct no arquivo e fecha
	if(file.is_open()){
		
		file.write((char*)&evento, sizeof(Log));
		
		file.close();
		
		return 1;
		
	}
	
	else {
		
		cout << "Ops, o arquivo n�o foi aberto" << endl;
		
		return 0;
	}
	
}



int main() {
	
	// pt-br
	setlocale(LC_ALL, "Portuguese");

	int opcao = 555;
	
	for(int i=0;;){
	
		system("cls");
		cout << endl << "\t" << ">>>> Menu de op��es <<<<" << "\t" << endl;
		cout << endl;
		cout << "1 - Incluir" << endl;
		cout << "2 - Exluir" << endl;
		cout << "3 - Alterar" << endl;
		cout << "4 - Consultar" << endl;
		cout << "5 - Listar l�gico" << endl;
		cout << "6 - Lista f�sico" << endl;
		cout << "7 - Propriedades" << endl;
		cout << "99 - Sair" << endl;
		cout << endl;
		cout << "Digite a opcao desejada: ";
		cin >> opcao;	
		
		// incluir
		if(opcao == 1){
			
			// declara struct
			Log evento; 
			
			// variavel usada para pegar o retorno da fun��o
			int opcao1;
			
			// chama fun��o pra pegar dados
			evento = capturaDados(); 
			
			// chama funcao para escrever no arquivo
			opcao1 = escreveDados(evento);
			
			if(opcao1 == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Registro inserido com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				cout << "0 - Menu principal" << endl;
				cout << "99 - Sair" << endl;
				cout << endl;
				cout << "Digite a opcao desejada: ";
				cin >> opcao1;
				
				if(opcao1 == 0){
					
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
					
				}
				
				else if(opcao1 == 99){
				
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usu�rio <<<<" << "\t" << endl;
					exit(0);
					
				}
				
				else {
					
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl;
					cout << "ERRO = � necess�rio digitar uma op��o v�lida" << endl << endl;;
					exit(0);
					
				}
			}
			
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Erro ao inserir o registro no banco de dados <<<<" << "\t" << endl;
				cout << endl;
				
			}
			
			
		}
		// excluir
		else if(opcao == 2){
			
			return(2);
			
		}
		// alterar
		else if(opcao == 3){
			
			return(3);
			
		}
		// consultar
		else if(opcao == 4){
			
			return(4);
			
		}
		// listar l�gico
		else if(opcao == 5){
			
			return(5);
			
		}
		// listar f�sico
		else if(opcao == 6){
			
			return(6);
			
		}
		// propriedades
		else if(opcao == 7){
			
			return(7);
			
		}
		// sair
		else if(opcao == 99){
			
			system("cls");
			cout << "PROGRAMA FINALIZADO PELO USU�RIO" << endl << endl;
			exit(0);
			
		}
		// op��o inv�lida
		else{
			
			system("cls");
			cout << "PROGRAMA INTERROMPIDO POR ERRO" << endl << endl;
			cout << "ERRO = � necess�rio digitar uma op��o v�lida" << endl << endl;;
			system("pause");	
					
		}

	}


return EXIT_SUCCESS;

}
