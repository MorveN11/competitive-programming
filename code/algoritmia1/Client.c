#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
  // Crear socket
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  // Configurar la dirección del servidor
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(12345);                  // Puerto
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Dirección IP del servidor

  // Conectar al servidor
  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

  // Juego
  int guess;
  char response[256];
  do
  {
    printf("Adivina el número: ");
    scanf("%d", &guess);

    // Enviar intento al servidor
    send(clientSocket, &guess, sizeof(guess), 0);

    // Recibir respuesta del servidor
    recv(clientSocket, response, sizeof(response), 0);
    printf("Respuesta del servidor: %s\n", response);

  } while (strcmp(response, "Correcto") != 0);

  // Cerrar el socket
  close(clientSocket);

  return 0;
}
