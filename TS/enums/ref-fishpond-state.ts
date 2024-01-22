export enum RefFishpondState {
	REF_FISHPOND_STATE_STOP = 0, // STOP State.
	REF_FISHPOND_STATE_FIXING = 1, // Fixing mode and waiting for repairing.
	REF_FISHPOND_STATE_NORMAL = 2, // Fish pond is normal and stable.
	REF_FISHPOND_STATE_RELEASE = 3, // Fish pond will release a box of fish.
	REF_FISHPOND_STATE_CLEAN = 4, // Fish pond will turn the table over.
	REF_FISHPOND_STATE_ENUM_END = 5, // 
}