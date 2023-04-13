#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>


/*CADASTRO VERSÃO 5.0
1.0 - Adicionado cadastro da placa;
1.1 - registro da placa agora é feito por um procedimento;
1.2 - Adicionado erro pro cadastro da placa;
2.0 - Adicionar seleção de marca;
2.1 - Refatorado seleção de marca;
3.0 - Seleção de Veiculo;
4.0 - Seleção de Setor;
5.0 - Registro de Chassi;
5.1 - Refatoração rapida;
5.2 - Correção de bugs, Adição de textos que faltavam;
*/

char placa[8];
char chassi[18];
char aux[2];
int placaVet[7],chassiVet[17], marcaN, modeloN, setorN;
bool valido = true;
char marca[10][15] = {"CHEVROLET","CITROEN","FIAT","HONDA","JEEP","KIA","PEUGEOT","RENAULT","TOYOTA","VOLKSWAGEN"}, marcaVeiculo[15], modeloVeiculo[15],setorVeiculo[15];
char modeloGM[14][15] = {"S10","D-20","CLASSIC","MONTANA","SPIN","COBALT","ONIX","CRUZE","CORSA","OMEGA","ASTRA","PRISMA","BAZER","ZAFIRA"};
char modeloCIT[3][15] = {"JUMPER","JUMPY","AIRCROSS"};
char modeloFiat[7][15] = {"PALIO","STRADA","UNO","DOBLO","CARGO","MULTIJET","FIORINO"};
char modeloJeep[1][15] = {"RENEGADE"};
char modeloKia[1][15] = {"BESTA"};
char modeloHD[2][15] = {"XRE300","CG125"};
char modeloPG[3][15] = {"PARTNER","BOXER","207"};
char modeloToyo[3][15] = {"HILUX","BANDEIRANTES","HILUX SW4"};
char modeloRN[5][15] = {"MASTER","KANGOO","LOGAN","DUSTER","KWID"};
char modeloVW[5][15] = {"GOL","KOMBI","PARATI","SAVEIRO","VOYAGE"};
char setor[10][30] = {"SETRAB","SELURB","SEINFRA","SEMOP","FUNREBOM","SECRETARIA DE SAUDE","SEMUSP ADMINISTRAÇÃO FLORIANO","SEMUSP ADMINISTRAÇÃO IGUATEMI", "AMITECH", "SEMOB"};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loading();
void registrarPlaca();
void registrarMarca();
void registrarChassi();
void registrarSetor();
//------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL, "portuguese");
	
	do{
		registrarPlaca();
		if(!valido){
			printf("Erro, um ou mais caracteres invalidos.\nO Campo deve ser preenchido com o padrão ABC1234 ou ABC1D23.\n");
			printf("Por favor preencha novamente.\n");
		}
	}while(!valido);
	
	loading();
	
	registrarMarca();
	
	loading();
	
	registrarSetor();
	
	loading();
	
	registrarChassi();
	
	loading();
	
	printf("Placa: %s \n", placa);
	printf("Marca: %s \n", marcaVeiculo);
	printf("Modelo: %s \n", modeloVeiculo);
	printf("Chassi: %s \n", chassi);
	printf("Setor: %s \n", setorVeiculo);
	
    system("pause");
}

