import {MAVLinkMessage} from 'node-mavlink';
import {readInt64LE, readUInt64LE} from 'node-mavlink';
import {RefComponentId} from '../enums/ref-component-id';
import {RefFishType} from '../enums/ref-fish-type';
/*
Indicate fish man find a fish.
*/
// component Indicate which fishmonger. uint8_t
// fish_type Indicate the type of the fish. uint8_t
// pack_count Indicate how many same packs have been sent since fishmonger is at TRIGGERED. First pack is 0. uint16_t
export class FishmongerFindFish extends MAVLinkMessage {
	public component!: RefComponentId;
	public fish_type!: RefFishType;
	public pack_count!: number;
	public _message_id: number = 4;
	public _message_name: string = 'FISHMONGER_FIND_FISH';
	public _crc_extra: number = 36;
	public _message_fields: [string, string, boolean][] = [
		['pack_count', 'uint16_t', false],
		['component', 'uint8_t', false],
		['fish_type', 'uint8_t', false],
	];
}