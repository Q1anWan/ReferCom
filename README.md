 # Referee System Protocol
*深圳科创学院2024高中生机器人冬令营 裁判系统通讯系统*   
*InnoxSZ 2024 Robotics Winter Camp for High School Students.* 
This submodule is the protocol of Referee System. Based on Mavlink v2.    
Author: qianwan.Jin   

>Version: 4   
Generate Date: 2024/01/22     
Description: Adding machine Feeding Table and change ID

>Version: 3   
Generate Date: 2023/12/20     
Description: Fix system component ID overun

>Version: 1.0   
Generate Date: 2023/12/13     
Description: Creat this protocol  

- [Referee System Protocol](#referee-system-protocol)
  - [Enum](#enum)
  - [Message](#message)
      - [Overall](#overall)
      - [Elaborate](#elaborate)
  - [Sample](#sample)
      - [Logic](#logic)
      - [Sample C code](#sample-c-code)

## Enum
- **REF_COMPONENT_ID**   
  Component ID.
  > While using mavlink transmission functions, both system_id and component_id should type in a same **REF_COMPONENT_ID** value, which indicate the sender.

  | Name                            | ID  | Description        |
  | ------------------------------- | --- | ------------------ |
  | REF_COMPONENT_ID_SERVER         | 1   | Referee server.    |
  | REF_COMPONENT_ID_X_FISHMONGER_A | 2   | Team X Fishmonger A. |
  | REF_COMPONENT_ID_X_FISHMONGER_B | 3   | Team X Fishmonger B. |
  | REF_COMPONENT_ID_X_FEEDINGTBALE | 4   | Team X Feeding Table. |
  | REF_COMPONENT_ID_Y_FISHMONGER_A | 5   | Team Y Fishmonger A. |
  | REF_COMPONENT_ID_Y_FISHMONGER_B | 6   | Team Y Fishmonger B. |
  | REF_COMPONENT_ID_Y_FEEDINGTBALE | 7   | Team Y Feeding Table. |
  | REF_COMPONENT_ID_FISHPOND       | 8   | Fish pond.         |

- **REF_ERROR_CODE**   
  Error codes of component.
  | Name                    | ID  | Description                  |
  | ----------------------- | --- | ---------------------------- |
  | REF_ERROR_NONE          | 0   | STOP State.                  |
  | REF_ERROR_COMMUNICATION | 1   | Communication is error.      |
  | REF_ERROR_VISION        | 2   | REF_ERROR_CV.                |
  | REF_ERROR_BATTERY       | 3   | Battery is going to run out. |

- **REF_FISHMONGER_STATE**   
  State machine of fishmonger.
  | Name                           | ID  | Description                     |
  | ------------------------------ | --- | ------------------------------- |
  | REF_FISHMONGER_STATE_STOP      | 0   | STOP State.            |
  | REF_FISHMONGER_STATE_FIXING    | 1   | Fixing State.            |
  | REF_FISHMONGER_STATE_SCANNING  | 2   | Fishmonger is waiting the fish. |
  | REF_FISHMONGER_STATE_COOLING   | 3   | Fishmonger is cooling.          |
  | REF_FISHMONGER_STATE_TRIGGERED | 4   | Fishmonger triggered by fish.          |

- **REF_FISHPOND_STATE**   
  State machine of fish pond.
  | Name                       | ID  | Description                           |
  | -------------------------- | --- | ------------------------------------- |
  | REF_FISHPOND_STATE_STOP    | 0   | STOP State.  |
  | REF_FISHPOND_STATE_FIXING  | 1   | Fixing State.|
  | REF_FISHPOND_STATE_NORMAL  | 2   | Fish pond is normal and stable.      |
  | REF_FISHPOND_STATE_RELEASE | 3   | Fish pond will release a box of fish. |
  | REF_FISHPOND_STATE_CLEAN   | 4   | Fish pond will turn the table over.  |

- **REF_FEEDINGTABLE_STATE**   
  State machine of feed table.
  | Name                       | ID  | Description                           |
  | -------------------------- | --- | ------------------------------------- |
  | REF_FEEDINGTABLE_STATE_STOP    | 0   | STOP State.                  |
  | REF_FEEDINGTABLE_STATE_FIXING  | 1   | Fixing State.                  |
  | REF_FEEDINGTABLE_STATE_NORMAL  | 2   | Feeding table is normal and stable.      |
  | REF_FEEDINGTABLE_STATE_RELEASE | 3   | Feeding table is releasig new fish feed. |
  | REF_FEEDINGTABLE_STATE_CLEAN   | 4   | Feeding table is turning the table over. |

- **REF_FISH_TYPE**   
  Fish types.
  | Name            | ID  | Description  |
  | --------------- | --- | ------------ |
  | REF_FISH_RED    | 0   | Red fish.    |
  | REF_FISH_ORANGE | 1   | Orange fish. |
  | REF_FISH_YELLOW | 2   | Yellow fish. |
  | REF_FISH_GREEN  | 3   | Green fish.  |
  | REF_FISH_BLUE   | 4   | Blue fish.   |

## Message
#### Overall
| Name                 | Sender     | Receiver   | Trigger Condition                                                     | Description                     |
| -------------------- | ---------- | ---------- | --------------------------------------------------------------------- | ------------------------------- |
| server_heartbeat     | Server     | Components | Periodic.                                                             | Indicate server is alive.       |
| set_component_state  | Server     | Components | Server actively send.                                                 | Set a new state of a component. |
| component_heartbeat  | Components | Server     | After receiving a message from server or an error happened.           | Return status of component.     |
| fishmonger_find_fish | Fishmonger | Server     | Periodic while fishmonger is at REF_FISHMONGER_STATE_TRIGGERED state. | Indicate the color the fish.    |


#### Elaborate
- **server_heartbeat**   
  Server heartbeat message should be sent periodically. This message can be used to detect whether a component is offline.
  | Field      | Type     | Enum  | Description                                                                      |
  | ---------- | -------- | :---: | -------------------------------------------------------------------------------- |
  | pack_count | uint32_t |   /   | Indicate id of heartbeat. Can be used as offline detection. The first pack is 0. |

- **set_component_state**   
  This message would set a new state for a component.
  - Set a component to STOP can clear error flag
  - The new_state should be correspond to component.
  - You can not set Fishmonger into REF_FISHMONGER_STATE_TRIGGERED
  - The parameter can indicate the box of fish pond you want to release. Otherwise, override it.

  | Field     | Type    |       Enum       | Description                             |
  | --------- | ------- | :--------------: | --------------------------------------- |
  | component | uint8_t | REF_COMPONENT_ID | Indicate the component you want to set. |
  | new_state | uint8_t |        *         | Indicate the new state.                 |
  | parameter | uint8_t |        /         | The auxiliary parameters.               |
 

- **component_heartbeat**      
  Component heartbeat indicate status of a component.
  - This message will be sent after receiving a message from server or an error occurred.
  - Clear error flag by set component state into STOP
  
  | Field           | Type     |      Enum      | Description                                         |
  | --------------- | -------- | :------------: | --------------------------------------------------- |
  | state           | uint8_t  |       /        | Indicate the state of now.                          |
  | error_code      | uint8_t  | REF_ERROR_CODE | Indicate error code. See more in chapter ***Enum*** |
  | battery_voltage | uint16_t |       /        | Indicate voltage of battery. Unit is mV.            |
  | pack_count      | uint32_t |       /        | Indicate id of heartbeat. The first pack is 0.      |

- **fishmonger_find_fish**
  Indicate fish man find a fish.   
  | Field      | Type     |       Enum       | Description                                                                                        |
  | ---------- | -------- | :--------------: | -------------------------------------------------------------------------------------------------- |
  | component  | uint8_t  | REF_COMPONENT_ID | Indicate which fishmonger.                                                                         |
  | fish_type  | uint8_t  |  REF_FISH_TYPE   | Indicate the type of the fish.                                                                     |
  | pack_count | uint16_t |        /         | Indicate how many same packs have been sent since fishmonger is at TRIGGERED. The first pack is 0. |


## Sample
#### Logic
- When server send a **server_heartbeat** 
  1. Server send **server_heartbeat** 
  2. Components return **component_heartbeat** after received **server_heartbeat**.

---

- When server ask fishpond stop
  1. Server send **set_component_state** to fishpond with REF_FISHPOND_STATE_STOP.
  2. Components return **component_heartbeat** with state REF_FISHPOND_STATE_STOP after received **set_component_state**.
  
- When server ask fishpond get into fixing mode
  1. Server send **set_component_state** to fishpond with REF_FISHPOND_STATE_FIXING.
  2. Components return **component_heartbeat** with state REF_FISHPOND_STATE_FIXING after received **set_component_state**.
   
- When server ask fishpond release
  1. Server send **set_component_state** to fishpond with REF_FISHPOND_STATE_RELEASE and parameter filled with box ID(1-6 indicates rotate 60 degree to 360 degree, counter-closewise).
  2. Components return **component_heartbeat** with state REF_FISHPOND_STATE_RELEASE after received **set_component_state**.
  3. Components return **component_heartbeat** with REF_FISHPOND_STATE_NORMAL after releasing. 
   
- When server ask fishpond clean
  1. Server send **set_component_state** to fishpond with REF_FISHPOND_STATE_RELEASE.
  2. Components return **component_heartbeat** with state REF_FISHPOND_STATE_RELEASE after received **set_component_state**.
  3. Components return **component_heartbeat** with REF_FISHPOND_STATE_NORMAL after cleaning.

---

- When server ask feeding table stop
  1. Server send **set_component_state** to feeding table with REF_FEEDINGTABLE_STATE_STOP.
  2. Components return **component_heartbeat** with state REF_FEEDINGTABLE_STATE_STOP after received **set_component_state**.
  
- When server ask feeding table get into fixing mode
  1. Server send **set_component_state** to feeding table with REF_FEEDINGTABLE_STATE_FIXING.
  2. Components return **component_heartbeat** with state REF_FEEDINGTABLE_STATE_FIXING after received **set_component_state**.
   
- When server ask feeding table release
  1. Server send **set_component_state** to feeding table with REF_FEEDINGTABLE_STATE_RELEASE and parameter filled with box ID(1-3 indicates RELEASE 1 to 3 boxes).
  2. Components return **component_heartbeat** with state REF_FEEDINGTABLE_STATE_RELEASE after received **set_component_state**.
  3. Components return **component_heartbeat** with REFFEEDINGTABLE_STATE_NORMAL after releasing. 
   
- When server ask feeding table clean
  1. Server send **set_component_state** to feeding table with REF_FEEDINGTABLE_STATE_RELEASE.
  2. Components return **component_heartbeat** with state REF_FEEDINGTABLE_STATE_RELEASE after received **set_component_state**.
  3. Components return **component_heartbeat** with REF_FEEDINGTABLE_STATE_NORMAL after cleaning.

---

- When server ask fishmonger stop
  1. Server send **set_component_state** to fishmonger with REF_FISHMONGER_STATE_STOP.
  2. Components return **component_heartbeat** with state REF_FISHMONGER_STATE_STOP after received **set_component_state**.
   
- When server ask fishmonger get into fixing mode
  1. Server send **set_component_state** to fishmonger with REF_FISHMONGER_STATE_FIXING.
  2. Components return **component_heartbeat** with state REF_FISHMONGER_STATE_FIXING after received **set_component_state**.

- When server ask fishmonger start scanning 
  1. Server send **set_component_state** to fishmonger with REF_FISHMONGER_STATE_SCANNING.
  2. Components return **component_heartbeat** with state REF_FISHMONGER_STATE_SCANNING after received **set_component_state**.

- When fishmonger find a fish
  1. Fishmonger changes into REF_FISHMONGER_STATE_TRIGGERED until server ask it change.
  2. Fishmonger send **component_heartbeat** to fishmonger with REF_FISHMONGER_STATE_TRIGGERED. 
  3. Fishmonger send **fishmonger_find_fish** to server with REF_FISH_TYPE periodically.

- When server realize fishmonger find a fish and ask it get into cooling
  1. Server send **set_component_state** to fishmonger with REF_FISHMONGER_STATE_COOLING.
  2. Components return **component_heartbeat** with state REF_FISHMONGER_STATE_COOLING after received **set_component_state**.



#### Sample C code

``` C
/*演示发送Server心跳包*/
#include "mavlink.h" //首先引用头文件
uint32_t cnt = 0;    // 心跳包的数据: 发送次数
/*这是串口发送函数*/
extern void uart_transmit(uint8_t *buffer, uint16_t data_length);

/*举个例子 Server发送心跳包*/
uint8_t MyTask()
{
    /*准备各个变量*/
    /*创建一个Mavlink消息结构体*/
    mavlink_message_t *msg = (mavlink_message_t *)malloc(sizeof(mavlink_message_t));
    /*清理这部分内存*/
    memset(msg, 0, sizeof(mavlink_message_t));
    /*消息需要发送的字节数长度*/
    uint16_t Txlen = 0;

    /*发送一个正确心跳包*/
    /*准备发送数据*/
    /*获取一段内存用于发送缓冲*/
    /*真实字节长度PAYLOAD_LEN+12*/
    uint8_t *txbuf = (uint8_t *)malloc(MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN + 12);

    /*封包*/
    /*各个变量可能使用了约定的枚举, 有最大最小值限制等. 建议参考ReferCom.xml原始文件*/
    /*函数传入值: 1.发送的主机(Server) 2.发送的部件(Server)*/
    /*函数传入值: 3.消息结构体*/
    /*函数传入值: 4.消息的内容*/
    mavlink_msg_server_heartbeat_encode(REF_COMPONENT_ID::REF_COMPONENT_ID_SERVER, REF_COMPONENT_ID::REF_COMPONENT_ID_SERVER,
                                        msg,
                                        cnt++);

    /*将包转移至发送缓冲区*/
    Txlen = mavlink_msg_to_send_buffer(txbuf, msg);

    /*执行发送*/
    uart_transmit(txbuf, Txlen);
    /*释放内存*/
    free((void *)txbuf);
    free((void *)msg);
    /*Do something else*/
    /*...*/

    return 1;
}
```

```C
/*演示接收来自Fishpond和Fishmonger的数据*/
#include "mavlink.h" //首先引用头文件

/*这是串口接收函数*/
extern void uart_recieve(uint8_t *&buffer, uint16_t *recieve_length);

/*举个例子 Server 接收心跳包*/
uint8_t MyTask()
{
    /*准备变量*/
    /*接受到的消息*/
    mavlink_component_heartbeat_t fishpond_status;
    mavlink_component_heartbeat_t fishmonger_X_A_status;
    /*.....*/
    /*创建Mavlink状态变量*/
    mavlink_status_t status;
    /*选择一个Mavlink通道*/
    int chan = MAVLINK_COMM_0;
    /*创建一个Mavlink消息结构体*/
    mavlink_message_t *msg = (mavlink_message_t *)malloc(sizeof(mavlink_message_t));
    /*清理这部分内存*/
    memset(msg, 0, sizeof(mavlink_message_t));

    /*接收缓冲区*/
    /*大小随意 注意可能出现多条消息粘包接收情况*/
    uint8_t *rxbuf = (uint8_t *)malloc(512);
    /*接收到的数据长度*/
    uint16_t RxLen = 0;
    /*接收与解析消息*/
    for (;;)
    {
        /*接收数据*/
        uart_recieve(rxbuf, &RxLen);

        /*收到新数据*/
        for (ULONG i = 0; i < RxLen; i++)
        {
            /*解包*/
            /*MavlinkV2出现错误包后，再次接收二个正常包后恢复正常解析，但第一个正常包将丢失，第二个可被正确解析*/
            if (mavlink_parse_char(chan, rxbuf[i], msg, &status))
            {
                /*解析包成功 处理数据*/
                switch (msg->msgid)
                {
                    case COMPONENT_HEARTBEAT:
                    {
                        switch (msg->sysid)
                        {
                            case REF_COMPONENT_ID::REF_COMPONENT_ID_FISHPOND:
                            {
                                mavlink_msg_component_heartbeat_decode(msg, &fishpond_status);
                                /*Do someting with new message*/
                                /*...*/
                                break;
                            }
                            case REF_COMPONENT_ID::REF_COMPONENT_ID_X_FISHMONGER_A:
                            {
                                mavlink_msg_component_heartbeat_decode(msg, &fishmonger_X_A_status);
                                /*Do someting with new message*/
                                /*...*/
                                break;
                            }
                        }
                    }
                    /*其他数据处理*/
                    /*...*/
                }
            }
        }

        /* Sleep thread for 1ms if no data received */
        sleep(1);
    }

    /*Do something else*/
    /*...*/

    /*释放资源*/
    free((void *)msg);
    free((void *)rxbuf);
    return 1;
}
```