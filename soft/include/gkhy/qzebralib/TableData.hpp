#pragma once
#include "gkhy\qzebralib\qzebra_lib_global.hpp"
#include <assert.h>

namespace gkhy
{
	namespace QZebraLib
	{
		/**
		 * DmuTableData - Demodulator Unit Table Data.
		 * componentCode - 3010 stands for DMU-1
		 * tableSize = 4(component code) + 256
		 */
		#pragma pack(push, 4) 
		struct QZEBRA_LIB_EXPORT DmuTableData 
		{
			int		componentCode;			// 3010H/3011H

			// Offset 0 to 12
			int		spectAnalysisFlowID;	// 0 Spectrum Analysis Data Flow ID, 0x00000000 to 0xFFFFFFFF.
			int		vectAnalysisFlowID;		// 1 Vector Analysis Data Flow ID, 0x00000000 to 0xFFFFFFFF.
			int		reserved0;				// 2 reserved
			float	inputFreq;				// 3 Input freq, 520,000,000Hz to 920,000,000, in Hz
			int		ifInputPort;			// 4 IF input port, 0 : Normal port; 1 : Alternate port.
			float	carriAcqRange;			// 5 carrier acq range. 10,000 to 1,000,000(in +/-Hz)
			int		pcdDemod;				// 6 PCM demodulation. 0: bpsk, 1 qpsk, 2 oqpsk, 3 uqpsk, 4 8psk.
			float	bitRate;				// 7 Total I+Q BR or I BR in UQPSK
			float	qBitRate;				// 8 Bit Rate(Q BR in UQPSK)
			float	iqRatio;				// 9 I/Q ratio in UQPSK, 0 to 100 db
			int		pcmCodeForIChann;		// 10 0:NRZ-L, 1:NRZ-M, 2:NRZ-s, 3:DNRZ, 4:BP-L, 5:BPM, 6:BPS
			int		matchedFilter;			// 11 0:integral & dump, 1:raised cosine, 2:root raised cosine, 3 to 1002:custom filter 1
											// to 1000, 1003:GMSK Gaussian filter
			float	rollOffOrBt;			// 12 0.1 to 1.0(in %)

			// Offset 13 to 23
			int		viterbi;				// 13 viterbi I/Q decoding, 0:single decoding, 1:dual decoding
			int		outputClockPolarity;	// 14 0:normal clock, 1:inverted clock
			int		iqPolarity;				// 15 0:normal, 1:i inverted, q normal,etc.
			int		outputMode;				// 16 0:separate I & Q, 1:iq merged
			int		clockPolarityForQ;		// 17 UQPSK mode, 0: normal clcok, 1: inverted clock
			int		berOrFrameSync;			// 18 0:internal connection, 1:reserved
			int		berMode;				// 19 0:off, 1:file, 2:pn10, 3:pn11, 4:pn15, 5:pn23
			int		fileNum;				// 20 file num for ber in file mode, warning if file does not exist
			int		reserved1;				// 21
			int		berCounting;			// 22 0:accumulation mode, else n = duration
			int		oqpskOffsetAdjust;		// 23

			// Offset 24 to 39
			int		reserved2;				// 24
			int		reserved3;				// 25
			int		demodulationMode;		// 26 0:demodulation, 1:spectrum analysis
			int		reserved4;				// 27
			int		reserved5;				// 28
			int		numOfSymbOrPoint;		// 29 1 or 2
			int		viterbiDecoder;			// 30
			int		viterbiDecoderForQ;		// 31 viterbi decoder for q channel in UQPSK
			int		pcmCodeForQ;			// 32 pcm code for q channel in UQPSK mode
			int		viterbiPuncturing1;		// 33 viterbi puncturing on i channel
			int		viterbiPuncturing2;		// 34 viterbi puncturing on q channel
			int		psk8Config;				// 35 8 PSK configuration
			int		reserved6;				// 36
			int		reserved7;				// 37
			int		reserved8;				// 38
			int		reserved9;				// 39

			// Offset 40 to 53
			float	carrierOffset;			// 40
			float	ifLevel;				// 41 +127 to -128(in dbm)
			int		carrierPllStatus;		// 42 0:acquisition, 1:unlocked, 2:locked
			float	ebNoForIChannel;		// 43 in UQPSK mode
			int		bitSyncStatus1;			// 44 0: unlocked, 1:locked, if UQPSK, bit sync for i channel
			int		bitSyncStatus2;			// 45 0: unlocked, 1:locked, if UQPSK, bit sync for q channel
			float	bitRateOffset1;			// 46 if UQPSK, BR offset for i channel
			float	bitRateOffset2;			// 47 if UQPSK, BR offset for q channel
			int		vertibiTcmStatus;		// 48 if dual viterbi, for i channel
			float	berMergerOrForI;		// 49 if offset 56 = 0: ber fo merged i & q
			// if offset 56 = 1(or in UQPSK mode):ber for i channel
			float	berForQChannel;			// 50
			int		numOfBitErrors;			// 51 if offset 56 = 0:number of bits in error for merged i & q
			// if offset 56 = 1(or in UQPSK mode): number of bits in error for i channel
			int		numOfBitsForQ;			// 52 number of bits in error for q channel
			float	oqpskOffset;			// 53

			// Offset 54 to 59
			int		softLicenses;			// 54 software licenses, hardware capability & warning
			int		reserved10;				// 55
			int		berMeasurementType;		// 56
			float	spectrumAnalysisRange;	// 57
			int		reserved11;				// 58
			float	viterbiBerTcmBer;		// 59 viterbi ber(if offset 35 = 0) or tcm ber(if offset 35 = 1)
			// for dual viterbi:viterbi ber on i channel

			// Offset 60 to 63
			float	viterbiBerForQ;			// 60 viterbi ber for q channel
			float	ebNoForQChannel;		// 61 in UQPSK mode
			int		minBitRate;				// 62
			int		maxBitRate;				// 63
			
			DmuTableData(void); 
		};
		#pragma pack(pop)


		/**
		 * GlobalHdrTableData - global hdr table data.
		 * componentCode - 3001
		 * tableSize = 4(component code) + 240
		 */
		#pragma pack(push,4)

