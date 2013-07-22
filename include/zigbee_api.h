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
#define cnum 32

struct zb_dev{
        char    	id[ZB_ID_LEN];
	int     	channel;
	int     	group_id;
	int     	mac_addr;
	int     	dev_id;
	int 		pan_id;
        int     	type;
	int             cluster_list[cnum];  	//cnum is total number of cluster 
};

enum{
    ZB_SUCCESS,         // Command success
    ZB_FAILURE,         // Commnad failure
    ZB_DISCON           // Error, ZigBee disconnected
};


/**
 * @name             zb_connect
 * @brief            connect to the zigbee control socket
 * @param   addr     the zigbee socket address
 * @param   port     the zigbee socket port
 * @retval           the connect result
 */
int zb_connect(char *addr, int port);


/**
 * @name             zb_isalive
 * @brief            verify is zigbee socket is still alive
 * @retval  0        zigbee still alive
 * @retval  others   zigbee dead
 */
int zb_isalive();


/**
 * @name             zb_list_dev_num
 * @brief            list the device number which connected to zigbee coordinator
 * @retval  0        no device connected
 * @retval  >0       the conencted device
 */
int zb_list_dev_num();


/**
 * @name             zb_list_dev
 * @brief            show the device which connected to zigbee coordinator
 * @retval  0        send success
 * @retval  others   error
 */
int zb_list_dev();


/**
 * @name             zb_start_pjoin
 * @brief            start zigbee permission join
 * @param   timeout  the timeout value in second, 0 means default timeout
 * @retval  0        pjoin start
 * @retval  others   error in enum
 */
int zb_start_pjoin(int timeout);


/**
 * @name             zb_start_pjoin_with_id
 * @brief            start zigbee permission join with specified device id
 * @param   timeout  the timeout value in second, 0 means default timeout
 * @param   pid      the pid which allow to join
 * @retval  0        pjoin start
 * @retval  others   error in enum
 */
int zb_start_pjoin_with_id(int timeout, char *pid);


/**
 * @name             zb_stop_join
 * @brief            stop  zigbee permission to join
 * @retval  0        pjoin stop
 * @retval  others   error
 */
int zb_stop_join();


/**
 * @name             zb_control_command
 * @brief            send  zigbee control command with specified device id or group
 * @param  	dev_id   device id if null means control specified group or all device
 * @param   type     device type(ON/OFF switch etc......)
 * @param   cluster  cluster number 
 * @param   group    only works when dev_id is null , if it is also null control all the device  
                     else means control the specified group
 * @param            data like on/off/toggle/RGB.....
 * @retval  0        send success
 * @retval  others   error
 */
int zb_control_command(int dev_id,int type,int cluster,int group,char* data);


/**
 * @name             zb_call_back
 * @brief            zigbee callback for automatic response
 * @param   dev_id	 device id 
 * @param   cluster	 cluster number 
 * @param   data	 data like temperature that automatic response
 * @retval  0        send success
 * @retval  others   error
 */
int zb_callback(int dev_id,int cluster,char* data);


/**
 * @name             zb_get_dev_status
 * @brief            check the device status
 * @param   dev_id	 device id 
 * @param   cluster	 cluster number 
 * @param   group	 group number if null means all group 
 * @retval  0        send success
 * @retval  others   error in enum
 */
int zb_get_dev_status(int dev_id,int cluster,int group);


/**
 * @name             zb_init
 * @brief            initial the zigbee network with specified pan_id
 * @param   pan_id	 pan id if null then automatic assigned one
 * @retval  0        send success
 * @retval  others   error
 */
int zb_init(int pan_id);


/**
 * @name             zb_block_list
 * @brief            to block specified mac address device to connect the control box
 * @param   mac_addr an unique number to represent each zigbee device
 * @retval  0        send success
 * @retval  others   error in enum
 */
int zb_block_list(int mac_addr);

/**
 * @name             zb_migrate_pan
 * @brief            migrate the whole network to another pan id
 * @param   pan_id 	 pan id
 * @retval  0        send success
 * @retval  others   error in enum
 */
int zb_migrate_pan(int pan_id);


/**
 * @name             zb_change_id
 * @brief            change the specified divice’s device id
 * @param   mac_addr device mac address
 * @param   dev_id 	 device id
 * @retval  0        send success
 * @retval  others   error in enum
 */
int zb_change_id(int mac_addr,int dev_id);


/**
 * @name             zb_group_add
 * @brief            add zigbee device into a group
 * @param   dev_id 	 device id
 * @param   group 	 new a group if there is not such group or add/change a zigbee device's group id  
 * @retval  0        send success
 * @retval  others   error in enum
 */
int zb_group_add(int dev_id,int group);

/**
 * @name             zb_group_leave
 * @brief            choose a zigbee device to leave a group
 * @param   dev_id 	 device id
 * @retval  0        send success
 * @retval  others   error
 */
int zb_group_leave(int dev_id);

/**
 * @name             zb_group_list
 * @brief            shows all group member of the specified group 
 * @param   group_id group id
 * @retval  0        send success
 * @retval  others   error
 */
int zb_group_list(int group_id);


#endif

