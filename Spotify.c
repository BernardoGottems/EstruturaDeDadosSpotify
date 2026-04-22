#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica
{
    char nome[30];
    char artista[30];

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
};

void push(struct Pilha *p, struct Musica m){
    struct No *novo = malloc(sizeof(struct No));

    if(novo != NULL){
        novo->dado = m;
        novo->proximo = p->topo;
        p->topo = novo;
    }else{
        printf("Erro ao alocar memória!\n");
    }
}

int pop(struct Pilha *p, struct Musica *m) {
    if (p->topo == NULL) {
        return 0;
    }
    struct No *removido = p->topo;
    *m = removido->dado;      
    p->topo = removido->proximo; 
    free(removido);            
    return 1;                  
}

void enqueue(struct Fila *f, struct Musica m) {
    struct No *novo = malloc(sizeof(struct No));
    if (novo != NULL) {
        novo->dado = m;
        novo->proximo = NULL;
        if(f->inicio == NULL){
            f->inicio = novo;
        }else{
            f->fim->proximo = novo;
        }
        f->fim = novo;
        printf("\n Musica adicionada com sucesso! \n \n");
    } else printf("Erro ao alocar memoria!\n");
}

int dequeue(struct Fila *f, struct Musica *m){
    if(f->inicio == NULL){
        return 0;
    }

    struct No *removido = f->inicio;
    *m = removido->dado;
    f->inicio = removido->proximo;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    free(removido);
    return 1;
}




int main(){
    struct Pilha historico;
    struct Fila playlist;
    iniciaPilha(&historico);
    iniciaFila(&playlist);

    int opt;

    do{
        printf("\n----- SPOTIFY -----");
        printf("\n 1- Adicionar na playlist");
        printf("\n 2- Tocar proxima");
        printf("\n 3- Voltar musica");
        printf("\n 4- Sair");
        printf("\n -------------------\n Escolha: ");
        scanf("%d", &opt);
        getchar();//getchar para limpar o buffer

        switch (opt){
        case 1: // adicionarMusica
            struct Musica nova_musica;
            printf("\n Nome da musica: ");
            fgets(nova_musica.nome, sizeof(nova_musica.nome), stdin);
            nova_musica.nome[strcspn(nova_musica.nome, "\n")] = '\0';
            printf(" Nome do artista: ");
            fgets(nova_musica.artista, sizeof(nova_musica.artista), stdin);
            nova_musica.artista[strcspn(nova_musica.artista, "\n")] = '\0';
            enqueue(&playlist , nova_musica);
            break;
        case 2: // proxMusica
            struct Musica tocando;
             if(dequeue(&playlist, &tocando)){
                printf("\n \n  Tocando: %s - %s", tocando.nome, tocando.artista);               
                push(&historico, tocando);
             }
             else{
                printf("\nFim da playlist!\n");
             }
              
            break;

        case 3:
             struct Musica anterior;
             if (pop(&historico, &anterior)) {
                    printf("\nVoltando para: %s - %s\n", anterior.nome, anterior.artista);
                } else {
                    printf("\nNao ha musicas no historico! \n");
                }
            
             
    
            break;

        case 4: // sair

            printf("\n...SAINDO \n");
            break;

        default:
            printf("\nOpção invalida! \n");
        
            break;

        } 

    }while(opt != 4);

    return 0;

}
