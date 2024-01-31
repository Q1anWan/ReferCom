#pragma once
// MESSAGE STATE_RC PACKING

#define MAVLINK_MSG_ID_STATE_RC 4


typedef struct __mavlink_state_rc_t {
 uint8_t state; /*<  Indicate if RC Connected.*/
} mavlink_state_rc_t;

#define MAVLINK_MSG_ID_STATE_RC_LEN 1
#define MAVLINK_MSG_ID_STATE_RC_MIN_LEN 1
#define MAVLINK_MSG_ID_4_LEN 1
#define MAVLINK_MSG_ID_4_MIN_LEN 1

#define MAVLINK_MSG_ID_STATE_RC_CRC 182
#define MAVLINK_MSG_ID_4_CRC 182



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STATE_RC { \
    4, \
    "STATE_RC", \
    1, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_state_rc_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STATE_RC { \
    "STATE_RC", \
    1, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_state_rc_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a state_rc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  Indicate if RC Connected.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_state_rc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_RC_LEN];
    _mav_put_uint8_t(buf, 0, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STATE_RC_LEN);
#else
    mavlink_state_rc_t packet;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STATE_RC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STATE_RC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
}

/**
 * @brief Pack a state_rc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  Indicate if RC Connected.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_state_rc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_RC_LEN];
    _mav_put_uint8_t(buf, 0, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STATE_RC_LEN);
#else
    mavlink_state_rc_t packet;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STATE_RC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STATE_RC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
}

/**
 * @brief Encode a state_rc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param state_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_state_rc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_state_rc_t* state_rc)
{
    return mavlink_msg_state_rc_pack(system_id, component_id, msg, state_rc->state);
}

/**
 * @brief Encode a state_rc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_state_rc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_state_rc_t* state_rc)
{
    return mavlink_msg_state_rc_pack_chan(system_id, component_id, chan, msg, state_rc->state);
}

/**
 * @brief Send a state_rc message
 * @param chan MAVLink channel to send the message
 *
 * @param state  Indicate if RC Connected.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_state_rc_send(mavlink_channel_t chan, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_RC_LEN];
    _mav_put_uint8_t(buf, 0, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_RC, buf, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
#else
    mavlink_state_rc_t packet;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_RC, (const char *)&packet, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
#endif
}

/**
 * @brief Send a state_rc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_state_rc_send_struct(mavlink_channel_t chan, const mavlink_state_rc_t* state_rc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_state_rc_send(chan, state_rc->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_RC, (const char *)state_rc, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
#endif
}

#if MAVLINK_MSG_ID_STATE_RC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_state_rc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_RC, buf, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
#else
    mavlink_state_rc_t *packet = (mavlink_state_rc_t *)msgbuf;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_RC, (const char *)packet, MAVLINK_MSG_ID_STATE_RC_MIN_LEN, MAVLINK_MSG_ID_STATE_RC_LEN, MAVLINK_MSG_ID_STATE_RC_CRC);
#endif
}
#endif

#endif

// MESSAGE STATE_RC UNPACKING


/**
 * @brief Get field state from state_rc message
 *
 * @return  Indicate if RC Connected.
 */
static inline uint8_t mavlink_msg_state_rc_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a state_rc message into a struct
 *
 * @param msg The message to decode
 * @param state_rc C-struct to decode the message contents into
 */
static inline void mavlink_msg_state_rc_decode(const mavlink_message_t* msg, mavlink_state_rc_t* state_rc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    state_rc->state = mavlink_msg_state_rc_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_STATE_RC_LEN? msg->len : MAVLINK_MSG_ID_STATE_RC_LEN;
        memset(state_rc, 0, MAVLINK_MSG_ID_STATE_RC_LEN);
    memcpy(state_rc, _MAV_PAYLOAD(msg), len);
#endif
}
