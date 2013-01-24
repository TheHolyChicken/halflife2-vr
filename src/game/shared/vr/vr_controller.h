#include <stdio.h>
#include <math.h>
#include "freespace.h"
#include "vr/motionsensor.h"


/*	===================
	VR Controller - Handles coordination of all the raw sensor data, syncing across them and turning them into usable game inputs
	=================== */

#define SENSOR_COUNT 1

enum VrTrackedPart
{
	HEAD = 0,
	WEAPON = 1,
	BODY = 2
};

class VrController 
{
 
public:
 
	VrController();
	~VrController();
 
	QAngle  headOrientation( void );
	QAngle  weaponOrientation( void );
	QAngle  bodyOrientation( void );
	void	update( void );
	void	calibrate( void );
	bool	initialized() { return _initialized; }
	
protected:
	float _totalAccumulatedYaw[SENSOR_COUNT];
	float _previousYaw[SENSOR_COUNT];
	bool _initialized;
	
	MotionSensor* _sensors[SENSOR_COUNT];
	float _fake3[10];
	QAngle _cachedAngles[SENSOR_COUNT];
	float _fake[10];
	QAngle _calibrationAngles[SENSOR_COUNT];
	float _fake2[10];
};

VrController* VR_Controller();
