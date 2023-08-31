
#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/examples/i2c1_master_example.h"
#define I2C_ADDRESS_RTC 0x68

volatile static unsigned int  msecTime = 0;
volatile static unsigned char secTime  = 0;
volatile static unsigned char minTime  = 0;
volatile static unsigned char hourTime = 0;

static uint8_t writeBuffer[32];

void NixieDriveBCD(unsigned char num)
{
	switch (num) {
		case 0:
			BCD_0_LAT = 0;
			BCD_1_LAT = 0;
			BCD_2_LAT = 0;
			BCD_3_LAT = 0;
			break;
		case 1:
			BCD_0_LAT = 1;
			BCD_1_LAT = 0;
			BCD_2_LAT = 0;
			BCD_3_LAT = 0;
			break;
		case 2:
			BCD_0_LAT = 0;
			BCD_1_LAT = 1;
			BCD_2_LAT = 0;
			BCD_3_LAT = 0;
			break;
		case 3:
			BCD_0_LAT = 1;
			BCD_1_LAT = 1;
			BCD_2_LAT = 0;
			BCD_3_LAT = 0;
			break;
		case 4:
			BCD_0_LAT = 0;
			BCD_1_LAT = 0;
			BCD_2_LAT = 1;
			BCD_3_LAT = 0;
			break;
		case 5:
			BCD_0_LAT = 1;
			BCD_1_LAT = 0;
			BCD_2_LAT = 1;
			BCD_3_LAT = 0;
			break;
		case 6:
			BCD_0_LAT = 0;
			BCD_1_LAT = 1;
			BCD_2_LAT = 1;
			BCD_3_LAT = 0;
			break;
		case 7:
			BCD_0_LAT = 1;
			BCD_1_LAT = 1;
			BCD_2_LAT = 1;
			BCD_3_LAT = 0;
			break;
		case 8:
			BCD_0_LAT = 0;
			BCD_1_LAT = 0;
			BCD_2_LAT = 0;
			BCD_3_LAT = 1;
			break;
		case 9:
			BCD_0_LAT = 1;
			BCD_1_LAT = 0;
			BCD_2_LAT = 0;
			BCD_3_LAT = 1;
			break;
		case 10:
			BCD_0_LAT = 1;
			BCD_1_LAT = 1;
			BCD_2_LAT = 1;
			BCD_3_LAT = 1;
			break;
  }
}

/* フェード制御（割込み呼出し） */
#define FADE_EFFECT_PITCH 15     /* フェードエフェクトピッチ */
uint16_t fadeValue = 0;
uint8_t displayDigitNum;
uint8_t displayDigitDot;
uint8_t displayDigitLED;
uint8_t currentDigitNum;
uint8_t currentDigitDot;
uint8_t currentDigitLED;
uint8_t nextDigitNum;
uint8_t nextDigitDot;
uint8_t nextDigitLED;

void driveFadeEffect (void)
{
	unsigned char i;
	static unsigned char delayCNT = 0;
	static unsigned char pitchCNT = FADE_EFFECT_PITCH;
	static unsigned char timerCNT = 0;

	if (fadeValue > 0) {
		if (delayCNT >= fadeValue) {
			delayCNT = 0;
			if (pitchCNT == 0) {
				pitchCNT = FADE_EFFECT_PITCH;
				fadeValue = 0;
				currentDigitNum = nextDigitNum;
				currentDigitDot = nextDigitDot;
				currentDigitLED = nextDigitLED;
			} else {
				pitchCNT--;
			}
		} else {
			delayCNT++;
		}
	}

	if (timerCNT >= FADE_EFFECT_PITCH) {
		timerCNT = 0;
	} else {
		timerCNT++;
	}

	if ((pitchCNT >= timerCNT) && (fadeValue > 0)) {
		displayDigitNum = currentDigitNum;
		displayDigitDot = currentDigitDot;
		displayDigitLED = currentDigitLED;
	} else {
		displayDigitNum = nextDigitNum;
		displayDigitDot = nextDigitDot;
		displayDigitLED = nextDigitLED;
	}
	NixieDriveBCD(displayDigitNum);
	DOT_LAT = displayDigitDot;
	LED_LAT = displayDigitLED;
	return;
}

