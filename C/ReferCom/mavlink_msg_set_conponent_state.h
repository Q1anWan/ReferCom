#pragma once
// MESSAGE SET_CONPONENT_STATE PACKING

#define MAVLINK_MSG_ID_SET_CONPONENT_STATE 2


typedef struct __mavlink_set_conponent_state_t {
 uint8_t component; /*<  Indicate the component need to be set.*/
 uint8_t new_state; /*<  Indicate new state*/
 uint8_t parameter; /*<  Auxiliary parameters*/
} mavlink_set_conponent_state_t;

#define MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN 3
#define MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN 3
#define MAVLINK_MSG_ID_2_LEN 3
#define MAVLINK_MSG_ID_2_MIN_LEN 3

#define MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC 217
#define MAVLINK_MSG_ID_2_CRC 217



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_CONPONENT_STATE { \
    2, \
    "SET_CONPONENT_STATE", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_conponent_state_t, component) }, \
         { "new_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_conponent_state_t, new_state) }, \
         { "parameter", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_conponent_state_t, parameter) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_CONPONENT_STATE { \
    "SET_CONPONENT_STATE", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_conponent_state_t, component) }, \
         { "new_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_conponent_state_t, new_state) }, \
         { "parameter", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_conponent_state_t, parameter) }, \
         } \
}
#endif

/**
 * @brief Pack a set_conponent_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param component  Indicate the component need to be set.
 * @param new_state  Indicate new state
 * @param parameter  Auxiliary parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_conponent_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t component, uint8_t new_state, uint8_t parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, new_state);
    _mav_put_uint8_t(buf, 2, parameter);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN);
#else
    mavlink_set_conponent_state_t packet;
    packet.component = component;
    packet.new_state = new_state;
    packet.parameter = parameter;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_CONPONENT_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
}

/**
 * @brief Pack a set_conponent_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component  Indicate the component need to be set.
 * @param new_state  Indicate new state
 * @param parameter  Auxiliary parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_conponent_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t component,uint8_t new_state,uint8_t parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, new_state);
    _mav_put_uint8_t(buf, 2, parameter);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN);
#else
    mavlink_set_conponent_state_t packet;
    packet.component = component;
    packet.new_state = new_state;
    packet.parameter = parameter;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_CONPONENT_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
}

/**
 * @brief Encode a set_conponent_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_conponent_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_conponent_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_conponent_state_t* set_conponent_state)
{
    return mavlink_msg_set_conponent_state_pack(system_id, component_id, msg, set_conponent_state->component, set_conponent_state->new_state, set_conponent_state->parameter);
}

/**
 * @brief Encode a set_conponent_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_conponent_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_conponent_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_conponent_state_t* set_conponent_state)
{
    return mavlink_msg_set_conponent_state_pack_chan(system_id, component_id, chan, msg, set_conponent_state->component, set_conponent_state->new_state, set_conponent_state->parameter);
}

/**
 * @brief Send a set_conponent_state message
 * @param chan MAVLink channel to send the message
 *
 * @param component  Indicate the component need to be set.
 * @param new_state  Indicate new state
 * @param parameter  Auxiliary parameters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_conponent_state_send(mavlink_channel_t chan, uint8_t component, uint8_t new_state, uint8_t parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, new_state);
    _mav_put_uint8_t(buf, 2, parameter);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE, buf, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
#else
    mavlink_set_conponent_state_t packet;
    packet.component = component;
    packet.new_state = new_state;
    packet.parameter = parameter;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE, (const char *)&packet, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
#endif
}

/**
 * @brief Send a set_conponent_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_conponent_state_send_struct(mavlink_channel_t chan, const mavlink_set_conponent_state_t* set_conponent_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_conponent_state_send(chan, set_conponent_state->component, set_conponent_state->new_state, set_conponent_state->parameter);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE, (const char *)set_conponent_state, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_conponent_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t component, uint8_t new_state, uint8_t parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, new_state);
    _mav_put_uint8_t(buf, 2, parameter);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE, buf, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
#else
    mavlink_set_conponent_state_t *packet = (mavlink_set_conponent_state_t *)msgbuf;
    packet->component = component;
    packet->new_state = new_state;
    packet->parameter = parameter;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_CONPONENT_STATE, (const char *)packet, MAVLINK_MSG_ID_SET_CONPONENT_STATE_MIN_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN, MAVLINK_MSG_ID_SET_CONPONENT_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_CONPONENT_STATE UNPACKING


/**
 * @brief Get field component from set_conponent_state message
 *
 * @return  Indicate the component need to be set.
 */
static inline uint8_t mavlink_msg_set_conponent_state_get_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field new_state from set_conponent_state message
 *
 * @return  Indicate new state
 */
static inline uint8_t mavlink_msg_set_conponent_state_get_new_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field parameter from set_conponent_state message
 *
 * @return  Auxiliary parameters
 */
static inline uint8_t mavlink_msg_set_conponent_state_get_parameter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a set_conponent_state message into a struct
 *
 * @param msg The message to decode
 * @param set_conponent_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_conponent_state_decode(const mavlink_message_t* msg, mavlink_set_conponent_state_t* set_conponent_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_conponent_state->component = mavlink_msg_set_conponent_state_get_component(msg);
    set_conponent_state->new_state = mavlink_msg_set_conponent_state_get_new_state(msg);
    set_conponent_state->parameter = mavlink_msg_set_conponent_state_get_parameter(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN? msg->len : MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN;
        memset(set_conponent_state, 0, MAVLINK_MSG_ID_SET_CONPONENT_STATE_LEN);
    memcpy(set_conponent_state, _MAV_PAYLOAD(msg), len);
#endif
}
