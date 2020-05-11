#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <locale.h>

using namespace std;


struct Log {
	
	int id; // valor chave
	char data[10]; // xx/xx/xx
	char hora[6]; // xx:xx
	char tipo[8]; // PERDA para perda de vídeo e DETEC para detecção de movimento
	
}; // 28 bytes 


// nome do arquivo bin
const string ARQ = "log.dat";

/*

	Essa função é utilizada para checar se o ID já existe no arquivo ou é menor que 0
	Retorna -1 caso seja menor que 0
	Retorna 1 caso ela encontra a id no arquivo
	Retorna 0 caso ela não encontre a id no arquivo

*/
int verificaId(int id){
	
	int tam, aux = -1, paraOlaco = 0;
	
	if(id < 0){
		
		return -1;
		
	}

	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            // testa se a id do arquivo é igual a que foi inserida
            if (evento.id == id) {
                paraOlaco = 1;
                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {                      
                                 
            file.close();
            
            return 1;
            
        }
		
		else {            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
	
}

/*

	Captura a entrada de dados e salva em uma struct
	Retorna a struct com os dados salvos nela

*/
Log capturaDados(){
	
	// struct
	Log evento;
		
	system("cls");
	cout << endl << "\t" << ">>>> Captura dados <<<<" << "\t" << endl;
	cout << endl;
	
	cout << "Informe a ID: ";
	cin >> evento.id;	
	
	cin.ignore();
		
	cout << endl << endl << "[PERDA] = Perda de vídeo || [DETEC] Detecção de movimento" << endl;
	cout << "Informe o tipo de evento: ";
	gets(evento.tipo);		
	
	cout << endl << endl << "Exemplo de data: XX/XX/XX" << endl;
	cout << "Insira a data: ";
	gets(evento.data);			
			
	cout << endl << endl << "Exemplo de hora: XX:XX" << endl;
	cout << "Insira a data: ";	
	gets(evento.hora);
	
	return evento;
	
} 

/*

	Captura a entrada de dados e salva em uma struct
	Retorna a struct com os dados salvos nela
	
	Utilizada para alterar dados, apenas inclui novo(a) nas saidas para a tela

*/
Log capturanovoDados(){
	
	// struct
	Log evento;
		
	system("cls");
	cout << endl << "\t" << ">>>> Captura novos dados <<<<" << "\t" << endl;
	cout << endl;
	
	cout << "Informe a nova ID: ";
	cin >> evento.id;	
	
	cin.ignore();
		
	cout << endl << endl << "[PERDA] = Perda de vídeo || [DETEC] Detecção de movimento" << endl;
	cout << "Informe o novo tipo de evento: ";
	gets(evento.tipo);		
	
	cout << endl << endl << "Exemplo de data: XX/XX/XX" << endl;
	cout << "Insira a nova data: ";
	gets(evento.data);			
			
	cout << endl << endl << "Exemplo de hora: XX:XX" << endl;
	cout << "Insira a nova data: ";	
	gets(evento.hora);
	
	return evento;
	
} 

/*

	Após todas as interações da main(), o usuario tem a opção de sair ou voltar ao menu
	Essa função pega o dado do usuario e devolve o valor para ser tratado

*/
int chamaMenu(){
	
	int x;
	
	cout << "0 - Menu principal" << endl;
	cout << "99 - Sair" << endl;
	cout << endl;
	cout << "Digite a opcao desejada: ";
	cin >> x;
	
	return x;
}
	

/*

	Após salvar as informações na struct e confirmar que a ID não está duplicada, essa função é chamada
	Recebendo a própria struct como parametro, ela simpleste adiciona ao final do arquivo
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int escreveDados(Log evento){
	
	// saida para o arquivo 
	ofstream file;
	
	// abre o arquivo log.dat para saida de dados, do tipo binário e para inserção ao final
	file.open(ARQ.c_str(), ios::out | ios::binary | ios::app);
	
	// se arquivo estiver aberto, escreve os dados da struct no arquivo e fecha
	if(file.is_open()){
		
		file.write((char*)&evento, sizeof(Log));
		
		file.close();
		
		return 1;
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
}


/*

	Mostra em tela todos os registro que tem ID diferente de -1
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int listarLogico(){
	
	// entrada para a programa
	ifstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::binary);
	
	// se arquivo estiver aberto, escreve os dados da struct no arquivo e fecha
	if(file.is_open()){
		
		int tam;
		
		// struct para receber os registros
		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);
		
		// tabelação para exibir a lista
		cout << "ID" << "\t" << "TIPO" << "\t" << "DATA" << "\t\t" << "HORA" << endl;	
		
		while(file.tellg() < tam){
			
			// pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
            
            if(evento.id != -1){
			
	            // Mostra o registro em tela                
	            cout << evento.id << "\t" << evento.tipo << "\t" << evento.data << "\t" << evento.hora << endl;	
						
			}
		}
		
		file.close();
		
		return 1;
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
	
	
}


/*

	Mostra em tela todos os registros
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int listarFisico(){
	
	// entrada para a programa
	ifstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::binary);
	
	// se arquivo estiver aberto, escreve os dados da struct no arquivo e fecha
	if(file.is_open()){
		
		int tam;
		
		// struct para receber os registros
		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);
		
		// tabelação para exibir a lista
		cout << "ID" << "\t" << "TIPO" << "\t" << "DATA" << "\t\t" << "HORA" << endl;	
		
		while(file.tellg() < tam){
			
			// pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
            
            // Mostra o registro em tela                
            cout << evento.id << "\t" << evento.tipo << "\t" << evento.data << "\t" << evento.hora << endl;			
			
		}
		
		file.close();
		
		return 1;
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
	
}

/*

	Conta a quantidade de registros com ID diferente de -1
	Retorna i que é a quantidade de linhas com id diferente de -1
	Retorna 0 se sem sucesso
	
*/
int qtdeReg(){
	
	// entrada para a programa
	ifstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::binary);
	
	// se arquivo estiver aberto, calculo a qtde e fecha
	if(file.is_open()){

		int tam, i=0;
		
		// struct para receber os registros
		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);	
		
		while(file.tellg() < tam){
			
			// pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
		
			if(evento.id !=-1){
				i++;
			}
			
		}
		
		file.close();
		
		return i;
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}	
	
}

