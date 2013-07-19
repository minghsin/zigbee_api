/**
 * @file    zigbee_api.h
 * @brief   high level zigbee api
 * @date    2013/07/19
 * @author  Kaija Chang <kaija.chang@gmail.com>
 */

#ifndef __ZIGBEE_API_H
#define __ZIGBEE_API_H
#include "zigbee_ha.h"


#define ZB_ID_LEN   32

struct zb_dev{
    char    id[ZB_ID_LEN];
    int     type;
};

enum{
    ZB_SUCCESS,         // Command success
    ZB_FAILURE,         // Commnad failure
    ZB_DISCON          // Error, ZigBee disconnected
};


/**
 * @name            zb_connect
 * @brief           connect to the zigbee control socket
 * @param   addr    the zigbee socket address
 * @param   port    the zigbee socket port
 * @retval          the connect result
 */
int zb_connect(char *addr, int port);


/**
 * @name            zb_isalive
 * @brief           verify is zigbee socket is still alive
 * @retval  0       zigbee still alive
 * @retval  others  zigbee dead
 */
int zb_isalive();


/**
 * @name            zb_list_dev_num
 * @brief           list the device number which connected to zigbee coordinator
 * @retval  0       no device connected
 * @retval  >0      the conencted device
 */
int zb_list_dev_num();



/**
 * @name            zb_start_pjoin
 * @brief           start zigbee permission join
 * @param   timeout the timeout value in second, 0 means default timeout
 * @retval  0       pjoin start
 * @retval  others  error in enum
 */
int zb_start_pjoin(int timeout);




/**
 * @name            zb_start_pjoin_with_id
 * @brief           start zigbee permission join with specified device id
 * @param   timeout the timeout value in second, 0 means default timeout
 * @param   pid     the pid which allow to join
 * @retval  0       pjoin start
 * @retval  others  error in enum
 */
int zb_start_pjoin_with_id(int timeout, char *pid);






#endif
