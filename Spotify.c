#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica
{
    char nome[20];
    char artis[20];
    float tempo;

};

struct No{
    char valor;
    struct No *proximo;
};

struct Pilha{
    struct No *topo;
};

void inicializar(struct Pilha *p){
    p->topo = NULL;
}

void push(struct Pilha *p){
    int valor = 0;
    struct No *novo = malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}




int main(){

    int opt;

    do{
        printf("----- SPOTIFY -----");
        printf("1- Adicionar na playlist");
        printf("2- Tocar próxima");
        printf("3- Voltar música");
        printf("4- Sair");
        printf("-------------------");
        scanf("%d", &opt);
        // aqui teria o getchar() pra limpar o buffer

        switch (opt){
        case 1: // adicionarMusica
            printf("Nome da música: ");
            // e aqui entraria o fgets
            printf("Artista: ");
            // fgets
            // enqueue(...);
            break;
            
        case 2: // proxMusica
             /*if(dequeue()){

                printf("");
                push();
             }
             else{
                printf("\nFim da playlist!\n");
             }*/
              
            break;

        case 3: // voltMusica 
         
             
    
            break;

        case 4: // sair

            printf("\n...SAINDO\n");

        default:
            printf("\nOpção inválida!\n");
        
            break;

        }

    }while(opt != 4);

    return 0;

}
