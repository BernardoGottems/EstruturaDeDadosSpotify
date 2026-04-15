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
    int idade da muisca;
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
        scanf("%d", &opt);

        switch (opt){
        case 1:
            //  proxMusica()
            break;
            
        case 2:
            // voltMusica   
            break;

        case 3:
            //sair;
            break;

        }

    }while(opt != 3 || opt == 2);


    struct Musica m1;
    strcpy(m1.artis, "\n joao pe de barro");
    strcpy(m1.nome, "\n ai ai meu pe");
    strcpy(m1.nome, "rapaz - xaropinho");
    int putsk=9;
    m1.tempo = 908.67;


    printf("%s", m1.artis);
    printf("%s", m1.nome);


}