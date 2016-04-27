/*server main process*/

#include "server_main.h"

int main(int argc, char **argv) {
  ClientManager curClient = new ClientManager;
  delete (curClient);
  return 0;
}
