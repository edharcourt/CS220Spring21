"""
Utility for making sure all of the Raspberry Pis are up and running.
"""
# https://stackoverflow.com/questions/2953462/pinging-servers-in-python

import platform    # For getting the operating system name
import subprocess  # For executing a shell command

def ping(host):
    """
    Returns True if host (str) responds to a ping request.
    Remember that a host may not respond to a ping (ICMP) request even if the host name is valid.
    """

    # Option for the number of packets as a function of
    param = '-n' if platform.system().lower()=='windows' else '-c'

    # Building the command. Ex: "ping -c 1 google.com"
    command = ['ping', param, '1', host]

    cp = subprocess.run(command, capture_output=True)
    return cp.returncode == 0


if __name__ == "__main__":
    hosts  = open("piips.txt")
    success = True
    for host in hosts:
        host = host.strip()  # get rid of eol
        if ping(host):
            print(f"{host} is alive")
        else:
            print(f"{host} is not alive")
            success = False

    if success:
       print("All hosts are alive")