		struct  GlobalHdrTableData
		{
			int		componentCode;								// 3001H
			//OFFSET  	 //TYPE  //CONFIGURATION PARAMETER  	//VALUE  
			/* 0 */  	 int  	 MonitoringFlowId;				//	 0 to FFFFFFFFH  
			/* 1 */  	 int  	 LoggingFlowId;					//	 0 to FFFFFFFFH  
			/* 2 */		 int  	 ReferenceFreqSel;				//	 0 : Internal (10 MHz) 1 : External/Internal auto select  
			/* 3 */  	 int  	 LeapYear;						//	 0 : No 1 : Yes  
			/* 4 */  	 int  	 TimeCurrentOffset;				//	 In seconds (see note 1)  
			/* 5 */  	 int  	 TimeDateOfNextOffset1;			//	 In seconds (see note 2)  
			/* 6 */  	 int  	 TimeNextOffset1;				//	 In seconds (see note 2)  
			/* 7 */  	 int  	 TimeDateOfNextOffset2;			//	 In seconds (see note 2)  
			/* 8 */  	 int  	 TimeNextOffset2;				//	 In seconds (see note 2)  
			/* 9 */  	 int  	 TimeCode;						//	 0 : IRIG-B 1 : NASA-36  
			/* 10 */  	 float   CableCompensation;				//	 0 to 12 (in dB)  
			/* 11to21*/  int	 Reserved1[11];					//	 
			/* 22 */  	 int  	 CORTEXHDRShelfID;				//	 Configurable in Windows registry  
			/* 23 */  	 int	 Reserved2;						//	 
			/* 24 */  	 int  	 TestModulator;					//	 0 : Not mounted 1 : Mounted  
			/* 25 */  	 int  	 DataProcessingUnit;			//	 0 : No DPU mounted 
																//	 Bit 0 = 1 : DPU # 1 Mounted 
																//	 Bit 1 = 1 : DPU # 2 Mounted 
																//	 Bit 2 = 1 : DPU # 3 Mounted  
			/* 26 */  	 int  	 DemodulatorUnit;				//	 0 : Only DMU # 1 mounted 1 : DMU # 1 &2 mounted  
			/* 27 */  	 int  	 DataRecordingUnit;				//	 0 : No DRU mounted 
																//	 Bit 0 = 1 : DRU # 1 Mounted 
																//	 Bit 1 = 1 : DRU # 2 Mounted 
																//	 Bit 2 = 1 : DRU # 3 Mounted  

			/* 28 */  	 int	 Reserved3;						//	 
			/* 29 */  	 int  	 TimeAlarm;						//	 0 : OK 1 : Alarm  
			/* 30 */  	 int  	 DemodulatorStatus;				//	 0 : OK 
																//	 Bit 0 = 1 : Demodulator # 1 not responding 
																//	 Bit 1 = 1 : Demodulator # 2 not responding  
			/* 31 */  	 int  	 TestModulatorStatus;			//	 0 : OK 1 : Test Modulator not responding  
			/* 32 */  	 int	 Reserved4;						//	 
			/*33to35 */  int	 Reserved5[3];					//	 
			/* 36 */  	 int  	 CORTEXHDRMiscellaneousAlarms;  //	 All bits to 0 : OK 
																//	 Bit 0 : Reserved 
																// 	 Bit 3 = 1 : Demodulator DSP alarm 
																//	 Bit 4-7 = 1 : PCI bus alarm 
																//	 Bit 8-17 = 1 : Demodulator H/W alarm 
																//	 Bit 16 = 1 : Temperature alarm 
																//	 Bit 18 = 1 : Test Modulator H/W alarm 
																//	 Bits 19-31 : Reserved  
			/* 37 */  	 int  	 ProjectIdentification;			//	 0 : Generic CORTEX HDR Other values : Project dependant.  
			/* 38 */  	 int  	 SoftwareId;					//  
			/* 39 */  	 int  	 HardwareID;					//	 Bits 0-15 : Serial Number (binary) Bits 16-31 : Model ID (BCD)  
			/* 40 */  	 int  	 SelectedFrequencyReference;	//	 0 : Internal (10 MHz) 
																//	 1 : Input 1 (10 MHz, PLL locked) 
																//	 5 : Input 1 (5 MHz, PLL locked) 
																//	 9 : Input 1 (10 MHz, PLL unlocked) 
																//	 13 : Input 1 (5 MHz, PLL unlocked)  
			/* 41 */  	 int  	 TimeTagFormat;					//	 3 (see note 3) Other values : reserved  
			/*42&43*/    int  	 TimeTag[2];					//	 See § 2.1.1  	
			/* 44 */  	 int  	 IRIGBNASA36Decoder;			//	 0 : Unlocked 1 : Flywheel 2 : Locked  
			/* 45 */  	 int  	 TCPIPMonitoringClients;		//	 Number of connected clients  
			/* 46 */  	 int  	 TCPIPControlClients;			//	 Number of connected clients  
			/* 47 */  	 int  	 TCPIPLoggingClients;			//	 Number of connected clients  
			/* 48 */  	 int  	 TCPIPSpectrumAnalysisClients;	//	 Number of connected clients  
			/* 49 */  	 int  	 TCPIPVectorAnalysisClients;	//	 Number of connected clients  
			/* 50 */  	 int  	 TCPIPTelemetryClients;			//	 Number of connected clients  
			/* 51 */  	 int  	 CableequalizationFilter;		//	 0 : Available 
																//	 Bit 1 = 1 : Cable equalizer not available 
																//	 Bit 30 = 1 : License problem 
																//	 Bit 31 = 1 : Hardware problem (FPGA)  
			/*52to59 */  int	 Reserved6[8];					//	 
			GlobalHdrTableData()
			{
				assert( 61 * 4 == sizeof(GlobalHdrTableData));
				componentCode = 0x3001;
				TestModulator = 1;
				DataProcessingUnit = 1;
				DemodulatorUnit = 0;
				DataRecordingUnit = 0;
			}
		};
		#pragma pack(pop)


		/**
		 *
		 * hdrTalbe -- hdr table data
		 * component code -- 3000H
		 * tableSize = 4(component code) + 4
		 */
		#pragma pack(push,4)
		struct  HdrTableData
		{
			int componentCode;   // 3000H
			int version;		 //  Byte 0 (LSB) = CORTEX type ,Bit 3 = 1 : CORTEX HDR 
								 //	 See ICD STI 100013 E3Rx  
								 //	 Byte 1 : SPS_HDR software revision (F633193)  
								 //	 Byte 2 : SPS_HDR software version (F633193)  
								 //	 Byte 3 (MSB) : Reserved for Extension  
			HdrTableData()
			{
				assert( 2 * 4 == sizeof(HdrTableData) );
				componentCode = 0x3000;
			}
		};
		#pragma pack(pop)

