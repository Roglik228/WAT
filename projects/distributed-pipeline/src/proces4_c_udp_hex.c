// Proces IV: Socket/UDP -> HEX -> STDOUT

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//======================================================================
int error( int ern, const char *msg ){
	perror( msg );
	return ern;
}
//======================================================================
int main( void ) {

	/* zmienne predefiniowane *****************************************/
	int port = 12347;

	/* zmienne niezainicjowane ****************************************/
	int fd, n, i;
	int opt = 1;
	int rcvbuf = 1024 * 1024;
	char buffer[2048];
	socklen_t socklen;

	struct sockaddr_in serv_addr, cli_addr;

	/* tworzymy gniazdo UDP ********************************************/
	fd = socket( AF_INET, SOCK_DGRAM, 0 );
	if( fd < 0 )
		return error( 1, "socket()" );

	setsockopt( fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt) );
	setsockopt( fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf, sizeof(rcvbuf) );

	/* zapelniamy strukture zerami ************************************/
	bzero( (char *) &serv_addr, sizeof(serv_addr) );

	/* przypisujemy parametry ******************************************/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	/* mapujemy gniazdo ************************************************/
	if( bind(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0 )
		return error( 2, "bind()" );

	fprintf(stderr, "Proces IV: nasluchuje UDP na porcie %d\n", port);

	/* odbieramy dane i wypisujemy HEX *********************************/
	socklen = sizeof(cli_addr);
	while( 1 ){
		n = recvfrom(fd, buffer, sizeof(buffer), 0, (struct sockaddr *) &cli_addr, &socklen);
		if( n < 0 ){
			perror( "recvfrom()" );
			continue;
		}

		for( i = 0; i < n; i++ ){
			printf( "%02x ", (unsigned char) buffer[i] );
		}
		//fwrite(buffer,1,n,stdout);
		fflush(stdout);
	}

	/* zamykamy gniazdo ***********************************************/
	close(fd);

	//------------------------------------------------------------------
	return 0;
}
//======================================================================
