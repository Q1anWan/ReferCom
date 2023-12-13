import {MAVLinkMessage} from 'node-mavlink';
import {ServerHeartbeat} from './messages/server-heartbeat';
import {SetConponentState} from './messages/set-conponent-state';
import {ComponentHeartbeat} from './messages/component-heartbeat';
import {FishmongerFindFish} from './messages/fishmonger-find-fish';
export const messageRegistry: Array<[number, new (system_id: number, component_id: number) => MAVLinkMessage]> = [
	[0, ServerHeartbeat],
	[2, SetConponentState],
	[3, ComponentHeartbeat],
	[4, FishmongerFindFish],
];