#include "gtest/gtest.h"


extern "C"
{
#include<avr/io.h>
#include"Drivers/led/led_driver.h"
#include"Drivers/Termometer/Termometer.h"
}


class TermometerTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		termometer_create();
		led_create();
	}
	void TearDown()
	{

	}
};

TEST_F(TermometerTest, TermometerStart) {
  EXPECT_EQ(0x01, DDRG);
  uint8_t value = PORTG & _BV(PG0);
  EXPECT_EQ(0x01, value);
}

TEST_F(TermometerTest, Termometer_input) {
	EXPECT_EQ(0x00, DDRK);
}

TEST_F(TermometerTest, ADMUX_Setup) {
	EXPECT_EQ(0x47, ADMUX);
}

TEST_F(TermometerTest, ADCSRA_setup) {
	EXPECT_EQ(0xEF, ADCSRA);
}

TEST_F(TermometerTest, ADCSRB_setup) {
	EXPECT_EQ(0x0D, ADCSRB);
}
