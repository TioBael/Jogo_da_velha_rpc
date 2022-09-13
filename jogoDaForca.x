struct mensagem{
    char palavraChave[46];
    char tentativa;
    char strAster[46];
    bool acertou;
    bool conclusao;
};

program JogoDaForca{
    version VERSAO{
        mensagem menuPrincipal(mensagem) = 1;
        mensagem Aster(mensagem) = 2;
        mensagem checkLetra(mensagem) = 3;
        bool Jogo(mensagem) = 4;
    } = 1;
} = 23;