/*

	Utilizado apenas na função retornaProp para que retorne o tamanho do arquivo 

*/
int tamReg(){
	
	// ID = 4 bytes
	// DATA = 10 bytes
	// HORA = 6 bytes
	// TIPO = 8 bytes
	// TOTAL = 28 bytes

	return (28);
}

/*

	Informa a quantidade de registros, o tamanho de cada registro e o tamanho do arquivo
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int retornaProp(){

	// entrada para a programa
	ifstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::binary);
	
	// se arquivo estiver aberto, calculo o tamanho e fecha
	if(file.is_open()){

		int arq, qtde, tam;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		arq = file.tellg();		
		
		// calcula a quantidade de registros
		qtde = qtdeReg();
		if(qtde < 0){
			cout << endl << "Ops, tivemos algum erro ao calcular a quantidade de registros" << endl;
			
			return 0;
			
		}
		
		// calcula o tamanho dos registros
		tam = tamReg();
		if(tam != 28){
			cout << endl << "Ops, tivemos algum erro ao calcular o tamanho de cada registro" << endl;
			
			return 0;
			
		}
		
		// mostra na tela			
		cout << "Quantidade de registros: " << qtde << endl;
		
		cout << endl << "Tamanho de cada registro: " << tam << " bytes"  << endl;
		
		cout << endl << "Tamanho do arquivo: " << arq << " bytes" << endl;
		
		file.close();
		
		return 1;
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
		
}

/*

	Exclusão de um registro a partir de um ID, essa exclusão é lógica então a ID do registro será marcada como -1
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int excluiId(){
	
	int idExcluir, tam, aux = -1, paraOlaco = 0;
	
	system("cls");
	cout << endl << "\t" << ">>>> Excluir por ID <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "Entre com a ID: ";
	cin >> idExcluir;
	
	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            // testa se a id do arquivo é igual a que foi inserida
            if (evento.id == idExcluir) {
                paraOlaco = 1;
                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {
        	
            // define a id do registro para -1 = excluido
            evento.id = -1;
            
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // escreve o mesmo registro mas agora com -1 na id
            file.write((char*)&evento, sizeof(Log));            
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
	
}

/*

	Exclusão de registro a partir do TIPO, essa função procura a primeira aparição do TIPO que não esteja deletado e marca como -1 a ID para exclusão lógica
	
	Exemplo:
	
		ID 	TIPO 
		-1	PERDA <~~ não muda pois já tem -1 na ID
		10	PERDA <~~ primeira aparição do TIPO com a ID diferente de -1, então deleta logicamente
		
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso						

*/
int excluiTipo(){
	
	int tam, aux = -1, paraOlaco = 0;
	char tipoExcluir[8];
	
	system("cls");
	cout << endl << "\t" << ">>>> Excluir por TIPO <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "[PERDA] = Perda de vídeo || [DETEC] Detecção de movimento" << endl;
	cout << "Entre com o TIPO: ";
	cin.ignore();
	gets(tipoExcluir);
	
	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            
            if (strcmp(evento.tipo, tipoExcluir) == 0) {
                paraOlaco = 1;               
                                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {
        	
            // define a id do registro para -1 = excluido
            evento.id = -1;
            
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // escreve o mesmo registro mas agora com -1 na id
            file.write((char*)&evento, sizeof(Log));            
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}	
	
}


/*

	Alteração de registro a partir da ID, antes de fazer a alteração com os novos dados inseridos pelo usuario testa se a ID já existe e se existir não fará alteração
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int alterarId(){
	
	int idAlterar, tam, aux = -1, paraOlaco = 0;

	system("cls");
	cout << endl << "\t" << ">>>> Alterar por ID <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "Entre com a ID: ";
	cin >> idAlterar;
	
	if(idAlterar == -1){
		
		return -1;
		
	}

	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            // testa se a id do arquivo é igual a que foi inserida
            if (evento.id == idAlterar) {
                paraOlaco = 1;
                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {
        	
        	// variavel p pegar o retorno da função
        	int chamaverificaId;
        	
        	// chama função para pegar dados e armanezar na variavel
            evento = capturanovoDados();
            
            /*
            // chama a função e salva na variavel para tratarmos as saidas
            chamaverificaId = verificaId(evento.id);            
            
			if(chamaverificaId == -1){
				
				return -1;
				
			}
			else if (chamaverificaId == 1){
				
				return 2;
				
			}         
            */
            
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // escreve o mesmo registro mas agora com -1 na id
            file.write((char*)&evento, sizeof(Log));            
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}


}


