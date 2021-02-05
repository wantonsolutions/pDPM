#!/bin/bash

host=`hostname`
pword="iwicbV15"
prefix="[launcher] "

#reset the nics
echo "$prefix running on $host"

if [[ $host == "b09-27.sysnet.ucsd.edu" ]]; then
    memcached -u root -I 128m -m 2048
elif [[ $host == "yak-00.sysnet.ucsd.edu" ]]; then
    running_meta=`ps -e | grep run_ms.sh`
    if [[ "$running_meta" == "" ]]; then
        echo "$prefix no meta running, starting meta"
        echo $pword | sudo -S ~/warm/setup.sh
        echo $pword | sudo -S ./run_ms.sh 0
    else
        echo "$prefix allready running meta server running memory"
        echo $pword | sudo -S ./run_memory.sh 2
    fi
elif [[ $host == "yak-01.sysnet.ucsd.edu" ]]; then
        echo $pword | sudo -S ~/warm/setup.sh
        echo $pword | sudo -S ./run_client.sh 1
else
    echo "$prefix unknown host $host"
fi

    
