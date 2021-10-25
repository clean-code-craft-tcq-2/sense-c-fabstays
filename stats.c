#include "stats.h"
#include <math.h>

int emailAlertCallCount;
int ledAlertCallCount;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
	float sum =0;
	if (!(setlength==0))
	{
		float tempmin = numberset[0];
		float tempmax = numberset[0];
		for(int i=0; i<=setlength;i++)
		{
			sum += numberset[i];
			if(tempmax <numberset[i])
			{
				tempmax = numberset[i];
			}
			if(tempmin >numberset[i])
			{
				tempmin = numberset[i];
			}
		}
		
		s.average = sum/setlength;
	
    s.min = tempmin;
    s.max = tempmax;
	}
	else
	{
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	}	
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if(computedStats.max > maxThreshold)
	{
		alerters[0]();
		alerters[1]();
	}	
		
}

