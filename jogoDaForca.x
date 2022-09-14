struct mensagem{
    int acertou;
    int conclusao;
    int dificuldade;
    char palavraChave[46];
    char tentativa;
    char strAster[46];
};

program JogoDaForca{
    version VERSAO{
        mensagem menuPrincipal(mensagem) = 1;
        mensagem Aster(mensagem) = 2;
        mensagem checkLetra(mensagem) = 3;
        int Jogo(mensagem) = 4;
    } = 1;
} = 23;