		/**
		 *
		 * TestModulatorTableData -- test modulator table data
		 * talbeSize = 4 + 60 * 4
		 * component code = 3020H
		 */
		#pragma pack(push,4)
		struct  TestModulatorTableData
		{
			int componentCode;								// 0x3020H

			//TYPE  //CONFIGURATION PARAMETER				//VALUE  
			int		 Reserved1;									//	 
			float    CarrierFrequency;						//	 716,000,000 to 724,000,000 (in Hz)  
			int  	 ModulationMode;						//	 0 : BPSK 1 : QPSK 2 : OQPSK 3 : UQPSK 4 : 8PSK  
			int  	 Modulation;							//	 0 : OFF 1: ON  
			int  	 IFCarrier;								//	 0 : OFF 1 : ON  
			float    IFCarrierLevel;						//	-10 to 40 
			float    OQPSKOffsetAdjust;						//	 -0.5 to + 0.5 (in symbol). 0 is for symbol offset  
			int		 PSK8Configuration;						//	 Bit 0 = Reserved 
															//   Bit 1 = Phase Rotation Inverted=1, CCSDS=0 
															//	 Bit 2 = Mapping Natural=0, Gray=1  
			int		 Reserved2[2];							//	 
			int  	 PCMModulatingSignal;					//	 0 : Internal 
															//   1 : External PCM (PCM IN port) 
															//	 2 : External PCM-I (UQPSK mode) 
															//	 3 : External PCM Q (UQPSK mode)  
			int  	 MatchedFilter;							//	 0 : No filter 
															//   1 : Raised cosine filter 
															//	 2 : Root raised cosine filter  
			float    RollOffFactor;							//	 0.1 to 1.0 (in %)  
			int  	 ViterbiEncodingForIChannel;			//	 0 : OFF 1 : Viterbi encoding (G2 Inverted) 
															//   2 : Viterbi encoding (G2)  
			int  	 NoiseGenerator;						//	 0 : OFF 1 : ON  
			float    NoiseLevel;							//	 -93 to -132 (in dbm/Hz)  


			float    BitRateTotalIQ;						//	 BPSK & UQPSK : 1,000,000 to 240,000,000 (in bps) 
															//	 QPSK & OQPSK : 2,000,000 to 480,000,000 (in bps) 
															//	 8PSK : 3,000,000 to 720,000,000 (in bps)  
			float    BitRateQ;								//	 1,000,000 to 240,000,000 (in bps)  
			float    IQratioinUQPSK;						//	 0 to 100 dB  
			int  	 PCMcodeforIChannel;					//	 0 : NRZ-L 1 : NRZ-M 2 : NRZ-S 3 : DNRZ 4 : BPL 5 : BPM 6 : BPS  
			int  	 OperatingMode;							//	 0 : OFF (for reset purpose) 
															//	 1 : File 2 : Pseudo :PN10 3 : Pseudo :PN11 
															//	 4 : Pseudo :PN15 5 : Pseudo :PN23  
			int  	 FileNumber;							//	 0 to 4294967295  
			int  	 CycleLength;							//	 32 to 2,097,152 (in bytes)  
			int  	 TransmittedNRZL;						//	 0 : Normal 1 : Inverted  
			float    BeaconFrequency;						//	 700,000,000 to 835,000,000 (in Hz)  
			int  	 Beacon;								//	 0 : OFF 1 : ON  
			float    BeaconLevelRelativeToCarrier;			//	-30 to -40
			int  	 ViterbiIQEncoding;						//	 0 : Single 1 : Dual  
			
			int  	 PCMCodeForQChannel;					//	 0 : NRZ-L 1 : NRZ-M 2 : NRZ-S 3 : DNRZ 4 : BPL 5 : BPM 6 : BPS  
			int  	 ViterbiEncodingForQChannel;			//	 0 : OFF 1 : Viterbi encoding (Inverted G2) 2 : Viterbi encoding  
			int		 Reserved3[10];							//	 
			
			int  	 HWStatus1;								//	 0 : OK 
															//	 Bit 0 = 1 : Xilinx download alarm 
															//	 Bit 1 = 1 : Calibration alarm  
			int  	 HWStatus2;								//	 0 : OK 
															//	 Bit 0 = 1 : Int. clock generation alarm 
															//	 Bit 1 = 1 : External clock alarm (wrong frequency)  
			int  	 ProgrammableIFRange;					//	 1 : 716,000,000 to 724,000,000 (in Hz) Other values : reserved  
			int  	 BeaconGenerator;						//	 0 : Not available 1 : Available  
			int		 Reserved4[6];							//	 
			int  	 Softwarelicenses;						//	 0 : OK, 
															//	 1 : Warning : 
															//	 Bit 29 : Insertion error in File mode 
															//	 Bit 30 : Simulation file read error 
															//	 Bit 31 : BR not supported by hardware  
			int	 Reserved5[9];								//	

			
			TestModulatorTableData()
			{
				assert( 61 * 4 == sizeof(TestModulatorTableData) );
				componentCode = 0x3020;
			}
			
		};
		#pragma pack(pop)

		/**
		 *
		 * dpuTalbe -- data processing unit table
		 * tableSize = 4(component code) + 320
		 * component code = 3070/3071/3072
		 *
		 */
		#pragma pack(push,4)
		struct QZEBRA_LIB_EXPORT DpuTableData
		{
			int componentCode;
			
			//TYPE   //CONFIGURATION PARAMETER              //  VALUE  
			int  	 TelemetryFlowId;						//	 0 0 to FFFFFFFFH  
			int		 DataSource;							//   1
			int  	 TelemetryDataWordTransmission;			//	 2 0 : Normal 1 : 32 bits MSB & 32 bits LSB  
			int  	 FrameSizeOrBlockSize;					//	 3 10 to 1,048,576 (in bytes)  
			int  	 SynchronizationWordLSB;				//	 4 MSB aligned  
			int  	 SynchronizationWordMSB;				//	 5
			int  	 SynchronizationWordLength;				//	 6 8 to 64 (in bits)  
			int  	 SynchronizationWordMaskLSB;			//	 7 < 1 > bits in the mask indicate what bits in the Synchronization Word must be ignored  
			int  	 SynchronizationWordMaskMSB;			//	 8
			int  	 SYNCThreshold;							//	 9 0 to 15  
			int  	 CTLThreshold;							//	 10 0 to 15  
			int  	 LTSThreshold;							//	 11 0 to 15  
			int  	 BitSlipWindow;							//	 12 0 : 0 bit 
															//	 1 :  1 bit 
															//	 2 :  2 bits  
			int  	 FrameSynchronizer;						//	 13 0 : OFF 1 : ON  
			int  	 Descrambling;							//	 14 0 : OFF 1 : ON  
			int  	 ReedSolomonDecoding1;					//	 15 Bit 0 0 : OFF 1 : ON 
															//	 Bit 1 : 0 Idle frame discarded 1 Idle frame not discarded (RS DVB)  
			int  	 FrameChecking;							//	 16 0 : OFF 1 : CRC  
			
