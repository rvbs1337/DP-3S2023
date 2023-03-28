#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*CADASTRO VERSÃO 1.2
1.0 - Adicionado cadastro da placa;

1.1 - registro da placa agora é feito por um procedimento;

1.2 - Adicionado erro pro cadastro da placa;

pre 2.0 - Adicionar seleção de marca
*/

char placa[8];
char aux[2];
int placaVet[7];
bool valido = true;
char marca[15][10] = ["Chevrolet","Citroen","Fiat","Honda","Jeep","Kia","Peugeot","Renault","Toyota","Volkswagen"];

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

int main(){
	setlocale(LC_ALL, "portuguese");
	
	do{
		registrarPlaca();
		if(!valido){
			printf("Erro, um ou mais caracteres invalidos.\nO campo deve ser preenchido com o padrão ABC1234 ou ABC1D23.\n");
			printf("Por favor preencha novamente.\n");
		}
	}while(!valido);
	
    system("pause");

	
}
