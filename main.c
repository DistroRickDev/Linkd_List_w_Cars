#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char brand[20];
    char model[20];
    int year;
    float consumption;
    struct car *next;
} car;

car *head = NULL;

void write();
void read();
void list_car();
void ord_cons();
void ord_cons_M();
void ord_year();
void ord_year_M();
void reg_car();
void greater_cons();
void smallest_cons();
void del_st_item();
void del_last_item();
void del_sel_item();

int main() {
    int opcao = -1;
    read();
    while (opcao != 0) {
        printf("\n\nMenu\n\nEscolha uma das opcoes abaixo:\n");
        printf("1-Inserir Carro:\n");
        printf("2-Lista Carros:\n");
        printf("3-Carro com maior consumo:\n");
        printf("4-Carro com menor consumo:\n");
        printf("5-Ordenar lista por ordem decresc. de consumo:\n");
        printf("6-Ordenar lista por ordem cresc. de consumo:\n");
        printf("7-Ordenar lista por ordem decresc. de ano:\n");
        printf("8-Ordenar lista por ordem cresc. de ano:\n");
        printf("9-Eliminar primeiro item da tabela:\n");
        printf("10-Eliminar ultimo item da tabela:\n");
        printf("11- Eliminar carro da lista por escolha do utilizador\n");
        printf("0-Sair do programa:\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                reg_car();
                write();
                break;
            case 2:
                list_car();
                break;
            case 3:
                greater_cons();
                break;
            case 4:
                smallest_cons();
                break;
            case 5:
                ord_cons();
                break;
            case 6:
                ord_cons_M();
                break;
            case 7:
                ord_year();
                break;
            case 8:
                ord_year_M();
                break;
            case 9:
                del_st_item();
                break;
            case 10:
                del_last_item();
                break;
            case 11:
                del_sel_item();
                break;
            case 0:
                printf("Escolheu sair do programa \n");
                write();
                exit(0);
            default:
                printf("Introduza uma opcao valida\n");
                break;
        }
    }
    return 0;
}

void write(){
    car *pt = head;
    FILE *fptr;
    fptr = fopen ("cars.b","wb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }
    while(pt != NULL){
        fwrite(pt, sizeof(car), 1, fptr);
        pt = pt->next;
    }

    fclose(fptr);

}



void read(){
    FILE *fptr;
    fptr = fopen ("cars.b","rb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }

    while (1){
        car *newcar = malloc(sizeof(car));
        if (fread(newcar, sizeof(car),1,fptr)==0 ){
            fclose(fptr);
            return;
        }
        newcar->next = head;
        head = newcar;
    }

    fclose(fptr);

}

void list_car(){
    car *ptr =  head;

    printf("Brand\tModel\tYear\tComsumption:\n");
    while (ptr != NULL) {

        printf("%s \t%s \t%d \t%.2f\n",
               ptr->brand,
               ptr->model,
               ptr->year,
               ptr->consumption);

        ptr = ptr->next;
    }
}

void ord_cons(){

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->consumption > nextCar->consumption) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}
void ord_cons_M(){

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->consumption < nextCar->consumption) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}


void ord_year(){

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->year > nextCar->year) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}

void ord_year_M()
{

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->year < nextCar->year) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}


void reg_car(){
    car *new_car =(car*)malloc(sizeof(car));
    printf("Registe a marca do carro\n");
    scanf("%s", new_car->brand);
    printf("Registe o modelo do carro\n");
    scanf("%s", new_car->model);
    printf("Introduza o ano do carro\n");
    scanf("%d", &new_car->year);
    printf("Introduza o consumo do carro\n");
    scanf("%f", &new_car->consumption);

    new_car->next= head;
    head = new_car;
}

void greater_cons() {
    car *ptr =  head;
    car *ptr_2 = head;
    printf("Comsumption:\n");
    while (ptr != NULL) {
        if (ptr->consumption > ptr_2->consumption) {
            ptr_2 = ptr;

        }
        ptr = ptr->next;
    }
    printf("O carro com maior consumo e %s %s que consome %.2f\n", ptr_2->brand,ptr_2->model, ptr_2->consumption);
}

void smallest_cons() {
    car *ptr =  head;
    car *ptr_2 = head;
    printf("Comsumption:\n");
    while (ptr != NULL) {
        if (ptr->consumption < ptr_2->consumption) {
            ptr_2 = ptr;


        }
        ptr = ptr->next;
    }
    printf("O carro com menor consumo e %s %s que consome %.2f\n", ptr_2->brand,ptr_2->model, ptr_2->consumption);
}

void del_st_item() {
    car *ptr = head;
    car *aux = head;
    while (ptr != NULL){
        if(ptr == head){
            aux= ptr->next; // guardo posição do next do ptr
            free(ptr); //
            ptr->next=head;
            head = aux;
            ptr = head;
        }
        ptr = ptr->next;
    }
}

void del_last_item() {
    car *ptr = head;
    car * previous = NULL;
    car * aux;
    while (ptr != NULL){
        if(ptr->next != NULL){
            previous = ptr;
        }
        else{
            aux = ptr->next;
            free(ptr);
            ptr = previous;
            ptr->next = aux;
        }
        ptr = ptr->next;

    }

}

void del_sel_item()
{
    char marca[20];
    char modelo[20];
    car *ptr = head;
    car *aux = head;
    car *previous = NULL;
    printf("Por favor selecione a marca e modelo a eliminar\n");
    printf("Introduza a marca \n");
    scanf("%s", marca);
    printf("Introduza o modelo \n");
    scanf("%s", modelo);
    while (ptr != NULL){
        if(strcmp(marca, ptr->brand) == 0 && strcmp(modelo, ptr->model)==0){
            aux = ptr->next;
            free(ptr);
            ptr = previous;
            ptr->next = aux;
        }
        else
        {
            printf("Marca ou modelo nao encontrado\n");

        }
        previous = ptr;
        ptr = ptr->next;
    }
}
