/** @file
 *    @brief MAVLink comm protocol testsuite generated from ReferCom.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef REFERCOM_TESTSUITE_H
#define REFERCOM_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_ReferCom(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_ReferCom(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_server_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SERVER_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_server_heartbeat_t packet_in = {
        963497464
    };
    mavlink_server_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pack_count = packet_in.pack_count;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_server_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_server_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_server_heartbeat_pack(system_id, component_id, &msg , packet1.pack_count );
    mavlink_msg_server_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_server_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pack_count );
    mavlink_msg_server_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_server_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_server_heartbeat_send(MAVLINK_COMM_1 , packet1.pack_count );
    mavlink_msg_server_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SERVER_HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SERVER_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_set_conponent_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_CONPONENT_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_conponent_state_t packet_in = {
        5,72,139
    };
    mavlink_set_conponent_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.component = packet_in.component;
        packet1.new_state = packet_in.new_state;
        packet1.parameter = packet_in.parameter;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_conponent_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_conponent_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_conponent_state_pack(system_id, component_id, &msg , packet1.component , packet1.new_state , packet1.parameter );
    mavlink_msg_set_conponent_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_conponent_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.component , packet1.new_state , packet1.parameter );
    mavlink_msg_set_conponent_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_conponent_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_conponent_state_send(MAVLINK_COMM_1 , packet1.component , packet1.new_state , packet1.parameter );
    mavlink_msg_set_conponent_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SET_CONPONENT_STATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SET_CONPONENT_STATE) != NULL);
#endif
}

static void mavlink_test_component_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COMPONENT_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_component_heartbeat_t packet_in = {
        963497464,17443,151,218
    };
    mavlink_component_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pack_count = packet_in.pack_count;
        packet1.battery_voltage = packet_in.battery_voltage;
        packet1.state = packet_in.state;
        packet1.error_code = packet_in.error_code;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_component_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_heartbeat_pack(system_id, component_id, &msg , packet1.state , packet1.error_code , packet1.battery_voltage , packet1.pack_count );
    mavlink_msg_component_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.error_code , packet1.battery_voltage , packet1.pack_count );
    mavlink_msg_component_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_component_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_heartbeat_send(MAVLINK_COMM_1 , packet1.state , packet1.error_code , packet1.battery_voltage , packet1.pack_count );
    mavlink_msg_component_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("COMPONENT_HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_COMPONENT_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_state_rc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_STATE_RC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_state_rc_t packet_in = {
        5
    };
    mavlink_state_rc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_STATE_RC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_STATE_RC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_rc_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_state_rc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_rc_pack(system_id, component_id, &msg , packet1.state );
    mavlink_msg_state_rc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_rc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state );
    mavlink_msg_state_rc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_state_rc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_rc_send(MAVLINK_COMM_1 , packet1.state );
    mavlink_msg_state_rc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("STATE_RC") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_STATE_RC) != NULL);
#endif
}

static void mavlink_test_ReferCom(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_server_heartbeat(system_id, component_id, last_msg);
    mavlink_test_set_conponent_state(system_id, component_id, last_msg);
    mavlink_test_component_heartbeat(system_id, component_id, last_msg);
    mavlink_test_state_rc(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // REFERCOM_TESTSUITE_H
