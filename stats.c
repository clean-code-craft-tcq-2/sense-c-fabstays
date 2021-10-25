#include "stats.h"
#include <math.h>

int emailAlertCallCount;
int ledAlertCallCount;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
	float sum =0.0;
	if (!(setlength==0))
	{
		s.min = numberset[0];
		s.max = numberset[0];
		for(int i=0; i<=setlength;i++)
		{
			sum += numberset[i];
			if(s.max <numberset[i])
			{
				s.max = numberset[i];
			}
			if(s.min >numberset[i])
			{
				s.min = numberset[i];
			}
		}
		
		s.average = sum/setlength;

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

