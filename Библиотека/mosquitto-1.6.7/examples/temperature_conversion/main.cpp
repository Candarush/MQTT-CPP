#include "temperature_conversion.h"

int main(int argc, char *argv[])
{
	class mqtt_tempconv *tempconv;
	int rc;

	mosqpp::lib_init();

	tempconv = new mqtt_tempconv("M30-212B-18/Game", "test.mosquitto.org", 1883);
	tempconv->loop_forever();

	mosqpp::lib_cleanup();

	return 0;
}

