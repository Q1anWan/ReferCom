import {MAVLinkMessage} from 'node-mavlink';
import {readInt64LE, readUInt64LE} from 'node-mavlink';
/*
Indicate referee server is alive.
*/
// pack_count Indicate id of heartbeat. First pack is 0. uint32_t
export class ServerHeartbeat extends MAVLinkMessage {
	public pack_count!: number;
	public _message_id: number = 0;
	public _message_name: string = 'SERVER_HEARTBEAT';
	public _crc_extra: number = 36;
	public _message_fields: [string, string, boolean][] = [
		['pack_count', 'uint32_t', false],
	];
}