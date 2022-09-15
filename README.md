# Trabalho A1 - Jogo da Forca + SUN-RPC

O trabalho consiste em utilizar um metodo de distribuição para criar um jogo.

## Sobre:

O jogo escolhido para ser criado foi um Jogo da Forca, onde o usuario pode escolher entre 3 dificuldades (Facil, Médio e Dificil), onde essas dificuldades mudam basando-se no tamanho da palavra que foi escolhida pelo servidor.

O servidor ficará responsavel em escolher uma palavra, logo em seguida, o cliente (jogador) escolherá qual dificuldade ele irá jogar, as mudanças das dificuldades são simples:

- Fácil:
    
    Ela modifica o numero de tentativas para ser 3/4 (ou 75%) do tamanho da palavra. Exemplo: `amedrontarem`, uma palavra de 12 letras, o jogador terá 9 tentativas para acertar.

- Médio:

    Ela modifica o numero de tentativas para ser 2/4 (ou 50%) do tamanho da palavra. Exemplo: `amedrontarem`, uma palavra de 12 letras, o jogador terá 6 tentativas para acertar.

- Dificil:

    Ela modifica o numero de tentativas para ser 1/4 (ou 25%) do tamanho da palavra. Exemplo: `amedrontarem`, uma palavra de 12 letras, o jogador terá 3 tentativas para acertar.

Sendo que se o jogador acertar uma letra, ele não perde a tentativa.

## Código:

O codigo original do jogo antes da distribuição pode ser visto [aqui](./jogoDaForca.c).

O codigo depois da distribuição do cliente, pode ser visto [aqui](./jogoDaForca_client.c).

O codigo depois da distribuião do servidor, pode ser visto [aqui](./jogoDaForca_server.c).

Caso deseje alterar algo no codigo, foque sua atenção nos três codigos supracitados, os outros arquivos não devem ser alterados, aviso do próprio RPCGEN.

Para compliar, basta dar o comando `Make` na pasta com os arquivos, o Makefile é quase igual ao fornecido pelo rpcgen, com apenas uma mudança necessaria devido ao uso da biblioteca `math.h`, onde no sistemas Linux, se torna necessario o uso da flag `-lm` como argumento para o GCC.

Para executar, rode primeiro o servidor `./jogoDaForca_server`, e num console separado, rode o cliente `./jogoDaForca_client [endereço_de_ip]`.


## Particularidades:

Esse jogo foi desenvolvido visando ser jogado em ambientes Linux, logo, ele não funciona em sistemas Windows.

Agradecimentos ao GP!