			int  	 CRCPolynomial;							//	 17 MSB aligned. Example : 80050000H for a CRC16 10210000 H for CCITT  
			int  	 CRCPresetValue;						//	 18 MSB aligned. Example : 0H for a CRC16 FFFF0000 H for CCITT  
			int  	 VirtualChannelSelection;				//	 19 0 to 58  
			
			int  	 SelectedVirtualChannel1;				//	 20 64-bit field : If bit Dx = 1 : Virtual Channe1 # x is discarded  
			int  	 SelectedVirtualChannel2;				//	 21
			int  	 ReedSolomonDecoding2;					//	 22 0 : OFF 1 : ON  
			int  	 TMBlockEnding;							//	 23 0 to 8  
			int  	 Reserved1[24];							//	 
			int  	 FrameSynchronizerStatus;				//	 48 0 : Search phase 1 : Check phase 2 : Locked3 : Flywheel  
			int  	 BitSlip;								//	 49 (0 to 2)  
			int  	 FrameCheck;							//	 50 0 : OK1 : Alarm  
			int  	 FrameSequenceCounter;					//	 51 0 to FFFFFFFFH  
			int  	 GoodFramesCounter;						//	 52 0 to FFFFFFFFH  
			int  	 BadFramesCounter;						//	 53 0 to FFFFFFFFH  
			int  	 ReceivedFramesCounter;					//	 54 0 to FFFFFFFFH  
			
			int  	 NumberOfFrameSync;						//	 55 0 to FFFFFFFFH  
			int  	 CounterOfFramesTransmitted;			//	 56 0 to FFFFFFFFH  
			int  	 PCRAMOverrunAlarm;						//	 57 0 : No overrun Else : Number of lost PC RAM buffers (global counter for all connected TM Clients. 
															//	 Reset when operating mode set to Acquisition)  
			int  	 Reserved2[2];							//	 58-59
			int  	 ReedSolomonDecoderStatus;				//	 60 0 to 16*interleave factor : Number of corrected symbols 
															//	 (255 : correction capacity exceeded ; 254 : interleave error)  
			float   ReedSolomonDecoderBER;					//	 61 0 to 1  
			int  	 SoftwareLicenses;					    //	 62 0 : not supported, 1 : supported :Bit 
															//	 Bit 0 : R-S decoding Bit 1 : TCP-IP interface 
															//	 Bit 2 : Data recording Bit 3 : Descrambling 
															//	 Bit 5 : 0=RS CCSDS / 1=RS DVB 0 : OK, 1 : Warning :
															//	 Bit 31 : R-S license not supported by current menu 
															//	 Bit 30 : R-S license not available 
															//	 Bit 29 : De-scrambling not supported by current menu  
			int  	 RSDBVTransportFrameStatus;				//	 63 Bit 0/1 : 0 : Search phase 1 : Check phase 2 : Locked 3 : 
															//	 Flywheel Bit 2: 0 idle received 1 data received Bit 8 to 31 : 
															//	 drop out : increase by 1 each lock to search even) 
															//	 (reset if R-S decoder restarted or reset BER)  
			int  	 IdleFrameCounterRSDVB;					//	 64 0 to FFFFFFFFH  
			int  	 Reserved3[15];							//	 65-79

			DpuTableData();			
		};

		#pragma pack(pop)


		/**
		 *
		 * DrgTableData -- data recording global table
		 * component code = 0x3040H
		 * tableSize = 4(component code) + 256
		 *
		 */
		#pragma pack(push,4)
		struct  DrgTableData
		{
			int componentCode;
			
			//TYPE   //CONFIGURATION PARAMETER  		 //VALUE  
			int		 Reserved1;							 //	 
			int  	 DiskMemoryAllocationForTelemetryBuffering;//	 D7-D0 : Telemetry-A D15-D8 :Telemetry-B D23-D16 : 
															   //	 Telemetry-C D31-D24 : Reserved 0 to 100 (in %) 
															   //	 for each telemetry flow. Total must not exceed 100.  
			int  	 DiskManagement;					 //	 0 : FIFO mode 1 : Fill up & wait until manual erase  
			int  	 ErasingConfiguration;				 //	 D7-D0: Occupied Warning level % D15-D8: Occupied Alarm 
														 //  level % D23-D16: Temporary files Keeping duration (in days, 0 means until alarm) 
														 //	 D31-D24: Nominal files Keeping duration (in days, 0 means until alarm)  
			int  	 LogicalChannelsNumber;				 //	 D7-D0: Logical Channel for TMA D15-D8: Logical Channel for 
														 //	 TMB D23-D16: Logical Channel for TMC D31-D24: Reserved D31-D0 0: logical channel unused  
			int  	 PassesPartitionConfiguration;		 //	 D5-D0: Partition ID TMA [0,63] D6: Disk Controller 
														 //	 ID TMA (0 or 1) D7: Reserved D15-D8: Idem D7-D0 for TMB D23-D16: 
														 //	 Idem D7-D0 for TMC D31-D24: Reserved  
			int		 Reserved2[26];						 //	 

			int  	 TimeTag1[2];					     //	 See2.1.1  
			int  	 ErrorCode1;						 //	 0 : OK else : Error  
			int  	 TotalStorageCapacity1;				 //	 In Mbytes  
			int  	 CapacityOfPartition1;				 //	 In Mbytes  
			int  	 NumberOfTMRecordingPartitions1;	 //	 1 to 64  
			int  	 TMRecordingPartitionSize1;			 //	 In Mbytes  
			int  	 SizeOfLastTMRecordingPartition1;	 //	 In Mbytes  
			int  	 Status1;							 //	 0 : OK Bit 31 : System Partition not exist Bit 30 : 
												
			int		 Reserved3[2];						 //	 