void MCC_USB_CDC_WRITE(const char *msg)
{
	// USBデバイスがまだ構成されていない場合、
	// 通信するホストがないため何もせずに戻ります。
	if( USBGetDeviceState() < CONFIGURED_STATE ) return;
	
	// 現在中断(suspended)の場合は、リモートウェイクアップを発行する必要があるか
	// 確認する必要があります。また、現在ホストと通信していないため、どのような
	// キーボードコマンドも処理できません。
	if( USBIsDeviceSuspended()== true ) return;
	
	//while( USBUSARTIsTxTrfReady() == false) {}
	// 文字列をUSBに送信します。
	putUSBUSART((uint8_t *)msg, strlen(msg));

	return;
}


/* 時刻変数セット（時、分、秒） */
void setTimeCount (unsigned char hour, unsigned char min, unsigned char sec)
{
	hourTime = hour;
	minTime  = min;
	secTime  = sec;
	return;
}

/* RTCのリードと時刻変数のセット */
void readTimeRTC (void)
{
	unsigned char hour10  = 0;
	unsigned char hour1   = 0;
	unsigned char min10   = 0;
	unsigned char min1    = 0;
	unsigned char sec10   = 0;
	unsigned char sec1    = 0;
	uint8_t I2C_BUFF[3];
	uint8_t buff[32];

	I2C1_ReadDataBlock(I2C_ADDRESS_RTC, 0x00, &I2C_BUFF[0], 3);

	sec10 = (I2C_BUFF[0] >> 4) & 0x0f;
	sec1  = I2C_BUFF[0] & 0x0f;
	min10 = (I2C_BUFF[1] >> 4) & 0x0f;
	min1  = I2C_BUFF[1] & 0x0f;
	hour10 = (I2C_BUFF[2] >> 4) & 0x0f;
	hour1  = I2C_BUFF[2] & 0x0f;

	setTimeCount(hour10 * 10 + hour1, min10 * 10 + min1, sec10 * 10 + sec1);

	return;
}

/* RTC 初期化 */
void RTC_Initialize (void)
{
	I2C_RST_LAT = 1; //RTCリセット解除
	readTimeRTC();
	I2C1_Write1ByteRegister(I2C_ADDRESS_RTC, 0x0e, 0x40); //1pps矩形波出力設定
	return;
}

/* 1秒時計カウントアップ（割込み呼出し） */
void countUpTimer (void)
{
	secTime ++;
	if (secTime > 59){
		secTime = 0;
		minTime++;
		if (minTime > 59){
			minTime = 0;
			hourTime++;
			if (hourTime > 23) {
				hourTime = 0;
			}
		}
	}

	return;
}

void Handler_TMR0(void)
{
	CDCTxService();
	driveFadeEffect();
	return;
}

//RTC 1pps割り込み
void Handler_INT2(void)
{
	countUpTimer();
	nextDigitNum = secTime % 10;
//	nextDigitDot = 1;
	if (nextDigitDot == 0) {
		nextDigitDot = 1;
		nextDigitLED = 1;
	} else {
		nextDigitDot = 0;
		nextDigitLED = 0;
	}
	fadeValue = 100;
	return;
}

void main(void)
{
	unsigned char cnt, cnt2 = 0;

	// Initialize the device
	SYSTEM_Initialize();
	RTC_Initialize();
	TMR0_SetInterruptHandler(Handler_TMR0);
	INT2_SetInterruptHandler(Handler_INT2);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    INTERRUPT_GlobalInterruptEnable(); // Enable the Global Interrupts
	//INTERRUPT_GlobalInterruptDisable(); // Disable the Global Interrupts
    INTERRUPT_PeripheralInterruptEnable(); // Enable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptDisable(); // Disable the Peripheral Interrupts

//	DELAY_milliseconds(2000);

    while (1)
    {
		if (SW_1_PORT == 0) {
			EPWM1_LoadDutyValue(60*(1024/100));
		}
		else if (SW_2_PORT == 0) {
			EPWM1_LoadDutyValue(45*(1024/100));
		}
		else if (SW_3_PORT == 0) {
			EPWM1_LoadDutyValue(10*(1024/100));
		}
		else {
			EPWM1_LoadDutyValue(30*(1024/100));
		}
    }
}
/**
 End of File
*/