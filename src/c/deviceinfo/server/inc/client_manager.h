/*client manager for manage the connectted client list*/

#include "common_inc.h"

class ClientManager {
 private:
  int user_id;

 public:
  ClientManager();
  virtual ~ClientManager();
  bool init();
};
