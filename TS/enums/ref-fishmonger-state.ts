export enum RefFishmongerState {
	REF_FISHMONGER_STATE_STOP = 0, // STOP State.
	REF_FISHMONGER_STATE_FIXING = 1, // Fixing mode and waiting for repairing.
	REF_FISHMONGER_STATE_SCANNING = 2, // Fishmonger is waiting for the fish.
	REF_FISHMONGER_STATE_COOLING = 3, // Fishmonger is cooling.
	REF_FISHMONGER_STATE_TRIGGERED = 4, // Fishmonger triggered by fish.
	REF_FISHMONGER_STATE_ENUM_END = 5, // 
}