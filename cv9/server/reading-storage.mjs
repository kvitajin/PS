class ReadingStorage {
    constructor(config = { maxLength: 17280, maxAge: 17280 }) {
        this.config = config;
        this.readings = [];
    }

    push(reading) {
        this.readings.push(reading);
        this.cleanUp();
    }

    cleanUp() {
        return;
    }
}

export {
    ReadingStorage
}