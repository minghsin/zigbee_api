#include <stdio.h>
#include "zigbee_api.h"
#include "zigbee_ha.h"
int main()
{
    int type =0 ;
    type = type | ZIGBEE_HA_TYPE;
    type = type | HA_ONOFF_SWITCH;
    
	printf("test function %d\n", type);
	return 0;
}