			int  	 GlobalDiskCapacityStatus;			 //	 D7-D0: Current occupied Percentage D9-D8: Occupied space status 
														 //	 0: no alarm 1: Warning level reached 2: Alarm level reached D31-D10: Reserved  
			int  	 StorageTypeRegistrySetting;		 //	 0: TCP/IP 1: FTP Standard 2: FTP Specific-1  
			int  	 DirectoriesStatus;					 //	 0:OK else : TBD  
			int		 Reserved4[2];						 //	 

			int  	 TimeTag2[2];						 //	 See  2.1.1  
			int  	 ErrorCode2;						 //	 0 : OK else : Error  
			int  	 TotalStorageCapacity2;				 //	 In Mbytes  
			int  	 CapacityOfPartition2;				 //	 In Mbytes  
			int  	 NumberOfTMRecordingPartitions2;	 //	 1 to 64  
			int  	 TMRecordingPartitionSize2;			 //	 In Mbytes  
			int  	 SizeOfLastTMRecordingPartition2;	 //	 In Mbytes  
			int  	 Status2;
			int		 Reserved5[2];						 //	 

			int		 Reserved6[3];						 //	 
			int  	 ConfigurationChecking;				 //	 0 : Configuration OK D23 to D20 = 1 : XIL RAM vs BR inconsistency (TM-A, B, C) 
														 // D31 to D28 = 1 : PC RAM alignment alarm (TM-A, B, C) D27 to D24 = 1 : 
														 //	XIL RAM alignment alarm (TM-A, B, C) Specific for FTP: D0 = 1 : Erasing 
														 //	configuration Warning % > Alarm % D1 = 1 : Logical Channel Number 
														 //	inconsistency D2 = 1 : Partition Number Inconsistency D3 = 1 : 
														 //	Controller Number Inconsistency  
			int  	 OperatingMode;						 //	 0 : Configuration mode 1: Acquisition mode  


			
			DrgTableData()
			{
				assert( 65 * 4 == sizeof(DrgTableData) );
				componentCode = 0x3040;
			}
			
		};

		#pragma pack(pop)

		/**
		 *
		 *
		 * DruTableData -- data recording unit table
		 * component code -- 3041/3042/3043
		 * tableSize = 4(component code) + 2432
		 * 由于表太大，这里暂时不实现
		 */
		#pragma pack(push,4)
		struct  DruTableData
		{
			int componentCode;
			
			int reserverd[608];

			
			DruTableData()
			{
				assert( 609 * 4 == sizeof(DruTableData) );
			}
			
		};

		#pragma pack(pop)


		/**
		 *
		 *
		 * HdrProSpeTableData -- hdr project specific table
		 * component code -- 3080H
		 * tableSize = 4(component code) + 256
		 */
		#pragma pack(push,4)

		struct HdrProSpeTableData
		{
			int componentCode;

			//OFFSET  	 //TYPE  						//VALUE  
			/*0 to 31*/  	 int speParameters[32];		//Integer or Float,Specific parameters 1 to 32 
			/*32 to 63*/  	 int speStatus[32];			//Integer or Float,Specific status & alarms 1 to 32 

		
			HdrProSpeTableData()
			{
				assert( 65 * 4 == sizeof(HdrProSpeTableData) );
				componentCode = 0x3080;
			}
			
		};

		#pragma pack(pop)

		/**
		 *
		 * AllComponentTableData -- all component table
		 * component code = 3100H
		 * tableSize:variable-length depending on the hdr configuration
		 * 为了跟其他的monitoring table 兼容，这里仅仅列出component code
		 */
		#pragma pack(push,4)

		struct  AllComponentTableData
		{
			int componentCode;

			
			AllComponentTableData()
			{
				assert(4 == sizeof(AllComponentTableData) );
				componentCode = 0x3100;
			}
			
		};

		#pragma pack(pop)


		// 以下这些表格纯粹是为了兼容法国设备
		/**
		 *
		 * HySeriesTableData -- hy series table
		 * component code -- 0
		 * tableSize = 4(component code) + 4
		 */
		#pragma pack(push,4)

		struct HySeriesTableData
		{
			int componentCode;

			int reserved;
			
			HySeriesTableData()
			{
				assert( 4 * 2 == sizeof(HySeriesTableData) );
				componentCode = 0;
			}
			
		};

		#pragma pack(pop)

		/**
		 *
		 * ConfigNamesTableData -- configuration names table
		 * component code -- 0x200H
		 * tableSize = 4(component code) + 200
		 */
		#pragma pack(push,4)

		struct ConfigNamesTableData
		{
			int componentCode;

			int reserved[50];
			
			ConfigNamesTableData()
			{
				assert( 51 * 4 == sizeof(ConfigNamesTableData) );
				componentCode = 0x200;
			}
			
		};

		#pragma pack(pop)

		/**
		 *
		 * GlobHySeriesTableData -- global hy series table
		 * component code -- 0x201H
		 * tableSize = 4(component code) + 144
		 */
		#pragma pack(push,4)

		struct GlobHySeriesTableData
		{
			int componentCode;

			int reserved[36];
			
			GlobHySeriesTableData()
			{
				assert( 37 * 4 == sizeof(GlobHySeriesTableData) );
			}
			
		};

		#pragma pack(pop)

		/**
		 *
		 * AllHySeriesTableData -- all hy series table
		 * component code -- 0x210H
		 * tableSize = 4(component code) + 348
		 */
		#pragma pack(push,4)

		struct AllHySeriesTableData
		{
			int componentCode;

			int reserved[87];
			
			AllHySeriesTableData()
			{
				assert( 88 * 4 == sizeof(AllHySeriesTableData) );
				componentCode = 0x210;
			}
			
		};

		#pragma pack(pop)


		/**
		 *
		 * AllHyProductTableData -- all hy product table
		 * component code -- 0x2FFH
		 * tableSize = 4(component code) + 348
		 */
		#pragma pack(push,4)

		struct AllHyProductTableData
		{
			int componentCode;

			int reserved[87];
			
			AllHyProductTableData()
			{
				assert( 88 * 4 == sizeof(AllHyProductTableData) );
				componentCode = 0x2FF;
			}
			
		};

		#pragma pack(pop)

		// 以下三个表是为了实现control flow用，每个表的构造函数建议保留，因为在
		// 构造函数中设置了numOfParameters，而这个参数我们是固定的
		/**
		 *
		 *
		 * DmuConfigTableData -- Configuration Command Message 
		 * for Demodulator Unit Table
		 * table size = (1 + 1 + 2 * 40) * 4
		 *
		 *
		 */
		#pragma pack(push, 4)

