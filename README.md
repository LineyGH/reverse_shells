# Reverse Shells in Multiple Languages

This repository contains reverse shell scripts in the following programming languages:

- Python
- Ruby
- PHP
- JavaScript
- C
- C++
- C#
- F#
- Perl
- Go
- Java
- PowerShell
- R
- Bash

## Disclaimer

The scripts in this repository are for **educational purposes only**. I am not responsible for how these reverse shells are used. **You are solely responsible for ensuring that you have explicit permission to use these scripts on any network or system.**

Unauthorized access or testing of systems without permission is illegal and unethical. **Use these scripts responsibly and only in environments where you have clear authorization.** Misuse of this code may result in legal consequences.


## Instructions

These reverse shell scripts are intended for educational and ethical penetration testing purposes only. **Do not use these scripts without permission on networks or systems you do not own or have explicit authorization to test.**

### Usage

Before running any of these reverse shells, make sure to:

1. **Change the `attacker_ip` and `attacker_port`** to your actual IP address and listening port.
   - Example:
     - `attacker_ip = "192.168.1.10"`
     - `attacker_port = 4444`

2. Start a listener on your attack machine using a tool like `netcat` or `nc`:
   ```bash
   nc -lvnp 4444