/*

	Alteração de registro a partir do TIPO, antes de fazer a alteração com os novos dados inseridos pelo usuario testa se a ID já existe e se existir não fará alteração
	Retorna 1 se sucesso
	Retorna 0 se sem sucesso

*/
int alterarTipo(){
	
	int tam, aux = -1, paraOlaco = 0;
	char tipoAlterar[8];
	
	system("cls");
	cout << endl << "\t" << ">>>> Alterar por TIPO <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "[PERDA] = Perda de vídeo || [DETEC] Detecção de movimento" << endl;
	cout << "Entre com o TIPO: ";
	cin.ignore();
	gets(tipoAlterar);
	
	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            
            if ((strcmp(evento.tipo, tipoAlterar) == 0) && (evento.id != -1))  {
                paraOlaco = 1;               
                                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {
        	
            // variavel p pegar o retorno da função
        	int chamaverificaId;
        	
        	// chama função para pegar dados e armanezar na variavel
            evento = capturanovoDados();
            
        	/*
            // chama a função e salva na variavel para tratarmos as saidas
            chamaverificaId = verificaId(evento.id);            
            
			if(chamaverificaId == -1){
				
				return -1;
				
			}
			else if (chamaverificaId == 1){
				
				return 2;
				
			}   
            */
            
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // escreve o mesmo registro mas agora com -1 na id
            file.write((char*)&evento, sizeof(Log));            
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
	
}


/*

	Realiza uma consulta no arquivo e mostra o registro que tiver a ID correspondente
	Retorna 1 se sucesso e 0 se sem sucesso

*/
int consultaId(){

	int idConsultar, tam, aux = -1, paraOlaco = 0;

	system("cls");
	cout << endl << "\t" << ">>>> Consultar por ID <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "Entre com a ID: ";
	cin >> idConsultar;
	
	if(idConsultar == -1){
		
		return -1;
		
	}

	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            // testa se a id do arquivo é igual a que foi inserida
            if (evento.id == idConsultar) {
                paraOlaco = 1;
                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {        	
                      
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
            
            // Mostra o registro em tela                
            system("cls");
			cout << endl << "\t" << ">>>> Registro correspondente a ID <<<<" << "\t" << endl;
			cout << endl;
			
			// tabelação para exibir a lista
			cout << "ID" << "\t" << "TIPO" << "\t" << "DATA" << "\t\t" << "HORA" << endl;
            cout << evento.id << "\t" << evento.tipo << "\t" << evento.data << "\t" << evento.hora << endl;	
                      
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}

}


/*

	Realiza uma consulta no arquivo e mostra o registro primeiro registro que tiver a TIPO correspondente
	Retorna 1 se sucesso e 0 se sem sucesso

*/
int consultaTipo(){
	
	int tam, aux = -1, paraOlaco = 0;
	char tipoConsulta[8];
	
	system("cls");
	cout << endl << "\t" << ">>>> Alterar por TIPO <<<<" << "\t" << endl;
	cout << endl;	
	
	cout << "[PERDA] = Perda de vídeo || [DETEC] Detecção de movimento" << endl;
	cout << "Entre com o TIPO: ";
	cin.ignore();
	gets(tipoConsulta);
	
	// chama o arquivo
	fstream file;
	
	// abre o arquivo log.dat para entrada de dados no programa e saida de dados para o arquivo do tipo binário
	file.open(ARQ.c_str(), ios::in | ios::out  | ios::binary);
	
	if(file.is_open()){

		Log evento;
		
		// fim do arquivo
		file.seekg(0, file.end);
		
		// pega o tamanho do arquivo
		tam = file.tellg();
		
		// volta para o inicio do arquivo
		file.seekg(0, file.beg);

        while ((file.tellg() < tam) && (paraOlaco == 0)) {
        	
            // captura do arquivo e salva na struct
            file.read((char*)&evento, sizeof(Log));
            
            
            if ((strcmp(evento.tipo, tipoConsulta) == 0) && (evento.id != -1))  {
                paraOlaco = 1;               
                                
            }
            
            // variavel que auxialiará na sobreposição
            aux++;
            
        }		
        
        if (paraOlaco == 1) {
        	
            //Posiciona no registro a ser alterado
            file.seekg(aux * tamReg());
            
            // pega um registro do arquivo
            file.read((char*)&evento, sizeof(Log));
            
            // Mostra o registro em tela                
            system("cls");
			cout << endl << "\t" << ">>>> Registro correspondente ao TIPO <<<<" << "\t" << endl;
			cout << endl;
			
			// tabelação para exibir a lista
			cout << "ID" << "\t" << "TIPO" << "\t" << "DATA" << "\t\t" << "HORA" << endl;
            cout << evento.id << "\t" << evento.tipo << "\t" << evento.data << "\t" << evento.hora << endl;	
         	
            
            file.close();
            
            return 1;
            
        }
		
		else {
			
			cout << endl;
            cout << "Ops, o registro não foi encontrado" << endl;
            
            return 0;
            
        }	
		
	}
	
	else {
		
		cout << "Ops, o arquivo não foi aberto" << endl;
		
		return 0;
	}
			
}


/*

	O menu principal foi desenvolvido com o um for infinito para que consigamos voltar com praticidade para o menu sem ter que chamar uma função para isso
	Para sair do programa podemos utilizar um break pois saimos do laço atual (for) e caimos no return EXIT_SUCCES

*/
int main() {
	
	// pt-br
	setlocale(LC_ALL, "Portuguese");

	int opcao = 555;
	
	for(int i=0;;){
	
		system("cls");
		cout << endl << "\t" << ">>>> Menu de opções <<<<" << "\t" << endl;
		cout << endl;
		cout << "1 - Incluir" << endl;
		cout << "2 - Exluir lógico" << endl;
		cout << "3 - Alterar" << endl;
		cout << "4 - Consultar" << endl;
		cout << "5 - Listar lógico" << endl;
		cout << "6 - Listar físico" << endl;
		cout << "7 - Propriedades" << endl;
		cout << "99 - Sair" << endl;
		cout << endl;
		cout << "Digite a opcao desejada: ";
		cin >> opcao;	
		
		// incluir
		if(opcao == 1){
			
			// declara struct
			Log evento; 
			
			// variavel usada para pegar o retorno da função
			int opcao1, chamaverificaId;
			
					
			// chama função pra pegar dados
			evento = capturaDados(); 			
			
			chamaverificaId = verificaId(evento.id);
			
			if(chamaverificaId == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
				cout << "ERRO = a ID informada já existe no arquivo" << endl << endl;;
				break;
				
			}
			
			else if(chamaverificaId == -1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
				cout << "ERRO = não é possível adicionar uma ID menor que zero" << endl << endl;;
				break;
				
			}				
			
			// chama funcao para escrever no arquivo
			opcao1 = escreveDados(evento);
			
			// testa o retorno para informar ao usuario se o registro foi feito
			if(opcao1 == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Registro inserido com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao1 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao1 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao1 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao inserir registro no arquivo" << endl << endl;;
				break;
				
			}
			
			
		}
		// excluir
		else if(opcao == 2){
			
			int opcao2;
			
			system("cls");
			cout << endl << "\t" << ">>>> Excluir <<<<" << "\t" << endl;
			cout << endl;
			
			cout << "[1] = Por ID || [2] Por TIPO" << endl << endl;
			cout << "Informe o opção de exclusão: ";
			cin >> opcao2;
			
			if(opcao2 == 1){
				opcao2 = excluiId();
			}
			else if(opcao2 == 2){
				opcao2 = excluiTipo();
			}
			else{
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
				break;
				
			}

			if(opcao2 == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Registro apagado com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao2 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao2 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao2 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
								
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao apagar registro do arquivo" << endl << endl;;
				break;
				
			}			

		
			
		}
		// alterar
		else if(opcao == 3){
			
			int opcao3;
			
			system("cls");
			cout << endl << "\t" << ">>>> Alterar <<<<" << "\t" << endl;
			cout << endl;
			
			cout << "[1] = Por ID || [2] Por TIPO" << endl << endl;
			cout << "Informe o opção de exclusão: ";
			cin >> opcao3;
			
			if(opcao3 == 1){
				opcao3 = alterarId();
				/*
				if(opcao3 == -1){
					
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = não é possível adicionar uma ID menor que zero" << endl << endl;;
					break;
					
				}
				else if(opcao3 == 2){
					
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = a ID informada já existe no arquivo" << endl << endl;;
					break;
					
				}
				*/
			}
			else if(opcao3 == 2){
				opcao3 = alterarTipo();
				/*
				if(opcao3 == -1){
					
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = não é possível adicionar uma ID menor que zero" << endl << endl;;
					break;
					
				}
				else if(opcao3 == 2){
					
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = a ID informada já existe no arquivo" << endl << endl;;
					break;
					
				}
				*/
			}
			else{
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
				break;
				
			}

			if(opcao3 == 1){
				
				system("cls");
				cout << endl << "\t" << ">>>> Registro alterado com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao3 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao3 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao3 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			else if(opcao3 == -1){
				
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = não é possível alterar um registro excluído" << endl << endl;;
				break;
			
			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
								
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao alterar registro do arquivo" << endl << endl;;
				break;
				
			}
			
		}
		// consultar
		else if(opcao == 4){

			int opcao4;
			
			system("cls");
			cout << endl << "\t" << ">>>> Consultar <<<<" << "\t" << endl;
			cout << endl;
			
			cout << "[1] = Por ID || [2] Por TIPO" << endl << endl;
			cout << "Informe o opção de consulta: ";
			cin >> opcao4;
			
			if(opcao4 == 1){
				opcao4 = consultaId();
			}
			else if(opcao4 == 2){
				opcao4 = consultaTipo();
			}
			else{
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
				break;
				
			}

			if(opcao4 == 1){				
				
				cout << endl << "\t" << ">>>> Consulta realizada com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao4 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao4 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao4 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			else if(opcao4 == -1){
				
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = não é possível consultar um registro excluído" << endl << endl;;
				break;
			
			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
								
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao consultar registro do arquivo" << endl << endl;;
				break;
				
			}			
			
			
		}
		// listar lógico
		else if(opcao == 5){
			
			int opcao5;
			
			system("cls");
			cout << endl << "\t" << ">>>> Listar lógico <<<<" << "\t" << endl;
			cout << endl;
			
			opcao5 = listarLogico();
			
			
			// testa o retorno 
			if(opcao5 == 1){				
				
				cout << endl << endl << "\t" << ">>>> Listagem lógica feita com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao5 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao5 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao5 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao listar registros do arquivo" << endl << endl;;
				break;
				
			}
			
		}
		// listar físico
		else if(opcao == 6){
			
			int opcao6;
			
			system("cls");
			cout << endl << "\t" << ">>>> Listar físico <<<<" << "\t" << endl;
			cout << endl;
			
			opcao6 = listarFisico();
			
			
			// testa o retorno 
			if(opcao6 == 1){				
				
				cout << endl << endl << "\t" << ">>>> Listagem física feita com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao6 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao6 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao6 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}

			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao listar registros do arquivo" << endl << endl;;
				break;
				
			}
			
			
		}
		// propriedades
		else if(opcao == 7){
			
			int opcao7;
			
			system("cls");
			cout << endl << "\t" << ">>>> Propriedades <<<<" << "\t" << endl;
			cout << endl;
			
			opcao7 = retornaProp();
			
			// testa retorno
			if(opcao7 == 1){
				
				cout << endl << endl << "\t" << ">>>> Propriedades retornadas com sucesso <<<<" << "\t" << endl;
				cout << endl;
				
				// da opcao do usuario sair do laço for ou simplesmente voltar ao for
				opcao7 = chamaMenu();
				
				// testa opção do usuario, se for 0 simplesmente imprime na tela pois o for criado é infinito
				if(opcao7 == 0){
							
					system("cls");
					cout << endl << "\t" << ">>>> Retornando ao menu <<<<" << "\t" << endl;
					cout << endl;
								
				}
							
				// se for 99 encerra o programa diretamente
				else if(opcao7 == 99){
							
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado pelo usuário <<<<" << "\t" << endl;
					break;
								
				}
							
				// nesse ponto do programa, resolvemos encerrar caso o usuario digite algo fora do pedido
				else {
								
					system("cls");
					cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl << endl;
					cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
					break;
								
				}
							
			}
			
			// caso o return seja diferente de 1 (sucesso), informa ao usuario e também finaliza o programa
			else {
				
				system("cls");
				cout << endl << "\t" << ">>>> Programa finalizado por ERRO <<<<" << "\t" << endl <<  endl;
				cout << "ERRO = falha ao retornar as propriedades" << endl << endl;;
				break;
				
			}
			
			
		}
		// sair
		else if(opcao == 99){
			
			system("cls");
			cout << "PROGRAMA FINALIZADO PELO USUÁRIO" << endl << endl;
			break;
			
		}
		// opção inválida
		else{
			
			system("cls");
			cout << "PROGRAMA INTERROMPIDO POR ERRO" << endl << endl;
			cout << "ERRO = é necessário digitar uma opção válida" << endl << endl;;
			break;	
					
		}

	}


	return EXIT_SUCCESS;

}
