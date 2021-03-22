#include "gtest/gtest.h"


extern "C"
{
#include<avr/io.h>
#include"Drivers/Timer/Timer.h"
}


class TimerTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		timer_init();
	}
	void TearDown()
	{

	}
};

TEST_F(TimerTest, Prescaler_setup) {
	EXPECT_EQ(0x04, TCCR1B);//00000100
}

TEST_F(TimerTest, Mask_setup) {
	EXPECT_EQ(0x04, TIMSK1);//00000100
}
