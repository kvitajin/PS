import { Server as SocketIOServer } from 'socket.io';
import { UDPServer } from "./udp.mjs";
import { app, http } from './http.mjs';
import { ReadingStorage } from './reading-storage.mjs';

const UDP_PORT = 9000;
const HTTP_PORT = 3000;

const io = new SocketIOServer(http);
const udp = new UDPServer();
const readingStorage = new ReadingStorage();

udp.addListener('global', (reading) => {
    io.emit('readings', [reading]);
    console.log(`Emitted reading ${JSON.stringify(reading)} to all connected clients.`);

    readingStorage.push(reading);
});

io.on('connection', client => {
    client.emit('readings', readingStorage.readings);
});

udp.bind(UDP_PORT, () => {
    const address = udp.socket.address();
    console.log(`UDP server listening ${address.address}:${address.port}`);
});
http.listen(HTTP_PORT, () => {
    const address = http.address();
    console.log(`HTTP server listening on ${address.address}:${address.port}`);
});