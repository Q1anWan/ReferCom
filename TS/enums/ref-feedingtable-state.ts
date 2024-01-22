export enum RefFeedingtableState {
	REF_FEEDINGTABLE_STATE_STOP = 0, // STOP State.
	REF_FEEDINGTABLE_STATE_FIXING = 1, // Fixing mode and waiting for repairing.
	REF_FEEDINGTABLE_STATE_NORMAL = 2, // Feeding table is normal and stable.
	REF_FEEDINGTABLE_STATE_RELEASE = 3, // Feeding table is releasig new fish feed.
	REF_FEEDINGTABLE_STATE_CLEAN = 4, // Feeding table is turning the table over.
	REF_FEEDINGTABLE_STATE_ENUM_END = 5, // 
}