import {MAVLinkMessage} from 'node-mavlink';
import {readInt64LE, readUInt64LE} from 'node-mavlink';
import {RefComponentId} from '../enums/ref-component-id';
/*
Set component state with a paramater.
*/
// component Indicate the component need to be set. uint8_t
// new_state Indicate new state uint8_t
// parameter Auxiliary parameters uint8_t
export class SetConponentState extends MAVLinkMessage {
	public component!: RefComponentId;
	public new_state!: number;
	public parameter!: number;
	public _message_id: number = 2;
	public _message_name: string = 'SET_CONPONENT_STATE';
	public _crc_extra: number = 217;
	public _message_fields: [string, string, boolean][] = [
		['component', 'uint8_t', false],
		['new_state', 'uint8_t', false],
		['parameter', 'uint8_t', false],
	];
}