//------------------------------------------------------------------------------
void loading(){
	system("cls");
	for(int i = 0; i<2; i++){
		printf("Carregando.");
		Sleep(400);
		system("cls");
		printf("Carregando..");
		Sleep(400);
		system("cls");
		printf("Carregando...");
		Sleep(400);
		system("cls");
	}
}
//------------------------------------------------------------------------------
void registrarPlaca(){
		valido = true;
		placa[1] = '\0';
		
		while(strlen(placa) != 7){
		printf("placa: ");
		gets(placa);
		fflush(stdin);
		}
		
		strupr(placa);

		for(int i = 0; i < 7; i++){
			placaVet[i] = placa[i];
		}
		
		for(int i = 0; i < 7; i++){
    
			switch(i){
			case 0:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					return;
				}
			break;
			case 1:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					return;
				}
			break;
			case 2:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					return;
				}
			break;
			case 3:
				if(placaVet[i] < 48 || placaVet[i] > 57){
					valido = false;
					return;
				}
			break;
            case 4:
                if(!(placaVet[i] >= 48 && placaVet[i] <= 57) && !(placaVet[i] >= 65 && placaVet[i] <= 90)){
					valido = false;
                    return;
					}
			break;
            case 5:
                if(placaVet[i] < 48 || placaVet[i] > 57 ){
                    valido = false;
                    return;   
			    }
			break;
            case 6:
                if(placaVet[i] < 48 || placaVet[i] > 57 ){
                    valido = false;
                    return;   
                }
            break;
            }
        }            

}
//------------------------------------------------------------------------------
void registrarMarca(){
	
	printf("Qual a marca do veiculo? Digite o número:\n");
	
	for(int i = 0; i < 10; i++){
		printf("%d - %s\n", i+1, marca[i]);	
	}
    
	scanf("%i", &marcaN);
	fflush(stdin);
    system("cls");
    
    switch(marcaN){

			case 1:
				strcpy(marcaVeiculo, marca[0]);
				printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 14; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloGM[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloGM[modeloN-1]);
						
						system("cls");
						
			break;
			case 2:
				strcpy(marcaVeiculo, marca[1]);	
				printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 3; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloCIT[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloCIT[modeloN-1]);
						
						system("cls");
						
			break;
			case 3:
				strcpy(marcaVeiculo, marca[2]);
				printf("Qual o modelo? Digite o número:\n");	
				for(int i = 0; i < 7; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloFiat[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloFiat[modeloN-1]);
						
						system("cls");
						
			break;
            case 4:
				strcpy(marcaVeiculo, marca[3]);	
				printf("Qual o modelo? Digite o número:\n");	
				for(int i = 0; i < 2; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloHD[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloHD[modeloN-1]);
						
						system("cls");
						
            break;
            case 5:
                strcpy(marcaVeiculo, marca[4]);	
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 1; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloJeep[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloJeep[modeloN-1]);
						
						system("cls");
						
            break;   
            case 6:
                strcpy(marcaVeiculo, marca[5]);
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 1; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloKia[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloKia[modeloN-1]);
						
						system("cls");
						
            break;   
            case 7:
                strcpy(marcaVeiculo, marca[6]);	 
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 3; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloPG[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloPG[modeloN-1]);
						
						system("cls");
						
            break;    
            case 8:
                strcpy(marcaVeiculo, marca[7]);	
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 5; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloRN[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloRN[modeloN-1]);
						
						system("cls");
						
            break;   
            case 9:
                strcpy(marcaVeiculo, marca[8]);	
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 3; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloToyo[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloToyo[modeloN-1]);
						
						system("cls");
						
            break;   
            case 10:
                strcpy(marcaVeiculo, marca[9]);	
                printf("Qual o modelo? Digite o número:\n");
				for(int i = 0; i < 5; i++){ //seleção dos modelos
						printf("%d - %s\n", i+1, modeloVW[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloVW[modeloN-1]);
						
						system("cls");
						
            break;   
                
       }
}
//------------------------------------------------------------------------------
void registrarChassi(){
		valido = true;
	
		while(strlen(chassi) != 17){	
		printf("Chassi: ");
		gets(chassi);
		fflush(stdin);
		}
		
		strupr(chassi);

		for(int i = 0; i < 17; i++){
			chassiVet[i] = chassi[i];
		}
		
		for(int i = 0; i < 17; i++){
    
			switch(i){
			case 0:
				if(chassiVet[i] < 48 || chassiVet[i] > 57){
					valido = false;
					break;
				}
			break;
			case 1:
				if(chassiVet[i] < 65 || chassiVet[i] > 90){
					valido = false;
					break;
				}
			break;
			case 2:
				if(chassiVet[i] < 65 || chassiVet[i] > 90){
					valido = false;
					break;
				}
			break;
			case 3:
				if(chassiVet[i] < 65 || chassiVet[i] > 90){
					valido = false;
					break;
				}
			break;
            case 4:
                if(chassiVet[i] >= 65 && chassiVet[i] <= 90){
					valido = false;
					}
                    break;
            case 5:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
			    }
            case 6:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 7:
				if(chassiVet[i] < 65 || chassiVet[i] > 90){
					valido = false;
					break;    
            }
            case 8:
				if(chassiVet[i] < 65 || chassiVet[i] > 90){
					valido = false;
					break;    
            }
            case 9:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 10:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 11:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 12:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 13:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 14:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
            	}
            case 15:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            case 16:
                if(chassiVet[i] < 48 || chassiVet[i] > 57 ){
                    valido = false;
                    break;   
                }
        }            

	}
}
//-------------------------------------------------------------------------------
void registrarSetor(){
	printf("Insira o setor do veiculo: \n");
	for(int i = 0; i < 10; i++){ //seleção do setor
    printf("%d - %s\n", i+1, setor[i]);	
   	}
   	scanf("%d", &setorN);
	fflush(stdin);
						
	strcpy(setorVeiculo,setor[setorN-1]);
}
