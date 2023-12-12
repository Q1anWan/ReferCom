#pragma once
// MESSAGE FISHMONGER_FIND_FISH PACKING

#define MAVLINK_MSG_ID_FISHMONGER_FIND_FISH 4


typedef struct __mavlink_fishmonger_find_fish_t {
 uint16_t pack_count; /*<  Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0.*/
 uint8_t component; /*<  Indicate which fishmonger.*/
 uint8_t fish_type; /*<  Indicate the type of the fish.*/
} mavlink_fishmonger_find_fish_t;

#define MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN 4
#define MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN 4
#define MAVLINK_MSG_ID_4_LEN 4
#define MAVLINK_MSG_ID_4_MIN_LEN 4

#define MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC 36
#define MAVLINK_MSG_ID_4_CRC 36



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FISHMONGER_FIND_FISH { \
    4, \
    "FISHMONGER_FIND_FISH", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_fishmonger_find_fish_t, component) }, \
         { "fish_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_fishmonger_find_fish_t, fish_type) }, \
         { "pack_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_fishmonger_find_fish_t, pack_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FISHMONGER_FIND_FISH { \
    "FISHMONGER_FIND_FISH", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_fishmonger_find_fish_t, component) }, \
         { "fish_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_fishmonger_find_fish_t, fish_type) }, \
         { "pack_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_fishmonger_find_fish_t, pack_count) }, \
         } \
}
#endif

/**
 * @brief Pack a fishmonger_find_fish message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param component  Indicate which fishmonger.
 * @param fish_type  Indicate the type of the fish.
 * @param pack_count  Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fishmonger_find_fish_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t component, uint8_t fish_type, uint16_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN];
    _mav_put_uint16_t(buf, 0, pack_count);
    _mav_put_uint8_t(buf, 2, component);
    _mav_put_uint8_t(buf, 3, fish_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN);
#else
    mavlink_fishmonger_find_fish_t packet;
    packet.pack_count = pack_count;
    packet.component = component;
    packet.fish_type = fish_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FISHMONGER_FIND_FISH;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
}

/**
 * @brief Pack a fishmonger_find_fish message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component  Indicate which fishmonger.
 * @param fish_type  Indicate the type of the fish.
 * @param pack_count  Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fishmonger_find_fish_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t component,uint8_t fish_type,uint16_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN];
    _mav_put_uint16_t(buf, 0, pack_count);
    _mav_put_uint8_t(buf, 2, component);
    _mav_put_uint8_t(buf, 3, fish_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN);
#else
    mavlink_fishmonger_find_fish_t packet;
    packet.pack_count = pack_count;
    packet.component = component;
    packet.fish_type = fish_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FISHMONGER_FIND_FISH;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
}

/**
 * @brief Encode a fishmonger_find_fish struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fishmonger_find_fish C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fishmonger_find_fish_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fishmonger_find_fish_t* fishmonger_find_fish)
{
    return mavlink_msg_fishmonger_find_fish_pack(system_id, component_id, msg, fishmonger_find_fish->component, fishmonger_find_fish->fish_type, fishmonger_find_fish->pack_count);
}

/**
 * @brief Encode a fishmonger_find_fish struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fishmonger_find_fish C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fishmonger_find_fish_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fishmonger_find_fish_t* fishmonger_find_fish)
{
    return mavlink_msg_fishmonger_find_fish_pack_chan(system_id, component_id, chan, msg, fishmonger_find_fish->component, fishmonger_find_fish->fish_type, fishmonger_find_fish->pack_count);
}

/**
 * @brief Send a fishmonger_find_fish message
 * @param chan MAVLink channel to send the message
 *
 * @param component  Indicate which fishmonger.
 * @param fish_type  Indicate the type of the fish.
 * @param pack_count  Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fishmonger_find_fish_send(mavlink_channel_t chan, uint8_t component, uint8_t fish_type, uint16_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN];
    _mav_put_uint16_t(buf, 0, pack_count);
    _mav_put_uint8_t(buf, 2, component);
    _mav_put_uint8_t(buf, 3, fish_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH, buf, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
#else
    mavlink_fishmonger_find_fish_t packet;
    packet.pack_count = pack_count;
    packet.component = component;
    packet.fish_type = fish_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH, (const char *)&packet, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
#endif
}

/**
 * @brief Send a fishmonger_find_fish message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fishmonger_find_fish_send_struct(mavlink_channel_t chan, const mavlink_fishmonger_find_fish_t* fishmonger_find_fish)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fishmonger_find_fish_send(chan, fishmonger_find_fish->component, fishmonger_find_fish->fish_type, fishmonger_find_fish->pack_count);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH, (const char *)fishmonger_find_fish, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
#endif
}

#if MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fishmonger_find_fish_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t component, uint8_t fish_type, uint16_t pack_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, pack_count);
    _mav_put_uint8_t(buf, 2, component);
    _mav_put_uint8_t(buf, 3, fish_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH, buf, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
#else
    mavlink_fishmonger_find_fish_t *packet = (mavlink_fishmonger_find_fish_t *)msgbuf;
    packet->pack_count = pack_count;
    packet->component = component;
    packet->fish_type = fish_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH, (const char *)packet, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_MIN_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_CRC);
#endif
}
#endif

#endif

// MESSAGE FISHMONGER_FIND_FISH UNPACKING


/**
 * @brief Get field component from fishmonger_find_fish message
 *
 * @return  Indicate which fishmonger.
 */
static inline uint8_t mavlink_msg_fishmonger_find_fish_get_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field fish_type from fishmonger_find_fish message
 *
 * @return  Indicate the type of the fish.
 */
static inline uint8_t mavlink_msg_fishmonger_find_fish_get_fish_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field pack_count from fishmonger_find_fish message
 *
 * @return  Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0.
 */
static inline uint16_t mavlink_msg_fishmonger_find_fish_get_pack_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a fishmonger_find_fish message into a struct
 *
 * @param msg The message to decode
 * @param fishmonger_find_fish C-struct to decode the message contents into
 */
static inline void mavlink_msg_fishmonger_find_fish_decode(const mavlink_message_t* msg, mavlink_fishmonger_find_fish_t* fishmonger_find_fish)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fishmonger_find_fish->pack_count = mavlink_msg_fishmonger_find_fish_get_pack_count(msg);
    fishmonger_find_fish->component = mavlink_msg_fishmonger_find_fish_get_component(msg);
    fishmonger_find_fish->fish_type = mavlink_msg_fishmonger_find_fish_get_fish_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN? msg->len : MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN;
        memset(fishmonger_find_fish, 0, MAVLINK_MSG_ID_FISHMONGER_FIND_FISH_LEN);
    memcpy(fishmonger_find_fish, _MAV_PAYLOAD(msg), len);
#endif
}
