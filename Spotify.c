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



void inicializar(struct Pilha *p){
    p->topo = NULL;
}

struct Fila{
    Struct No *inicio;
    Struct No *fim;
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
    int opt;

    struct Pilha p1;

    inicializar(&p1);
    push()


    do{
        scanf("%d", &opt);

        switch (opt){
        case 1:
            //  proxMusica()
            break;
            
        case 2:
            // voltMusica   
            break;

        case 3:
            push();
            break;
            
        case 4:
            //sair;
            break;

        } 

    }while(opt != 3 || opt == 2);


    struct Musica m1;
    strcpy(m1.artis, "\n joao pe de barro");
    strcpy(m1.nome, "\n ai ai meu pe");
    m1.tempo = 0.59;


    printf("%s", m1.artis);
    printf("%s", m1.nome);


}