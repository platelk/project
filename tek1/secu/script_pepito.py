#!/usr/bin/env python
import nmap                         # import nmap.py module

ip = '10.19.253.'

nm = nmap.PortScanner()         # instantiate nmap.PortScanner object
nm.scan(ip, '31337')      # scan host 127.0.0.1, ports from 22 to 443
nm.command_line()                   # get command line used for the scan : nmap -oX - -p 22-443 127.0.0.1
nm.scaninfo()                       # get nmap scan informations {'tcp': {'services': '22-443', 'method': 'connect'}}
nm.all_hosts()                      # get all hosts that were scanned
nm[ip].hostname()          # get hostname for host 127.0.0.1
nm[ip].state()             # get state of host 127.0.0.1 (up|down|unknown|skipped)
nm[ip].all_protocols()     # get all scanned protocols ['tcp', 'udp'] in (ip|tcp|udp|sctp)
nm[ip].all_tcp()           # get all ports for tcp protocol (sorted version)
nm[ip].all_udp()           # get all ports for udp protocol (sorted version)
nm[ip].all_ip()            # get all ports for ip protocol (sorted version)
nm[ip].all_sctp()          # get all ports for sctp protocol (sorted version)
nm[ip].has_tcp(22)         # is there any information for port 22/tcp on host 127.0.0.1


# a more usefull example :
for host in nm.all_hosts():
    print('----------------------------------------------------')
    print('Host : %s (%s)' % (host, nm[host].hostname()))
    print('State : %s' % nm[host].state())
    
    for proto in nm[host].all_protocols():
        print('----------')
        print('Protocol : %s' % proto)
        lport = nm[host][proto].keys()
        lport.sort()
        for port in lport:
            print('port : %s\tstate : %s' % (port, nm[host][proto][port]['state']))
