export enum RefErrorCode {
	REF_ERROR_NONE = 0, // STOP State.
	REF_ERROR_COMMUNICATION = 1, // Communication is error.
	REF_ERROR_CV = 2, // Computer vision is error.
	REF_ERROR_BATTERY = 3, // Battery is going to run out.
	REF_ERROR_CODE_ENUM_END = 4, // 
}