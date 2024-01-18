#!/bin/bash

openvpn_configfile="/home/czernecki/Pobrane/VPN-AGH.2024.ovpn"
vpn_pid_file="/tmp/vpn.agh.pid"
log_file="/home/czernecki/Pobrane/vpnagh.log"

log_event() {
     if [ -f "$log_file" ]; then
        echo ""
    else
        touch $log_file
        echo "UTworzono plik z logami"
    fi

    event=$1
    timestamp=$(date)
    echo "[$timestamp] $event" >> "$log_file"
}

start() {
    if [ -f "$vpn_pid_file" ]; then
        echo "Istnieje już połączenie VPN"
    else
        sudo openvpn $openvpn_configfile
        echo "Otwieranie połączenia VPN"
        log_event "Otwarto połączenie"
        ssh user@student.agh.edu.pl; 
    fi
    
}

status() {
    if [ -f "$vpn_pid_file" ]; then
        echo "Istnieje połączenie VPN"
    else
        echo "Nie ma utworzonego połaczenia VPN"
    fi
    log_event "Sprawdzono status"
}

stop() {
    if [ -f "$vpn_pid_file" ]; then
        echo "Zamykanie połączenia..."
        sudo kill $(cat "$vpn_pid_file")
        rm "$vpn_pid_file"
        log_event "Zamknięto połączenie"
    else
        echo "Nie ma utworzonego połaczenia VPN"
    fi
}

case "$1" in
    "start")
        start
    ;;
    "status")
        status
    ;;
    "stop")
        stop
    ;;
    *)
        echo "Wybierz opcje start/status/stop"
esac