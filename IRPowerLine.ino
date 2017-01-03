#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 12;
int RECV_POWER = 11;

int DELAY_TIME_DEFAULT = 200;
int DELAY_TIME_ZERO = 0;

int RELE_1 = 2;
int RELE_2 = 3;
int RELE_3 = 4;
int RELE_4 = 5;
int RELE_5 = 6;
int RELE_6 = 7;
int RELE_7 = 8;
int RELE_8 = 9;

boolean RELE_1_ON = false;
boolean RELE_2_ON = false;
boolean RELE_3_ON = false;
boolean RELE_4_ON = false;
boolean RELE_5_ON = false;
boolean RELE_6_ON = false;
boolean RELE_7_ON = false;
boolean RELE_8_ON = false;

long BT_RELE_1 = 0x10;
long BT_RELE_2 = 0x810;
long BT_RELE_3 = 0x410;
long BT_RELE_4 = 0xC10;
long BT_RELE_5 = 0;
long BT_RELE_6 = 0;
long BT_RELE_7 = 0;
long BT_RELE_8 = 0;
long BT_POWER  = 0xA90;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);

  // configure IR
  if (RECV_POWER > 0)
  {
    pinMode(RECV_POWER, OUTPUT);
    digitalWrite(RECV_POWER, HIGH);
  }

  irrecv.enableIRIn();
  irrecv.blink13(true);

  // configure rele ports
  setupAllRelePorts();
  tunOffAllRelePorts(DELAY_TIME_ZERO);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);

    if (results.value == BT_RELE_1)
    {
      Serial.println("Rele 1");
      toggleRele(1, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_2)
    {
      Serial.println("Rele 2");
      toggleRele(2, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_3)
    {
      Serial.println("Rele 3");
      toggleRele(3, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_4)
    {
      Serial.println("Rele 4");
      toggleRele(4, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_5)
    {
      Serial.println("Rele 5");
      toggleRele(5, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_6)
    {
      Serial.println("Rele 6");
      toggleRele(6, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_7)
    {
      Serial.println("Rele 7");
      toggleRele(7, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_RELE_8)
    {
      Serial.println("Rele 8");
      toggleRele(8, DELAY_TIME_DEFAULT);
    }
    else if (results.value == BT_POWER)
    {
      Serial.println("Power");

      if (RELE_1_ON && RELE_2_ON && RELE_3_ON && RELE_4_ON && RELE_5_ON && RELE_6_ON && RELE_7_ON && RELE_8_ON)
      {
        tunOffAllRelePorts(DELAY_TIME_DEFAULT);
      }
      else if (!RELE_1_ON && !RELE_2_ON && !RELE_3_ON && !RELE_4_ON && !RELE_5_ON && !RELE_6_ON && !RELE_7_ON && !RELE_8_ON)
      {
        tunOnAllRelePorts(DELAY_TIME_DEFAULT);
      }
      else
      {
        tunOffAllRelePorts(DELAY_TIME_DEFAULT);
      }
    }

    irrecv.resume();
  }

  delay(100);
}

/* Configure all rele ports */
void setupAllRelePorts()
{
  pinMode(RELE_1, OUTPUT);
  pinMode(RELE_2, OUTPUT);
  pinMode(RELE_3, OUTPUT);
  pinMode(RELE_4, OUTPUT);
  pinMode(RELE_5, OUTPUT);
  pinMode(RELE_6, OUTPUT);
  pinMode(RELE_7, OUTPUT);
  pinMode(RELE_8, OUTPUT);
}

/* Turn off all rele ports */
void tunOffAllRelePorts(int delayTime)
{
  tunOffRele(1, delayTime);
  tunOffRele(2, delayTime);
  tunOffRele(3, delayTime);
  tunOffRele(4, delayTime);
  tunOffRele(5, delayTime);
  tunOffRele(6, delayTime);
  tunOffRele(7, delayTime);
  tunOffRele(8, delayTime);
}

/* Turn on all rele ports */
void tunOnAllRelePorts(int delayTime)
{
  tunOnRele(1, delayTime);
  tunOnRele(2, delayTime);
  tunOnRele(3, delayTime);
  tunOnRele(4, delayTime);
  tunOnRele(5, delayTime);
  tunOnRele(6, delayTime);
  tunOnRele(7, delayTime);
  tunOnRele(8, delayTime);
}

/* Turn on one rele port */
void tunOnRele(int index, int delayTime)
{
  switch (index)
  {
    case 1:
      digitalWrite(RELE_1, LOW);
      RELE_1_ON = true;
      break;
    case 2:
      digitalWrite(RELE_2, LOW);
      RELE_2_ON = true;
      break;
    case 3:
      digitalWrite(RELE_3, LOW);
      RELE_3_ON = true;
      break;
    case 4:
      digitalWrite(RELE_4, LOW);
      RELE_4_ON = true;
      break;
    case 5:
      digitalWrite(RELE_5, LOW);
      RELE_5_ON = true;
      break;
    case 6:
      digitalWrite(RELE_6, LOW);
      RELE_6_ON = true;
      break;
    case 7:
      digitalWrite(RELE_7, LOW);
      RELE_7_ON = true;
      break;
    case 8:
      digitalWrite(RELE_8, LOW);
      RELE_8_ON = true;
      break;
  }

  delay(delayTime);
}

/* Turn off one rele port */
void tunOffRele(int index, int delayTime)
{
  switch (index)
  {
    case 1:
      digitalWrite(RELE_1, HIGH);
      RELE_1_ON = false;
      break;
    case 2:
      digitalWrite(RELE_2, HIGH);
      RELE_2_ON = false;
      break;
    case 3:
      digitalWrite(RELE_3, HIGH);
      RELE_3_ON = false;
      break;
    case 4:
      digitalWrite(RELE_4, HIGH);
      RELE_4_ON = false;
      break;
    case 5:
      digitalWrite(RELE_5, HIGH);
      RELE_5_ON = false;
      break;
    case 6:
      digitalWrite(RELE_6, HIGH);
      RELE_6_ON = false;
      break;
    case 7:
      digitalWrite(RELE_7, HIGH);
      RELE_7_ON = false;
      break;
    case 8:
      digitalWrite(RELE_8, HIGH);
      RELE_8_ON = false;
      break;
  }

  delay(delayTime);
}

/* Toggle one rele port to on or off */
void toggleRele(int index, int delayTime)
{
  switch (index)
  {
    case 1:
      if (RELE_1_ON)
      {
        tunOffRele(1, delayTime);
      }
      else
      {
        tunOnRele(1, delayTime);
      }
      break;
    case 2:
      if (RELE_2_ON)
      {
        tunOffRele(2, delayTime);
      }
      else
      {
        tunOnRele(2, delayTime);
      }
      break;
    case 3:
      if (RELE_3_ON)
      {
        tunOffRele(3, delayTime);
      }
      else
      {
        tunOnRele(3, delayTime);
      }
      break;
    case 4:
      if (RELE_4_ON)
      {
        tunOffRele(4, delayTime);
      }
      else
      {
        tunOnRele(4, delayTime);
      }
      break;
    case 5:
      if (RELE_5_ON)
      {
        tunOffRele(5, delayTime);
      }
      else
      {
        tunOnRele(5, delayTime);
      }
      break;
    case 6:
      if (RELE_6_ON)
      {
        tunOffRele(6, delayTime);
      }
      else
      {
        tunOnRele(6, delayTime);
      }
      break;
    case 7:
      if (RELE_7_ON)
      {
        tunOffRele(7, delayTime);
      }
      else
      {
        tunOnRele(7, delayTime);
      }
      break;
    case 8:
      if (RELE_8_ON)
      {
        tunOffRele(8, delayTime);
      }
      else
      {
        tunOnRele(8, delayTime);
      }
      break;
  }
}


