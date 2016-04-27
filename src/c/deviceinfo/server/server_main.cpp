/*server main process*/

#include "server_main.h"

int main(int argc, char **argv) {
  
  pClientManager = new ClientManager;
  pConfigStore = new ConfigStore;
  pInfoRecorder = new InfoRecorder;


  pClientManager->init();
  pConfigStore->init();
  pInfoRecorder->init();

  pInfoRecorder->start();
  pConfigStore->start();
  pCLientManager->start()

  delete (pClientManager);
  delete (pConfigStore);
  delete (pInfoRecorder);
  return 0;
}
