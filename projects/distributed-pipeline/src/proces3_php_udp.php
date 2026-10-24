<?php
	# Proces III: XML-RPC -> Socket/UDP -> Proces IV
	# php -S 127.0.0.1:12346 proces3_php_udp.php

	function handler( $method, $params = array()){
		
		$host_udp = "127.0.0.1";
		$port_udp = 12347;

		$data = $params[0];
		
		error_log("dostal");
		// Use md5 function here
		$hash = md5($data);

		error_log("The MD5 hash of '$data' is: $hash");
		$bin = base64_decode($data, true);
		
		$socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);

		$len = strlen($bin);

		if( $len > 0 ){
			socket_sendto($socket, $bin, $len, 0, $host_udp, $port_udp);
			usleep(1000);
			error_log("wyslal");
		}

		socket_close($socket);

		return array("ok" => 1, "bytes" => $len);
	}

	$xmlrpc = xmlrpc_server_create();
	xmlrpc_server_register_method($xmlrpc, "push", "handler");

	$xml = file_get_contents("php://input");

	$response = xmlrpc_server_call_method($xmlrpc, $xml, NULL);

	header("Content-Type: text/xml");
	print $response;

	xmlrpc_server_destroy($xmlrpc);
?>
