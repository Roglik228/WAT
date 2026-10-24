#!/usr/bin/python3

# Proces II: Socket/TCP -> XML-RPC -> Proces III

import socket
import xmlrpc.client
import hashlib

host = "127.0.0.1"
port = 12345
xmlrpc_url = "http://127.0.0.1:12346/RPC2"

# Gniazdo TCP
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
server.listen(5)

print("Proces II: nasluchuje TCP na", host, port)

# Obsluga kolejnych klientow 
while True:
    client, address = server.accept()
    print("Proces II: polaczenie od", address)

    rpc = xmlrpc.client.ServerProxy(xmlrpc_url, allow_none=True)

    with client:
        file = client.makefile("rb")
       
        while True:
            line = file.readline()
            if not line:
                break

            data = line.strip().decode("ascii")
            res = hashlib.md5(data.encode())
            if data == "":
                continue
            
            print("dostal")
            print(res.hexdigest())

            try:
                rpc.push(data)

                print("wyslal")

            except Exception as e:
                print("Proces II: blad XML-RPC:", e)
                break

    print("Proces II: koniec polaczenia")