		struct QZEBRA_LIB_EXPORT DmuConfigTableData 
		{			
			int		componentCode;			// 3010H
			int     numOfParameters;	    // must be 40

			// Offset 0 to 12
			int		parameterID1;
			int		spectAnalysisFlowID;	// Spectrum Analysis Data Flow ID, 0x00000000 to 0xFFFFFFFF.
			int		parameterID2;
			int		vectAnalysisFlowID;		// Vector Analysis Data Flow ID, 0x00000000 to 0xFFFFFFFF.
			int		parameterID3;
			int		reserved0;				// reserved
			int		parameterID4;
			float	inputFreq;				// Input freq, 520,000,000Hz to 920,000,000, in Hz
			int		parameterID5;
			int		ifInputPort;			// IF input port, 0 : Normal port; 1 : Alternate port.
			int		parameterID6;
			float	carriAcqRange;			// carrier acq range. 10,000 to 1,000,000(in +/-Hz)
			int		parameterID7;
			int		pcdDemod;				// PCM demodulation. 0: bpsk, 1 qpsk, 2 oqpsk, 3 uqpsk, 4 8psk.
			int		parameterID8;
			float	bitRate;				// Total I+Q BR or I BR in UQPSK
			int		parameterID9;
			float	qBitRate;				// Bit Rate(Q BR in UQPSK)
			int		parameterID10;
			float	iqRatio;				// I/Q ratio in UQPSK, 0 to 100 db
			int		parameterID11;
			int		pcmCodeForIChann;		// 0:NRZ-L, 1:NRZ-M, 2:NRZ-s, 3:DNRZ, 4:BP-L, 5:BPM, 6:BPS
			int		parameterID12;
			int		matchedFilter;			// 0:integral & dump, 1:raised cosine, 2:root raised cosine, 3 to 1002:custom filter 1
											//    to 1000, 1003:GMSK Gaussian filter
			int		parameterID13;
			float	rollOffOrBt;			// 0.1 to 1.0(in %)

			
			int		parameterID14;
			int		viterbi;				// viterbi I/Q decoding, 0:single decoding, 1:dual decoding
			int		parameterID15;
			int		outputClockPolarity; 	// 0:normal clock, 1:inverted clock //clockPolarity;
			int		parameterID16;
			int		iqPolarity;				// 0:normal; 1:i inv; 2:q inv; 3 i,q inv; 4 swap, 5 swap, i inv; 6: swap q inv; 7 swap i,q inv
			int		parameterID17;
			int		outputMode;				// 0:separate I & Q, 1:iq merged
			int		parameterID18;
			int		clockPolarityForQ;		// UQPSK mode, 0: normal clcok, 1: inverted clock
			int		parameterID19;
			int		berOrFrameSync;			// 0:internal connection, 1:reserved
			int		parameterID20;
			int		berMode;				// 0:off, 1:file, 2:pn10, 3:pn11, 4:pn15, 5:pn23
			int		parameterID21;
			int		fileNum;				// file num for ber in file mode, warning if file does not exist
			int		parameterID22;
			int		reserved1;				// 
			int		parameterID23;
			int		berCounting;			// 0:accumulation mode, else n = duration
			int		parameterID24;
			int		oqpskOffsetAdjust;		//

			// Offset 24 to 39
			int		parameterID25;
			int		reserved2;				//
			int		parameterID26;
			int		reserved3;				//
			int		parameterID27;
			int		demodulationMode;		// 0:demodulation, 1:spectrum analysis
			int		parameterID28;
			int		reserved4;				//
			int		parameterID29;
			int		reserved5;				//
			int		parameterID30;
			int		numOfSymbOrPoint;		// 1 or 2
			int		parameterID31;
			int		viterbiDecoder;			// 
			int		parameterID32;
			int		viterbiDecoderForQ;		// viterbi decoder for q channel in UQPSK
			int		parameterID33;
			int		pcmCodeForQ;			// pcm code for q channel in UQPSK mode
			int		parameterID34;
			int		viterbiPuncturing1;		// viterbi puncturing on i channel
			int		parameterID35;
			int		viterbiPuncturing2;		// viterbi puncturing on q channel
			int		parameterID36;
			int		psk8Config;				// 8 PSK configuration
			int		parameterID37;
			int		reserved6;				//
			int		parameterID38;
			int		reserved7;				// 
			int		parameterID39;
			int		reserved8;				//
			int		parameterID40;
			int		reserved9;				//

			DmuConfigTableData();
		};

		#pragma pack(pop)

		/**
		 *
		 * DpuConfigTableData -- Configuration Command Message
		 * for data processing Unit Table
		 * tableSize = (1 +1 + 2*48) * 4
		 * component code = 3070/3071/3072
		 *
		 */
	#pragma pack(push,4)
		struct QZEBRA_LIB_EXPORT DpuConfigTableData
		{
			int		componentCode;
			int		numOfParameters;	    // must be 48

			//TYPE   //CONFIGURATION PARAMETER              //  VALUE 
			int      parameterID1;
			int  	 TelemetryFlowId;						//	 0 to FFFFFFFFH  
			int      parameterID2;
			int		 DataSource;							//  
			int      parameterID3;
			int  	 TelemetryDataWordTransmission;			//	 0 : Normal 1 : 32 bits MSB & 32 bits LSB 
			int      parameterID4;
			int  	 FrameSizeOrBlockSize;					//	 10 to 1,048,576 (in bytes) 
			int      parameterID5;
			int  	 SynchronizationWordLSB;				//	 MSB aligned 
			int      parameterID6;
			int  	 SynchronizationWordMSB;				//
			int      parameterID7;
			int  	 SynchronizationWordLength;				//	 8 to 64 (in bits)  
			int      parameterID8;
			int  	 SynchronizationWordMaskLSB;			//	 < 1 > bits in the mask indicate what bits in the Synchronization Word must be ignored  
			int      parameterID9;
			int  	 SynchronizationWordMaskMSB;			//	
			int      parameterID10;
			int  	 SYNCThreshold;							//	 0 to 15  
			int      parameterID11;
			int  	 CTLThreshold;							//	 0 to 15  
			int      parameterID12;
			int  	 LTSThreshold;							//	 0 to 15
			int      parameterID13;
			int  	 BitSlipWindow;							//	 0 : 0 bit 
			//	 1 :  1 bit 
			//	 2 :  2 bits  
			int      parameterID14;
			int  	 FrameSynchronizer;						//	 0 : OFF 1 : ON  
			int      parameterID15;
			int  	 Descrambling;							//	 0 : OFF 1 : ON  
			int      parameterID16;
			int  	 ReedSolomonDecoding1;					//	 Bit 0 0 : OFF 1 : ON 
			//	 Bit 1 : 0 Idle frame discarded 1 Idle frame not discarded (RS DVB)  
			int      parameterID17;
			int  	 FrameChecking;							//	 0 : OFF 1 : CRC  

