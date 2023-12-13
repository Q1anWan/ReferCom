export enum RefFishmongerState {
	REF_FISHMONGER_STATE_STOP = 0, // STOP State.
	REF_FISHMONGER_STATE_SCANNING = 1, // Fishmonger is waiting for the fish.
	REF_FISHMONGER_STATE_COOLING = 2, // Fishmonger is cooling.
	REF_FISHMONGER_STATE_TRIGGERED = 3, // Fishmonger triggered by fish.
	REF_FISHMONGER_STATE_ENUM_END = 4, // 
}