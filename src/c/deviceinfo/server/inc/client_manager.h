/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
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