			int      parameterID18;
			int  	 CRCPolynomial;							//	 MSB aligned. Example : 80050000H for a CRC16 10210000 H for CCITT  
			int      parameterID19;
			int  	 CRCPresetValue;						//	 MSB aligned. Example : 0H for a CRC16 FFFF0000 H for CCITT  
			int      parameterID20;
			int  	 VirtualChannelSelection;				//	 0 to 58  

			int      parameterID21;
			int  	 SelectedVirtualChannel1;				//	 64-bit field : If bit Dx = 1 : Virtual Channe1 # x is discarded  
			int      parameterID22;
			int  	 SelectedVirtualChannel2;				//	
			int      parameterID23;
			int  	 ReedSolomonDecoding2;					//	 0 : OFF 1 : ON  
			int      parameterID24;
			int  	 TMBlockEnding;							//	 0 to 8  

			int		 parameterId25;
			int  	 Reserved25;
			int		 parameterId26;
			int  	 Reserved26;
			int		 parameterId27;
			int  	 Reserved27;
			int		 parameterId28;
			int  	 Reserved28;
			int		 parameterId29;
			int  	 Reserved29;
			int		 parameterId30;
			int  	 Reserved30;
			int		 parameterId31;
			int  	 Reserved31;
			int		 parameterId32;
			int  	 Reserved32;
			int		 parameterId33;
			int  	 Reserved33;
			int		 parameterId34;
			int  	 Reserved34;
			int		 parameterId35;
			int  	 Reserved35;
			int		 parameterId36;
			int  	 Reserved36;
			int		 parameterId37;
			int  	 Reserved37;
			int		 parameterId38;
			int  	 Reserved38;
			int		 parameterId39;
			int  	 Reserved39;
			int		 parameterId40;
			int  	 Reserved40;
			int		 parameterId41;
			int  	 Reserved41;
			int		 parameterId42;
			int  	 Reserved42;
			int		 parameterId43;
			int  	 Reserved43;
			int		 parameterId44;
			int  	 Reserved44;
			int		 parameterId45;
			int  	 Reserved45;
			int		 parameterId46;
			int  	 Reserved46;
			int		 parameterId47;
			int  	 Reserved47;
			int		 parameterId48;
			int  	 Reserved48;							//	 
			DpuConfigTableData();
		};

		#pragma pack(pop)



		/**
		 * GlobalHdrConfigTableData - Configuration Command Message
		 * for Global Hdr Table
		 * table size = (1 + 1 + 2*22) * 4
		 * componentCode - 3001
		 */
		#pragma pack(push,4)

		struct  GlobalHdrConfigTableData
		{
			int		componentCode;// 3001H
			int		numOfParameters;// must be 22

			//OFFSET  	 //TYPE  //CONFIGURATION PARAMETER  	//VALUE  
						 int	 parameterID1;
			/* 0 */  	 int  	 MonitoringFlowId;				//	 0 to FFFFFFFFH 
						 int	 parameterID2;
			/* 1 */  	 int  	 LoggingFlowId;					//	 0 to FFFFFFFFH 
						 int	 parameterID3;
			/* 2 */		 int  	 ReferenceFreqSel;				//	 0 : Internal (10 MHz) 1 : External/Internal auto select
						 int	 parameterID4;
			/* 3 */  	 int  	 LeapYear;						//	 0 : No 1 : Yes  
						 int	 parameterID5;
			/* 4 */  	 int  	 TimeCurrentOffset;				//	 In seconds (see note 1) 
						 int	 parameterID6;
			/* 5 */  	 int  	 TimeDateOfNextOffset1;			//	 In seconds (see note 2) 
					     int	 parameterID7;
			/* 6 */  	 int  	 TimeNextOffset1;				//	 In seconds (see note 2) 
						 int	 parameterID8;
			/* 7 */  	 int  	 TimeDateOfNextOffset2;			//	 In seconds (see note 2) 
						 int	 parameterID9;
			/* 8 */  	 int  	 TimeNextOffset2;				//	 In seconds (see note 2)
						 int	 parameterID10;
			/* 9 */  	 int  	 TimeCode;						//	 0 : IRIG-B 1 : NASA-36 
						 int	 parameterID11;
			/* 10 */  	 float   CableCompensation;				//	 0 to 12 (in dB)  
						 int	 parameterID[11];
			/* 11to21*/  int	 Reserved1[11];					//
			GlobalHdrConfigTableData()
			{
				assert( 46 * 4 == sizeof(GlobalHdrConfigTableData) );
				componentCode = 0x3001;
				numOfParameters = 22;
			}
		};

		#pragma pack(pop)

		// 以下这三个都是服务器发给客户端的table,但都没有component code
		/**
		 *
		 * ConfigAckTableData -- server 发给客户端的ack message
		 *
		 */
		#pragma pack(push,4)

		struct ConfigAckTableData
		{
 			union
 			{// 用union是为了跟前面的table兼容，因为ack table本身没有componentCode字段
 				int componentCode;
 				int ack;
 			};
			ConfigAckTableData()
			{
				componentCode = 0;
			}
		};
		#pragma pack(pop) 

		/**
		 *
		 * RejectionTableData -- 当超过某个flow的最大连接数时,server发给客户端的table 
		 *
		 */
		#pragma pack(push,4)

		struct RejectionTableData
		{
			union
			{
				int componentCode;
				int rejection;
			};

			RejectionTableData()
			{
				rejection = -2;
			}
		};

		#pragma pack(pop)
			
		 /**
		  *
		  * NegtiveTableData -- 当flowId 不对, 消息大小不对，componentcode不对,server发给客户端的table
		  *
		  */
		#pragma pack(push,4)
		struct NegtiveTableData
		{
			union
			{
				int componentCode;
				int negtive;
			};

			NegtiveTableData()
			{
				negtive = -1;
			}
		};
		#pragma pack(pop)


		/**
		* monitoringReqTable--客户端发给服务器的monitor request
		*/
		#pragma pack(push,4)
		struct MonitorReqTableData
		{
			int componentCode;
			MonitorReqTableData()
			{
				componentCode = 0;
			}
		};
		#pragma pack(pop)

