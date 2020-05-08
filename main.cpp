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


// nome do arquivo bin
const string ARQ = "log.dat";


// captura os dados e armazena na struct
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

// pega a informa��o ap�s alguma a��o no programa
int chamaMenu(){
	
	int x;
	
	cout << "0 - Menu principal" << endl;
	cout << "99 - Sair" << endl;
	cout << endl;
	cout << "Digite a opcao desejada: ";
	cin >> x;
	
	return x;
}
	

// insere os dados da struct no arquivo
int escreveDados(Log evento){
	
	// saida para o arquivo 
	ofstream file;
	
	// abre o arquivo log.dat para saida de dados, do tipo bin�rio e para inser��o ao final
	file.open(ARQ.c_str(), ios::out | ios::binary | ios::app);
	
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

// mostra na tela todos os registros armazenados no arquivo
int listarFisico(){
	
	// entrada para a programa
	ifstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e do tipo bin�rio
	file.open(ARQ.c_str(), ios::in | ios::binary);
	
	// se arquivo estiver aberto, escreve os dados da struct no arquivo e fecha
	if(file.is_open()){
		
		int x;
		
		// struct para receber os registros
		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		x = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);
		
		while(file.tellg() < x){
			
			// pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
            
            // Mostra o registro em tela                
            cout << evento.id << "\t" << evento.data << "\t" << evento.hora << "\t" << evento.tipo << endl;			
			
		}
		
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
			
			// testa o retorno para informar ao usuario se o registro foi feito
			if(opcao1 == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Registro inserido com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do la�o for ou simplesmente voltar ao for
				opcao1 = chamaMenu();
				
				// testa op��o do usuario, se for 0 simplesmente imprime na tela pois o for criado � infinito
				if(opcao1 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao1 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usu�rio <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = � necess�rio digitar uma op��o v�lida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e tamb�m finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao inserir registro no arquivo" << endl << endl;;
				break;
				
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
			
			int opcao6;
			
			system("cls");
			cout << endl << "\t" << ">>>> Listar f�sico <<<<" << "\t" << endl;
			cout << endl;
			
			opcao6 = listarFisico();
			
			
			// testa o retorno 
			if(opcao6 == 1){				
				
				cout << endl << endl << "\t" << ">>>> Listagem f�sica feita com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do la�o for ou simplesmente voltar ao for
				opcao6 = chamaMenu();
				
				// testa op��o do usuario, se for 0 simplesmente imprime na tela pois o for criado � infinito
				if(opcao6 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao6 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usu�rio <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = � necess�rio digitar uma op��o v�lida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e tamb�m finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao listar registros do arquivo" << endl << endl;;
				break;
				
			}
			
			
		}
		// propriedades
		else if(opcao == 7){
			
			return(7);
			
		}
		// sair
		else if(opcao == 99){
			
			system("cls");
			cout << "PROGRAMA FINALIZADO PELO USU�RIO" << endl << endl;
			break;
			
		}
		// op��o inv�lida
		else{
			
			system("cls");
			cout << "PROGRAMA INTERROMPIDO POR ERRO" << endl << endl;
			cout << "ERRO = � necess�rio digitar uma op��o v�lida" << endl << endl;;
			break;	
					
		}

	}


return EXIT_SUCCESS;

}
