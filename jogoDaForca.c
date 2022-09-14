#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    char palavraChave[46];
    char tentativa;
    char strAster[46];
    int acertou;
    int conclusao;
} mensagem;

/*
    CABEÇALHOS
*/

void Perdeu(mensagem msm);
void Ganhou(mensagem msm);
int MenuPrincipal(mensagem msm); // necessario
int Dificuldade(int op, int qtdLetra); //desnecessario
mensagem Aster(mensagem msm); //necessario
mensagem checkLetra(mensagem msm); //necessario
int Jogo(mensagem msm); //necessario
int main();

/*
    POSSIVEL RESULTADO DO JOGO
*/
void Perdeu(mensagem msm){
    printf("\nUma pena, voce perdeu!\nA palavra chave era: %s\n", msm.palavraChave);
}
/*
    POSSIVEL RESULTADO DO JOGO
*/
void Ganhou(mensagem msm){
    printf("\nParabens, voce acertou!\nA palavra era: %s\n", msm.palavraChave);
}
/*
    MENU PRINCIPAL E SELEÇÃO DE DIFICULDADE
*/
int MenuPrincipal(mensagem msm){
    int op=0, qtdLetra;
    for(op;op > 3 || op < 1; ){
        printf("\nQual a dificuldade do jogo?\n1 - Facil\n2 - Medio\n3 - Dificil\n");
        fflush(stdout);
        scanf(" %d", &op);

        if(op > 3 || op < 1)
            printf("\nOpcao Invalida, tente novamente!");
    }
    qtdLetra = strlen(msm.palavraChave);
    
    return Dificuldade(op, qtdLetra);
}

/*
    AJUSTE DA DIFICULDADE, A DIFICULDADE É ALTERADA BASEANDO-SE NO TAMANHO DA PALAVRA
    FACIL -> 3/4 DO TAMANHO DA PALAVRA EM TENTATIVAS
    MÉDIO -> 2/4 DO TAMANHO DA PALAVRA EM TENTATIVAS
    DIFICIL -> 1/4 DO TAMANHO DA PALAVRA EM TENTATIVAS
    SEMPRE ARREDONDANDO PARA CIMA
*/
int Dificuldade(int op, int qtdLetra){
    int modDificuldade=0;
    switch(op){
        case 1:
            modDificuldade = ceilf(qtdLetra*3.0/4);
            printf("\nDificuldade selecionada: Facil\nVoce tera %d tentativas\nPressione Enter para iniciar...\n", modDificuldade);
            return modDificuldade;
            break;
        case 2:
            modDificuldade = ceilf(qtdLetra*2.0/4);
            printf("\nDificuldade selecionada: Medio\nVoce tera %d tentativas\nPressione Enter para iniciar...\n", modDificuldade);
            return modDificuldade;
            break;
        case 3:
            modDificuldade = ceilf(qtdLetra/4.0);
            printf("\nDificuldade selecionada: Dificil\nVoce tera %d tentativas\nPressione Enter para iniciar...\n", modDificuldade);
            return modDificuldade;
            break;
        default:
            break;
    }
}

/*
    CRIAÇÃO DA STRING DE ASTERISCOS, NO TAMANHO DA PALAVRA CHAVE
*/
mensagem Aster(mensagem msm){
    for(int i=0; msm.palavraChave[i]!='\0';i++){
        msm.strAster[i] = '*';
    }
    return msm;
}

/*
    VERIFICADOR DA PALAVRA, PARA VER SE O JOGADOR ACERTOU OU ERROU,
    SE O JOGADOR ACERTOU, O ASTERISCO SERÁ SUBSTITUIDO PELA LETRA, E O JOGADOR NÃO PERDERÁ A TENTATIVA,
    SE ELE ERROU, A STRING DE ASTERISCOS SE MANTERÁ A MESMA, O USUARIO PERDERÁ UMA TENTATIVA.
*/
mensagem checkLetra(mensagem msm) {
    for(int i=0; msm.palavraChave[i]!='\0';i++){
        if(msm.tentativa == msm.palavraChave[i]){
            msm.strAster[i] = msm.tentativa;
            msm.acertou = 0;
        }
    }
    return msm;
}

/*
    VERIFICADOR DE FIM DE JOGO, SE A TENTATIVA DO JOGADOR COINCIDIR COM A PALAVRA CHAVE, ELE GANHARÁ
    CASO CONTRARIO, ELE PERDERÁ
*/
int Jogo(mensagem msm){
    if( strcmp(msm.strAster,msm.palavraChave) == 0 )
        return 0;

    return 1;
}

int main(){
    mensagem msm;
    strcpy(msm.strAster, "");
    
    
    for(int i=0; i!=1; ){
        printf("\nDigite a palavra para ser adivinhada: ");
        fflush(stdin);
        scanf("%s", msm.palavraChave);
        printf("\nTem certeza que a palavra para ser adivinhada eh: %s ?\n1 - sim\n0 - nao\n", msm.palavraChave);
        scanf(" %d", &i);
        if(i==1){
            system("clear");
        }
    }

    int dificuldade = MenuPrincipal(msm);

    /*
        LIMPAR A TELA E FAZER COM QUE O CONSOLE PARE E ESPERE O USUARIO PRESSIONAR QUALQUER COISA,
        SÓ FUNCIONARÁ EM SISTEMAS LINUX.
    */
    system("read dummy");
    system("clear");

    msm = Aster(msm);
    msm.conclusao = 1;

    printf("---");
    printf("\n\nTamanho da Palavra: %d letras\n\n", strlen(msm.strAster));
    printf("---");
    msm.acertou = 1;

    /*
        O JOGO PROPRIAMENTE DITO, ELE FARÁ UM LOOPING BASEADO NA DIFICULDADE SELECIONADA.
        E SE ELE RECEBER FALSO NA CONCLUSÃO, O LOOPING CONTINUARÁ.
    */
    for(int i=0;i<dificuldade;i++){
        msm.acertou = 1;
        printf("\nVoce tem: %d tentativa(s)!", dificuldade-i);
        printf("\nDigite uma letra: ");
        fflush(stdin);
        scanf(" %c", &msm.tentativa);

        if(msm.conclusao == 1){
            msm = checkLetra(msm);
            printf("\n%s", msm.strAster);
            printf("\n\n---");
            if(msm.acertou == 0)
                i--;
        }
        msm.conclusao = Jogo(msm);
        
        if(msm.conclusao == 0){
            Ganhou(msm);
            break;
        }
    }

    if(msm.conclusao == 1)
        Perdeu(msm);
}