import dgram from 'dgram';

class UDPServer {
    constructor() {
        this.socket = dgram.createSocket('udp4');
        this.callbacks = new Map();

        this.socket.on('error', (err) => {
            console.log(`server error:\n${err.stack}`);
            this.socket.close();
        });

        this.socket.on('message', (buffer, rinfo) => {
            const size32 = 4;
            const shift = 1000;

            const reading = {
                timestamp: null,
                hts221: {
                    temperature: 0,
                    humidity: 0
                },
                lps25h: {
                    temperature: 0,
                    pressure: 0
                }
            };

            reading.timestamp = buffer.readInt32LE(0);
            reading.hts221.temperature = buffer.readInt32LE(size32 * 2) / shift;
            reading.hts221.humidity = buffer.readInt32LE(size32 * 4) / shift;
            reading.lps25h.temperature = buffer.readInt32LE(size32 * 6) / shift;
            reading.lps25h.pressure = buffer.readInt32LE(size32 * 8) / shift;
            
            this.callbacks.forEach(cb => cb(reading));
        });
    }

    bind(port, cb) {
        this.socket.bind(port);
        this.socket.once('listening', cb);
    }

    addListener(id, callback) {
        this.callbacks.set(id, callback);
    }

    removeListener(id) {
        this.callback.delete(id);
    }
}

export {
    UDPServer
}