#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*CADASTRO VERSÃO 2.1
1.0 - Adicionado cadastro da placa;

1.1 - registro da placa agora é feito por um procedimento;

1.2 - Adicionado erro pro cadastro da placa;

2.0 - Adicionar seleção de marca;

2.1 - Refatorado seleção de marca;
*/

char placa[8];
char aux[2];
int placaVet[7], marcaN;
bool valido = true;
char marca[15][15] = {"Chevrolet","Citroen","Fiat","Honda","Jeep","Kia","Peugeot","Renault","Toyota","Volkswagen"}, marcaVeiculo[15];

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
//char marca[15][15] = {"Chevrolet","Citroen","Fiat","Honda","Jeep","Kia","Peugeot","Renault","Toyota","Volkswagen"};
void registrarMarca(){
	
	printf("O veículo é de que marca? Digite o número:\n");
	
	for(int i = 0; i < 10; i++){
		printf("%d - %s\n", i+1, marca[i]);	
	}
    
	scanf("%i", &marcaN);
    
    switch(marcaN){

			case 1:
				strcpy(marcaVeiculo, marca[0]);	
				
			break;
			case 2:
				strcpy(marcaVeiculo, marca[1]);		
			
			break;
			case 3:
				strcpy(marcaVeiculo, marca[2]);		
				
			break;
            case 4:
				strcpy(marcaVeiculo, marca[3]);		
			    
            break;
            case 5:
                strcpy(marcaVeiculo, marca[4]);	   
            break;   
			    
            case 6:
                strcpy(marcaVeiculo, marca[5]);	   
            break;   
                
            case 7:
                strcpy(marcaVeiculo, marca[6]);	   
            break;   
                
            case 8:
                strcpy(marcaVeiculo, marca[7]);	 
            break;   
                
            case 9:
                strcpy(marcaVeiculo, marca[8]);	    
            break;   
            
            case 10:
                strcpy(marcaVeiculo, marca[9]);	   
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
	
	registrarMarca();
	
	printf("%s \n", marcaVeiculo);
	
    system("pause");

	
}
