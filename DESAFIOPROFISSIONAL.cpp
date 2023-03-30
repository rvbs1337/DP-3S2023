#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>


/*CADASTRO VERSÃO 3.0
1.0 - Adicionado cadastro da placa;

1.1 - registro da placa agora é feito por um procedimento;

1.2 - Adicionado erro pro cadastro da placa;

2.0 - Adicionar seleção de marca;

2.1 - Refatorado seleção de marca;

3.0 - Seleção de Veiculo;
*/

char placa[8];
char aux[2];
int placaVet[7], marcaN, modeloN;
bool valido = true;
char marca[10][15] = {"CHEVROLET","CITROEN","FIAT","HONDA","JEEP","KIA","PEUGEOT","RENAULT","TOYOTA","VOLKSWAGEN"}, marcaVeiculo[15], modeloVeiculo[15];
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

void loading(){
	system("cls");
	for(int i = 0; i<14; i++){
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

void registrarPlaca(){
		valido = true;
		
		printf("placa: ");
		gets(placa);
		fflush(stdin);
		
		strupr(placa);

		for(int i = 0; i < 7; i++){
			placaVet[i] = placa[i];
		}
		
		for(int i = 0; i < 7; i++){
    
			switch(i){
			case 0:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					break;
				}
			break;
			case 1:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					break;
				}
			break;
			case 2:
				if(placaVet[i] < 65 || placaVet[i] > 90){
					valido = false;
					break;
				}
			break;
			case 3:
				if(placaVet[i] < 48 || placaVet[i] > 57){
					valido = false;
					break;
				}
			break;
            case 4:
                if(!(placaVet[i] >= 48 && placaVet[i] <= 57) && !(placaVet[i] >= 65 && placaVet[i] <= 90)){
					valido = false;
					}
                    break;
            case 5:
                if(placaVet[i] < 48 || placaVet[i] > 57 ){
                    valido = false;
                    break;   
			    }
            case 6:
                if(placaVet[i] < 48 || placaVet[i] > 57 ){
                    valido = false;
                    break;   
                }
            }
        }            

}

void registrarMarca(){
	
	printf("O veículo é de que marca? Digite o número:\n");
	
	for(int i = 0; i < 10; i++){
		printf("%d - %s\n", i+1, marca[i]);	
	}
    
	scanf("%i", &marcaN);
	fflush(stdin);
    system("cls");
    
    switch(marcaN){

			case 1:
				strcpy(marcaVeiculo, marca[0]);
				for(int i = 0; i < 14; i++){
						printf("%d - %s\n", i+1, modeloGM[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloGM[modeloN-1]);
			break;
			case 2:
				strcpy(marcaVeiculo, marca[1]);	
				for(int i = 0; i < 3; i++){
						printf("%d - %s\n", i+1, modeloCIT[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloCIT[modeloN-1]);	
			break;
			case 3:
				strcpy(marcaVeiculo, marca[2]);	
				for(int i = 0; i < 7; i++){
						printf("%d - %s\n", i+1, modeloFiat[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloFiat[modeloN-1]);	
			break;
            case 4:
				strcpy(marcaVeiculo, marca[3]);		
				for(int i = 0; i < 2; i++){
						printf("%d - %s\n", i+1, modeloHD[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloHD[modeloN-1]);  
            break;
            case 5:
                strcpy(marcaVeiculo, marca[4]);	
				for(int i = 0; i < 1; i++){
						printf("%d - %s\n", i+1, modeloJeep[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloJeep[modeloN-1]);   
            break;   
            case 6:
                strcpy(marcaVeiculo, marca[5]);
				for(int i = 0; i < 1; i++){
						printf("%d - %s\n", i+1, modeloKia[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloKia[modeloN-1]);	   
            break;   
            case 7:
                strcpy(marcaVeiculo, marca[6]);	 
				for(int i = 0; i < 3; i++){
						printf("%d - %s\n", i+1, modeloPG[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloPG[modeloN-1]);  
            break;    
            case 8:
                strcpy(marcaVeiculo, marca[7]);	
				for(int i = 0; i < 5; i++){
						printf("%d - %s\n", i+1, modeloRN[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloRN[modeloN-1]); 
            break;   
            case 9:
                strcpy(marcaVeiculo, marca[8]);	
				for(int i = 0; i < 3; i++){
						printf("%d - %s\n", i+1, modeloToyo[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloToyo[modeloN-1]);    
            break;   
            case 10:
                strcpy(marcaVeiculo, marca[9]);	
				for(int i = 0; i < 5; i++){
						printf("%d - %s\n", i+1, modeloVW[i]);	
						}
						scanf("%d", &modeloN);
						fflush(stdin);
						
						strcpy(modeloVeiculo,modeloVW[modeloN-1]);   
            break;   
                
       }
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	do{
		registrarPlaca();
		if(!valido){
			printf("Erro, um ou mais caracteres invalidos.\nO campo deve ser preenchido com o padrão ABC1234 ou ABC1D23.\n");
			printf("Por favor preencha novamente.\n");
		}
	}while(!valido);
	
	loading();
	
	registrarMarca();
	
	loading();
	
	printf("Placa: %s \n", placa);
	printf("Marca: %s \n", marcaVeiculo);
	printf("Modelo: %s \n", modeloVeiculo);
	
    system("pause");

	
}
