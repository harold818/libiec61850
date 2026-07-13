/*
 *  time.c
 *
 *  Copyright 2013-2024 Michael Zillgith
 *
 *  This file is part of Platform Abstraction Layer (libpal)
 *  for libiec61850, libmms, and lib60870.
 */

#include "hal_time.h"
#include <time.h>
#include <sys/time.h>
#include <zephyr/drivers/rtc.h>

msSinceEpoch
Hal_getTimeInMs()
{
    msSinceEpoch msTime = 0;

#ifdef CONFIG_RTC
    const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
    struct rtc_time rtcTime;

    if (rtc_get_time(rtc_dev, &rtcTime) == 0)
    {
        msTime = (msSinceEpoch)(rtcTime.tm_sec) * 1000UL;
        msTime += (msSinceEpoch)(rtcTime.tm_nsec) / 1000000UL;
    }
    else
    {
        return 0;
    }
#else
    msTime = k_uptime_get();
#endif

    return msTime;
}

nsSinceEpoch
Hal_getTimeInNs()
{
    nsSinceEpoch nsTime = 0;

#ifdef CONFIG_RTC
    const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
    struct rtc_time rtcTime;

    if (rtc_get_time(rtc_dev, &rtcTime) == 0)
    {
        nsTime = (nsSinceEpoch)(rtcTime.tm_sec) * 1000000000UL;
        nsTime += (nsSinceEpoch)(rtcTime.tm_nsec);
    }
    else
    {
        return 0;
    }
#else
    nsTime = k_uptime_get() * 1000000UL;
#endif

    return nsTime;
}

bool
Hal_setTimeInNs(nsSinceEpoch nsTime)
{
#ifdef CONFIG_RTC
    const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
    struct rtc_time rtcTime;

    rtcTime.tm_sec = nsTime / 1000000000UL;
    rtcTime.tm_nsec = nsTime % 1000000000UL;

    if (rtc_set_time(rtc_dev, &rtcTime) == 0){
        return true;
    }
#endif

    return false;
}

msSinceEpoch
Hal_getMonotonicTimeInMs()
{
    return k_uptime_get();
}

nsSinceEpoch
Hal_getMonotonicTimeInNs()
{
    return k_uptime_ticks() * 1000000000UL / CONFIG_SYS_CLOCK_TICKS_PER_SEC;
}
