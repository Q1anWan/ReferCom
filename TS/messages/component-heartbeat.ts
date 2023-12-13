import {MAVLinkMessage} from 'node-mavlink';
import {readInt64LE, readUInt64LE} from 'node-mavlink';
import {RefErrorCode} from '../enums/ref-error-code';
/*
Indicate component is alive.
*/
// state Indicate the state of now. uint8_t
// error_code Indicate error code. uint8_t
// battery_voltage Indicate voltage of battery. uint16_t
// pack_count Indicate id of heartbeat. First pack is 0. uint32_t
export class ComponentHeartbeat extends MAVLinkMessage {
	public state!: number;
	public error_code!: RefErrorCode;
	public battery_voltage!: number;
	public pack_count!: number;
	public _message_id: number = 3;
	public _message_name: string = 'COMPONENT_HEARTBEAT';
	public _crc_extra: number = 244;
	public _message_fields: [string, string, boolean][] = [
		['pack_count', 'uint32_t', false],
		['battery_voltage', 'uint16_t', false],
		['state', 'uint8_t', false],
		['error_code', 'uint8_t', false],
	];
}