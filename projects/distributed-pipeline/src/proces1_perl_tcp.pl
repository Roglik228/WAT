#!/usr/bin/perl

# Proces I: STDIN -> Socket/TCP -> Proces II

use warnings;
use strict;

use Socket qw(PF_INET SOCK_STREAM pack_sockaddr_in inet_aton);
use MIME::Base64 qw(encode_base64);

my $host  = "127.0.0.1";
my $port  = 12345;
my $chunk = 512;

my $socket;

binmode(STDIN);

if( ! socket( $socket, PF_INET, SOCK_STREAM, 0 ) ){
	die "socket(): $!\n";
}

if( ! connect($socket, pack_sockaddr_in( $port, inet_aton( $host ) ) ) ){
	die "connect(): $!\n";
}

binmode($socket);

my $old = select($socket);$| = 1; select($old);

# STDIN
while( 1 ){
	my $buffer = "";
	my $n = sysread(STDIN, $buffer, $chunk);

	if( ! defined $n ){
		die "sysread(): $!\n";
	}

	last if( $n == 0 );

	my $data = encode_base64($buffer, "");
	print $socket $data . "\n";
	print STDOUT "wyslane";
}

shutdown($socket, 1);
close( $socket ) or die "close: $!";

exit( 0 );
