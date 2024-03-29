#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write

#include <pthread.h> //for threading , link with lpthread

void *connection_handler(void *);

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int socket_desc, new_socket, c, *new_sock;
  struct sockaddr_in server, client;
  char *message;

  // Create socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1)
  {
    printf("Could not create socket");
  }

  // Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8888);

  // Bind
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
  {
    puts("bind failed");
    return 1;
  }
  puts("bind done");

  // Listen
  listen(socket_desc, 3);

  // Accept and incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);
  while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c)))
  {
    puts("Connection accepted");

    // Reply to the client
    message = "Hello Client , I have received your connection. And now I will assign a handler for you\n";
    write(new_socket, message, strlen(message));

    pthread_t sniffer_thread;
    new_sock = malloc(1);
    *new_sock = new_socket;

    if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) < 0)
    {
      perror("could not create thread");
      return 1;
    }

    // Now join the thread , so that we dont terminate before the thread
    // pthread_join( sniffer_thread , NULL);
    puts("Handler assigned");
  }

  if (new_socket < 0)
  {
    perror("accept failed");
    return 1;
  }

  return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
  // Get the socket descriptor
  int sock = *(int *)socket_desc;

  char *message;

  // Send some messages to the client
  message = "Greetings! I am your connection handler\n";
  write(sock, message, strlen(message));

  message = "Its my duty to communicate with you\n";
  write(sock, message, strlen(message));
  int number;
  int numeroAleatorio = rand() % 10 + 1;
  while (1)
  {
    message = "Guess a number between 1 - 10: ";
    write(sock, message, strlen(message));
    char buffer[1024];
    read(sock, buffer, sizeof(buffer));
    message = "You entered: ";
    write(sock, message, strlen(message));
    write(sock, buffer, strlen(buffer));
    int numero = atoi(buffer);
    if (numero == numeroAleatorio)
    {
      message = "You win!\n";
      write(sock, message, strlen(message));
      break;
    }
    else if (numero > numeroAleatorio)
    {
      message = "Too high!\n";
      write(sock, message, strlen(message));
    }
    else
    {
      message = "Too low!\n";
      write(sock, message, strlen(message));
    }
  }
  free(socket_desc);
}
