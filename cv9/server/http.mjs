import path from 'path';
import { fileURLToPath } from 'url';
import express from 'express';
import { createServer } from 'http';

const app = express();
const http = createServer(app);

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.use(express.static(path.resolve(__dirname, '../client/dist')));

app.get('*', (req, res) => {
    res.sendFile(path.resolve(__dirname, '../client/dist', 'index.html'));
})

export {
    app,
    http
};