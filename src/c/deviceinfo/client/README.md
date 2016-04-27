*Deviceinfo_collect is a service that collect log(logcat/dmesg) & device info from device within filter config and record them for analysis*

**Deviceinfo_collect contains below modules.**
1. DevInfo_wrapper: wrapper to collect runtime device info including (os version/network status/display status/device id/xxx).
2. LogInfo_wrapper: wrapper to read all logs from [/dev/logger]&[/dev/kmsg].
3. LogInfo_filter:  a filter to filter specify STRING based on config.
4. Info_recorder:    a Recored to store filtered loginfo & device info to [files].
5. Info_client:     a Info process client to analysis the recoded files.
6. Config_parser:   a parser to parse service config contains [DeviceInfo] [spectfy STRTING] [recorder files] [Client files]

**Typical DeviceInfo string looks like**
    [ro.baseband]: [msm]
    [ro.board.platform]: [msm8974]
    [ro.boot.baseband]: [msm]
    [ro.boot.boot_recovery]: [0]
    [ro.boot.bootdevice]: [msm_sdcc.1]
    [ro.boot.bootloader]: [N9008ZMUGOC3]
    [ro.boot.hardware]: [qcom]
    [ro.boot.serialno]: [8d63b451]
    [ro.boot.warranty_bit]: [1]
    [ro.bootimage.build.date]: [Sun Jan 24 18:35:49 MST 2016]
    [ro.bootimage.build.date.utc]: [1453685749]
    [ro.bootimage.build.fingerprint]: [samsung/cm_hlte/hlte:6.0.1/MMB29T/fbbcb9e316:userdebug/test-keys]

    *device info filter sample*
    //see deviceinfo_collect/etc/info_filter.xml[json].

 **Typical LogInfo string from logger(Android)**
    04-18 13:17:59.972  3120  3203 I GlobalDismissManager: no sender configured
    04-18 13:17:59.973  3120  3203 D AlertService: Beginning updateAlertNotification
    04-18 13:17:59.988  3120  3203 D AlertService: No fired or scheduled alerts

**Typical LogInfo string from kmsg(Kernel)**
    [ 6094.820154] [0:    kworker/u:5:  370] sec_bat_check_callback:  battery->pdata->bat_irq_gpio(535)
    [ 6094.820266] [0:    kworker/u:5:  370] sec_bat_check_callback:  Battery status(1)
    [ 6094.820881] [0:    kworker/u:5:  370] max77803_get_health_state: reg_data(0x3)


**Define LogInfo String based on previous sample**
    [D] [$Property TAG]: [$Property string]
    [A] [$TimeStamp] [UID] [PID] [$Module TAG]: [$Module string]
    [K] [$TimeStamp] [UID] [PID] [$Module TAG if has]: [$Module string]

    *loginfo filter sample:*
    //see deviceinfo_collect/etc/info_filter.xml[json].

**LogInfo String Details**
1. [D]/[A]/[K]  defines loginfo string comes from DeviceInfo or android layer or kernel layer.
2. [$TimeStamp]     is the fixed format to record loginfo time. eg:[04-18 13:17:59.972]
3. [UID] [PID]      shows the process/thread id if have.
4. [$Module TAG]    shows the TAG STRING defines in log if it has.
5. [$Module string] shows all the string contains in logcat/kmsg.


**Filter Define**
1. $TAG:       [AlertService] string to define which tag we should GET from loginfo.
2. $CONTAIN:   [Beginning] string to define which loginfo we should GET from $TAG[item 1].
3. $EXCEPTION: [No fired] string to define which loginfo we should REMOVE from $TAG+$CONTAIN[item 2].


**Recorder Define**
1. $LogInfo_limit:    max loginfo size to write to one file.
2. $LogInfo_count:    max count to write [max loginfo size] to one file.
3. $LogFile_limit:    max file count. will rewrite the oldest file in loop.

    *recorder.json file sample:*
    //see deviceinfo_collect/etc/recorder.xml[json].


**Client Define**
1. $Server_addr:    server address in [IP_ADDR] or [DOMAIN_NAME].
2. $Server_port:    server port.
3. $Config_version: current config file version.
4. $Retry_limit:    retry limit in send record and get update config.

    *clent.json file sample:*
    //see deviceinfo_collect/etc/client.xml[json].
