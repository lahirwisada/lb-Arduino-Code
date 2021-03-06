//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsCard(void) -
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsCard(void)
{
  setMuxChannel(UUT_CARD_MUX_CH);
  switch (boardType)
  {
    case DIGIO16I2C_CARD:
      Serial.println(F("Not supported at present"));
      break;
    case DIGIO128_CARD:
      bounceLedsDIGIO128_CARD();
      break;
    case OPTOIN8I2C_CARD:
      Serial.println(F("Can't bounce LEDs on an input only card"));
      break;
    case OPTOOUT8I2C_CARD:
      Serial.println(F("Not supported at present"));
      break;
    case DIGIO32I2C_CARD:
      bounceLedsDigio32();
      break;
    case PROTO16I2C_CARD:
      bounceLedsPROTO16I2C_CARD();
      break;
    case ODASPSOC5_CARD:
      Serial.println(F("Not supported at present"));
      break;
    case NEW_CARD:
      Serial.println(F("Not supported at present"));
      break;
    case I2CIO8_CARD:
      bounceLedsI2CIO8();
      break;
    case I2CIO8X_CARD:
      bounceLedsI2CIO8X();
      break;
    default:
      Serial.println(F("Not supported at present - default case"));
      break;
  }
    if (Serial.available() > 0)
    {
      Serial.read();
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsPROTO16I2C_CARD(void)
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsPROTO16I2C_CARD(void)
{
  Serial.println(F("Bouncing LEDs - any key to stop"));
  Adafruit_MCP23017 mcp;
  mcp.begin(0);      // use default address

  while (1)
  {
    for (uint8_t port = 0; port < 16; port++)
    {
      mcp.pinMode(port, OUTPUT);
      mcp.digitalWrite(port, HIGH);
      delay(250);
      mcp.digitalWrite(port, LOW);
    }
    if (Serial.available() > 0)
    {
      Serial.read();
      return;
    }
  }

}

//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsDigio32(void)
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsDigio32(void)
{
  Digio32 Dio32;
  Dio32.begin(0);
  Serial.println(F("Bouncing LEDs - any key to stop"));
  while (1)
  {
    for (uint8_t port = 0; port < 32; port++)
    {
      Dio32.pinMode(port, OUTPUT);
      Dio32.digitalWrite(port, HIGH);
      delay(2);
      Dio32.digitalWrite(port, LOW);
      delay(2);
    }
    if (Serial.available() > 0)
    {
      Serial.read();
      return;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsDIGIO128_CARD(void)
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsDIGIO128_CARD(void)
{
  Digio128 Dio128;
  Dio128.begin();
  Serial.println(F("Bouncing LEDs DIGIO-128 - any key to stop"));
  while (1)
  {
    for (uint8_t port = 0; port < 127; port++)
    {
      Dio128.pinMode(port, OUTPUT);
      delay(20);
      Dio128.digitalWrite(port, HIGH);
      delay(20);
      Dio128.digitalWrite(port, LOW);
      delay(20);
    }
    if (Serial.available() > 0)
    {
      Serial.read();
      return;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsI2CIO8(void)
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsI2CIO8(void)
{
  LandBoards_I2CIO8 i2cio8Card;
  i2cio8Card.begin();
  Serial.println(F("Bouncing LEDs I2CIO8 - any key to stop"));
  while (1)
  {
    for (uint8_t port = 0; port < 4; port++)
    {
      i2cio8Card.writeLED(port, HIGH);
      delay(250);
      i2cio8Card.writeLED(port, LOW);
    }
    for (uint8_t port = 2; port > 0; port--)
    {
      i2cio8Card.writeLED(port, HIGH);
      delay(250);
      i2cio8Card.writeLED(port, LOW);
    }
    if (Serial.available() > 0)
    {
      Serial.read();
      return;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////
// void bounceLedsI2CIO8(void)
//////////////////////////////////////////////////////////////////////////////////////

void bounceLedsI2CIO8X(void)
{
  LandBoards_I2CIO8X i2cio8XCard;
  i2cio8XCard.begin();
  Serial.println(F("Bouncing LEDs I2CIO8X - any key to stop"));
  for (int port = 0; port < 8; port++)
    i2cio8XCard.pinMode(port,OUTPUT);
  while (1)
  {
    for (uint8_t port = 0; port < 8; port++)
    {
      i2cio8XCard.digitalWrite(port, HIGH);
      delay(250);
      i2cio8XCard.digitalWrite(port, LOW);
    }
    if (Serial.available() > 0)
    {
      Serial.read();
      return;
    }
  }
}


