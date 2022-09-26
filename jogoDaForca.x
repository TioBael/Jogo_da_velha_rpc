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
        void showServidor(mensagem) = 2;
    } = 1;
} = 23;