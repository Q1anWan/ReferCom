#pragma once
// MESSAGE SERVER_HEARTBEAT PACKING

#define MAVLINK_MSG_ID_SERVER_HEARTBEAT 0


typedef struct __mavlink_server_heartbeat_t {
 uint32_t pack_count; /*<  Indicate id of heartbeat. First pack is 0.*/
} mavlink_server_heartbeat_t;

#define MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN 4
#define MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN 4
#define MAVLINK_MSG_ID_0_LEN 4
#define MAVLINK_MSG_ID_0_MIN_LEN 4

#define MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC 36
#define MAVLINK_MSG_ID_0_CRC 36



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SERVER_HEARTBEAT { \
    0, \
    "SERVER_HEARTBEAT", \
    1, \
    {  { "pack_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_server_heartbeat_t, pack_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SERVER_HEARTBEAT { \
    "SERVER_HEARTBEAT", \
    1, \
    {  { "pack_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_server_heartbeat_t, pack_count) }, \
         } \
}
#endif

/**
 * @brief Pack a server_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_server_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN);
#else
    mavlink_server_heartbeat_t packet;
    packet.pack_count = pack_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERVER_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
}

/**
 * @brief Pack a server_heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_server_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN);
#else
    mavlink_server_heartbeat_t packet;
    packet.pack_count = pack_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERVER_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
}

/**
 * @brief Encode a server_heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param server_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_server_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_server_heartbeat_t* server_heartbeat)
{
    return mavlink_msg_server_heartbeat_pack(system_id, component_id, msg, server_heartbeat->pack_count);
}

/**
 * @brief Encode a server_heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param server_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_server_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_server_heartbeat_t* server_heartbeat)
{
    return mavlink_msg_server_heartbeat_pack_chan(system_id, component_id, chan, msg, server_heartbeat->pack_count);
}

/**
 * @brief Send a server_heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param pack_count  Indicate id of heartbeat. First pack is 0.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_server_heartbeat_send(mavlink_channel_t chan, uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN];
    _mav_put_uint32_t(buf, 0, pack_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT, buf, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
#else
    mavlink_server_heartbeat_t packet;
    packet.pack_count = pack_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a server_heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_server_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_server_heartbeat_t* server_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_server_heartbeat_send(chan, server_heartbeat->pack_count);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT, (const char *)server_heartbeat, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_server_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, pack_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT, buf, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
#else
    mavlink_server_heartbeat_t *packet = (mavlink_server_heartbeat_t *)msgbuf;
    packet->pack_count = pack_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVER_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_SERVER_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN, MAVLINK_MSG_ID_SERVER_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE SERVER_HEARTBEAT UNPACKING


/**
 * @brief Get field pack_count from server_heartbeat message
 *
 * @return  Indicate id of heartbeat. First pack is 0.
 */
static inline uint32_t mavlink_msg_server_heartbeat_get_pack_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a server_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param server_heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_server_heartbeat_decode(const mavlink_message_t* msg, mavlink_server_heartbeat_t* server_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    server_heartbeat->pack_count = mavlink_msg_server_heartbeat_get_pack_count(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN;
        memset(server_heartbeat, 0, MAVLINK_MSG_ID_SERVER_HEARTBEAT_LEN);
    memcpy(server_heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
