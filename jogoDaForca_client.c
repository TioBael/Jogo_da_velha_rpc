/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "jogoDaForca.h"


void jogodaforca_1(char *host){
	CLIENT *clnt;
	mensagem  *result_1;
	mensagem  menuprincipal_1_arg;
	mensagem  *result_2;
	mensagem  aster_1_arg;
	mensagem  *result_3;
	mensagem  checkletra_1_arg;
	bool_t  *result_4;
	mensagem  jogo_1_arg;
	int dificuldade;

#ifndef	DEBUG
	clnt = clnt_create (host, JogoDaForca, VERSAO, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	
	result_1 = menuprincipal_1(&menuprincipal_1_arg, clnt);
	if (result_1 == (mensagem *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_1 = aster_1(&aster_1_arg, clnt);
	if (result_1 == (mensagem *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_1 = checkletra_1(&checkletra_1_arg, clnt);
	if (result_1 == (mensagem *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_1 = jogo_1(&jogo_1_arg, clnt);
	if (result_1 == (bool_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	printf("\n%s\n", result_1->palavraChave);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[]){
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	jogodaforca_1 (host);
exit (0);
}
