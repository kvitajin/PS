import { Server as SocketIOServer } from 'socket.io';
import { http } from './app.mjs';

const io = new SocketIOServer(http);

export {
    io
}