#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica
{
    char nome[30];
    char artis[30];
    float tempo;

};
struct No{
    struct Musica dado;
    struct No *proximo;
};
struct Pilha{
    struct No *topo;
};

struct Fila{
    struct No *inicio;
    struct No *fim;
};


void iniciaPilha(struct Pilha *p){
    p->topo = NULL;

};
void iniciaFila(struct Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}


void push(struct Pilha *p, struct Musica m) {
    struct No *novo = malloc(sizeof(struct No));
    
    if (novo) {
        novo->dado = m;
        novo->dado.tempo;
        novo->proximo = p->topo; 
        p->topo = novo;        
        printf("música adicionada com sucesso!");
    } else printf("Erro ao alocar memória!\n");
}



int main(){
    struct Pilha historico;
    struct Fila playlist;

    int opt;

    do{
        printf("----- SPOTIFY -----");
        printf("\n 1- Adicionar na playlist");
        printf("\n 2- Tocar proxima");
        printf("\n 3- Voltar musica");
        printf("\n 4- Sair");
        printf("\n -------------------\n");
        scanf("%d", &opt);
        // aqui teria o getchar() pra limpar o buffer

        switch (opt){
        case 1: // adicionarMusica
        struct Musica nova_musica;
        printf("\n Nome da música: ");
        fgets(nova_musica.nome, sizeof(nova_musica.nome), stdin);
            
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
            break;

        default:
            printf("\nOpção inválida!\n");
        
            break;

        } 

    }while(opt != 4);

    return 0;

}
