@echo off
"C:\Program Files\Microchip\xc16\v1.10\bin\xc16-gcc.exe"   ../App_MTR.c  -o build/default/production/_ext/1472/App_MTR.o  -c -mcpu=24FJ256GB106  -MMD -MF "build/default/production/_ext/1472/App_MTR.o.d"        -g -omf=coff -mlarge-code -mlarge-data -O1 -I"..\UART" -I"..\MSDCLInterface" -I".." -I"..\..\..\..\..\Source\ApplicationProfiles\SEProfile\Source\SE_MTR" -I"..\..\.." -I"..\..\..\..\..\Source\ApplicationProfiles\SEProfile\Source" -I"..\..\..\..\..\Source\ApplicationProfiles\SEProfile\Interface" -I"..\..\..\..\..\Source\ZCL\Interface\ClusterDomain\SmartEnergy" -I"..\..\..\..\..\Source\ZCL\Interface\ClusterDomain\General" -I"..\..\..\..\..\Source\ZCL\Interface" -I"..\..\..\..\..\Source\CBKE" -I"..\..\..\..\..\Source\Common" -I"..\..\..\..\..\Source\ZigBeeStack" -msmart-io=1 -Wall -msfr-warn=off
