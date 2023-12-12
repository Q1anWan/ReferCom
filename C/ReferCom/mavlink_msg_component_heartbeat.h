#pragma once
// MESSAGE COMPONENT_HEARTBEAT PACKING

#define MAVLINK_MSG_ID_COMPONENT_HEARTBEAT 3


typedef struct __mavlink_component_heartbeat_t {
 uint32_t pack_count; /*<  Indicate id of heartbeat. First pack is 0.*/
 uint16_t battery_voltage; /*< [mV] Indicate voltage of battery.*/
 uint8_t state; /*<  Indicate the state of now.*/
 uint8_t error_code; /*<  Indicate error code.*/
} mavlink_component_heartbeat_t;

#define MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN 8
#define MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN 8
#define MAVLINK_MSG_ID_3_LEN 8
#define MAVLINK_MSG_ID_3_MIN_LEN 8

#define MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC 244
#define MAVLINK_MSG_ID_3_CRC 244



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMPONENT_HEARTBEAT { \
    3, \
    "COMPONENT_HEARTBEAT", \
    4, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_component_heartbeat_t, state) }, \
         { "error_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_component_heartbeat_t, error_code) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_component_heartbeat_t, battery_voltage) }, \
         { "pack_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_component_heartbeat_t, pack_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMPONENT_HEARTBEAT { \
    "COMPONENT_HEARTBEAT", \
    4, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_component_heartbeat_t, state) }, \
         { "error_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_component_heartbeat_t, error_code) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_component_heartbeat_t, battery_voltage) }, \
         { "pack_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_component_heartbeat_t, pack_count) }, \
         } \
}
#endif

/**
 * @brief Pack a component_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  Indicate the state of now.
 * @param error_code  Indicate error code.
 * @param battery_voltage [mV] Indicate voltage of battery.
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, uint8_t error_code, uint16_t battery_voltage, uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);
    _mav_put_uint16_t(buf, 4, battery_voltage);
    _mav_put_uint8_t(buf, 6, state);
    _mav_put_uint8_t(buf, 7, error_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN);
#else
    mavlink_component_heartbeat_t packet;
    packet.pack_count = pack_count;
    packet.battery_voltage = battery_voltage;
    packet.state = state;
    packet.error_code = error_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMPONENT_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
}

/**
 * @brief Pack a component_heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  Indicate the state of now.
 * @param error_code  Indicate error code.
 * @param battery_voltage [mV] Indicate voltage of battery.
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,uint8_t error_code,uint16_t battery_voltage,uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);
    _mav_put_uint16_t(buf, 4, battery_voltage);
    _mav_put_uint8_t(buf, 6, state);
    _mav_put_uint8_t(buf, 7, error_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN);
#else
    mavlink_component_heartbeat_t packet;
    packet.pack_count = pack_count;
    packet.battery_voltage = battery_voltage;
    packet.state = state;
    packet.error_code = error_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMPONENT_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
}

/**
 * @brief Encode a component_heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param component_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_component_heartbeat_t* component_heartbeat)
{
    return mavlink_msg_component_heartbeat_pack(system_id, component_id, msg, component_heartbeat->state, component_heartbeat->error_code, component_heartbeat->battery_voltage, component_heartbeat->pack_count);
}

/**
 * @brief Encode a component_heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_component_heartbeat_t* component_heartbeat)
{
    return mavlink_msg_component_heartbeat_pack_chan(system_id, component_id, chan, msg, component_heartbeat->state, component_heartbeat->error_code, component_heartbeat->battery_voltage, component_heartbeat->pack_count);
}

/**
 * @brief Send a component_heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param state  Indicate the state of now.
 * @param error_code  Indicate error code.
 * @param battery_voltage [mV] Indicate voltage of battery.
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_component_heartbeat_send(mavlink_channel_t chan, uint8_t state, uint8_t error_code, uint16_t battery_voltage, uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);
    _mav_put_uint16_t(buf, 4, battery_voltage);
    _mav_put_uint8_t(buf, 6, state);
    _mav_put_uint8_t(buf, 7, error_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT, buf, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
#else
    mavlink_component_heartbeat_t packet;
    packet.pack_count = pack_count;
    packet.battery_voltage = battery_voltage;
    packet.state = state;
    packet.error_code = error_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a component_heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_component_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_component_heartbeat_t* component_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_component_heartbeat_send(chan, component_heartbeat->state, component_heartbeat->error_code, component_heartbeat->battery_voltage, component_heartbeat->pack_count);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT, (const char *)component_heartbeat, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_component_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, uint8_t error_code, uint16_t battery_voltage, uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, pack_count);
    _mav_put_uint16_t(buf, 4, battery_voltage);
    _mav_put_uint8_t(buf, 6, state);
    _mav_put_uint8_t(buf, 7, error_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT, buf, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
#else
    mavlink_component_heartbeat_t *packet = (mavlink_component_heartbeat_t *)msgbuf;
    packet->pack_count = pack_count;
    packet->battery_voltage = battery_voltage;
    packet->state = state;
    packet->error_code = error_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE COMPONENT_HEARTBEAT UNPACKING


/**
 * @brief Get field state from component_heartbeat message
 *
 * @return  Indicate the state of now.
 */
static inline uint8_t mavlink_msg_component_heartbeat_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field error_code from component_heartbeat message
 *
 * @return  Indicate error code.
 */
static inline uint8_t mavlink_msg_component_heartbeat_get_error_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field battery_voltage from component_heartbeat message
 *
 * @return [mV] Indicate voltage of battery.
 */
static inline uint16_t mavlink_msg_component_heartbeat_get_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field pack_count from component_heartbeat message
 *
 * @return  Indicate id of heartbeat. First pack is 0.
 */
static inline uint32_t mavlink_msg_component_heartbeat_get_pack_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a component_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param component_heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_component_heartbeat_decode(const mavlink_message_t* msg, mavlink_component_heartbeat_t* component_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    component_heartbeat->pack_count = mavlink_msg_component_heartbeat_get_pack_count(msg);
    component_heartbeat->battery_voltage = mavlink_msg_component_heartbeat_get_battery_voltage(msg);
    component_heartbeat->state = mavlink_msg_component_heartbeat_get_state(msg);
    component_heartbeat->error_code = mavlink_msg_component_heartbeat_get_error_code(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN;
        memset(component_heartbeat, 0, MAVLINK_MSG_ID_COMPONENT_HEARTBEAT_LEN);
    memcpy(component_heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