		/**
		 * VectorAnalysisRequestTableData -- 客户端发给服务器的vector request
		 */
		#pragma pack(push,4)
		struct VectorAnalysisRequestTableData
		{
			union
			{
				int componentCode;
				int analysisDataSource;//0 : Demodulator # 1  1 : Demodulator # 2
			};
			int dataFlow;//0 : Permanent flow  1 : Single block transmission
			int reserved5;
			int reserved6;
			int reserved7;
			int reserved8;
			int reserved9;
			int reserved10;
			int reserved11;
			int reserved12;
			
			VectorAnalysisRequestTableData()
			{
				analysisDataSource = 0;
				dataFlow = 1;
			}
		};
		#pragma pack(pop)

		/**
		 * VectorAnalysisDataMsgTableData--服务器发给客户端的vector data
		 */
		#pragma pack(push,4)
		struct VectorAnalysisDataMsgTableData
		{
			union
			{
				int componentCode;
				int timeTag1;
			};
			int timeTag2;

			float IFLevel;// -128 to +127 (in dBm) 
			float EbNoII1Q1;//	-128 to +127 (in dB) 
			float EbNoII1Q0;//-128 to +127 (in dB)
			float EbNoII0Q0;//-128 to +127 (in dB) 
			float EbNoII0Q1;//-128 to +127 (in dB) 
			float EbNoQI1Q1;//-128 to +127 (in dB) 
			float EbNoQI1Q0;//-128 to +127 (in dB) 
			float EbNoQI0Q0;//-128 to +127 (in dB) 
			float EbNoQI0Q1;//-128 to +127 (in dB) 
			int   Reserved14; 
			int   NumberOfVectorPointsSymbol;//	1 to 32 	 
			int   Reserved16;
			int   Reserved17;
			float IQValue[512];
			VectorAnalysisDataMsgTableData()
			{
				assert( 527 * 4 == sizeof(VectorAnalysisDataMsgTableData) );
			}
		};
		#pragma pack(pop)

		/**
		* NegativeVectorAnalysisAckTableData -- 服务器发给客户端的vector ack
		*/
#pragma pack(push,4)
		struct NegativeVectorAnalysisAckTableData
		{
			union
			{
				int componentCode;
				int ack;
			};
			NegativeVectorAnalysisAckTableData()
			{
				ack = 1;
			}
		};
#pragma pack(pop)


#pragma pack(push,4)

		struct ProbeTableData
		{			
			int componentCode;	
			unsigned int spyData[512 * 8];
			int peakBufferUse;

			ProbeTableData()
			{
				//assert( 527 * 4 == sizeof(ProbeTableData) );
			}
		};

#pragma pack(pop)

#pragma pack(push,4)
		struct ProbeRequestTableData
		{
			union
			{
				int componentCode;
				int analysisDataSource;//0 : Demodulator # 1  1 : Demodulator # 2
			};
			int dataFlow;//0 : Permanent flow  1 : Single block transmission
			int reserved5;
			int reserved6;
			int reserved7;
			int reserved8;
			int reserved9;
			int reserved10;
			int reserved11;
			int reserved12;

			ProbeRequestTableData()
			{
				analysisDataSource = 0;
				dataFlow = 1;
			}
		};
#pragma pack(pop)

#pragma pack(push,4)
		struct NegativeProbeAckTableData
		{
			union
			{
				int componentCode;
				int ack;
			};
			NegativeProbeAckTableData()
			{
				ack = 1;
			}
		};
#pragma pack(pop)	

		/**
		 * ResetBerTableData -- 客户端发给服务器的reset ber 命令
		 */
		#pragma pack(push,4)
		struct ResetBerTableData
		{
			int componentCode;
			int numberOfParameters;
			int parameterId;
			ResetBerTableData()
			{
				componentCode = 0x3010;
				numberOfParameters = 1;
				parameterId = 0xfffffffe;
			}
		};
		#pragma pack(pop)


		/**
		 * TelemetryRequestTableData -- 客户端发给服务器的Real Time Telemetry Data Request
		 */
		#pragma pack(push,4)
		struct TelemetryRequestTableData
		{	  	 
			union
			{
				int componentCode;
				int telemetryChannel; // 0 : Telemetry channel A 
									  // 1 : Telemetry channel B 
									  // 2 : Telemetry channel C
			};
			int requestCode;//
			int reserved5;
			int reserved6;
			int reserved7;
			int numberOfTMBlocks; // Number of TM Blocks per telemetry message
								  // range: 1 to 131072
			int telemetryMessageRate; // 0 : Transmit all TM blocks
									  // -N : Number of TM blocks to discard between two consecutive telemetry messages
									  //  > 0 : Reserved
			int selectedVirtualChannelMSB; // If bit Dx = 0 : Virtual Channe1 # x is transmitted 
			int selectedVirtualChannelLSB; // 
			int firstTMBlockToTransmit; // 0 : Start transmitting from the first TM Block in the PC RAM buffer
										// 1 : Start transmitting from first TM Block in PC RAM buffer with time-tag specified by offsets 13 & 14
			int timeTagOfFirstTMBlock1;
			int timeTagOfFirstTMBlock2;
			int lastTMBlockToTransmit; // 0 : Transmit data until IP connection closure
									   // 1 : Last TM Block in PC RAM buffer with time-tag specified by offsets 13 & 14
			  	 	 
			int timeTagOfLastTMBlock1;
			int timeTagOfLastTMBlock2;

			int reserved18;
			int reserved19;
			int reserved20;
			int reserved21;
			int reserved22;
			int reserved23;
			int reserved24;
			int reserved25;
			int reserved26;
			int reserved27;
			int reserved28;
			int reserved29;
			int reserved30;
				
			TelemetryRequestTableData()
			{
				assert(28 * 4 == sizeof(TelemetryRequestTableData));
			}
		};
		#pragma pack(pop)


#pragma pack(push,4)
		struct TelemetryTableData
		{	  	 
			union
			{
				int componentCode;
				int telemetryChannel; // 0 : Telemetry channel A 
				// 1 : Telemetry channel B 
				// 2 : Telemetry channel C
			};
			
			char data[4 * 512 * 1024];
			TelemetryTableData()
			{
				assert(sizeof(int) + sizeof(data) == sizeof(TelemetryTableData));
			}
		};
#pragma pack(pop)
	}
}
