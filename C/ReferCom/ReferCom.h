/** @file
 *  @brief MAVLink comm protocol generated from ReferCom.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_REFERCOM_H
#define MAVLINK_REFERCOM_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_REFERCOM.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_REFERCOM_XML_HASH -7706864192925688548

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 36, 4, 4, 0, 0, 0}, {2, 217, 3, 3, 0, 0, 0}, {3, 244, 8, 8, 0, 0, 0}, {4, 182, 1, 1, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_REFERCOM

// ENUM DEFINITIONS


/** @brief Component ID. */
#ifndef HAVE_ENUM_REF_COMPONENT_ID
#define HAVE_ENUM_REF_COMPONENT_ID
typedef enum REF_COMPONENT_ID
{
   REF_COMPONENT_ID_SERVER=1, /* Referee server. | */
   REF_COMPONENT_ID_X_FEEDINGTBALE=2, /* Team X Feeding Table. | */
   REF_COMPONENT_ID_Y_FEEDINGTBALE=3, /* Team Y Feeding Table. | */
   REF_COMPONENT_ID_FISHPOND=4, /* Fish pond. | */
   REF_COMPONENT_ID_ENUM_END=5, /*  | */
} REF_COMPONENT_ID;
#endif

/** @brief Error codes of component. */
#ifndef HAVE_ENUM_REF_ERROR_CODE
#define HAVE_ENUM_REF_ERROR_CODE
typedef enum REF_ERROR_CODE
{
   REF_ERROR_NONE=0, /* No error. | */
   REF_ERROR_COMMUNICATION=1, /* Communication is error. | */
   REF_ERROR_BATTERY=3, /* Battery is going to run out. | */
   REF_ERROR_CODE_ENUM_END=4, /*  | */
} REF_ERROR_CODE;
#endif

/** @brief State machine of fishmonger. */
#ifndef HAVE_ENUM_REF_FEEDINGTABLE_STATE
#define HAVE_ENUM_REF_FEEDINGTABLE_STATE
typedef enum REF_FEEDINGTABLE_STATE
{
   REF_FEEDINGTABLE_STATE_STOP=0, /* STOP State. | */
   REF_FEEDINGTABLE_STATE_FIXING=1, /* Fixing mode and waiting for repairing. | */
   REF_FEEDINGTABLE_STATE_NORMAL=2, /* Feeding table is normal and stable. | */
   REF_FEEDINGTABLE_STATE_RELEASE=3, /* Feeding table is releasig new fish feed. | */
   REF_FEEDINGTABLE_STATE_CLEAN=4, /* Feeding table is turning the table over. | */
   REF_FEEDINGTABLE_STATE_ENUM_END=5, /*  | */
} REF_FEEDINGTABLE_STATE;
#endif

/** @brief State machine of fish pond. */
#ifndef HAVE_ENUM_REF_FISHPOND_STATE
#define HAVE_ENUM_REF_FISHPOND_STATE
typedef enum REF_FISHPOND_STATE
{
   REF_FISHPOND_STATE_STOP=0, /* STOP State. | */
   REF_FISHPOND_STATE_FIXING=1, /* Fixing mode and waiting for repairing. | */
   REF_FISHPOND_STATE_NORMAL=2, /* Fish pond is normal and stable. | */
   REF_FISHPOND_STATE_RELEASE=3, /* Fish pond will release a box of fish. | */
   REF_FISHPOND_STATE_CLEAN=4, /* Fish pond will turn the table over. | */
   REF_FISHPOND_STATE_ENUM_END=5, /*  | */
} REF_FISHPOND_STATE;
#endif

/** @brief Fish types. */
#ifndef HAVE_ENUM_REF_FISH_TYPE
#define HAVE_ENUM_REF_FISH_TYPE
typedef enum REF_FISH_TYPE
{
   REF_FISH_RED=0, /* Red fish. | */
   REF_FISH_ORANGE=1, /* Orange fish. | */
   REF_FISH_YELLOW=2, /* Yellow fish. | */
   REF_FISH_GREEN=3, /* Green fish. | */
   REF_FISH_BLUE=4, /* Blue fish. | */
   REF_FISH_TYPE_ENUM_END=5, /*  | */
} REF_FISH_TYPE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 5
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 5
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_server_heartbeat.h"
#include "./mavlink_msg_set_conponent_state.h"
#include "./mavlink_msg_component_heartbeat.h"
#include "./mavlink_msg_state_rc.h"

// base include



#if MAVLINK_REFERCOM_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_SERVER_HEARTBEAT, MAVLINK_MESSAGE_INFO_SET_CONPONENT_STATE, MAVLINK_MESSAGE_INFO_COMPONENT_HEARTBEAT, MAVLINK_MESSAGE_INFO_STATE_RC}
# define MAVLINK_MESSAGE_NAMES {{ "COMPONENT_HEARTBEAT", 3 }, { "SERVER_HEARTBEAT", 0 }, { "SET_CONPONENT_STATE", 2 }, { "STATE_RC", 4 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_REFERCOM_H
